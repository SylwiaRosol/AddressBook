#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Users.h"


using namespace std;

vector <Users> Users::transferUsersFromFile (vector <Users> &allUsers) {
    fstream plik;
    plik.open("uzytkownicy.txt", ios::in);
    string line;
    int numberWord = 1;
    string word;
    Users user;
    int numberIdUser;

    while(getline(plik,line)) {
        for( int i = 0; i < line.size(); i++) {
            if(line[i] != '|' ) {
                word += line[i];
            } else {
                switch (numberWord) {
                case 1:
                    user.numberIdUser = atoi(word.c_str());
                    break;
                case 2:
                    user.userName = word;
                    break;
                case 3:
                    user.password = word;
                    break;
                }
                if(numberWord == 3) {
                    numberWord = 0;
                    allUsers.push_back(user);
                }
                numberWord++;
                word = "";
            }
        }
    }

    plik.close();
    return allUsers;
}

void Users::transferUsersFromVectorToFile(vector <Users> &allUsers) {
    fstream plik;

    plik.open("uzytkownicy.txt", ios::out | ios::trunc );

    for( vector<Users>::iterator i = allUsers.begin(); i <allUsers.end(); i++) {
        plik << i-> numberIdUser << "|" << i->userName << "|" << i->password << "|" << endl;
    }
    plik.close();

}

vector <Users> Users::addUser (vector<Users> &allUsers) {
    string userName;
    string password;
    int numberIdUser;
    Users user;
    fstream plik;

    system("cls");

    cout<< "---------REJSTRACJA--------" << endl;
    cout << "Podaj swoj login" << endl;
    cin >> user.userName;
    cout << "Podaj haslo" << endl;
    cin >> user.password;
    cout << "Uzytkownik zostal dodany" << endl;

    if (allUsers.empty() == true) {
        user.numberIdUser = 0;
    } else {
        user.numberIdUser = allUsers.back().numberIdUser+1;
    }

    allUsers.push_back(user);
    transferUsersFromVectorToFile(allUsers);
    system("pause");
    return allUsers;
}

int Users::singIn (vector<Users> &allUsers) {
    string userName;
    string password;
    int numberIdUser=0;
    Users user;
    bool goodName = false;

    cout << "---------LOGOWANIE-------" << endl;
    cout <<"Podaj swoja nazwe uzytkownika" << endl;
    cin >> userName;
    for( vector<Users>::iterator i = allUsers.begin(); i < allUsers.end(); i++) {
        if ( i->userName == userName) {
            goodName = true;
            cout << "Podaj haslo" << endl;
            cin >> password;
            if (i->password == password) {
                cout << "Jestes zalogowany" << endl;
                numberIdUser = i-> numberIdUser;
            } else if (i->password != password) {
                cout << "Bledne haslo. Sprobuj ponownie" << endl;
                numberIdUser = 0;
            }}}
        if (goodName == false)  {
                cout << "Bledna nazwa uzytkownika. Sprobuj ponownie" << endl;
                numberIdUser = 0;
        }
        system("pause");
        return numberIdUser;
    }

vector <Users> Users::changePassword (vector <Users> &allUsers, int numberIdUser) {
        string newPassword;
        cout << "--------ZMIANA HASLA--------" << endl;
        cout << "Podaj nowe haslo" << endl;
        cin >> newPassword;

        for( vector<Users>::iterator i = allUsers.begin(); i < allUsers.end(); i++) {
            if( i-> numberIdUser == numberIdUser) {
                i-> password = newPassword;
                cout << "Haslo zostalo zmienione" << endl;
                transferUsersFromVectorToFile(allUsers);
            }
        }
        system("pause");
        return allUsers;
    }

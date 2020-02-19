#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Users {
    string userName;
    string password;
    int numberIdUser;

};

struct Person {
    int numberIdPerson, phoneNumberPerson, numberIdUser;
    string namePerson, surnamePerson, email, address;
};



vector <Users> transferUsersFromFile ( vector <Users> &allUsers) {
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

vector <Person> transferPeopleFromFileToStructure (vector<Person> &peopleFromBook, int numberIdUserLogged) {
    fstream plik;
    plik.open("ksiazka.txt", ios::in);
    string line;
    int numberWord = 1;
    string word;
    Person personFromBook;
    int numberIdPerson;



    while(getline(plik,line)) {
        for( int i = 0; i < line.size(); i++) {
            if(line[i] != '|' ) {
                word += line[i];
            } else {

                switch (numberWord) {
                case 1:
                    personFromBook.numberIdPerson = atoi(word.c_str());
                    break;
                case 2:
                    personFromBook.numberIdUser = atoi(word.c_str());
                    break;
                case 3:
                    personFromBook.namePerson = word;
                    break;
                case 4:
                    personFromBook.surnamePerson = word;
                    break;
                case 5:
                    personFromBook.phoneNumberPerson =  atoi(word.c_str());
                    break;
                case 6:
                    personFromBook.email = word;
                    break;
                case 7:
                    personFromBook.address = word;
                    break;
                }
                if(numberWord == 7) {
                    numberWord = 0;
                    if( personFromBook.numberIdUser == numberIdUserLogged) {
                        peopleFromBook.push_back(personFromBook);
                    }
                }

                numberWord++;
                word = "";
            }
        }
    }

    plik.close();
    return peopleFromBook;
}

void transferPeopleFromStructureToFile(vector <Person> &peopleFromBook) {
    fstream plik;
    plik.open( "ksiazka.txt", ios::out | ios::trunc );
    for( vector<Person>::iterator i = peopleFromBook.begin(); i <peopleFromBook.end(); i++) {

        plik << i->numberIdPerson << "|" << i->numberIdUser << "|" << i->namePerson << "|" << i->surnamePerson << "|" << i->phoneNumberPerson  << "|" << i->email << "|" << i->address << "|" << endl;
    }

    plik.close();
}

void transferToSecondFile(vector <Person> &peopleFromBook, int numberIdPerson, int numberIdUserLogged) {
    fstream plik1, plik2;
    plik1.open( "ksiazka.txt", ios::in);
    plik2.open( "ksiazka_tymczasowa.txt", ios::out | ios::app);


    string line;
    int numberWord = 1;
    string word;
    Person personFromBook;



    while(getline(plik1,line)) {
        for( int i = 0; i < line.size(); i++) {
            if(line[i] != '|' ) {
                word += line[i];
            } else {

                switch (numberWord) {
                case 1:
                    personFromBook.numberIdPerson = atoi(word.c_str());
                    break;
                case 2:
                    personFromBook.numberIdUser = atoi(word.c_str());
                    break;
                case 3:
                    personFromBook.namePerson = word;
                    break;
                case 4:
                    personFromBook.surnamePerson = word;
                    break;
                case 5:
                    personFromBook.phoneNumberPerson =  atoi(word.c_str());
                    break;
                case 6:
                    personFromBook.email = word;
                    break;
                case 7:
                    personFromBook.address = word;
                    break;

                }
                if(numberWord == 7) {
                    numberWord = 0;
                    if( personFromBook.numberIdUser != numberIdUserLogged) {
                        plik2 << personFromBook.numberIdPerson << "|" << personFromBook.numberIdUser <<"|" << personFromBook.namePerson << "|" << personFromBook.surnamePerson << "|" << personFromBook.phoneNumberPerson  << "|" << personFromBook.email << "|" << personFromBook.address << "|" << endl;
                    }

                    else if(personFromBook.numberIdUser == numberIdUserLogged) {
                        int zmienna = personFromBook.numberIdPerson;
                        for( vector<Person>::iterator i = peopleFromBook.begin(); i <peopleFromBook.end(); i++) {
                            if (i->numberIdPerson == zmienna)
                                plik2 << i->numberIdPerson << "|" << i->numberIdUser << "|" << i->namePerson << "|" << i->surnamePerson << "|" << i->phoneNumberPerson  << "|" << i->email << "|" << i->address << "|" << endl;
                        }
                    }

                }

                numberWord++;
                word = "";
            }
        }
    }


    plik1.close();
    plik2.close();

    system("erase ksiazka.txt");
    rename( "ksiazka_tymczasowa.txt", "ksiazka.txt");
}

void transferUsersFromStructureToFile(vector <Users> &allUsers) {
    fstream plik;

    plik.open("uzytkownicy.txt", ios::out | ios::trunc );

        for( vector<Users>::iterator i = allUsers.begin(); i <allUsers.end(); i++) {
    plik << i-> numberIdUser << "|" << i->userName << "|" << i->password << "|" << endl;
        }
    plik.close();

}

int transferNumberIdLastPerson () {
    fstream plik;
    plik.open("ksiazka.txt", ios::in);
    string line;
    int numberWord = 1;
    string word;
    int numberIdLastPerson;
if (plik.good() == false)
{
    numberIdLastPerson = 0;
}

else {
    while(getline(plik,line)) {
        for( int i = 0; i < line.size(); i++) {
            if(line[i] != '|' ) {
                word += line[i];
            } else {

                switch (numberWord) {
                case 1:
                    numberIdLastPerson = atoi(word.c_str());
                    break;
                }
                if(numberWord == 7) {
                    numberWord = 0;
                }

                numberWord++;
                word = "";
            }
        }
    }
    }
    plik.close();
    return numberIdLastPerson;
}



vector <Users> addUser (vector<Users> &allUsers) {
    string userName;
    string password;
    int numberIdUser;
    Users user;
    fstream plik;

    system("cls");

    cout<< "Rejstracja" << endl;
    cout << "Podaj swoj login" << endl;
    cin >> userName;
    cout << "Podaj haslo" << endl;
    cin >> password;
    cout << "Uzytkownik zostal dodany" << endl;

    if (allUsers.empty() == true) {
        numberIdUser = 0;
    } else {
        numberIdUser = allUsers.back().numberIdUser;
    }

    user.userName = userName;
    user.password = password;
    user.numberIdUser = numberIdUser+1;
    allUsers.push_back(user);

    transferUsersFromStructureToFile(allUsers);
    return allUsers;
}

int singIn (vector<Users> &allUsers) {
    string userName;
    string password;
    int numberIdUser=0;
    Users user;
    cout <<"Podaj swoj nick" << endl;
    cin >> userName;
    for( vector<Users>::iterator i = allUsers.begin(); i < allUsers.end(); i++) {
        if ( i->userName == userName) {
            cout << "Podaj haslo" << endl;
            cin >> password;
            if (i->password == password) {
                cout << "Jestes zalogowany" << endl;
                numberIdUser = i-> numberIdUser;
            }
            else if (i->password != password) {
                    numberIdUser = 0;
                }
            else if (i->userName != userName) {
                numberIdUser = 0;
            }
        }
    }


    system("pause");

    return numberIdUser;
}

vector <Users> changePassword (vector <Users> &allUsers, int numberIdUser) {
    string newPassword;
    cout << "Podaj nowe haslo" << endl;
    cin >> newPassword;
    numberIdUser;

    for( vector<Users>::iterator i = allUsers.begin(); i < allUsers.end(); i++) {
        if( i-> numberIdUser == numberIdUser) {
            i-> password = newPassword;
            cout << "Haslo zostalo zmienione" << endl;

        }

    }
    transferUsersFromStructureToFile(allUsers);
    system("pause");
    return allUsers;
}



vector <Person> addPersonToAddressBook(vector<Person> &peopleFromBook, int numberIdUser) {

    fstream plik;
    string namePerson, surnamePerson, email, address;
    int phoneNumberPerson, numberIdPerson;
    Person personFromBook;

    numberIdPerson = transferNumberIdLastPerson ();

    plik.open("ksiazka.txt", ios::out | ios::app);


    cout << "-----DODAWANIE NOWEJ OSOBY DO KSIAZKI ADRESOWEJ-----" << endl << endl;
    cout << "Podaj imie przyjaciela: " << endl;
    cin >>  namePerson;
    cout << "Podaj nazwisko przyjaciela: " << endl;
    cin >> surnamePerson;
    cout << "Podaj nr telefonu przyjaciela: " << endl;
    cin >> phoneNumberPerson;
    cout << "Podaj email przyjaciela: " << endl;
    cin >> email;
    cout << "Podaj adres przyjaciela: " << endl;
    cin.ignore();
    getline(cin, address);
    numberIdPerson++;

    plik << numberIdPerson << "|" << numberIdUser << "|" << namePerson << "|" << surnamePerson << "|" << phoneNumberPerson  << "|" << email << "|" << address << "|" << endl;

    plik.close();

    personFromBook.numberIdPerson = numberIdPerson;
    personFromBook.namePerson = namePerson;
    personFromBook.surnamePerson = surnamePerson;
    personFromBook.phoneNumberPerson = phoneNumberPerson;
    personFromBook.email = email;
    personFromBook.address = address;

    peopleFromBook.push_back(personFromBook);

    cout << "Osoba zostala dodana do ksiazki telefonicznej";
    Sleep(1500);
    return peopleFromBook;
}

void searchByName (vector <Person> &peopleFromBook) {
    string namePerson = "";
    Person personFromBook;

    system("cls");
    cout << "-----WYSZUKIWANIE OSOBY PO IMIENIU-----"<< endl << endl;
    cout << "Podaj imie: " << endl;
    cin >> namePerson;

    cout <<"Dane wyszukanej osoby to: " << endl << endl;


    for( vector<Person>::iterator i = peopleFromBook.begin(); i < peopleFromBook.end(); i++) {

        if (i->namePerson == namePerson) {
            cout<<"Imie i nazwisko: " << i->namePerson << " " << i->surnamePerson << endl;
            cout<<"Telefon: " << i->phoneNumberPerson << endl;
            cout<< "Email: " << i->email << endl;
            cout<<"Adres: " << i->address << endl << endl;
        }


    }

    system("pause");

}

void searchBySurname (vector <Person> &peopleFromBook) {
    string surnamePerson;
    cout << "-----WYSZUKIWANIE OSOBY PO NAZWISKU-----"<< endl << endl;
    cout << "Podaj nazwisko: " << endl;
    cin >> surnamePerson;

    cout << "Dane wyszukanej osoby to: " << endl << endl;

    for( vector<Person>::iterator i = peopleFromBook.begin(); i <peopleFromBook.end(); i++) {

        if (i->surnamePerson == surnamePerson) {
            cout<<"Imie i nazwisko: " << i->namePerson << " " << i->surnamePerson << endl;
            cout<<"Telefon: " << i->phoneNumberPerson << endl;
            cout<< "Email: " << i->email << endl;
            cout<<"Adres: " << i->address << endl << endl;
        }
    }
    system("pause");

}

void findPersonInTheAddressBook(vector <Person> &peopleFromBook) {
    char choice;

    system("cls");
    cout << "1. Znajdz osobe o danym imieniu" << endl;
    cout << "2. Znajdz osobe o danym nazwisku" << endl;
    cin >> choice;

    switch (choice) {
    case '1':
        searchByName (peopleFromBook);
        break;
    case '2':
        searchBySurname (peopleFromBook);
        break;
    default:
        exit(0);
        break;
    }
}

void viewAllPeopleInTheAddressBook(vector <Person> &peopleFromBook) {

    cout << "-----WSZYSTKIE OSOBY Z KSIAZKI TELEFONICZNEJ----- " << endl << endl;

    for( vector<Person>::iterator i = peopleFromBook.begin(); i <peopleFromBook.end(); i++) {

        cout << i->namePerson << " " << i->surnamePerson << endl;
        cout <<"telefon: " << i->phoneNumberPerson << endl;
        cout << "email: " << i->email << endl;
        cout << "adres: " << i->address << endl;
        cout << "numer Id osoby: " << i->numberIdPerson << endl << endl;

    }
    system("pause");
}

vector <Person> deletePeopleFromBook(vector <Person> &peopleFromBook, int numberIdUser) {
    int numberId;
    char choice;
    cout << "-----USUWANIE OSOBY Z KSIAZKI ADRESOWEJ-----"<< endl << endl;
    cout << "Podaj numer ID osoby, ktora chcesz usunac" << endl;
    cin >> numberId;
    for( vector<Person>::iterator i = peopleFromBook.begin(); i <peopleFromBook.end(); i++) {
        if (i->numberIdPerson == numberId) {
            cout << "Jesli chcesz usunac osobe o numerz id " << numberId << " wcisnij t" << endl;
            cin >> choice;
            if( choice == 't') {
                peopleFromBook.erase(i);
                cout << "Zostala usunieta osoba o numerze id " << numberId << endl;
                system("pause");
            } else {
                cout << "Osoba nie zostala usunieta";
                Sleep(1500);
            }

        }
    }
    transferToSecondFile(peopleFromBook, numberId, numberIdUser);
    return peopleFromBook;
}

vector <Person> editInformacionFromBook(vector <Person> &peopleFromBook, int numberIdUser) {
    system("cls");
    char choice;
    int numberIdPerson, phoneNumberPerson, numerId;
    string namePerson, surnamePerson, email, address;

    cout << " -----EDYCJA DANYCH-----"<< endl << endl;
    cout<< "Podaj nr ID osoby, ktorej dane chcesz edytowac"<< endl;
    cin >> numerId;
    for( vector<Person>::iterator i = peopleFromBook.begin(); i < peopleFromBook.end(); i++) {

            if (i->numberIdPerson == numerId) {
                system("cls");
                cout << "-----CO CHCESZ EDYTOWAC-----"<< endl;
                cout << "----------------------"<< endl;
                cout << "1. Imie" << endl;
                cout << "2. Nazwisko" << endl;
                cout << "3. Numer telefonu" << endl;
                cout << "4. Email" << endl;
                cout << "5. Adres" << endl;
                cout << "6. Powrot do menu glownego" << endl;
                cout << "Twoj wybor to: ";
                cin >> choice;

                switch (choice) {
                case '1':
                    cout << "Podaj na jakie imie chcesz zmienic?"<< endl;
                    cin >> i->namePerson;
                    cout << "Imie zostalo zmienione" << endl;
                    Sleep(1500);
                    break;


                case '2':
                    cout << "Podaj na jakie nazwisko chcesz zmienic?"<< endl;
                    cin >>  i->surnamePerson;
                    cout << "Nazwisko zostalo zmienione" << endl;
                    Sleep(1500);
                    break;

                case '3':
                    cout << "Podaj na jaki numer telefonu chcesz zmienic?"<< endl;
                    cin >> i->phoneNumberPerson;
                    cout << "Numer telefonu zostal zmieniny" << endl;
                    Sleep(1500);
                    break;

                case '4':
                    cout << "Podaj na jaki adres email chcesz zmienic?"<< endl;
                    cin >> i->email;
                    cout << "Email zostal zmieniony" << endl;
                    Sleep(1500);
                    break;

                case '5':
                    cout << "Podaj na jaki adres chcesz zmienic?"<< endl;
                    cin >> i->address;
                    cout << "Adres zostal zmieniony" << endl;
                    Sleep(1500);
                    break;

                case '6':
                    break;
                }
        }
    }

    transferToSecondFile(peopleFromBook, numberIdPerson, numberIdUser);


    return peopleFromBook;
}





int main() {

    vector <Person> peopleFromBook;
    vector<Users> allUsers;
    int numberIdUser=0;
    char choice;

    allUsers = transferUsersFromFile (allUsers);

    while (1) {
        if(numberIdUser == 0) {
            system("cls");

            cout << "-----KSIAZKA TELEFONICZNA-----"<< endl;
            cout << "--------------------------"<< endl;
            cout << "1. Zarejstruj sie" << endl;
            cout << "2. Zaloguj sie" << endl;
            cout << "3. Zamknij program" << endl;
            cout << "Twoj wybor to: ";
            cin >> choice;

            switch (choice) {
            case '1':
                allUsers = addUser(allUsers);
                break;

            case '2':
                numberIdUser = singIn (allUsers);
                peopleFromBook = transferPeopleFromFileToStructure(peopleFromBook, numberIdUser);
                break;

            case '3':
                exit(0);
                break;
            }
        }


        else if( numberIdUser != 0) {

            system("cls");
            cout << "-----KSIAZKA TELEFONICZNA-----"<< endl;
            cout << "--------------------------"<< endl;
            cout << "1. Dodaj osobe do ksiazki telefonicznej" << endl;
            cout << "2. Znajdz osobe w ksiazce telefonicznej" << endl;
            cout << "3. Wyswietl wszystkie osoby w ksiazce telefonicznej" << endl;
            cout << "4. Usun adresata" << endl;
            cout << "5. Edytuj adresata" << endl;
            cout << "6. Zmien haslo" << endl;
            cout << "7. Wyloguj sie" << endl;;
            cout << "9. Zakoncz program" << endl;

            choice = '0';
            cin >> choice;

            switch (choice) {
            case '1':
                peopleFromBook = addPersonToAddressBook(peopleFromBook, numberIdUser);
                break;
            case '2':
                findPersonInTheAddressBook(peopleFromBook);
                break;
            case '3':
                viewAllPeopleInTheAddressBook(peopleFromBook);
                break;
            case '4':
                peopleFromBook = deletePeopleFromBook(peopleFromBook, numberIdUser);
                break;
            case '5':
                peopleFromBook = editInformacionFromBook(peopleFromBook, numberIdUser);
                break;
            case '6':
                allUsers = changePassword ( allUsers, numberIdUser);
                break;
            case '7':
                numberIdUser = 0;
                peopleFromBook.clear();
                break;
            case '9':
                exit(0);
                break;
            default:
                exit(0);
                break;
            }
        }
    }

    return 0;
}

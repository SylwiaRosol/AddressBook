#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Person {
    int numberIdPerson, phoneNumberPerson;
    string namePerson, surnamePerson, email, address;
};

vector <Person> transferPeopleFromFileToStructure (vector<Person> &peopleFromBook) {
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
                    personFromBook.namePerson = word;
                    break;
                case 3:
                    personFromBook.surnamePerson = word;
                    break;
                case 4:
                    personFromBook.phoneNumberPerson =  atoi(word.c_str());
                    break;
                case 5:
                    personFromBook.email = word;
                    break;
                case 6:
                    personFromBook.address = word;
                    break;

                }
                if(numberWord == 6) {
                    numberWord = 0;
                    peopleFromBook.push_back(personFromBook);

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

        plik << i->numberIdPerson << "|" << i->namePerson << "|" << i->surnamePerson << "|" << i->phoneNumberPerson  << "|" << i->email << "|" << i->address << "|" << endl;
    }

    plik.close();
}

vector <Person> addPersonToAddressBook(vector<Person> &peopleFromBook) {

    fstream plik;

    plik.open("ksiazka.txt", ios::out | ios::app);
    string namePerson, surnamePerson, email, address;
    int phoneNumberPerson, numberIdPerson;
    Person personFromBook;

    if (peopleFromBook.empty() == true) {
        numberIdPerson = 0;
    } else {
        numberIdPerson = peopleFromBook.back().numberIdPerson;
    }

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

    plik << numberIdPerson << "|" <<  namePerson << "|" << surnamePerson << "|" << phoneNumberPerson  << "|" << email << "|" << address << "|" << endl;

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
    string namePerson;
    Person personFromBook;

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

        if ( i->surnamePerson == surnamePerson) {
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

vector <Person> editInformacionFromBook(vector <Person> &peopleFromBook) {
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
    transferPeopleFromStructureToFile(peopleFromBook);
    return peopleFromBook;
}

vector <Person> deletePeopleFromBook(vector <Person> &peopleFromBook) {
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
    transferPeopleFromStructureToFile(peopleFromBook);
    return peopleFromBook;
}



int main() {

    vector <Person> peopleFromBook;
    Person personFromBook;


    peopleFromBook = transferPeopleFromFileToStructure(peopleFromBook);

    while (1) {
        system("cls");
        cout << "-----KSIAZKA TELEFONICZNA-----"<< endl;
        cout << "--------------------------"<< endl;
        cout << "1. Dodaj osobe do ksiazki telefonicznej" << endl;
        cout << "2. Znajdz osobe w ksiazce telefonicznej" << endl;
        cout << "3. Wyswietl wszystkie osoby w ksiazce telefonicznej" << endl;
        cout << "4. Usun adresata" << endl;
        cout << "5. Edytuj adresata" << endl;
        cout << "9. Zakoncz program" << endl;
        char choice;
        cin >> choice;

        switch (choice) {
        case '1':
            peopleFromBook = addPersonToAddressBook(peopleFromBook);
            break;
        case '2':
            findPersonInTheAddressBook(peopleFromBook);
            break;
        case '3':
            viewAllPeopleInTheAddressBook(peopleFromBook);
            break;
        case '4':
            peopleFromBook = deletePeopleFromBook(peopleFromBook);
            break;
        case '5':
            peopleFromBook = editInformacionFromBook(peopleFromBook);
            break;
        case '9':
            exit(0);
            break;
        default:
            exit(0);
            break;
        }
    }

    return 0;
}

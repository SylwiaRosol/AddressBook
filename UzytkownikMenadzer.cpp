#include "UzytkownikMenadzer.h"
#include "MetodyPomocnicze.h"



void UzytkownikMenadzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}


Uzytkownik UzytkownikMenadzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    string login;
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do{
    cout << "Podaj login: ";
    cin >> login;
    } while (czyIstniejeLogin(login));
     uzytkownik.ustawLogin(login);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);
    return uzytkownik;
}

int UzytkownikMenadzer::pobierzIdNowegoUzytkownika()
{
     if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenadzer::czyIstniejeLogin(string login)
{
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie " << endl;
            return true;
    }
    }
    return false;

}

int UzytkownikMenadzer::logowanieUzytkownika()
{
     Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                     idZalogowanegoUzytkownika = itr -> pobierzId();
                     return idZalogowanegoUzytkownika;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UzytkownikMenadzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> pobierzId() == pobierzIdZalogowanegoUzytkownika())
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
   plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}


void UzytkownikMenadzer::wylogowanie()
{
    idZalogowanegoUzytkownika = 0;
      cout << "Zostales wylogowany" << endl;
      Sleep(500);
}

int UzytkownikMenadzer::pobierzIdZalogowanegoUzytkownika()
{
return idZalogowanegoUzytkownika;
}

void UzytkownikMenadzer::ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika)
{
 idZalogowanegoUzytkownika = noweIdZalogowanegoUzytkownika;
}

 bool UzytkownikMenadzer::czyUzytkownikJestZalogowany()
 {
     if(idZalogowanegoUzytkownika > 0)
         return true;

     else
        return false;
 }

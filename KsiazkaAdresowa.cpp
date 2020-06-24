#include "KsiazkaAdresowa.h"

 void KsiazkaAdresowa::rejstracjaUzytkownika()
 {
     uzytkownikMenadzer.rejestracjaUzytkownika();
 }


void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenadzer.logowanieUzytkownika();
    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())
    {
       adresatMenadzer = new AdresatMenadzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
    }
   // uzytkownikMenadzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenadzer.logowanieUzytkownika());
    // adresatMenadzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanie()
{
    uzytkownikMenadzer.wylogowanie();
    delete adresatMenadzer;
    adresatMenadzer = NULL;
}

void KsiazkaAdresowa::dodajAdresata()
{
    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())
    {
        adresatMenadzer -> dodajAdresata();
    }
}

 void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
 {
     adresatMenadzer -> wyswietlWszystkichAdresatow();
 }


 char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
   /* cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    */
    cout << "4. Wyswietl adresatow" << endl;
   /* cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    */
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        else if (wejscie.length() > 1)
        {
            cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
        }

    }

    return znak;
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    uzytkownikMenadzer.czyUzytkownikJestZalogowany();
}

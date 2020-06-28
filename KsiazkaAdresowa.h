#include <iostream>

#include "UzytkownikMenadzer.h"
#include "AdresatMenadzer.h"


using namespace std;

class KsiazkaAdresowa
{

    UzytkownikMenadzer uzytkownikMenadzer;
    AdresatMenadzer *adresatMenadzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;


public:

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    { adresatMenadzer = NULL;
    };

    ~KsiazkaAdresowa () {
    delete adresatMenadzer;
    adresatMenadzer = NULL;
    }
    char wybierzOpcjeZMenuUzytkownika();
    char wybierzOpcjeZMenuGlownego();

    void rejstracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanie();

    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    int usunAdresata();
    void edytujAdresata();

    char wczytajZnak();
    bool czyUzytkownikJestZalogowany();
};

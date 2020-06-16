#include <iostream>

#include "UzytkownikMenadzer.h"
#include "AdresatMenadzer.h"


using namespace std;

class KsiazkaAdresowa
{

    UzytkownikMenadzer uzytkownikMenadzer;
    AdresatMenadzer adresatMenadzer;

    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    int idZalogowanegoUzytkownika;


public:

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), adresatMenadzer(nazwaPlikuZAdresatami)
    {
       uzytkownikMenadzer.wczytajUzytkownikowZPliku();
    };
    void rejstracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanie();
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
    char wybierzOpcjeZMenuUzytkownika();
    char wybierzOpcjeZMenuGlownego();
    char wczytajZnak();

};

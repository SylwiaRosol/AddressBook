#ifndef ADRESATMENADZER_H
#define ADRESATMENADZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <algorithm>

#include "Adresat.h"
#include "PlikZAdresatami.h"


using namespace std;

class AdresatMenadzer
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    Adresat adresat;
    int idOstatniegoAdresata;



public:
     AdresatMenadzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) :
        plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {};

    void dodajAdresata();
    Adresat podajDaneNowegoAdresata();

    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    string wczytajLinie();
};

#endif

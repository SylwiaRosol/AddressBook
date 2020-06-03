#ifndef ADRESATMENADZER_H
#define ADRESATMENADZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "UzytkownikMenadzer.h"

using namespace std;

class AdresatMenadzer
{

    vector <Adresat> adresaci;
    int idOstatniegoAdresata;
    int idZalogowanegoUzytkownika;
    Adresat adresat;


public:
    int dodajAdresata(int idZalogowanegoUzytkownika);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);

    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
};

#endif

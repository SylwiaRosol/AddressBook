#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"


using namespace std;

class PlikZAdresatami
{
    const string nazwaPlikuZAdresatami;
    fstream plikTekstowy;
    int idOstatniegoAdresata;

public:

    PlikZAdresatami(string nazwaPlikuZAdresatami) : nazwaPlikuZAdresatami(nazwaPlikuZAdresatami) {
    };
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> adresaci, int idZalogowanegoUzytkownika);
    Adresat pobierzDaneAdresata( string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami( string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int konwersjaStringNaInt(string liczba);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int pobierzIdOstatniegoAdresata();
    void dopiszAdresataDoPliku(Adresat adresat);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty();
};

#endif

#include "PlikTekstowy.h"

string PlikTekstowy::pobierzNazwePliku()
{
    return NAZWA_PLIKU;
}

bool PlikTekstowy::czyPlikJestPusty(fstream &plikTekstowy)
{
   // fstream plikTekstowy;
   // plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}


#include <iostream>
#include <vector>

#include "KsiazkaAdresowa.h"


using namespace std;

int main()
{
    int idUzytkownika;
    int idZalogowanegoUzytkownika,  idOstatniegoAdresata;
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt");
    //ksiazkaAdresowa.rejstracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    idUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(idUzytkownika);
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.dodajAdresata(idZalogowanegoUzytkownika);
    //ksiazkaAdresowa.wyswietlWszystkichAdresatow();


    return 0;
}

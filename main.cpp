#include <iostream>
#include <vector>

#include "KsiazkaAdresowa.h"


using namespace std;

int main()
{
    int idUzytkownika;
    int idZalogowanegoUzytkownika,  idOstatniegoAdresata;
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt");
    //ksiazkaAdresowa.rejstracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.dodajAdresata(idZalogowanegoUzytkownika);
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();


    return 0;
}

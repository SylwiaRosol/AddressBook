#include <iostream>
#include <vector>

#include "KsiazkaAdresowa.h"


using namespace std;

int main()
{

    char wybor, wybor2;
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt");

    while(1)
    {
    wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();
    if(wybor == '1')
    {
        ksiazkaAdresowa.rejstracjaUzytkownika();
    }
    else if(wybor == '2')
    {
        ksiazkaAdresowa.logowanieUzytkownika();
        while(ksiazkaAdresowa.czyUzytkownikJestZalogowany())
        {
        wybor2 = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();
        if (wybor2 == '1')
        {
            ksiazkaAdresowa.dodajAdresata();
        }
        else if (wybor2 == '2')
        {
            ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
        }
        else if (wybor2 == '3')
        {
            ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
        }

        else if (wybor2 == '4')
        {
            ksiazkaAdresowa.wyswietlWszystkichAdresatow();
        }
        else if (wybor2 == '5')
        {
            ksiazkaAdresowa.usunAdresata();
        }
        else if (wybor2 == '6')
        {
            ksiazkaAdresowa.edytujAdresata();
        }
        else if (wybor2 == '7')
        {
            ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
        }
        else if (wybor2 == '8')
        {
             ksiazkaAdresowa.wylogowanie();
        }
    }}
    else if (wybor = '9')
    {
        exit(0);
    }
    }

    return 0;
}

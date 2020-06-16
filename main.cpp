#include <iostream>
#include <vector>

#include "KsiazkaAdresowa.h"


using namespace std;

int main()
{
    int idUzytkownika;
    int idZalogowanegoUzytkownika,  idOstatniegoAdresata;
    char wybor, wybor2;
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt");
    wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();
    if(wybor == '1')
    {
        ksiazkaAdresowa.rejstracjaUzytkownika();
    }
    else if(wybor == '2')
    {
        idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
        while(idZalogowanegoUzytkownika != 0)
        {
        wybor2 = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();
        if (wybor2 == '1')
        {
            ksiazkaAdresowa.dodajAdresata(idZalogowanegoUzytkownika);
        }
        else if (wybor2 == '4')
        {
            ksiazkaAdresowa.wyswietlWszystkichAdresatow();
        }
        else if (wybor2 == '7')
        {
            ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
        }
        else if (wybor2 == '8')
        {
             ksiazkaAdresowa.wylogowanie();
             idZalogowanegoUzytkownika = 0;
        }
    }
}

    return 0;
}

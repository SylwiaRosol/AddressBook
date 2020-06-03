#include "KsiazkaAdresowa.h"

 void KsiazkaAdresowa::rejstracjaUzytkownika()
 {
     uzytkownikMenadzer.rejestracjaUzytkownika();
 }


void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenadzer.logowanieUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika)
{
    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wylogowanie()
{
    uzytkownikMenadzer.wylogowanie();
}

void KsiazkaAdresowa::dodajAdresata(int idZalogowanegoUzytkownika)
{
   adresatMenadzer.dodajAdresata(idZalogowanegoUzytkownika);
}
 void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
 {
     adresatMenadzer.wyswietlWszystkichAdresatow();
 }

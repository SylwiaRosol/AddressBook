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
    uzytkownikMenadzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenadzer.logowanieUzytkownika());
    adresatMenadzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanie()
{
    uzytkownikMenadzer.wylogowanie();
}

void KsiazkaAdresowa::dodajAdresata(int idZalogowanegoUzytkownika)
{
   adresatMenadzer.dodajAdresata(uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika() );
}

 void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
 {
     adresatMenadzer.wyswietlWszystkichAdresatow();
 }

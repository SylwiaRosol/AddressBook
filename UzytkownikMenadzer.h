#ifndef UZYTKOWNIKMENADZER_H
#define UZYTKOWNIKMENADZER_H


#include <iostream>
#include <sstream>
#include <vector>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenadzer
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    string wczytajLinie();

public:
    UzytkownikMenadzer(string nazwaPlikuZUzytkownikami) :
        plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
            idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
        };

    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanie();
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int noweidZalogowanegoUzytkownika);
    bool czyUzytkownikJestZalogowany();
};


#endif

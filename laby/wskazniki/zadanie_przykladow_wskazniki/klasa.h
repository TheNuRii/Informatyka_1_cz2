#pragma once
#include "uczen.h"
#include "iostream"

using namespace std;

class Klasa{
public:
    Klasa(int maxUczniow, string nazwaKlasy);
    Klasa(const Klasa &klasa_kopiujaca);
    ~Klasa();

    int getiloscUczniowWKlasie();
    void dodajUczniaDoKlasy(Uczen *nowy_uczen);
    Uczen* operator[](int indeks_ucznia);

    friend ostream& operator<<(ostream &out, const Klasa &wyswietlana_klasa);

private:
    Uczen **lista_klasy_;
    int maxUczniow_;
    string nazwaKlasy_;
    int ilosc_uczniow_w_klasie_;
};
#pragma once
#include "iostream"
#include "produkt.h"
using namespace std;

class Koszyk{
private:
    Produkt koszyk_[10];
    int ile_produktow_w_koszyku_;

public:
    Koszyk();
    void dodajProduktDoKoszyka( Produkt& produkt);
    void wyswietlCoZnajdujeSieWKoszyku();
    double calaWagaKoszyka();

    ~Koszyk();
};
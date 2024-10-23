#pragma once

#include "produkt.h"


class Koszyk{
private:
    int const WIELKOSC_KOSZYKA = 10;
    Produkt koszyk_[10];
    int index = 0;

public:
    Koszyk(){}

    void dodaj_do_koszyka(const Produkt& p);
    void wyswietl_produkty();
    double waga_koszyka() const;

    ~Koszyk(){}
};
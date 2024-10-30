#pragma once

#include "produkt.h"


class Koszyk
{
public:
    Koszyk();
    ~Koszyk();
    void wyswietl_koszyk();
    double waga();
    void dodaj(Produkt &p);

    //Koszyk(const Koszyk&);

    //Koszyk& operator=(const Koszyk &b);
    //Koszyk& operator+=(const Produkt &p);
    //Koszyk& operator-=(const Produkt &p);
    //Produkt& operator[](int i);

    //friend ostream& operator<<(ostream &cout, const Koszyk &kp);
private:
    Produkt tablica_[10];
    int indeks_;

    
};
#pragma once
#include "produkt.h"
#include "string"

using namespace std;

class Koszyk{
public:
    Koszyk();
    ~Koszyk();

    void wyświetlZawartoscKoszyka();
    void dodajDoKoszyka(Produkt &nowy_produkt);
    double wagaCalegoKoszyak();

private:
    Produkt koszyk_zakupow[10];

};
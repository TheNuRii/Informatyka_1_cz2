#pragma once
#include "string"

using namespace std;

class Produkt{
public:
    Produkt(string nazwa, double cenna, double waga, int podatek_VAT);
    Produkt();
    ~Produkt();
    void wyswietlInformacjeOProdukcie();
    double getWagaProduktu();

private:
    string nazwa_produktu_;
    double cenna_netto_;
    double waga_produktu_;
    int podatek_VAT_;
};
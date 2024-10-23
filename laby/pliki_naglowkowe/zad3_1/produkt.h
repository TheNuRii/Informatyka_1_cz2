#pragma once
#include "iostream"

using namespace std;

class Produkt {
private:
    string nazwa_;
    double cenna_netto_;
    double waga_;
    int podatek_vat_;

public:
    Produkt(string nazawa, double cenna_netto, double waga, int vat);
    Produkt();
    void wyswietlInfoOProdukcie();
    double getInfoOWadze();
    double wyliczWartoscBrutto();
    ~Produkt();
};
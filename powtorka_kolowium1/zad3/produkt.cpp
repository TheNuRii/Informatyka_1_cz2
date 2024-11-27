#include "iostream"
#include "produkt.h"

using namespace std;

Produkt::Produkt(string nazwa, double cenna, double waga, int podatek_VAT){
    nazwa_produktu_ = nazwa;
    cenna_netto_ = cenna;
}
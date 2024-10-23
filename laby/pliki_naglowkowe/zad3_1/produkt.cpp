#include "produkt.h"
#include "iostream"

using namespace std;

Produkt::Produkt(string nazwa, double cenna_netto, double waga, int vat){
    nazwa_ = nazwa;
    cenna_netto_ = cenna_netto;
    waga_ = waga;
    podatek_vat_ = vat;
}

Produkt::Produkt() : nazwa_(""), cenna_netto_(0), waga_(0), podatek_vat_(0){}

void Produkt::wyswietlInfoOProdukcie() {
    cout << nazwa_ << ", cena brutto=";
    cout << wyliczWartoscBrutto() << "PLN, waga=";
    cout << waga_ << 'g' << '\n';
}

double Produkt::getInfoOWadze() {
    return waga_;
}

double Produkt::wyliczWartoscBrutto() {
    double cenna_netto = cenna_netto_;
    double podatek_vat = podatek_vat_;
    return cenna_netto * (1 + podatek_vat/100);
}

Produkt::~Produkt() {}

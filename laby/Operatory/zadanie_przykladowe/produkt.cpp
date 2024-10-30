#include "produkt.h"

Produkt::Produkt(string nazwa, double cena, double waga, int vat) : nazwa_(nazwa), cena_(cena), waga_(waga), vat_(vat) {}

Produkt::Produkt() : nazwa_(""), cena_(0), waga_(0), vat_(0) {}

Produkt::~Produkt() {}

void Produkt::wyswietl() {
    cout << nazwa_ << ", cena brutto=" << cena_ * ( 1 + 0.01 * vat_) << "PLN, waga=" << waga_ << "g" << endl;
}

double Produkt::zwroc_wage()
{
    return waga_;
}
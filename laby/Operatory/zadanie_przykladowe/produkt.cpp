#include "produkt.h"

Produkt::Produkt(string nazwa, double cena, double waga, int vat) : nazwa_(nazwa), cena_(cena), waga_(waga), vat_(vat) {}

Produkt::Produkt() : nazwa_(""), cena_(0), waga_(0), vat_(0) {}

Produkt::Produkt(const Produkt &b) : nazwa_(b.nazwa_), cena_(b.cena_), waga_(b.waga_), vat_(b.vat_) {}

Produkt::~Produkt() {}

void Produkt::wyswietl() {
    cout << nazwa_ << ", cena brutto=" << cena_ * ( 1 + 0.01 * vat_) << "PLN, waga=" << waga_ << "g" << endl;
}

double Produkt::zwroc_wage()
{
    return waga_;
}

Produkt& Produkt::operator=(const Produkt &b)
{
        nazwa_ = b.nazwa_;
        cena_ = b.cena_;
        waga_ = b.waga_;
        vat_ = b.vat_;
    return *this;
}

bool operator==(const Produkt &p1, const Produkt &p2)
{
    if(p1.nazwa_ == p2.nazwa_ && p1.cena_ == p2.cena_ && p1.waga_ == p2.waga_ && p1.vat_ == p2.vat_)
        return true;
    else
        return false;
}

bool operator!=(const Produkt &p1, const Produkt &p2)
{
    if(p1.nazwa_ == p2.nazwa_ && p1.cena_ == p2.cena_ && p1.waga_ == p2.waga_ && p1.vat_ == p2.vat_)
        return false;
    else
        return true;
}

ostream& operator<<(ostream & out, const Produkt &p)
{
    out << '[' <<p.nazwa_ << ' ' << p.cena_ << ' ' << p.waga_ << ' ' << p.vat_ << ']';
    return out;
}

#pragma once
#include <string>

using namespace std;

class Produkt {
private:
    string nazwa_;
    double cenna_netto_;
    double waga_;
    int vat_;

public:
    Produckt(string nazawa, double cenna_netto, double waga, int vat);

    void wyswietl_info_o_produkcie() const;
    Produkt(){}
    ~Produkt(){}
};
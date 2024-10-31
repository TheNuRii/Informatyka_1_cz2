#pragma once
#include <string>
#include <iostream>
using namespace std;

class Produkt
{
public:
    Produkt(string nazwa, double cena, double waga, int vat);
    Produkt();
    Produkt(const Produkt&);
    ~Produkt();
    void wyswietl();
    double zwroc_wage();

    Produkt& operator=(const Produkt &b);

    friend bool operator==(const Produkt &p1, const Produkt &p2);
    friend bool operator!=(const Produkt &p1, const Produkt &p2);
    friend ostream& operator<<(ostream &cout, const Produkt &p);

private:
    string nazwa_;
    double cena_;
    double waga_;
    int vat_;

};
#pragma once
#include "iostream"

#define MAX_ROZMIAR 100

class Wektor {
private:
    double wektor_liczb_rzeczywistych_[MAX_ROZMIAR];
    int liczba_elementow_;
public:
    Wektor(int liczba_elementow);
    Wektor(const Wektor &inny_wektor);
    double podajWartoscZWektora(int indeks) const;
    void wpiszWartoscDoWektora(int indeks, double wartosc);
    int rozmiarWektora() const;
    void dodajWartoscDoWektora(const Wektor &inny_wektor);

    Wektor& operator+=(const Wektor &inny_wektor);
    Wektor& operator-=(const Wektor &inny_wektor);
    Wektor& operator=(const Wektor &inny_wektor);

    double& operator[](int indeks);

    friend Wektor operator+(const Wektor &pierwszy_wektor, const Wektor &drugi_wektor);
    friend std::ostream& operator<<(std::ostream &out, const Wektor &wektor);
    friend Wektor operator!(const Wektor &wektor);
    friend Wektor operator-(const Wektor &pierwszy_wektor, const Wektor &drugi_wektor);
};
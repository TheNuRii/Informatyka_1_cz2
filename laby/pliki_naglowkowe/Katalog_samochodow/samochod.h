#pragma once
#include "string"

class Samochod{
private:
    std::string numer_rejestracyjny_;
    int moc_silnika_;
    float waga_;
    char rodzaj_silnika_;

public:
    Samochod(std::string numer_rejestracyjny, int moc_silnika, float waga, char rodzaj_silnika);
    void wyswietlSamochod();
    void usunSamochod();
    ~Samochod();
};
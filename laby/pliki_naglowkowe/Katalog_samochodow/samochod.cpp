#include "samochod.h"
#include "iostream"

using namespace std;

Samochod::Samochod(string numer_rejestracyjny, int moc_silnika, float waga, char rodzaj_silnika){
    numer_rejestracyjny_ = numer_rejestracyjny;
    moc_silnika_ = moc_silnika;
    waga_ = waga;
    rodzaj_silnika_ = rodzaj_silnika;
}

void Samochod::wyswietlSamochod() {
    cout << numer_rejestracyjny_ << ' ' << moc_silnika_ << "||\n";
}

void Samochod::usunSamochod() {
    Samochod::~Samochod();
}
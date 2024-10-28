#include "samochod.h"
#include "iostream"

using namespace std;

Samochod::Samochod(string numer_rejestracyjny, int moc_silnika, float waga, char rodzaj_silnika){
    numer_rejestracyjny_ = numer_rejestracyjny;
    moc_silnika_ = moc_silnika;
    waga_ = waga;
    rodzaj_silnika_ = rodzaj_silnika;
}

string Samochod::uzyskajDostepDoNrRejestracyjnego() {
    return numer_rejestracyjny_;
}

int Samochod::uzyskajDostepdoMoc() {
    return moc_silnika_;
}

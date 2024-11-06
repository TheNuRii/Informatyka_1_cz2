#include "wektor.h"
#include "iostream"

using namespace std;

Wektor::Wektor(int liczba_elementow) {
    liczba_elementow_ = liczba_elementow;
    if (liczba_elementow < 1 || liczba_elementow > MAX_ROZMIAR){
        liczba_elementow_ = 1;
    }
    for(int i = 0; i < liczba_elementow_; i++){
        wektor_liczb_rzeczywistych_[i] = 0.0;
    }
}

Wektor::Wektor(const Wektor &inny_wektor) {
    liczba_elementow_ = inny_wektor.liczba_elementow_;
    cout << "Konstruktor kopiujacy\n";
    for (int i = 0; i < liczba_elementow_; i++)
        wektor_liczb_rzeczywistych_[i] = inny_wektor.wektor_liczb_rzeczywistych_[i];

}

double Wektor::podajWartoscZWektora(int indeks) const{
    if(indeks < 0 || indeks >= liczba_elementow_){
        return wektor_liczb_rzeczywistych_[0];
    }
    return wektor_liczb_rzeczywistych_[indeks];
}

void Wektor::wpiszWartoscDoWektora(int indeks, double wartosc) {
    if(indeks >= 0 && indeks < liczba_elementow_){
        wektor_liczb_rzeczywistych_[indeks] = wartosc;
    }
}

int Wektor::rozmiarWektora() const{
    return liczba_elementow_;
}

void Wektor::dodajWartoscDoWektora(const Wektor &inny_wektor) {
    if (liczba_elementow_ < inny_wektor.liczba_elementow_){
        for(int i=0; i < liczba_elementow_; i++){
            wektor_liczb_rzeczywistych_[i] += inny_wektor.wektor_liczb_rzeczywistych_[i];
        }
    } else {
        for (int i = 0; i < inny_wektor.liczba_elementow_; i++) {
            wektor_liczb_rzeczywistych_[i] += inny_wektor.wektor_liczb_rzeczywistych_[i];
        }
    }
}

Wektor operator+(const Wektor &pierwszy_wektor, const Wektor &drugi_wektor){

    Wektor wyniki_operacji_dodawania(pierwszy_wektor.liczba_elementow_);

    for(int i = 0; i < pierwszy_wektor.liczba_elementow_; i++){
        wyniki_operacji_dodawania.wektor_liczb_rzeczywistych_[i] = pierwszy_wektor.wektor_liczb_rzeczywistych_[i] + drugi_wektor.wektor_liczb_rzeczywistych_[i];
    }

    return wyniki_operacji_dodawania;
}

std::ostream& operator<<(std::ostream &out, const Wektor &wektor) {
    out << '[';
    for(int i =0; i<wektor.liczba_elementow_; ++i){
        out << wektor.wektor_liczb_rzeczywistych_[i];
        if(i < wektor.liczba_elementow_ - 1){
            out << ' ';
        }
    }
    out << ']';
    return out;
}

Wektor operator!(const Wektor &wektor){
    Wektor wynik_operacji_zmiany_znaku(wektor.liczba_elementow_);

    for(int i = 0; i<wektor.liczba_elementow_; i++){
        wynik_operacji_zmiany_znaku.wektor_liczb_rzeczywistych_[i] = -wektor.wektor_liczb_rzeczywistych_[i];
    }

    return wynik_operacji_zmiany_znaku;
}

Wektor operator-(const Wektor &pierwszy_wektor, const Wektor &drugi_wektor){
    Wektor wynik_operacji_odejmowania(pierwszy_wektor.liczba_elementow_);

    for(int i= 0; i < pierwszy_wektor.liczba_elementow_; i++){
        wynik_operacji_odejmowania.wektor_liczb_rzeczywistych_[i] = pierwszy_wektor.wektor_liczb_rzeczywistych_[i] - drugi_wektor.wektor_liczb_rzeczywistych_[i];
    }

    return wynik_operacji_odejmowania;
}

Wektor& Wektor::operator-=(const Wektor &inny_wektor) {
    if (liczba_elementow_ < inny_wektor.liczba_elementow_){
        for(int i=0; i < liczba_elementow_; i++){
            wektor_liczb_rzeczywistych_[i] -= inny_wektor.wektor_liczb_rzeczywistych_[i];
        }
    } else {
        for(int i=0; i < inny_wektor.liczba_elementow_; i++){
            wektor_liczb_rzeczywistych_[i] -= inny_wektor.wektor_liczb_rzeczywistych_[i];
        }
    }
    return *this;
}


Wektor& Wektor::operator+=(const Wektor &inny_wektor) {
    dodajWartoscDoWektora(inny_wektor);
    return *this;
}

Wektor& Wektor::operator=(const Wektor &inny_wektor) {
    if(this != &inny_wektor) {
        liczba_elementow_ = inny_wektor.liczba_elementow_;
        for(int i = 0; i < liczba_elementow_; i++){
            wektor_liczb_rzeczywistych_[i] = inny_wektor.wektor_liczb_rzeczywistych_[i];
        }
    }
    return *this;
}

double& Wektor::operator[](int indeks) {
    static double poza_zakresem = 0.0;
    if (indeks < 0 || indeks >= liczba_elementow_) {
        return poza_zakresem;
    }
    return wektor_liczb_rzeczywistych_[indeks];
}
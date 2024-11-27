#include "liczba.h"
#include "sstream"


Liczba::~Liczba() {}

Wymierna::Wymierna(float licznik, float mianownik) {
    licznik_ = licznik;
    mianownik_ = mianownik;
    
}

string Wymierna::typ() {
        return "Rational";
    }

Zespolona::Zespolona(float re, float im) {
    re_ = re;
    im_ = im;
}

string Zespolona::typ() {
        return "Complex";
    }

string Zespolona::wartosc() { 
    std::ostringstream wartosc_wyswietlana;
    wartosc_wyswietlana << (((re_) < 0) ? "-" : "") << abs(re_) << ((im_ > 0) ? "-" : "") << abs(im_) << "i";
    return wartosc_wyswietlana.str();
}

string Wymierna::wartosc() {
    std::ostringstream wartosc_wyswietlana;
    wartosc_wyswietlana << (((licznik_ * mianownik_) < 0) ? "-" : "") << abs(licznik_) << "/" << abs(mianownik_);
    return wartosc_wyswietlana.str();
}


#include "uczen.h"
#include "iostream"

using namespace std;

Uczen::Uczen(string imie, string nazisko) {
    imie_ucznia_ = imie;
    nazwisko_ucznia_ = nazisko;
}

void Uczen::setNazwiskoUcznia(string nowe_nazwisko) {
    nazwisko_ucznia_ = nowe_nazwisko;
}

void Uczen::setImieUcznia(string nowe_imie) {
    imie_ucznia_ = nowe_imie;
}


std::ostream& operator<<(std::ostream &out, const Uczen &uczen) {
    out << '|' << uczen.imie_ucznia_ << ' ' << uczen.nazwisko_ucznia_ << '|';
    return out;
}
#include <pracownik.h>

Pracownik::Pracownik() {
    imie_pracownika_ = "";
    nazwisko_pracownia_ = "";
    stanowisko_pracownia_ = "";
    pensja_pracownika_ = 0;}

Pracownik::Pracownik(string imie, string nazwisko, string stanowisko, int pensja) {
    imie_pracownika_ = imie;
    nazwisko_pracownia_ = nazwisko;
    stanowisko_pracownia_ = stanowisko;
    pensja_pracownika_ = pensja;
}

double Pracownik::getPensja() {
    return pensja_pracownika_;
}

ostream& operator<<(ostream &out, const Pracownik &pracownik) {
    out << '|' << pracownik.imie_pracownika_ << ' ' << pracownik.nazwisko_pracownia_ << '|' << endl;
    out << "Stanowisko: " << pracownik.stanowisko_pracownia_ << endl;
    out << "Pensja: " << pracownik.pensja_pracownika_ << endl;
    return out;
}
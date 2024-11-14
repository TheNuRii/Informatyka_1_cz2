#include "pojazdy.h"
#include "iostream"

Pojazd::Pojazd() {
    nazwa_pojazdu_ = "Pojazd";
    numer_poajazdu_ = 0;
    waga_pojazdu_ = 0;
}

Pojazd::~Pojazd() {}

std::ostream& operator<<(std::ostream &out, const Pojazd &pojazd) {
    out << pojazd.nazwa_pojazdu_ << ' ' << pojazd.numer_poajazdu_ << ' ' << pojazd.waga_pojazdu_;
    return out;
}

std::istream& operator>>(std::istream &in, Pojazd &pojazd) {
    cout << "Nazwa pojazdu: ";
    in >> pojazd.nazwa_pojazdu_;
    cout << "Numer: ";
    in >> pojazd.numer_poajazdu_;
    cout << "Waga: "; 
    in >> pojazd.waga_pojazdu_;
    return in;
}

bool Pojazd::rodzaj_pojazdu(string nazwa) const {
    if(nazwa == nazwa_pojazdu_){
        return true;
    } else {
        return false;
    }
    
}

PojazdSilnikowy::PojazdSilnikowy() : Pojazd(){
    nazwa_pojazdu_ = "PojazdSilnikowy";
    moc_silnika_ = 0;
    rodzaj_paliwa_ = "brak";
}

std::ostream& operator<<(std::ostream &out, const PojazdSilnikowy &pojazd_silnikowy) {
    out << static_cast<const Pojazd&>(pojazd_silnikowy);
    out << ' ' << pojazd_silnikowy.rodzaj_paliwa_ << ' ' << pojazd_silnikowy.moc_silnika_;
    return out;
}

std::istream& operator>>(std::istream &in, PojazdSilnikowy &pojazd_silnikowy){
    in >> static_cast<Pojazd&>(pojazd_silnikowy);
    cout << "Paliwo [b/d]: ";
    in >> pojazd_silnikowy.rodzaj_paliwa_;
    cout << "Moc [KM]: ";
    in >> pojazd_silnikowy.moc_silnika_;
    return in;
}

PojazdOsobowy::PojazdOsobowy() : PojazdSilnikowy() {
    nazwa_pojazdu_ = "PojazdOsobowy";
    liczba_miejsc_w_pojezdzie_ = 0;
}

std::ostream& operator<<(std::ostream &out, const PojazdOsobowy &pojazd_osobowy) {
    out << static_cast<const PojazdSilnikowy&>(pojazd_osobowy);
    out << " Liczba miejsc: " << pojazd_osobowy.liczba_miejsc_w_pojezdzie_;
    return out;
}

std::istream& operator>>(std::istream &in, PojazdOsobowy &pojazd_osobowy) {
    in >> static_cast<PojazdSilnikowy&>(pojazd_osobowy);
    cout << "Liczba miejsc: ";
    in >> pojazd_osobowy.liczba_miejsc_w_pojezdzie_;
    return in;
}

PojazdCiezarowy::PojazdCiezarowy() : PojazdSilnikowy() {
    nazwa_pojazdu_ = "PojazdCiezarowy";
    nosnosc_pojazdu_ = 0;
}

std::ostream& operator<<(std::ostream &out, const PojazdCiezarowy &pojazd_ciezarowy) {
    out << static_cast<const PojazdSilnikowy&>(pojazd_ciezarowy);
    out << " Nosnosc: " << pojazd_ciezarowy.nosnosc_pojazdu_;
    return out;
}

std::istream& operator>>(std::istream &in, PojazdCiezarowy &pojazd_ciezarowy) {
    in >> static_cast<PojazdSilnikowy&>(pojazd_ciezarowy);
    cout << "Nosnosc: ";
    in >> pojazd_ciezarowy.nosnosc_pojazdu_;
    return in;
}

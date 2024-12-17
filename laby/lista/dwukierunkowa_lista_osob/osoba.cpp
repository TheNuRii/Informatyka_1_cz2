#include "iostream"
#include "osoba.h"

using namespace std;

Osoba::Osoba(string imie, int wiek){
    imie_osoby_ = imie;
    wiek_osoby_ = wiek;
}

string Osoba::getImieOsoby() const{
    return imie_osoby_;
}

int Osoba::getWiekOsoby() const{
    return wiek_osoby_;
}

ostream& operator<<(ostream& out, const Osoba&osoba){
    out << osoba.imie_osoby_ << "( " << osoba.wiek_osoby_ << " l.)";
    return out; 
}

#include "iostream"
#include "osoba.h"

using namespace std;

Osoba::Osoba(){
    imie_osoby_ = " ";
    wiek_osoby_ = 0;
}

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

std::ostream operator<<(std::ostream out, const Osoba&osoba){
    out << osoba.imie_osoby_ << "( " << osoba.wiek_osoby_ << " l.)";
    return out; 
}

#include "koszyk.h"

Koszyk::Koszyk(): indeks_(0){}

Koszyk::~Koszyk(){}

void Koszyk::wyswietl_koszyk(){
    for(int i=0; i<indeks_; i++){
        tablica_[i].wyswietl();
    }

}

double Koszyk::waga()
{
    double suma_wag = 0;
    for(int x = 0; x < indeks_; x++)
    {
        suma_wag += tablica_[x].zwroc_wage();
    }
    return suma_wag;
}

void Koszyk::dodaj(Produkt &p)
{
    if(indeks_ >= 0 && indeks_ < 10)
    {
        tablica_[indeks_] = p;
        indeks_++;
    }
}

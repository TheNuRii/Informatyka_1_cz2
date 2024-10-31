#include "koszyk.h"
#include "iostream"

Koszyk::Koszyk(): indeks_(0){}

Koszyk::~Koszyk(){}

Koszyk::Koszyk(const Koszyk& k)
{
    indeks_ = k.indeks_;
    for(int i = 0; i < k.indeks_; i++)
    {
        tablica_[i] = k.tablica_[i];
    }
}

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

Koszyk& Koszyk::operator-=(const Produkt &p) {
    for(int i = 0; i < indeks_; ++i){
        if(tablica_[i] == p){
            if(i == indeks_ - 1){
            break;
            }
            tablica_[i] = tablica_[indeks_ - 1];
            indeks_--;
        }
    }

    return *this;
}

Koszyk& Koszyk::operator+=(const Produkt &p) {
    tablica_[indeks_] = p;
    indeks_++;
    return *this;
}


Koszyk& Koszyk::operator=(const Koszyk &b){
    indeks_ = b.indeks_;
    for(int i=0; i<indeks_; i++){
        tablica_[i] = b.tablica_[i];
    }
    return *this;
}

Produkt& Koszyk::operator[](int i){
    return tablica_[i];
}

ostream& operator<<(ostream & out, const Koszyk &kp){
    for(int i=0; i<kp.indeks_; i++){
        out << kp.tablica_[i] << ' ';
    }
    out << endl;
    return out;
}

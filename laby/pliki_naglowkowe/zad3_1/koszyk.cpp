#include "koszyk.h"
#include "produkt.h"

using namespace std;

Koszyk::Koszyk() {
    ile_produktow_w_koszyku_ = 0;
}

void Koszyk::dodajProduktDoKoszyka(Produkt &produkt){
    koszyk_[ile_produktow_w_koszyku_] = produkt;
    ile_produktow_w_koszyku_ ++;
}

void Koszyk::wyswietlCoZnajdujeSieWKoszyku() {
    for (int i = 0; i < ile_produktow_w_koszyku_; ++i){
        koszyk_[i].wyswietlInfoOProdukcie();
    }
}

double Koszyk::calaWagaKoszyka() {
    double waga_calego_koszyka = 0;
    for (int i = 0; i < ile_produktow_w_koszyku_; ++i){
        waga_calego_koszyka += koszyk_[i].getInfoOWadze();
    }

    return waga_calego_koszyka;
}
Koszyk::~Koszyk() {}


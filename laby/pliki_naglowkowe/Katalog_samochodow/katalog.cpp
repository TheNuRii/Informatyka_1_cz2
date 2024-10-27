#include "iostream"
#include "katalog.h"
#include "samochod.h"

using namespace std;

Katalog::Katalog(){
    ile_samochodow_w_katalogu_ = 0;
}

void Katalog::wyswietlSamochodyZnajdujaceSieWKatalogu() {
    for (int i = 0; i < ile_samochodow_w_katalogu_; ++i){
        katalog_samochodow_[i].wyswietlSamochod();
    }
}

void Katalog::dodajSamochodDoKatalogu(Samochod &samochod) {
    katalog_samochodow_[ile_samochodow_w_katalogu_] = samochod;
    ile_samochodow_w_katalogu_++;
}

void Katalog::usunSamochodZKatologu(int index_do_usuniecia) {
    if (index_do_usuniecia != 9){
        katalog_samochodow_[index_do_usuniecia] = katalog_samochodow_[9];
    } else{
        katalog_samochodow_[9].usunSamochod();
    }
}
#include "iostream"
#include "katalog.h"
#include "samochod.h"

using namespace std;

Katalog::Katalog() : ile_samochodow_w_katalogu_(0) {
    for (int i = 0; i < 10; ++i){
        katalog_samochodow_[i] = nullptr;
    }
}

void Katalog::wyswietlSamochodyZnajdujaceSieWKatalogu() {
    for (int i = 0; i < ile_samochodow_w_katalogu_; ++i){
        string konkrety_numer_rejestracyjny = katalog_samochodow_[i]->uzyskajDostepDoNrRejestracyjnego();
        int konkretna_moc_silnika = katalog_samochodow_[i]->uzyskajDostepdoMoc();
        cout << konkrety_numer_rejestracyjny << ' ' << konkretna_moc_silnika << "||";
    }
}

void Katalog::dodajSamochodDoKatalogu(Samochod *samochod) {
    if (ile_samochodow_w_katalogu_ < 10){
        katalog_samochodow_[ile_samochodow_w_katalogu_] = samochod;
        ile_samochodow_w_katalogu_++;
    }
}

void Katalog::usunSamochodZKatologu(int index_do_usuniecia) {
    if (index_do_usuniecia >= 0 && index_do_usuniecia < ile_samochodow_w_katalogu_) {
        katalog_samochodow_[index_do_usuniecia] = katalog_samochodow_[ile_samochodow_w_katalogu_ - 1];
        katalog_samochodow_[ile_samochodow_w_katalogu_ - 1] = nullptr;
        ile_samochodow_w_katalogu_--;
    }
}
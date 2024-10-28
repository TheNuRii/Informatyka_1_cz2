#pragma once
#include "string"
#include "samochod.h"

class Katalog{
private:
    Samochod* katalog_samochodow_[10];
    int ile_samochodow_w_katalogu_;

public:
    Katalog();
    void wyswietlSamochodyZnajdujaceSieWKatalogu();
    void dodajSamochodDoKatalogu(Samochod* samochod);
    void usunSamochodZKatologu(int index_do_usuniecia);
};
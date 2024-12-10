#include "iostream"

using namespace std;

class Budynek {
public:

    Budynek(string nazwa, float dlugosc, float szerokosc, float wysokosc){
        nazwa_budynku_ = nazwa;
        dlugosc_geograficzna_ = dlugosc;
        szerokosc_geograficzna_ = szerokosc;
        wysokosc_budynku_ = wysokosc;
    }

    Budynek(){
        nazwa_budynku_ = "";
        dlugosc_geograficzna_ = 0;
        szerokosc_geograficzna_ = 0;
        wysokosc_budynku_ = 0;
    }

    void wyswietlInformacje(){
        cout << nazwa_budynku_ << ' ' << dlugosc_geograficzna_;
        cout  << ' ' << szerokosc_geograficzna_ << ' ' << wysokosc_budynku_ ;
    }

    float getDlugoscGeograficzna(){
        return dlugosc_geograficzna_;
    }

    float getSzerokoscGeograficzna(){
        return szerokosc_geograficzna_;
    }

private:
    string nazwa_budynku_;
    float dlugosc_geograficzna_;
    float szerokosc_geograficzna_;
    float wysokosc_budynku_;
};
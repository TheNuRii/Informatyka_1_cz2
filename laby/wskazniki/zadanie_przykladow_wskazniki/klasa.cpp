#include "klasa.h"
#include "uczen.h"
#include "iostream"

using namespace std;

Klasa::Klasa(int maxUczniow, std::string nazwaKlasy) {
    nazwaKlasy_ = nazwaKlasy;
    maxUczniow_ = maxUczniow;
    ilosc_uczniow_w_klasie_ = 0;
    lista_klasy_ = new Uczen * [maxUczniow_];
}

Klasa::Klasa(const Klasa &klasa_kopiujaca) {
    maxUczniow_ = klasa_kopiujaca.maxUczniow_;
    nazwaKlasy_ = klasa_kopiujaca.nazwaKlasy_;
    ilosc_uczniow_w_klasie_ = klasa_kopiujaca.ilosc_uczniow_w_klasie_;
    lista_klasy_ = new Uczen * [maxUczniow_];

    for (int i = 0; i < maxUczniow_; ++i){
        lista_klasy_[i] = new Uczen(*klasa_kopiujaca.lista_klasy_[i]);
    }
}

Klasa::~Klasa() {
    for (int i = 0; i < ilosc_uczniow_w_klasie_; i++){
        delete lista_klasy_[i];
    }

    delete[] lista_klasy_;
}

int Klasa::getiloscUczniowWKlasie() {
    return ilosc_uczniow_w_klasie_;
}

void Klasa::dodajUczniaDoKlasy(Uczen *nowy_uczen) {
    if(ilosc_uczniow_w_klasie_ < maxUczniow_){
        lista_klasy_[ilosc_uczniow_w_klasie_] = nowy_uczen;
        ilosc_uczniow_w_klasie_++;
    }
}

Uczen* Klasa::operator[](int indeks_ucznia) {
    if(indeks_ucznia >= ilosc_uczniow_w_klasie_ || indeks_ucznia < 0){
        return lista_klasy_[0];
    } else{
        return lista_klasy_[indeks_ucznia];
    }
}

std::ostream& operator<<(std::ostream &out, const Klasa &wyswietlana_klasa){
    out << "Klasa" << wyswietlana_klasa.nazwaKlasy_ << ": ";
    for(int i =0; i<wyswietlana_klasa.ilosc_uczniow_w_klasie_; i++){
        out << *wyswietlana_klasa.lista_klasy_[i];
    }
    out << '\n';
    return out;
}


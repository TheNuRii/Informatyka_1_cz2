#include "iostream"

using namespace std;

class Zwierze{
public:
    Zwierze(){
    imie_zwierzecia_ = "";
    waga_ = 0;
    rok_urodzenia_ = 0;
    id_zwierzecia_ = "";
    }
    Zwierze(string imie, float waga, int rok_urodzenia, string id){
    imie_zwierzecia_ = imie;
    waga_ = waga;
    rok_urodzenia_ = rok_urodzenia;
    id_zwierzecia_ = id;
    }

    void wyswietlInformacje(){
    cout << imie_zwierzecia_ << ' ' << waga_ << ' '; 
    cout << rok_urodzenia_ << ' ' << id_zwierzecia_;
    }

    int getRokUrodzenia(){
        return rok_urodzenia_;
    }

    float getWaga(){
        return waga_;
    }

private:
    string imie_zwierzecia_;
    float waga_;
    int rok_urodzenia_;
    string id_zwierzecia_;
};   
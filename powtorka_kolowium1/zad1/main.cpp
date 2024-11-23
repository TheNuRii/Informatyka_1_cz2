#include <iostream>

using namespace std;

class Osoba{
public:
    string imie_osoby_;
    int wiek_osoby_;

    Osoba(){
        imie_osoby_ = "Jan";
        wiek_osoby_ = 20;
    }
};

class Pies {
public:
    Pies(){
        imie_psa_ = "Azor";
        rasa_psa_ = "Terier";
    }

    void setImiePsa(string nowe_imie_psa){
        imie_psa_ = nowe_imie_psa;
    }

    void setRasaPsa(string nowa_rasa_psa){
        rasa_psa_ = nowa_rasa_psa;
    }

    string getImiePsa(){
        return imie_psa_;
    }

    string getRasaPsa(){
        return rasa_psa_;
    }

private:
    string imie_psa_;
    string rasa_psa_;
};

class Prostokat{
public:
    Prostokat(float nowa_dlugosc_boku_a, float nowa_dlugosc_boku_b){
        dlugosc_boku_a_ =  nowa_dlugosc_boku_a;
        dlugosc_boku_b_ = nowa_dlugosc_boku_b;
    }

    float wyliczPoleProstokat(){
        return dlugosc_boku_a_ * dlugosc_boku_b_;
    }
private:
    float dlugosc_boku_a_;
    float dlugosc_boku_b_;
};

int main(){
int numer_classy;
cin >> numer_classy;

switch(numer_classy){
    case 1:{
        Osoba nowa_osoba = Osoba();
        string nowe_imie_osoby;
        int nowy_wiek_osoby;

        cout << nowa_osoba.imie_osoby_ << ' ' << nowa_osoba.wiek_osoby_ << '\n';
        cout << "Podaj imie i wiek=";
        cin >> nowe_imie_osoby >> nowy_wiek_osoby;
        nowa_osoba.imie_osoby_ = nowe_imie_osoby;
        nowa_osoba.wiek_osoby_ = nowy_wiek_osoby;

        cout << nowa_osoba.imie_osoby_ << ' ' << nowa_osoba.wiek_osoby_;
        break;
    }
    case 2:{
        Pies nowy_pies = Pies();
        string nowe_imie_psa;
        string nowa_rasa_pas;

        cout << nowy_pies.getImiePsa() << nowy_pies.getRasaPsa() << '\n';
        cout << "Imie i rasa=";
        cin >> nowe_imie_psa;
        getline(cin, nowa_rasa_pas);

        nowy_pies.setImiePsa(nowe_imie_psa);
        nowy_pies.setRasaPsa(nowa_rasa_pas);

        cout << nowy_pies.getImiePsa() << nowy_pies.getRasaPsa();
        break;
    }
    case 3:{
        float nowy_bok_a, nowy_bok_b;
        cout << "Boki prostokata=";
        cin >> nowy_bok_a >> nowy_bok_b;
        Prostokat nowy_prostoka = Prostokat(nowy_bok_a, nowy_bok_b);
        cout << nowy_prostoka.wyliczPoleProstokat();
        break;
    }
    default:{
        cout << "Niepoprawny numer zadania";
    }
}

return 0;
}
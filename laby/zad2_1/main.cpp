#include<iostream>
using namespace std;

class Osoba{
public:
    string imie;
    int wiek;
    Osoba();
};

class Pies{
private:
    string imie, rasa;
public:
    Pies();
    void setImie(string i){
        imie = i;
    }
    void setRasa(string r){
        rasa = r;
    }
    string getImie(){
        return imie;
    }
    string getRasa(){
        return rasa;
    }
};

class Prostokat{
private:
    float a, b;

public:
    Prostokat();
    float obwod();
    void setAB(float x, float y);
};

Prostokat::Prostokat(): a(0.0), b(0.0) {}

float Prostokat::obwod(){
    return 2*a + 2*b;
}

void Prostokat::setAB(float x, float y){
    a = x;
    b = y;
}

Osoba::Osoba() : imie("Jan"), wiek(20) {}
Pies::Pies() : imie("Azor"), rasa("Terier") {}

int main() {
    int zadanie;
    int wiek;
    string imie, rasa;
    Osoba my_osoba;
    Pies moj_pies;
    Prostokat moj_prostokat;
    float x, y;
    cin >> zadanie;

    switch (zadanie) {
        case 1:

            cout << my_osoba.imie << ' ' << my_osoba.wiek << '\n';
            cout << "Podaj imie i wiek=";
            cin >> imie >> wiek;
            my_osoba.imie = imie;
            my_osoba.wiek = wiek;
            cout << imie << ' ' << wiek;
            break;
        case 2:

            cout << moj_pies.getImie() << ' ' << moj_pies.getRasa() << '\n';
            cout << "Imie i rasa=";
            cin >> imie;
            getline(cin, rasa);

            moj_pies.setImie(imie);
            moj_pies.setRasa(rasa);
            cout << moj_pies.getImie() << moj_pies.getRasa();
            break;
        case 3:
            cout << "Boki prostokata=";
            cin >> x >> y;
            moj_prostokat.setAB(x, y);
            cout << moj_prostokat.obwod();
            break;
        default:
            cout << "Niepoprawny numer zadania";
    }
    return 0;
}
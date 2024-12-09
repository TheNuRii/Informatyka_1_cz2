#include "iostream"
#include "vector"
#include "zwierze.cpp"
#include "budynek.cpp"

using namespace std;

template <typename T>
class Kontener{
public:
    Kontener(int liczba_obiektow){
        kontener_obiektow_.reserve(liczba_obiektow);
    }

    void dodajObiektDoKontenera(T nowy_obiekt){
        kontener_obiektow_.push_back(nowy_obiekt);
    }

    void usunObiektZKontenera(int index){
         if (index >= 0 && index < int(kontener_obiektow_.size())) {
            kontener_obiektow_.erase(kontener_obiektow_.begin() + index);
        }
    }

    T pobierzObiektZKontenera(int index){
        return kontener_obiektow_[index];
    }

private:
    vector<T> kontener_obiektow_;
    int liczba_obiektow_;
};

int main(){

    int liczba_zwierzat;
    cout << "Liczba zwierzat=";
    cin >> liczba_zwierzat;

    Kontener<Zwierze> kontener_zwierzat(liczba_zwierzat);  
    for (int i = 0; i < liczba_zwierzat; i++){
        string imie;
        float waga;
        int rok_urodzenia;
        string id;    
        
        cout << "Imie=";
        cin >> imie;

        cout << "Waga=";
        cin >> waga;

        cout << "Rok urodzenia=";
        cin >> rok_urodzenia;

        cout << "ID=";
        cin >> id;
        Zwierze zwierzatko = Zwierze(imie, waga, rok_urodzenia, id);
        kontener_zwierzat.dodajObiektDoKontenera(zwierzatko);
    }

    int liczba_budynkow;
    cout << "Liczba budynkow=";
    cin >> liczba_budynkow;

    Kontener<Budynek> kontener_budynkow(liczba_budynkow);
    for (int i = 0; i < liczba_budynkow; i++){
        string nazwa;
        float dlugosc;
        float szerokosc;
        float wysokosc;

        cout << "Nazwa=";
        cin >> nazwa;

        cout << "Dlugosc geograficzna=";
        cin >> dlugosc;

        cout << "Szerokosc geograficzna=";
        cin >> szerokosc;

        cout << "Wysokosc=";
        cin >> wysokosc;
        Budynek budynek = Budynek(nazwa, dlugosc, szerokosc, wysokosc);
        kontener_budynkow.dodajObiektDoKontenera(budynek);
    }

    int index_zwierzatka;
    cout << "Indeks zwierzecia do usuniecia=";
    cin >> index_zwierzatka;
    kontener_zwierzat.usunObiektZKontenera(index_zwierzatka);
    liczba_zwierzat--;

    cout << "Zwierzeta=";
    for (int i = 0; i < liczba_zwierzat; i++){
        Zwierze zwierzatko = kontener_zwierzat.pobierzObiektZKontenera(i);
        zwierzatko.wyswietlInformacje();
    }
    
    cout << "\nBudynki=";
    for (int i = 0; i < liczba_budynkow; i++){
        Budynek budynek = kontener_budynkow.pobierzObiektZKontenera(i);
        budynek.wyswietlInformacje();
    }
return 0;
}
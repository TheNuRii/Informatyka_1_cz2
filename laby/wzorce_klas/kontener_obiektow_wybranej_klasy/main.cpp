#include "iostream"
#include "vector"
#include "algorithm"
#include "stdexcept"
#include "zwierze.cpp"
#include "budynek.cpp"

using namespace std;

template <typename T>
class Kontener{
public:
    Kontener(int rozmiar){
        rozmiar_kontenera_ = rozmiar;
        liczba_obiektow_ = 0;
        kontener_obiektow_ = new T * [rozmiar_kontenera_];
        for (int i = 0; i < rozmiar_kontenera_; ++i) {
            kontener_obiektow_[i] = nullptr;
        }
    }

    ~Kontener() {
        for (int i = 0; i < liczba_obiektow_; ++i) {
            delete kontener_obiektow_[i];
        }
        delete[] kontener_obiektow_;
    }

    bool dodajObiektDoKontenera(const T& nowy_obiekt){
        if (liczba_obiektow_ >= rozmiar_kontenera_) {
            cerr << "Blad: Kontener jest pelny!\n";
            return false;
        }
        kontener_obiektow_[liczba_obiektow_] = new T(nowy_obiekt);
        liczba_obiektow_++;
        return true;
    }

    bool usunObiektZKontenera(int index){
         if (index < 0 || index >= liczba_obiektow_) {
            return false;
        }
        delete kontener_obiektow_[index];
        liczba_obiektow_--;
        if (index < liczba_obiektow_) {
            kontener_obiektow_[index] = kontener_obiektow_[liczba_obiektow_];
        }
        kontener_obiektow_[liczba_obiektow_] = nullptr;
        return true;
    }

    int getRozmiarKontenera() const {
        return liczba_obiektow_;
    }

    T& operator[](int index) {
        if (index < 0 || index >= liczba_obiektow_) {
            throw out_of_range("Blad: Niepoprawny indeks");
        }
        return *(kontener_obiektow_[index]);
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= liczba_obiektow_) {
            throw out_of_range("Blad: Niepoprawny indeks");
        }
        return *(kontener_obiektow_[index]);
    }

private:
    T** kontener_obiektow_;
    int liczba_obiektow_;
    int rozmiar_kontenera_;
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

        while(waga<=0) {
            cin >> waga;
        }

        cout << "Rok urodzenia=";
        cin >> rok_urodzenia;

        while (rok_urodzenia <= 0){
            cin >> rok_urodzenia;
        }

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

        while(dlugosc<=0) {
            cin >> dlugosc;
        }

        cout << "Szerokosc geograficzna=";
        cin >> szerokosc;

        while(szerokosc<=0) {
            cin >> szerokosc;
        }

        cout << "Wysokosc=";
        cin >> wysokosc;

        while(wysokosc<=0) {
            cin >> wysokosc;
        }

        Budynek budynek = Budynek(nazwa, dlugosc, szerokosc, wysokosc);
        kontener_budynkow.dodajObiektDoKontenera(budynek);
    }

    int index_zwierzatka;
    cout << "Indeks zwierzecia do usuniecia=";
    cin >> index_zwierzatka;
    kontener_zwierzat.usunObiektZKontenera(index_zwierzatka);

     vector<Zwierze> nowy_kontener_zwierzat;
    for (int i = 0; i < kontener_zwierzat.getRozmiarKontenera(); i++)
        nowy_kontener_zwierzat.push_back(kontener_zwierzat[i]);

    sort(nowy_kontener_zwierzat.begin(), nowy_kontener_zwierzat.end(), [](Zwierze& pierwszy_zwierze, Zwierze& drugi_zwierze){
        if (pierwszy_zwierze.getRokUrodzenia() == drugi_zwierze.getRokUrodzenia())
            return pierwszy_zwierze.getWaga() < drugi_zwierze.getWaga();
        return pierwszy_zwierze.getRokUrodzenia() > drugi_zwierze.getRokUrodzenia();
        });

    vector<Budynek> nowy_kontener_budynkow;
    for (int i = 0; i < kontener_budynkow.getRozmiarKontenera(); i++)
        nowy_kontener_budynkow.push_back(kontener_budynkow[i]);

    sort(nowy_kontener_budynkow.begin(), nowy_kontener_budynkow.end(), [](Budynek& pierwszy_budynek, Budynek& drugi_budynek){ 
        return (pierwszy_budynek.getDlugoscGeograficzna() + pierwszy_budynek.getSzerokoscGeograficzna())
        < (drugi_budynek.getDlugoscGeograficzna() + drugi_budynek.getSzerokoscGeograficzna());
        });

    cout << "Zwierzeta=";

    for (auto& zwierze : nowy_kontener_zwierzat) {
        cout << "|";
        zwierze.wyswietlInformacje();
        cout << "|";
    }
    cout << "\n";

    cout << "Budynki=";

    for (auto& budynek : nowy_kontener_budynkow) {
        cout << "|";
        budynek.wyswietlInformacje();
        cout << "|";
    }
    cout << "\n";
    
    return 0;
}
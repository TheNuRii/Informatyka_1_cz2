#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

template<typename T>
class Kontener {
private:
    T** tab;
    int pojemnosc;
    int liczbaElementow;
public:
    Kontener(int rozmiar) : pojemnosc(rozmiar), liczbaElementow(0) {
        tab = new T * [pojemnosc];
        for (int i = 0; i < pojemnosc; ++i) {
            tab[i] = nullptr;
        }
    }

    ~Kontener() {
        for (int i = 0; i < liczbaElementow; ++i) {
            delete tab[i];
        }
        delete[] tab;
    }

    bool dodajElement(const T& elem) {
        if (liczbaElementow >= pojemnosc) {
            cerr << "Blad: Kontener jest pelny!\n";
            return false;
        }
        tab[liczbaElementow] = new T(elem);
        liczbaElementow++;
        return true;
    }

    bool usunElement(int indeks) {
        if (indeks < 0 || indeks >= liczbaElementow) {
            return false;
        }
        delete tab[indeks];
        liczbaElementow--;
        if (indeks < liczbaElementow) {
            tab[indeks] = tab[liczbaElementow];
        }
        tab[liczbaElementow] = nullptr;
        return true;
    }

    int rozmiar() const {
        return liczbaElementow;
    }

    T& operator[](int i) {
        if (i < 0 || i >= liczbaElementow) {
            throw out_of_range("Blad: Niepoprawny indeks");
        }
        return *(tab[i]);
    }

    const T& operator[](int i) const {
        if (i < 0 || i >= liczbaElementow) {
            throw out_of_range("Blad: Niepoprawny indeks");
        }
        return *(tab[i]);
    }
};

class Zwierze {
private:
    string imie;
    float waga;
    int rok_urodzenia;
    string etykieta_ID;
public:
    Zwierze() : imie(""), waga(0), rok_urodzenia(0), etykieta_ID("") {}
    Zwierze(const string& im, float w, int rok, const string& id)
        : imie(im), waga(w), rok_urodzenia(rok), etykieta_ID(id) {}

    void wyswietl() const {
        cout << imie << " " << waga << " " << rok_urodzenia << " " << etykieta_ID;
    }

    int getRok() const { return rok_urodzenia; }
    float getWaga() const { return waga; }
};

class Budynek {
private:
    string nazwa;
    float dlugosc_geogr;
    float szerokosc_geogr;
    float wysokosc;
public:
    Budynek() : nazwa(""), dlugosc_geogr(0), szerokosc_geogr(0), wysokosc(0) {}
    Budynek(const string& n, float d, float s, float h)
        : nazwa(n), dlugosc_geogr(d), szerokosc_geogr(s), wysokosc(h) {}

    void wyswietl() const {
        cout << nazwa << " " << dlugosc_geogr << " " << szerokosc_geogr << " " << wysokosc;
    }

    float suma_koord() const {
        return dlugosc_geogr + szerokosc_geogr;
    }
};

int main() {

    cout << "Liczba zwierzat=";
    int NZ; cin >> NZ;
    Kontener<Zwierze> kontenerZ(NZ);

    for (int i = 0; i < NZ; i++) {
        cout << "Imie=";
        string im; cin >> im;

        cout << "Waga=";
        float w; cin >> w;
        while(w<=0) {
        cin >> w; 
        }
        cout << "Rok urodzenia=";
        int r; cin >> r;

while(r<=0) {
cin >> r; 
}

        cout << "ID=";
        string id; cin >> id;

        Zwierze zw(im, w, r, id);
        kontenerZ.dodajElement(zw);
    }

    cout << "Liczba budynkow=";
    int NB; cin >> NB;
    Kontener<Budynek> kontenerB(NB);

    for (int i = 0; i < NB; i++) {
        cout << "Nazwa=";
        string n; cin >> n;

        cout << "Dlugosc geograficzna=";
        float d; cin >> d;
       while(d<0) {
cin >> d; 
}
        cout << "Szerokosc geograficzna=";
        float s; cin >> s;

while(s<=0) {
cin >> s; 
}

        cout << "Wysokosc=";
        float h; cin >> h;

while(h<=0) {
cin >> h; 
}

        Budynek bud(n, d, s, h);
        kontenerB.dodajElement(bud);
    }

    cout << "Indeks zwierzecia do usuniecia=";
    int idx; cin >> idx;
    kontenerZ.usunElement(idx);

    vector<Zwierze> vZ;
    for (int i = 0; i < kontenerZ.rozmiar(); i++)
        vZ.push_back(kontenerZ[i]);

    sort(vZ.begin(), vZ.end(), [](const Zwierze& a, const Zwierze& b) {
        if (a.getRok() == b.getRok())
            return a.getWaga() < b.getWaga();
        return a.getRok() > b.getRok();
        });

    vector<Budynek> vB;
    for (int i = 0; i < kontenerB.rozmiar(); i++)
        vB.push_back(kontenerB[i]);

    sort(vB.begin(), vB.end(), [](const Budynek& b1, const Budynek& b2) {
        return b1.suma_koord() < b2.suma_koord();
        });

    cout << "Zwierzeta=";

    for (auto& z : vZ) {
        cout << "|";
        z.wyswietl();
        cout << "|";
    }
    cout << "\n";

    cout << "Budynki=";

    for (auto& b : vB) {
        cout << "|";
        b.wyswietl();
        cout << "|";
    }
    cout << "\n";

    return 0;
}
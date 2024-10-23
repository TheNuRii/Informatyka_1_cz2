#include<iostream>
#include "koszyk.h"
#include "produkt.h"

using namespace std;

int main() {
    int N;
    cout << "N=";
    cin >> N;


    if(N > 0 & N <= 10){
        string nowa_nazwa;
        double nowa_cena;
        double nowa_waga;
        double nowy_vat;

        Koszyk koszyk;
        for (int i = 0; i < N; ++i){
            cout << "Nazwa=";
            cin >> nowa_nazwa;
            cout << "Cena[PLN]=";
            cin >> nowa_cena;
            cout << "Waga[g]=";
            cin >> nowa_waga;
            cout << "VAT[%]=";
            cin >> nowy_vat;

            Produkt nowy_produkt(nowa_nazwa, nowa_cena, nowa_waga, nowy_vat);
            koszyk.dodajProduktDoKoszyka(nowy_produkt);
        }

        koszyk.wyswietlCoZnajdujeSieWKoszyku();
        cout << "Waga koszyka[g]=" << koszyk.calaWagaKoszyka();
    }
    else{
        cout << "Bledne dane wejsciowe";
    }

    return 0;
}
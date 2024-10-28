#include<iostream>
#include "katalog.h"
#include "samochod.h"

using namespace std;

int main() {

    int N;
    cout << "N=";
    cin >> N;

    if (N < 0 & N > 10){
        Katalog katalog;
        string nowy_numer_rejestracyjny;
        int nowa_moc_slinika;
        float nowa_waga;
        char nowy_rodzaj_silnika;
        int index_do_usuniecia;

        for (int i = 0; i < N; ++i){
            cin >> nowy_numer_rejestracyjny >> nowa_moc_slinika >> nowa_waga >> nowy_rodzaj_silnika;
            Samochod *samochod;
            samochod = new Samochod(nowy_numer_rejestracyjny, nowa_moc_slinika, nowa_waga, nowy_rodzaj_silnika);
            katalog.dodajSamochodDoKatalogu(samochod);
        }

        cout << "I=";
        cin >> index_do_usuniecia;

        while(index_do_usuniecia < 0 & index_do_usuniecia > 10){
            cout << "I=";
            cin >> index_do_usuniecia;
        }

        katalog.usunSamochodZKatologu(index_do_usuniecia);
        katalog.wyswietlSamochodyZnajdujaceSieWKatalogu();
    } else{
        cout << "Bledne dane wejsciowe";
    }
    return 0;
}
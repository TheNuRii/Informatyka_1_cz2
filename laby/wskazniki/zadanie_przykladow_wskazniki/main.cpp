#include "klasa.h"
#include "uczen.h"
#include "iostream"

using namespace std;

int main(){
    int n;
    string nazawa;
    cout << "Podaj liczbe uczniow w klasie=";
    cin >> n;
    cout << "Nazwa=";
    cin >> nazawa;
    Klasa klasa(n, nazawa);
    for (int i = 0; i < n; ++i){
        string imie_ucznia, nazawisko_ucznia;
        cout << "Uczen #" << i + 1 << '=';
        cin >> imie_ucznia >> nazawisko_ucznia;
        Uczen *uczen = new Uczen(imie_ucznia, nazawisko_ucznia);
        klasa.dodajUczniaDoKlasy(uczen);
    }

    cout << klasa;
    Klasa kopia_klasy = klasa;
    cout << kopia_klasy;
    cout << "Indeks ucznia=";
    cin >> n;
    cout << "Nowe imie=";
    string noweImie;
    cin >> noweImie;
    cout << "Nowe nazwisko=";
    string noweNazwisko;
    cin >> noweNazwisko;
    klasa[n]->setImieUcznia(noweImie);
    klasa[n]->setNazwiskoUcznia(noweNazwisko);
    cout << klasa;
    cout << kopia_klasy;

    return 0;
};
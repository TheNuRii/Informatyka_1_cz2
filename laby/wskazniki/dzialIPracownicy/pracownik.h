#pragma once

#include <iostream>
#include <string>
using namespace std;

class Pracownik {
    public:
        Pracownik();
        Pracownik(string imie, string nazwisko, string stanowisko, int pensja);
        double getPensja();

        friend ostream& operator<<(ostream &out, const Pracownik &pracownik);
        
    private:
        string imie_pracownika_;
        string nazwisko_pracownia_;
        string stanowisko_pracownia_;
        double pensja_pracownika_;
};
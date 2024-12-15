#pragma once
#include <string>

using namespace std;

class Osoba{
public:
    Osoba();
    Osoba(string imie, int wiek);

    string getImieOsoby()const;
    int getWiekOsoby()const;
    friend ostream operator<<(ostream out, const Osoba &osoba);

    friend class Lista;
private:
    string imie_osoby_;
    int wiek_osoby_;
};
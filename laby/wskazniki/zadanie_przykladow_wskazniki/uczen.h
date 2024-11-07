#pragma once
#include "string"

using namespace std;

class Uczen{
private:
    string imie_ucznia_;
    string nazwisko_ucznia_;

public:
    Uczen(string imie_ucznia, string nazisko_ucznia);

    void setImieUcznia(string nowe_imie);
    void setNazwiskoUcznia(string nowe_nazwisko);

    friend std::ostream& operator<<(std::ostream &out, const Uczen &uczen);

};
#pragma once
#include <string>

using namespace std;

class Pojazd {
public:
    Pojazd();
    virtual ~Pojazd();  
    bool rodzaj_pojazdu(string nazwa) const;  

    friend std::ostream& operator<<(std::ostream &out, const Pojazd &pojazd);
    friend std::istream& operator>>(std::istream &in, Pojazd &pojazd);

protected:
    std::string nazwa_pojazdu_;
    int numer_poajazdu_;
    double waga_pojazdu_;
};

class PojazdSilnikowy : public Pojazd {
public:
    PojazdSilnikowy();

    friend std::ostream& operator<<(std::ostream &out, const PojazdSilnikowy &pojazd_silnikowy);
    friend std::istream& operator>>(std::istream &in, PojazdSilnikowy &pojazd_silnikowy);

protected:
    std::string rodzaj_paliwa_;
    int moc_silnika_;
};

class PojazdOsobowy : public PojazdSilnikowy {
public:
    PojazdOsobowy();

    friend std::ostream& operator<<(std::ostream &out, const PojazdOsobowy &pojazd_osobowy);
    friend std::istream& operator>>(std::istream &in, PojazdOsobowy &pojazd_osobowy);

protected:
    int liczba_miejsc_w_pojezdzie_;
};

class PojazdCiezarowy : public PojazdSilnikowy {
public:
    PojazdCiezarowy();

    friend std::ostream& operator<<(std::ostream &out, const PojazdCiezarowy &pojazd_ciezarowy);
    friend std::istream& operator>>(std::istream &in, PojazdCiezarowy &pojazd_ciezarowy);

protected:
    double nosnosc_pojazdu_;
};

#pragma once
#include <string>

using namespace std;
class Liczba{
public:
    virtual ~Liczba() = 0;
    virtual string typ() = 0;
    virtual string wartosc() = 0;
};

class Wymierna : public Liczba{
public:
    Wymierna(float licznik, float mianownik);
    string typ() override;
    string wartosc() override;
private:
    float licznik_;
    float mianownik_;
};

class Zespolona : public Liczba{
public:
    Zespolona(float re, float im);
    string typ() override;
    string wartosc() override;
private:
    float re_;
    float im_;
};


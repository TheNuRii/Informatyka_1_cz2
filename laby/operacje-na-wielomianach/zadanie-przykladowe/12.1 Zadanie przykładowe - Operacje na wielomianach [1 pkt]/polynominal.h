#pragma once
#include <list>
#include "term.h"
using namespace std;

class Polynominal {
public:
    Polynominal();                              // pusty
    Polynominal( const Polynominal &p );        // kopiujący
    Polynominal( const Term<int> &t );          // pojedynczy skladnik
    Polynominal(const int coef);                // tylko wspolczynnik
    Polynominal(const int coef,const int pow);  // coef x^pow
    void operator =( const Polynominal &right );
    void operator +=( const Polynominal &right );
    void operator *=(const Term<int> &right);

    friend Polynominal operator +(const Polynominal &left, const Polynominal &right);
    friend Polynominal operator *(const Polynominal &left, const Polynominal &right);
    friend ostream & operator<<(ostream &out, const Polynominal &p);

    list< Term<int> > terms_;                 // 'list' to lista dwukierunkowa, z STL
};

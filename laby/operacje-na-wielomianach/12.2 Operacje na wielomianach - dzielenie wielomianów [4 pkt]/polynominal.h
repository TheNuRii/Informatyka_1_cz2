#pragma once
#include <list>
#include "term.h"
using namespace std;

class Polynominal {
public:
    Polynominal();  
    Polynominal( const Polynominal &p ); 
    Polynominal( const Term<double> &t ); 
    Polynominal(const double coef); 
    Polynominal(const double coef, const int pow);  
    void operator =( const Polynominal &right );
    void operator +=( const Polynominal &right );
    void operator *=(const Term<double> &right);

    int degree() const;

    list< Term<double> > terms_;
};

ostream & operator<<(ostream &out, const Polynominal &p);

Polynominal operator -( const Polynominal &p );
Polynominal operator +(const Polynominal &left, const Polynominal &right);
Polynominal operator *(const Polynominal &left, const Polynominal &right);
Polynominal operator /(const Polynominal &left, const Polynominal &right);
Polynominal operator %(const Polynominal &left, const Polynominal &right);
void division(const Polynominal &left, const Polynominal &right, Polynominal &result, Polynominal &rmndr);

#include <iostream>
#include <vector>
#include <cassert>
#include "polynominal.h"
using namespace std;

Polynominal::Polynominal(){}
Polynominal::Polynominal(const Polynominal &p){
    for (auto itr = p.terms_.begin(); itr != p.terms_.end(); ++itr)
        terms_.push_back(*itr);
}
Polynominal::Polynominal( const Term<double> &t ){
    terms_.push_front(t);
}
Polynominal::Polynominal(const double coef){
   terms_.push_front(Term<double>(coef));
}
Polynominal::Polynominal(const double coef, const int pow){
    terms_.push_front(Term<double>(coef, pow));
} 

void Polynominal::operator =(const Polynominal &right){  
    if( !terms_.empty() ) terms_.clear();
    for (auto itr = right.terms_.begin(); itr != right.terms_.end(); ++itr)
        if((*itr).coef_!=0) terms_.push_back(*itr);
}
void Polynominal::operator +=( const Polynominal &right ){
    auto itrL{ terms_.begin() };
    auto itrR{ right.terms_.begin() };
    for( ; itrL!=terms_.end() && itrR!=right.terms_.end(); ++itrL ){
        while( itrR!=right.terms_.end() && ((*itrL).pow_ < (*itrR).pow_) ){
            if((*itrR).coef_!=0) terms_.insert( itrL, *itrR);
            ++itrR;
        }
        if( itrR!=right.terms_.end() && ((*itrL).pow_ == (*itrR).pow_) ){
            if((*itrR).coef_!=0) (*itrL) += (*itrR);
            ++itrR;
        }
    }
    while ( itrR!=right.terms_.end() ){
        if((*itrR).coef_!=0) terms_.insert(itrL,*itrR);
        ++itrR;
    } 
}
void Polynominal::operator *=(const Term<double> &right){
    list< Term<double> > tmp_list;
    if(right.coef_==0){
        terms_.clear();
    }else{    
        for( auto itr{ terms_.begin() }; itr!=terms_.end(); itr++ )
            if((*itr).coef_!=0 )
                tmp_list.push_back( (*itr) * right);    // mnożenie kolejnych elementów przez right
        terms_.clear();                                 // usuniecie orginału    
        for( auto itr{tmp_list.begin()}; itr!=tmp_list.end();itr++)    
            terms_.push_back(*itr);                     // kopiowanie
        tmp_list.clear();                               // usuniecie tymczasowej listy
    }
}
ostream & operator<<(ostream &out, const Polynominal &p){
    for(auto itr{ p.terms_.begin() }; itr!=p.terms_.end();  ){
        //out<<" ";
        if( itr==p.terms_.begin()){
            if((*itr).coef_>0) out<<" "; else out<<" -";
        }    
        if( abs((*itr).coef_)!=1 || ((*itr).pow_)==0) out<<abs((*itr).coef_);
        if( (*itr).pow_!=0 ) out<<"x";
        if( (*itr).pow_>1 || (*itr).pow_<0 ) out<<"^"<<(*itr).pow_;
        itr++;
        if(itr!=p.terms_.end()) {
            if((*itr).coef_>0) out<<" +";
            else out<<" -";
        }    
    }
    return out;
}

Polynominal operator *(const Polynominal &left, const Term<double> &right){
    Polynominal result(left);  
    result *= right;
    return result;
}


// do zaimplementowania
int Polynominal::degree() const {
}
Polynominal operator +(const Polynominal &left, const Polynominal &right){
}
Polynominal operator *(const Polynominal &left, const Polynominal &right){
}
Polynominal operator -(const Polynominal &p){
}
Polynominal operator /(const Polynominal &left, const Polynominal &right){
}
Polynominal operator %(const Polynominal &left, const Polynominal &right){
}
void division(const Polynominal &left, const Polynominal &right, Polynominal &result, Polynominal &rmndr){
}



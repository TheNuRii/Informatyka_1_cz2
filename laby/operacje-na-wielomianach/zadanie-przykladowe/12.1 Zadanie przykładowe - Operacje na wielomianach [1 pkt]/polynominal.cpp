#include <iostream>
#include "polynominal.h"
using namespace std;

Polynominal::Polynominal(){}
Polynominal::Polynominal(const Polynominal &p){
    for (auto itr = p.terms_.begin(); itr != p.terms_.end(); ++itr)
        if( (*itr).coef_!=0 ) terms_.push_back(*itr);
}
Polynominal::Polynominal( const Term<int> &t ){
    if( t.coef_!=0) terms_.push_front(t);
}
Polynominal::Polynominal(const int coef){
   if(coef!=0) terms_.push_front(Term<int>(coef));
}
Polynominal::Polynominal(const int coef, const int pow){
    if( coef!=0) terms_.push_front(Term<int>(coef, pow));
}

void Polynominal::operator =(const Polynominal &right){
    if( !terms_.empty() ) terms_.clear();
    for (auto itr = right.terms_.begin(); itr != right.terms_.end(); ++itr)
        if( (*itr).coef_!=0 ) terms_.push_back(*itr);
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


//***************************************************************************** */
//   Metody poniżej są przeznaczone do uzupełnienia przez studentów podczas zajęć
//***************************************************************************** */
void Polynominal::operator+=( const Polynominal &right ){
    auto itrL{ terms_.begin() };
    auto itrR {right.terms_.begin()} ;

    for(; itrL!=terms_.end() && itrR!=right.terms_.end(); ++itrL) {
        while(itrR!=right.terms_.end() && ((*itrL).pow_ < (*itrR).pow_) ){
            terms_.insert(itrL, *itrR);
            ++itrR;
        }
        
        if(itrR!=right.terms_.end() && ((*itrL).pow_ == (*itrR).pow_)){
            (*itrL) += *itrR;
            ++itrR;
        }
    }

    while(itrR!=right.terms_.end() ){
        terms_.insert(itrL, *itrR);
        ++itrR;
    }
}

void Polynominal::operator*= (const Term<int> &right){
    list<Term<int>> tmp_list;
    auto itr {terms_.begin()};
    for (; itr != terms_.end(); ++itr){
        tmp_list.push_back((*itr)*right);
    }

    terms_ = tmp_list;
}

Polynominal operator +(const Polynominal &left, const Polynominal &right){
    Polynominal result(left);
    result += right;
    return result;
}

Polynominal operator *(const Polynominal &left, const Term<int> &right){
    Polynominal result;

    for (auto itr = left.terms_.begin(); itr != left.terms_.end(); ++itr){
        result += (*itr) * right;
    }
    return result;
}

Polynominal operator* (const Polynominal &left, const Polynominal &right){
    Polynominal result;
    auto itrL{ left.terms_};
    auto itrR {right.terms_} ;

    
    }   
    return result;

}

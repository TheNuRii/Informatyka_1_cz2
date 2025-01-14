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
    if( !terms_.empty()) {
        terms_.clear();
    }
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



int Polynominal::degree() const {
    return terms_.empty() ? 0 : terms_.front().pow_;
}
Polynominal operator +(const Polynominal &left, const Polynominal &right){
    Polynominal result_add_operation(left);
    result_add_operation += right;
    return result_add_operation;
}
Polynominal operator *(const Polynominal &left, const Polynominal &right){
    Polynominal result_multiplication_operation;
    for (auto &termL : left.terms_)
        for (auto &termR : right.terms_)
            result_multiplication_operation += Polynominal(termL * termR);
    return result_multiplication_operation;
}
Polynominal operator -(const Polynominal &p){
    Polynominal result_substraction_operation;
    for (const auto &term : p.terms_) {
        result_substraction_operation.terms_.push_back(-term); 
    }
    return result_substraction_operation;
}
Polynominal operator /(const Polynominal &left, const Polynominal &right){
    assert(!right.terms_.empty());
    Polynominal result_division_operation;
    Polynominal temp_left = left;
    while(!temp_left.terms_.empty() && temp_left.degree()>=right.degree()){
        Term<double> term = temp_left.terms_.front()/ right.terms_.front();
        result_division_operation.terms_.push_back(term);
        temp_left = temp_left + (-Polynominal(term)* right);
    }
    return result_division_operation;
}
Polynominal operator %(const Polynominal &left, const Polynominal &right){
    assert(!right.terms_.empty());
    Polynominal temp_left = left;
    while (!temp_left.terms_.empty() && temp_left.degree()>= right.degree()){
        Term <double> term = temp_left.terms_.front()/ right.terms_.front();
        temp_left = temp_left + (-Polynominal(term)* right);
    }
    return temp_left;
}
void division(const Polynominal &left, const Polynominal &right, Polynominal &result, Polynominal &rmndr){
    assert(!right.terms_.empty());
    result = Polynominal();
    Polynominal temp_left = left;
    while(!temp_left.terms_.empty() && temp_left.degree() >= right.degree()){
        Term <double> term = temp_left.terms_.front()/ right.terms_.front();
        Polynominal temp(term);
        result += temp;
        temp_left = temp_left + (-temp* right);
    }
    rmndr = temp_left;
}



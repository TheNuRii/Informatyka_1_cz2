#pragma once
#include <stdexcept>
#include <cassert>
using namespace std;

template <typename T>
class Term {
    public:
    Term(T coef) : coef_(coef),pow_(0){}
    Term(T coef, int pow) : coef_(coef), pow_(pow){}
    void operator +=( const Term<T> &right ){
        assert ( pow_==right.pow_ );
        coef_ += right.coef_;
    }

    T coef_;
    const int pow_;
};

template <typename T>
bool operator ==(const Term<T> &left, const Term<T> &right){
    return (( left.coef_==right.coef_ ) && ( left.pow_==right.pow_ ));    
}

template <typename T>
Term<T> operator +(const Term<T> &left, const Term<T> &right){
    assert(left.pow_==right.pow_); 
    Term<T> result(left.coef_+right.coef_, left.pow_);
    return result;
}

template <typename T>
Term<T> operator *(const Term<T> &left, const Term<T> &right){
    Term<T> result(left.coef_ * right.coef_, left.pow_+right.pow_);
    return result;
}


// do zaimplementowania
template <typename T>
Term<T> operator /(const Term<T> &left, const Term<T> &right){
    assert(left.pow_==right.pow_);
    Term<T> result(left.coef_/right.coef_, left.pow_ - right.pow_);
    return result; 
}
template <typename T>
Term<T> operator-(const Term<T> &term) {
    return Term<T>(-term.coef_, term.pow_);
}
#include "treebst.h"
#include <iostream>

using namespace std;

template<typename T>
Treebst<T>::Treebst(){
    node_;
    left_ = nullptr;
    right_ = nullptr;
}

template<typename T>
Treebst<T>::Treebst(T v, Treebst<T>* l, Treebst<T> r){
    node_ = v;
    left_ = l;
    right_ = r;
}

template<typename T>
bool Treebst<T>::isLeft(){return left_!=nullptr;}

template<typename T>
bool Treebst<T>::isRight(){return right_!=nullptr;}

template<typename T>
void Treebst<T>::printPreOrder(){
    cout << '(' << node_ << ',';
    if(isLeft()) cout << left_->node_<<',';else cout << '-';
    if(isRight()) cout << right_->node_ << ')'; else cout << "-)";
    if(isLeft()) left_->printPreOrder();
    if(isRight()) right_->printPreOrder();
}

template<typename T>
void Treebst<T>::printInPreOrder(){
    if(isLeft()) left_->printPreOrder();
    cout << '(' << node_ << ',';
    if(isLeft()) cout << left_->node_<<',';else cout << '-';
    if(isRight()) cout << right_->node_ << ')'; else cout << "-)";
    if(isRight()) right_->printPreOrder();
}

template<typename T>
void Treebst<T>::printPostOrder(){
    if(isLeft()) left_->printPreOrder();
    if(isRight()) right_->printPreOrder();
    cout << '(' << node_ << ',';
    if(isLeft()) cout << left_->node_<<',';else cout << '-';
    if(isRight()) cout << right_->node_ << ')'; else cout << "-)";
}
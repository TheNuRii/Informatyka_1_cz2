#include <iostream>
#include "treebst.h"
using namespace std;

Treebst::Treebst():value(0), l(nullptr), r(nullptr) {}
Treebst::Treebst(int v, Treebst* left, Treebst* right)
: value(v), l(left), r(right) {}
Treebst::~Treebst(){}
 
bool Treebst::isLeft(){ return l!=nullptr; };
bool Treebst::isRight(){ return r!=nullptr; };
int Treebst::height(Treebst* w){
    if(w==nullptr) return -1;
    else{
        int lheight = height(w->l);
        int rheight = height(w->r);
        if(lheight > rheight) return lheight+1;
        else return rheight+1;
    }
}
Treebst* Treebst::insert(Treebst* w, int x){
    if( w==nullptr ) return new Treebst(x,nullptr,nullptr);
    if( x < w->value ) w->l = insert( w->l,x);
    else if(w->value<x) w->r = insert(w->r,x);
    else w->value = x;
    return w;
} 
Treebst* Treebst::removeall( Treebst* w){
    if(w==nullptr) return nullptr;
    if( w->isLeft()) removeall( w->l );
    if( w->isRight()) removeall( w->r );
    delete w;
    return nullptr;
}

void Treebst::printPreOrder(){
    cout<<"("<<value<<",";
    if(isLeft()) cout<<l->value<<",";else cout<<"-,";
    if(isRight()) cout<<r->value<<")";else cout<<"-)";
    if(isLeft())  l->printPreOrder();
    if(isRight()) r->printPreOrder(); 
}

// metody do zaimplemntowania

Treebst* Treebst::getMax( Treebst* w ){
    if(w==nullptr) return nullptr;
    while(w->isRight()) w = w->r;
    return w;
}
Treebst* Treebst::getMin( Treebst* w ){
    if(w==nullptr) return nullptr;
    while(w->isLeft()) w = w->l;
    return w;
}
bool Treebst::serach(Treebst* w, int x){
    if(w==nullptr) return false;
    if(w->value==x) return true;
    if(x<w->value) return serach(w->l,x);
    else return serach(w->r,x);
}
Treebst* Treebst::getnode(Treebst* w, int x ){
    if(w==nullptr) return nullptr;
    if(w->value==x) return w;
    if(x<w->value) return getnode(w->l,x);
    else return getnode(w->r,x);
}
int Treebst::count( Treebst* w ){
    if(w==nullptr) return 0;
    return 1+count(w->l)+count(w->r);
}
void Treebst::printInOrder(){
    if(isLeft()) l->printInOrder();
    cout<<"("<<value<<",";
    if(isLeft()) cout<<l->value<<",";else cout<<"-,";
    if(isRight()) cout<<r->value<<")";else cout<<"-)";
    if(isRight()) r->printInOrder();
}
void Treebst::printPostOrder(){
    if(isLeft()) l->printPostOrder();
    if(isRight()) r->printPostOrder();
    cout<<"("<<value<<",";
    if(isLeft()) cout<<l->value<<",";else cout<<"-,";
    if(isRight()) cout<<r->value<<")";else cout<<"-)";
}


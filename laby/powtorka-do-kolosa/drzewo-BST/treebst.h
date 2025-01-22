#pragma once

template<typename T>
class Treebst {
public:
    T node_;
    Treebst* left_;
    Treebst* right_;

    Treebst();
    Treebst(T v, Treebst<T>* l, Treebst<T>* r);


    bool isLeft();
    bool isRight();

    void printPreOrder();
    void printInOrder();
    void printPostOrder();
};
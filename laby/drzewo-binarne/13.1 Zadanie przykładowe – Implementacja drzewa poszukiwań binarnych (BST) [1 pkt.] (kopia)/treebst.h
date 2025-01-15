#pragma once

class Treebst{
    public:
        int value;
        Treebst* l; 
        Treebst* r;

        Treebst();
        Treebst(int v, Treebst* left, Treebst* right);
        ~Treebst();

        bool isLeft();
        bool isRight();
        int height(Treebst* w);
        Treebst* insert(Treebst* w, int x);
        Treebst* removeall( Treebst* w);
        void printPreOrder();
        
        // metody do zaimplementowania 
        
        Treebst* getMin( Treebst* w );
        Treebst* getMax( Treebst* w );
        int count( Treebst* w );
        bool serach(Treebst* w, int x);
        Treebst* getnode(Treebst* w, int x );
        void printInOrder();
        void printPostOrder(); 
        
};

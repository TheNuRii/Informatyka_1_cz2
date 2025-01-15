#include <iostream>
#include <list>
#include "treebst.h"
using namespace std;

int main(){ 

    Treebst* root = nullptr;
    Treebst* node;
    list<int> values;
    int value;

    // wprowadzanie serii danych int, wartość 0 kończy wczytywanie
    // np. 11 5 15 3 7 9 6 8 10 2 4 0
    cout<<"values: ";
    do{ 
        cin>>value;
        if(value==0) break;
        values.push_back(value);
    }while(1);
    for (int i : values) root = root->insert(root, i);

    root->printPreOrder(); cout<<endl;
    
    root->printInOrder(); cout<<endl;
    root->printPostOrder(); cout<<endl;
    node = root->getMax(root);
    cout<<"max: "<< node->value <<endl;
    node = root->getMin(root);
    cout<<"min: "<< node->value <<endl;
    cout<<"max height: "<<root->height(root)<<endl;

    cout<<"search Key ";
    for(int i=root->getMin(root)->value;i<=root->getMax(root)->value;++i){
        cout<<i<<":"<<((root->serach(root, i ))?"Y ":"N "); 
    }
    cout<<endl;
    
return 0; 
}
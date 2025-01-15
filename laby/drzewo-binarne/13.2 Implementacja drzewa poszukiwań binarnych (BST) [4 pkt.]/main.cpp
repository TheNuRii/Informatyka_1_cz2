#include <iostream>
#include <list>
#include "treebst.h"
using namespace std;

int main(){

    Treebst* root = nullptr;
    Treebst* node;
    list<int> values;
    int value;
    cout<<"values: "; 
    do{ 
        cin>>value;
        if(value==0) break;
        values.push_back(value);
    }while(1);

    // wprowadzanie serii danych int, wartość 0 kończy wczytywanie
    //np. 11 5 15 3 7 9 6 8 10 2 4 0 10 5 7 6 11 0
    for (int i : values) root = root->insert(root, i);

    root->printPreOrder(); cout<<endl;
    root->printInOrder(); cout<<endl;
    root->printPostOrder(); cout<<endl;
    node = root->getMax(root);
    cout<<"max: "<< node->value <<endl;
    node = root->getMin(root);
    cout<<"min: "<< node->value <<endl;
    cout<<"max height: "<<root->height(root)<<endl;

    cout<<"Key ";
    for(int i=root->getMin(root)->value;i<=root->getMax(root)->value;++i){
        cout<<i<<":"<<((root->serach(root, i ))?"Y ":"N "); 
    }
    cout<<endl;

    cout<<"Depth ";
    for(int i=root->getMin(root)->value;i<=root->getMax(root)->value;++i){
        int d = root->depth(root, i );
        if(d>-1) cout<<i<<":"<<d<<" "; 
    }
    cout<<endl;

    cout<<"Height of key ";
    for(int i=root->getMin(root)->value;i<=root->getMax(root)->value;++i){
        int h = root->height(root, i );
        if(h>-1) cout<<i<<":"<<h<<" "; 
    }
    cout<<endl;
    int x;
    cout<<"before: ";root->printPostOrder(); cout<<endl;
    cout<<"remove=";
    do{ 
        cin>>x;
        if( x==0 ) break;
            // cout<<"before: ";root->printPostOrder(); cout<<endl;
        if( root!=nullptr) root=root->remove(root,x);
        if( root!=nullptr) {
            // cout<<"after:  ";root->printPostOrder(); cout<<endl;
        }else{
            cout<<"tree is empty!"<<endl;
        }    
    }while(1);
    cout<<"after: ";root->printPostOrder(); cout<<endl;    

return 0; 
}
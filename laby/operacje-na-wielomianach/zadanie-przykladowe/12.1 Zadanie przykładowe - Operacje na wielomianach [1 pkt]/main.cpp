#include <iostream>
#include <vector>
#include <list>
#include <map>
#include "polynominal.h"
using namespace std;


int main(){
    int polynominalCount = 2;
    vector <Polynominal> poly(polynominalCount,Polynominal());
    map <int,int> positions;
    int elementCount=0, value, position; 
    
    for (int polynominalNo=0; polynominalNo<polynominalCount; ++polynominalNo){   
        positions.clear();
        cout << "Polynominal " << (polynominalNo+1) << endl;
        
        do { cout<<"number of elements [1-20]: "; cin >> elementCount; 
        } while( elementCount<1 || elementCount >20 );
        
        for(int i=0;i<elementCount;++i){
            do{ cout << "value position: "; cin >> value >> position; 
            }while(positions.count(position)==1 && value!=0);
            positions[position] = value;
            poly[polynominalNo] += Polynominal(value,position);
        }
    }
    Polynominal pSum,pProduct;
    cout << endl;
    for (int i=0; i<polynominalCount; ++i) cout << "poly[" << i << "] = " << poly[i] << endl;

    

    /*  addition  */
    for (int count=0; count<polynominalCount; ++count){
        if (count==0){
            pSum = poly[count];
        }else{
            pSum = pSum + poly[count];
        }
    }
    
    /*  multiplication  */
    for (int count=0; count<polynominalCount; ++count){
        if (count==0){
            pProduct = poly[count];
        }else{
            pProduct = pProduct * poly[count];
        }
    }
    
    
    /*  results  */
    cout <<"Sum: "<< pSum <<endl;
    cout <<"Product: "<< pProduct <<endl;

    return 0;
}
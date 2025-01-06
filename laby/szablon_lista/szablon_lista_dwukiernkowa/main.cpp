#include "doubleLinkList.h"
#include <iostream>
#include <cassert>

using namespace std;

class Number{
public:
    Number(float re, float im){
        re_ = re;
        im_ = im;
    }

    ~Number();

    float module(){
        return sqrt(re_ * re_ + im_ * im_);
    }

    bool operator==(const Number* other_number){
        return (re_ == other_number->re_ && im_ == other_number->im_);
    }

private:
    float re_;
    float im_;
};

int main(){ 
    int M;
    cout << "M=";
    cin >> M;
    DoubleLinkList<Number> list;
    cout << "Podaj elementy do dodania=";
    for (int i = 0; i < M; i++){
        float re, im;
        cin >> re >> im;
        list.addElementToList(new Number(re, im));
    }
    list.printListFromTheEnd();

    int N;
    cout << "N=";
    cin >> N;
    cout << "Podaj elementy do usuniecia=";
    for (int i = 0; i < N; i++){
        float re, im;
        cin >> re >> im;
        list.deleteElementFromList(new Number(re, im));
    }
    list.printListFromTheEnd();
    return 0;
}
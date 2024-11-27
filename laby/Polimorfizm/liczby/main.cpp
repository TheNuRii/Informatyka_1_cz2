#include "iostream"
#include "liczba.h"
#include "liczba.cpp"

using namespace std;

int main(){
    Zespolona* z;
    float re, im;
    cout << "Re=";
    cin >> re;
    cout << "Im=";
    cin >> im;
    z = new Zespolona(re, im);
    cout << z->typ() << endl;
    cout << z->wartosc() << endl;

    Wymierna* w;
    float licznik, mianownik;
    cout << "N=";
    cin >> licznik;
    cout << "D=";
    cin >> mianownik;
    w = new Wymierna(licznik, mianownik);
    cout << w->typ() << endl;
    cout << w->wartosc() << endl;

    int size;
    cout << "Size=";
    cin >> size;

    Liczba **liczby = new Liczba*[size];
    for (int i = 0; i < size; i++){

        if ((i & 0x01) || (i == 0)){
            cout << "N";
            cin >> licznik;
            cout << "D";
            cin >> mianownik;
            liczby[i] = new Wymierna(licznik, mianownik);
        } else {
            cout << "Re";
            cin >> re;
            cout << "Im";
            cin >> im;
            liczby[i] = new Zespolona(re, im);
        }
    }
    for(int i = 0; i < size; i++){
        cout << '[' << liczby[i]->typ() << ' ' << liczby[i]->wartosc() << ']';
    }
    cout << endl;
    for(int i = 0; i < size; i++){
        delete liczby[i];
    }
    delete[] liczby;
    delete z;
    delete w;
    return 0;
}
#include "koszyk.h"
#include "iostream"
using namespace std;

Koszyk koszyk(){}

Koszyk::Koszyk(){
    for (int i = 0; i < index; ++i) {
        cout << koszyk[i].nazwa << ", ";
        cout << "cenna brutto=" << koszyk[i].cena_netto * (1 + koszyk[i].vat / 100) << "PLN, ";
        cout << "waga=";
    }
}
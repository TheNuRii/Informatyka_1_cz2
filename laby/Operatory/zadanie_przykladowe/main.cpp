#include<iostream>
#include "koszyk.h"
#include "produkt.h"

using namespace std;

int main() {
    Koszyk koszyk;
    int n;
    cout << "N=";
    cin >> n;
    if (n < 1 || n > 10) {
        cout << "Bledne dane wejsciowe";
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        string nazwa;
        double cena, waga;
        int vat;
        
        cout << "Nazwa=";
        cin >> nazwa;
        cout << "Cena[PLN]=";
        cin >> cena;
        cout << "Waga[g]=";
        cin >> waga;
        cout << "VAT[%]=";
        cin >> vat;
        
        Produkt p = Produkt(nazwa, cena, waga, vat);
        
        koszyk+=p;
        
        Produkt p_kopia = p; // wywołuje konstruktor kopiujący
        
        koszyk += p_kopia;
    }
    
    cout << koszyk;
    
    Koszyk koszyk2 = koszyk; // wywołuje konstruktor kopiujący
    
    int id;
    cin >> id;
    koszyk -= koszyk[id];
    
    cout << koszyk;
    cout << koszyk2;
    
    Koszyk koszyk3;
    koszyk3 = koszyk; //wywołuje operator przypisania
    cout << koszyk3;
            
    return 0;
}

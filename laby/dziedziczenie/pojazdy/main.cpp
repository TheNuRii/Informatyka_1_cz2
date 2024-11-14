#include "pojazdy.h"
#include <iostream>

using namespace std;

int main(){
  Pojazd *flota[5];
  int l_pojazdow;
  
  cout << "Liczba pojazdow=";
  cin >> l_pojazdow;
  
  if (l_pojazdow>0 && l_pojazdow<5){
    for (int n=0; n<l_pojazdow; ++n){
      char c = ' ';
      cout << "Podaj rodzaj samochodu [o/c]:";
      do {
        cin >> c;
      } while ( c!='o' && c!='c' );
      
      switch (c){
        case 'o':
          flota[n] = new PojazdOsobowy;
          cin >> *static_cast<PojazdOsobowy*>(flota[n]);
          break;
        case 'c':
          flota[n] = new PojazdCiezarowy;
          cin >> *static_cast<PojazdCiezarowy*>(flota[n]);
          break;
      }
    }
    for (int n=0; n<l_pojazdow; ++n){
        cout << *flota[n] << endl;
    }    
    for (int n=0; n<l_pojazdow; ++n){
        cout << (PojazdSilnikowy&)(*flota[n]) << endl;
    }    
    for (int n=0; n<l_pojazdow; ++n){
        if (flota[n]->rodzaj_pojazdu("PojazdOsobowy"))
          cout << *static_cast<PojazdOsobowy*>(flota[n]);
        if (flota[n]->rodzaj_pojazdu("PojazdCiezarowy"))
          cout << *static_cast<PojazdCiezarowy*>(flota[n]);
        cout << endl;   
    }  
    
    for (int n = 0; n < l_pojazdow; ++n)
      delete flota[n];

  }else{
    cout << "Bledna liczba pojazdow.";
  }

}
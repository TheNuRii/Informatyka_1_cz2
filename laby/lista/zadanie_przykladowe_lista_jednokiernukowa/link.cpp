#include "istream"

using namespace std;

class Link {
public:
    Link * insert(double wartosc);

    friend class Lista;
    friend class Iterator;

private:
    double wartosc_;
    Link *nastepna_komurka_listy_;

    Link(double wartosc, Link *wskaznik){
        wartosc_ = wartosc;
        nastepna_komurka_listy_ = wskaznik;
    }   
};
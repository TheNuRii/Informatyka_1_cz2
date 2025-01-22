#include <iostream>
#include <iomanip>
#include <math.h>
#include "linkedlist.h"

using namespace std;

class Kordynaty{
public:
    double x_;
    double y_;

    Kordynaty(double new_x, double new_y){
        x_ = new_x;
        y_ = new_y;
    }

    std::ostream& operator<<(std::ostream& out){
        out << '(' << x_ << ", " << y_ << ')';
        return out;
    }

    bool operator==(const Kordynaty& other){
        return x_ == other.x_ && y_ == other.y_; 
        //(sqrt(x_**2 + y_**2) == 2.0);
    }

    
};


int main() {
    LinkedList<Kordynaty> lista_kordyntow;
    int N;

    cout << "N:";
    cin >> N;

    double new_x;
    double new_y;
    for(int i = 0; i < N; i++){
        cin >> new_x >> new_y;
        Kordynaty* nowe_kordynaty = new Kordynaty(new_x, new_y);
        lista_kordyntow.addElementToTheFront(*nowe_kordynaty);
    }

    lista_kordyntow.printFromTheBeginig();
   

    int c;
    cout << "(1-4):";
    cin  >> c;
    lista_kordyntow.printElementsDependOnC(c);

    Kordynaty* pierwszy_warunek_usuniecia = new Kordynaty(2.0, 2.0);
    lista_kordyntow.deleteElements(*pierwszy_warunek_usuniecia);

    return 1;
}

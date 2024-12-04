#include <iostream>

using namespace std;

template <typename T>
class Tschowek {
public:
    Tschowek(T objekt1, T objekt2) {
        podany_objekt1_ = objekt1;
        podany_objekt2_ = objekt2;
    }

    void wyswietlSumeLiczb() {
        cout << podany_objekt1_ + podany_objekt2_ << endl;
    }

    T getObjekt1() {
        return podany_objekt1_;
    }

    T  getObjekt2() {
        return podany_objekt2_;
    }

    bool operator>(const Tschowek<T> &tschowek) {
        return (this -> podany_objekt1_ + this -> podany_objekt2_) > (tschowek.podany_objekt1_ + tschowek.podany_objekt2_);
    }
private:
    T podany_objekt1_;
    T podany_objekt2_;
};


int main(){
    int liczba_natulrana_1, liczba_natulrana_2;
    cout << "Podaj dwie liczby naturalne=";
    cin >> liczba_natulrana_1 >> liczba_natulrana_2;

    Tschowek<int> tschowek1(liczba_natulrana_1, liczba_natulrana_2);
    tschowek1.wyswietlSumeLiczb();

    double liczba_rzeczywista_1, liczba_rzeczywista_2;
    cout << "Podaj dwie liczby rzeczywiste=";
    cin >> liczba_rzeczywista_1 >> liczba_rzeczywista_2;

    Tschowek<double> tschowek2(liczba_rzeczywista_1, liczba_rzeczywista_2);
    tschowek2.wyswietlSumeLiczb();

    string slowo_1, slowo_2;
    cout << "Podaj dwie slowa=";
    cin >> slowo_1 >> slowo_2;  

    Tschowek<string> tschowek3(slowo_1, slowo_2);
    tschowek3.wyswietlSumeLiczb();
    
    double kolejna_liczba_rzeczywista_1, kolejna_liczba_rzeczywista_2;
    cout << "Podaj dwie liczby rzeczywiste=";
    cin >> liczba_rzeczywista_1 >> liczba_rzeczywista_2;
    cout << "Podaj dwie liczby rzeczywiste=";
    cin >> kolejna_liczba_rzeczywista_1 >> kolejna_liczba_rzeczywista_2;

    Tschowek<double> tschowek4(liczba_rzeczywista_1, liczba_rzeczywista_2);
    Tschowek<double> tschowek5(kolejna_liczba_rzeczywista_1, kolejna_liczba_rzeczywista_2);
    
    if (tschowek4 > tschowek5){
        cout << tschowek4.getObjekt1() << " " << tschowek4.getObjekt2();
    } else {
        cout << tschowek5.getObjekt1() << " " << tschowek5.getObjekt2();
    }
    
return 0;
}
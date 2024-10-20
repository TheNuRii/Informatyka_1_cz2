#include <iostream>
using namespace std;

// Przyklad Klasy
class Adress {
    private:
        string Street, City, Country;
        int House_number, Zip_code[6];
    public:
        void enter_data(string, string, string, int, int[]);
        void display();
        int get_number(){
            return House_number;
        }
};

//Przyklad Destruktora
class Cylinder {
    double raidus;
public:
    Cylinder(double r = 1.0) : raidus(r) { }
    double area() {return 3.14 * raidus *  raidus;}
    // destruktor
    ~Cylinder(){
        std::cout<<"Cilinder descructor in use.";
    }
};

// Liczby zespolone
class complex {
public:
    double re, im;
    complex (double r, double  i) : re(r), im(i){}
};

complex Csum (complex a1, complex a2){
    complex sum(0, 0);
    sum.re = a1.re + a2.re;
    sum.im = a1.im + a2.im;
    return sum;
}

complex Cmult (complex a1, complex a2){
    complex product(0 , 0);
    product.re = a1.re * a2.re - a1.im * a2.im;
    product.im = a1.re * a2.im + a1.im * a2.re;
    return product;
}

int main(){
    Adress my_address, university, my_girl_friend;
    int where = my_girl_friend.get_number();

    Cylinder column(20);
    column.~Cylinder();

}

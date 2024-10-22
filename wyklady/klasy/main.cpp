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
    double re, im;
public:
    // konstruktor jako konwerter
    complex (double r = 0.0, double i = 0.0) : re(r), im(i){} // initialization list
    operator int (){            // akways no argument
        return (int) re;        // by assumption return real part
    }                           // as integer value

    friend  complex operator+ (complex a1, complex a2){ // operator dodawania
        return complex (a1.re + a2.re, a1.im + a2.im);
    }

    friend complex operator* (complex a1, complex a2){ // operator monożenia
        return complex (a1.re * a2.re - a1.im * a2.im, a1.re * a2.im + a1.im * a2.re);
    }
    friend complex Csum (complex, complex);
    friend complex Cmult (complex, complex);

    complex& operator+= (const complex& other){ //Operator przypisania dodawania (+=)
        re += other.re;
        im += other.im;
        return *this;
    }
};

// funkcja sumująca, wykorzystujacą klase complex
complex Csum (complex a1, complex a2){
    //complex sum(0, 0);
    complex sum;
    sum.re = a1.re + a2.re;
    sum.im = a1.im + a2.im;
    return sum;
}

// funkcja mnożąca, wykorzystująca klase complex
complex Cmult (complex a1, complex a2){
    /*complex product(0 , 0);
    product.re = a1.re * a2.re - a1.im * a2.im;
    product.im = a1.re * a2.im + a1.im * a2.re;
    return product;
     */
    return complex (a1.re * a2.re - a1.im * a2.im,
                    a1.re * a2.im + a1.im * a2.re);
}

// Funkcje zaprzyjaznione

class B;
class A{
public:
    int reader(B);
};

class B {
    int number;
    friend int A::reader(B);
};

// Przeladowanie operatorow


int main(){
    Adress my_address, university, my_girl_friend;
    int where = my_girl_friend.get_number();

    Cylinder column(20);
    column.~Cylinder();

    complex Z1(3, 5), Z2(7.0, 5.3), sum(0,0);
    // sum = sum(Z1, Z2);

    // int A::reader(B object){return object.reader;}

    return 0;
}

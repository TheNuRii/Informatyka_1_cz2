#include "iostream"

using namespace std;

class Vehicle{
private:
    double weight;
    int wheels;
public:
    virtual void start(){
        cout << "Starting engine";
    }
    double capacity();
    void loading();
};

class Car : public Vehicle{
public:void start(){cout << "starting a car.";}
};

// Kostruktor kopujacy
class Vector{
    int size; double *Ptr;
public:
    Vetor(const Vector &orginal);
};

int Vector::Vetor(const Vector &orginal) {

}

// Konstruktor przenoszacy

int Vector::Vetor(const Vector &&orginal) {
    size = orginal.size;
}


int main(){
    Vehicle *p;
    p = new Car;
    p -> start();
    return 0;
}


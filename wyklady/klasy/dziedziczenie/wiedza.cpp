#include "iostream"

using namespace std;

class Vehicle{
private:
    double weight;
    int wheels;
public:
    void start(){
        cout << "Starting engine";
    }
    double capacity();
    void loading();
};

class Motorcile : Vehicle{

};
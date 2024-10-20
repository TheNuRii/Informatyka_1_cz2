#include <iostream>

const double PI = 3.14;

class Shape{
  public:
    double volume;
    double area;  
};

class Cube : public Shape{
public:
    double side;

    Cube(double side){
        this->side = side;
        this->area = 6 * side * side;
        this->volume = side * side * side;
    }

    void display(){
        std::cout << "Area: " << area << '\n';
        std::cout << "Volume: " << volume << '\n';
    }
};

class Sphere : public Shape{
public:
    double radius;

    Sphere(double radius){
        this->radius = radius;
        this->area = 4 * PI * radius * radius;
        this->volume = 4/3 * PI * radius * radius * radius;
    }

    void display(){
        std::cout << "Area: " << area << '\n';
        std::cout << "Volume: " << volume << '\n';
    }
};
int main(){
    Cube cube(2);
    Sphere sphere(3);

    cube.display();
    sphere.display();
    return 0;
}
#include <iostream>

class Student {
public:
    std::string name;
    int age;
    double gpa;
    
    Student(std::string name, int age, double gpa) {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }

    void display() {
        std::cout << "Name: " << name << '\n';
        std::cout << "Age: " << age << '\n';
        std::cout << "GPA: " << gpa << '\n';
    }
};

class Pizza{
public:
    std::string name;
    int size;
    int price;
    std::string toppings = "None";
    Pizza(std::string name, int size, int price){
        this->name = name;
        this->size = size;
        this->price = price;
    }
    //Constructor overloading
    Pizza(std::string name, int size, int price, std::string toppings){
        this->name = name;
        this->size = size;
        this->price = price;
        this->toppings = toppings;
    }
    void display(){
        std::cout << "Name: " << name << '\n';
        std::cout << "Size: " << size << '\n';
        std::cout << "Price: " << price << '\n';
        std::cout << "Toppings: " << toppings << '\n';
    }
};

int main() {
    Student first_student("Mark", 21, 3.5);
    Student second_student("John", 22, 3.5);
    Student third_student = Student("Jane", 21, 3.5);
    Pizza pizza1("Margherita", 12, 15);
    Pizza pizza2("Pepperoni", 14, 20, "Perperoni");

    first_student.display();
    second_student.display();
    third_student.display();

    pizza1.display();
    pizza2.display();
    return 0;
}
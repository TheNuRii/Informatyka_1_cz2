#include <iostream>

class Person{
public:
    std::string name = "John";
    std::string occupation = "student";
    int age = 20;
    
    void display(){
        std::cout << "Name: " << name << '\n';
        std::cout << "Occupation: " << occupation << '\n';
        std::cout << "Age: " << age << '\n'; 
    }

    void change_name(std::string new_name){
        name = new_name;
    }

    void change_occupation(std::string new_occupation){
        occupation = new_occupation;
    }

    void change_age(int new_age){
        age = new_age;
    }
};

int main(){
    Person me;
    me.display();
    me.change_name("Macieh");
    me.change_occupation("student");
    me.change_age(20);
    me.display();

    return 0;
}
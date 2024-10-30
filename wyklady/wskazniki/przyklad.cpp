#include "iostream"
using namespace std;

void confused(int *);

class Person {
private:
    string name;
public:
    Person *father, *mother;
    Person(string text) : name(text), father(NULL), mother(NULL){}
};

class Person_inczej {
    string name;
    Person_inczej *father, *mother;
};

int main (){
    // wskaznik
    int *Pointer;
    int number = 3;
    Pointer = &number;
    int value = *Pointer;

    cout << Pointer << ": " << value;

    int *Pointer_1 = nullptr;
    //lub
    int *Pointer_2 = NULL;

    //Operatory new i delete

    int *number_ = nullptr;

    // Dynamiczne tworzenie obiektow
    Complex *number_ = new Complex(2,3);

    char s[] = "Polaka";
    // Stała wartość zmienny wskaźnik
    const char *ptr = s;
    // Zmienna wartość stały wskaźnik
    char *const cp = s;
    // Stała wartość stały wskaźnik
    const char *const ptr_ = s;

    // Dynamiczna laokacja tablicy
    int size;
    cin >> size;
    double *Vector = new double[size];
    Vector[5] = 33;
    *(Vector + 5) = 33;
    Vector[0] = 15;
    *Vector = 15;
    //Usuwamy pierwsza warosc w tablicy
    delete Vector;

    // Ususwamy cały obiekt
    delete [] Vector;

    // Tablica dwuwymiarowa
    double **Matrix;
    int size_1;
    int size_2;
    cin >> size_1 >> size_2;
    Matrix = new double *[size_1];
    for (int i = 0; i < size_1; ++i)
        Matrix = new double * *[size_2];

    // Obiekt klasy
    Address *Adr_Ptr &my_adress;

    // Rodowod
    Person *root = new Person("Jan Kowalski");
    root->father = new Person("Roch Kowalski");
    root->mother = new Person("Anna Potocka");
    root->father->father = new Person("Lech Kowalski");

    return 0;
}
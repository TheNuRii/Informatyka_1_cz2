#pragma once 

using namespace std;

template<typename T>
class Node{
public:
    Node(T element, Node<T>* next = nullptr);
    ~Node();

    void setElemet(T new_element);
    void setNextPtr(Node<T>* new_next);

    T getElement() const;
    Node<T>* getNextPtr() const;

private:
    T element_;
    Node<T>* next_;
};

template<typename T>
class LinkedList{
public:
    LinkedList(Node<T>* head = nullptr);
    
    void addElementToTheFront(T& new_elemt);

    void printFromTheBeginig();

    void  deleteElements(T elemet_to_delete);

    void printElementsDependOnC(int c);

private:
    Node<T>* head_;
};

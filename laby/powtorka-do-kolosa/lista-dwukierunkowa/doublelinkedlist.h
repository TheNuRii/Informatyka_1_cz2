#pragma once

template <typename T>
class Node{
public:
    Node(T elemet, Node<T>* next = nullptr, Node<T>* prev = nullptr);
    ~Node();

    void setElement(T new_element);
    void setNext(Node<T>* new_next);
    void setPrev(Node<T>* new_prev);

    T getElement();
    Node<T>* getNext();
    Node<T>* getPrev(); 
private:
    T element_;
    Node<T>* next_;
    Node<T>* prev_;
};

template <typename T>
class DoubleLinkedList{
public:
    DoubleLinkedList(Node<T>* head, Node<T>* tail);
    ~DoubleLinkedList();

    void addElementToList(const T& new_element);
    void delteElement(T* element_to_delete);

    void printListFromTheEnd();
private:
    Node<T>* head_;
    Node<T>* tail_;
};
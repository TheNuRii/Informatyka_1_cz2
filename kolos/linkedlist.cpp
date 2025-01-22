#include "linkedlist.h"
#include "iostream"

using namespace std;

template<typename T>
Node<T>::Node(T element, Node<T>* next){
    element_ = element;
    next_ = next;
}

template<typename T>
Node<T>::~Node(){;}

template<typename T>
void Node<T>::setElemet(T new_element){
    element_ = new_element;
}

template<typename T>
void Node<T>::setNextPtr(Node<T>* new_next){
    next_ = new_next;
}

template<typename T>
T Node<T>::getElement() const{
    return element_;
}

template<typename T>
Node<T>* Node<T>::getNextPtr() const{
    return next_;
}

template<typename T>
LinkedList<T>::LinkedList(Node<T>* head){
    head_ = head;
}

template<typename T>
void LinkedList<T>::addElementToTheFront(T& new_elemet){
    Node<T>* newNode = new Node<T>(new_elemet);
    if(head_ == nullptr){
        head_ = newNode;
    } else {
        newNode->getNextPtr() = head_->getNextPtr();
        head_ = newNode;
    }
}

template<typename T>
void LinkedList<T>::printFromTheBeginig(){
    Node<T>* currentNode =  head_;
    cout << '[';
    while(currentNode != nullptr){
        cout << currentNode->getElement;
        currentNode = currentNode->getNextPtr;
    }
}

template<typename T>
void LinkedList<T>::printElementsDependOnC(int c) {
    Node<T>* current_node = head_;
    while (current_node != nullptr) {
        if (c == 1) {
            cout << current_node->getElement();
        } else if (c == 2){
            cout << current_node->getElement();
        } else if (c == 3){
            cout << current_node->getElement();
        } else{
            cout << current_node->getElement();
        }
        current_node = current_node->getNextPtr();
    }
}

template<typename T>
void LinkedList<T>::deleteElements(T elemet_to_delete){
    Node<T>* current_node = head_;
    Node<T>* previous_node = nullptr;
    while (current_node != nullptr) {
        if (current_node->getElement() == elemet_to_delete) {
            if (previous_node == nullptr) {
                head_ = current_node->getNextPtr();
            } else {
                previous_node->setNextPtr(current_node->getNextPtr());
            }
            delete current_node;
        }
        previous_node = current_node;
        current_node = current_node->getNextPtr();
    }
}
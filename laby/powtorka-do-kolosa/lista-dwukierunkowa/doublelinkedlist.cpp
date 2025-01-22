#include "doublelinkedlist.h"
#include <iostream>

using namespace std;

template<typename T>
Node<T>::Node(T element, Node<T>* next, Node<T>* prev){
    element_ = element;
    next_ = next;
    prev_ = prev;
}

template<typename T>
T Node<T>::getElement(){
    return element_;
}

template<typename T>
Node<T>* Node<T>::getNext(){
    return next_;
}

template<typename T>
Node<T>* Node<T>::getPrev(){
    return prev_;
}

template <typename T>
void Node<T>::setElement(T new_element){
    element_ = new_element;
}

template <typename T>
void Node<T>::setNext(Node<T>* new_next){
    next_ = new_next;
}

template <typename T>
void Node<T>::setPrev(Node<T>* new_prev){
    prev_ = new_prev;
}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(Node<T>* head, Node<T>* tail){
    head_ = head;
    tail_ = tail;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){
    while(head_ != nullptr){
        DoubleLinkedList<T>* temp = head_;
        head_ = head_ ->getElement();
        delete temp;
    }
}

template<typename T>
void DoubleLinkedList<T>::addElementToList(const T& new_element){
    Node<T>* newNode = new Node<T>(new_element);
    if(head_ == nullptr){
        head_ = tail_ = newNode;
    } else {
        tail_->getNextElement() = newNode;
        newNode->prev_ = tail_;
        tail_ = newNode;
    }
}

template <typename T>
void DoubleLinkedList<T>::delteElement(T* element_to_delete){
    Node<T>* currentNode = head_;
    while(currentNode != nullptr){
        if (currentNode->element_ == element_to_delete){
            if(currentNode->getPrev() != nullptr){
                currentNode->getPrev()->getNext() = currentNode->getNext();
            } else {
                head_ = currentNode->getElement();
            }

            if(currentNode->getNext() != nullptr) {
                currentNode->getNext()->getPrev() = currentNode->getPrev();
            } else{
                tail_ = currentNode->getPrev();
            }
            
            delete currentNode;
            return;
        }
        currentNode = currentNode->getNext();
    }
}

template <typename T>
void DoubleLinkedList<T>::printListFromTheEnd(){
    Node<T>* curruntNode = tail_;
    while(curruntNode != nullptr){
        cout << curruntNode->element_ << ' ';
        curruntNode = curruntNode->getPrev();
    }
}
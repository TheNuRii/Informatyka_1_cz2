#include <node.h>
#include <iostream>

using namespace std;

template <typename T>
Node<T>::~Node(){
    delete next_element_;
    delete prev_element_;
}

template <typename T>
Node<T>::Node(T* data, Node* next, Node* prev){
    element_ = data;
    next_element_ = next;
    prev_element_ = prev;
}

template <class T>
Node* Node::setNextElement(Node* next){
    next_element_ = next;
    return next_element_;
}

template <typename T>
Node<T>* Node<T>::setPrevElement(Node* prev){
    prev_element_ = prev;
    return prev_element_;
}

template <typename T>
T Node<T>::setContentOfTheContener(T new_element){
    element_ = new_element;
    return element_;
}

template <typename T>
void Node<T>::getContentOfTheContener() const{
    cout << element_ << '\n';
}

template <typename T>
void Node<T>::getPrevElement() const{
    cout << prev_element_ << '\n';
}

template <typename T>
void Node<T>::getNextElement() const{
    cout << next_element_ << '\n';
}

template <typename T>
bool Node<T>::operator<(const Node& other){
    return element_ < other.element_;
}

template <typename T>
ostream& operator<<(ostream& os, const Node& node){
    os << node.element_;
    return os;
}
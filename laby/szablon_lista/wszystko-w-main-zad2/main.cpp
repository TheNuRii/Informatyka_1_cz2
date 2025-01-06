#include <iostream>
#include <string>
#include <math.h>

using namespace std;


template <typename T>
class Node {
public:
    Node(T *data, Node *next = nullptr, Node *prev = nullptr) {
        prev_element_ = prev;
        node_element_ = data; 
        next_element_ = next;
    }

    ~Node() {
        delete node_element_;
    }

    T* getNodeElement() const { 
        return node_element_; 
    }
    Node* getNextElement() const{
        return next_element_;
    }

    Node* getPrevElement() const{
        return prev_element_;
    }
    void setNodeElement(T *data){
        node_element_ = data;
    }
    void setNextElement(Node *next){
        next_element_ = next;
    }
    void setPrevElement(Node *prev){
        prev_element_ = prev;
    }

private:
    T* node_element_;
    Node* next_element_;
    Node* prev_element_;
};

template <typename T>
class DoubleLinkedList {
public:
    DoubleLinkedList(){
        linked_list_head_ = nullptr;
    }

    ~DoubleLinkedList() {
        while (linked_list_head_ != nullptr) {
            Node<T> *temp = linked_list_head_;
            linked_list_head_ = linked_list_head_->getNextElement();
            delete temp;
        }
    }

    void addElementToList(T *data) {
        if (linked_list_head_ == nullptr || data == nullptr) {
            linked_list_head_ = new Node<T>(data);
            return;
        }

        Node<T>* current = linked_list_head_;
        while (current->getNextElement() != nullptr && data != nullptr && !(data < current->getNextElement()->getNodeElement())) {
            current = current->getNextElement();
        }

        current->setNextElement(new Node<T>(data, current->getNextElement()));
    }

    void deleteElementFromList(T *data) {
        if (linked_list_head_ == nullptr) return;

        if (*linked_list_head_->getNodeElement() == data) {
            Node<T> *temp = linked_list_head_;
            linked_list_head_ = linked_list_head_->getNextElement();
            delete temp;
            return;
        }

        Node<T> *current = linked_list_head_;
        while (current->getNextElement() != nullptr && !(*current->getNextElement()->getNodeElement() == data)) {
            current = current->getNextElement();
        }

        if (current->getNextElement() != nullptr) {
            Node<T> *temp = current->getNextElement();
            current->setNextElement(temp->getNextElement());
            delete temp;
        }
    }

    void printFromTheEndList(){
        Node<T> *temp = linked_list_tail_;
        while(temp != nullptr && temp != linked_list_head_){
            cout << *(temp->getNodeElement()) << ' ';
            temp = temp->getPrevElement();
        }
        cout << *(temp->getNodeElement()) << endl;
    }
private:
    Node<T> *linked_list_head_;
    Node<T> *linked_list_tail_;
};

class Number{
public:
    Number(float re, float im){
        re_ = re;
        im_ = im;
    }

    ~Number(){
        re_ = 0;
        im_ = 0;
    }

    float module() const{
        return sqrt(re_ * re_ + im_ * im_);
    }

    bool operator==(const Number* other_number){
        return (re_ == other_number->re_ && im_ == other_number->im_);
    }

    bool operator<(const Number* other_number){
        return (module() > other_number->module());
    }

    friend ostream& operator<<(ostream& os, const Number& number){

        if(number.im_ > 0)
            os << number.re_ << "+" << number.im_ << "i";
        else if (number.im_ < 0)
            os << number.re_ << "-" << number.im_ << "i";
        else if (number.im_ == 0)
            os << number.re_;
        return os;
    }
private:
    float re_;
    float im_;
};

int main(){ 
    int M;
    cout << "M=";
    cin >> M;
    DoubleLinkedList<Number> list;
    cout << "Podaj elementy do dodania=";
    for (int i = 0; i < M; i++){
        float re, im;
        cin >> re >> im;
        list.addElementToList(new Number(re, im));
    }
    list.printFromTheEndList();

    int N;
    cout << "N=";
    cin >> N;
    cout << "Podaj elementy do usuniecia=";
    for (int i = 0; i < N; i++){
        float re, im;
        cin >> re >> im;
        list.deleteElementFromList(new Number(re, im));
    }
    list.printFromTheEndList();
    return 0;
}
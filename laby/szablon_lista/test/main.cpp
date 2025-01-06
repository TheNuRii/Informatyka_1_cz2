#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <typename T>
class Container {
public:
    Container(T data, Container *next = nullptr, Container *prev = nullptr){
        prev_element_ = prev;
        Container_element_ = data;
        next_element_ = next;
    }
    T getContainerElement() const { 
        return Container_element_; 
    }
    Container* getNextElement() const {
        return next_element_;
    }
    Container* getPrevElement() const {
        return prev_element_;
    }
    void setContainerElement(T data) {
        Container_element_ = data;
    }
    void setNextElement(Container *next) {
        next_element_ = next;
    }
    void setPrevElement(Container *prev) {
        prev_element_ = prev;
    }

private:
    T Container_element_;
    Container* next_element_;
    Container* prev_element_;
};

template <typename T>
class DoubleLinkedList {
public:

     DoubleLinkedList(){
        linked_list_head_ = nullptr;
        linked_list_tail_ = nullptr;
    }

    ~DoubleLinkedList() {
        while (linked_list_head_ != nullptr) {
            Container<T> *temp = linked_list_head_;
            linked_list_head_ = linked_list_head_->getNextElement();
            delete temp;
        }
    }

    void addElementToList(const T& data) {
        Container<T>* newContainer = new Container<T>(data);

        if (!linked_list_head_) { 
            linked_list_head_ = linked_list_tail_ = newContainer;
            return;
        }

        Container<T>* current = linked_list_head_;
        while (current != nullptr && !(data <= current->getContainerElement())) {
            current = current->getNextElement();
        }

        if (!current) { 
            linked_list_tail_->setNextElement(newContainer);
            newContainer->setPrevElement(linked_list_tail_);
            linked_list_tail_ = newContainer;
        } else if (current == linked_list_head_) { 
            newContainer->setNextElement(linked_list_head_);
            linked_list_head_->setPrevElement(newContainer);
            linked_list_head_ = newContainer;
        } else { 
            Container<T>* prev = current->getPrevElement();
            prev->setNextElement(newContainer);
            newContainer->setPrevElement(prev);
            newContainer->setNextElement(current);
            current->setPrevElement(newContainer);
        }
    }

    void deleteElementFromList(const T& data) {
        if (!linked_list_head_) return;

        Container<T>* current = linked_list_head_;
        while (current && !(current->getContainerElement() == data)) {
            current = current->getNextElement();
        }

        if (!current) return;

        if (current == linked_list_head_) { 
            linked_list_head_ = linked_list_head_->getNextElement();
            if (linked_list_head_)
                linked_list_head_->setPrevElement(nullptr);
            else
                linked_list_tail_ = nullptr;
        } else if (current == linked_list_tail_) { 
            linked_list_tail_ = linked_list_tail_->getPrevElement();
            if (linked_list_tail_)
                linked_list_tail_->setNextElement(nullptr);
            else
                linked_list_head_ = nullptr;
        } else { 
            Container<T>* prev = current->getPrevElement();
            Container<T>* next = current->getNextElement();
            prev->setNextElement(next);
            next->setPrevElement(prev);
        }

        delete current;
    }

    void printFromTheEndList() const {
        Container<T>* temp = linked_list_tail_;
        while (temp) {
            cout << temp->getContainerElement() << " ";
            temp = temp->getPrevElement();
        }
        cout << endl;
    }

private:
    Container<T> *linked_list_head_;
    Container<T> *linked_list_tail_;
};

class Number {
public:
    Number(float re = 0, float im = 0) : re_(re), im_(im) {}

    float module() const {
        return sqrt(re_ * re_ + im_ * im_);
    }

    bool operator==(const Number& other) const {
        return (re_ == other.re_ && im_ == other.im_);
    }

    bool operator<=(const Number& other) const {
        return (module() <= other.module());
    }

    friend ostream& operator<<(ostream& os, const Number& number) {
        if (number.im_ > 0)
            os << number.re_ << "+" << number.im_ << "i";
        else if (number.im_ < 0)
            os << number.re_ << number.im_ << "i";
        else
            os << number.re_;
        return os;
    }

private:
    float re_;
    float im_;
};

int main() { 
    int M;
    cout << "M=";
    cin >> M;

    DoubleLinkedList<Number> list;

    cout << "Podaj elementy do dodania=";
    for (int i = 0; i < M; ++i) {
        float re, im;
        cin >> re >> im;
        list.addElementToList(Number(re, im));
    }

    list.printFromTheEndList();

    int N;
    cout << "N=";
    cin >> N;

    cout << "Podaj elementy do usuniecia=";
    for (int i = 0; i < N; ++i) {
        float re, im;
        cin >> re >> im;
        list.deleteElementFromList(Number(re, im));
    }

    list.printFromTheEndList();

    return 0;
}

#ifndef DOUBLELINKLIST_CPP
#define DOUBLELINKLIST_CPP

#include "doubleLinkList.h"
#include "node.h"
#include "iostream"

using namespace std;

template <typename T>
DoubleLinkList<T>::DoubleLinkList() {
    head_ = nullptr;
    tail_ = nullptr;
}

template <typename T>
DoubleLinkList<T>::~DoubleLinkList() {
    while (head_ != nullptr) {
        Container<T>* temp = head_;
        head_ = head_->getNextElement();
        delete temp;
    }
}

template <typename T>
void DoubleLinkList::addElementToList(const T& data) {
    Container<T>* newContainer = new Container<T>(data);
    if (head_ == nullptr) {
        head_ = tail_ = newContainer;
    }
    else {
        tail_->getNextElement() = newContainer;
        newContainer->prevElement_ = tail_;
        tail_ = newContainer;
    }
}

template <typename T>
void DoubleLinkList<T>::deleteElementFromList(T* data) {
    Container<T>* current = tail_;
    while (current != nullptr) {
        if (current->element_ == data) {
            if (current->getPrevElement() != nullptr) {
                current->getPrevElement()->getNextElement() = current->getNextElement();
            }
            else {
                head_ = current->getNextElement();
            }
            if (current->getNextElement() != nullptr) {
                current->getNextElement()->getPrevElement() = current->getPrevElement();
            }
            else {
                tail_ = current->getPrevElement();
            }
            delete current;
            return;
        }
        current = current->getPrevElement();
    }
}

template <typename T>
void DoubleLinkList<T>::printListFromTheEnd() {
    Container<T>* current = tail_;
    while (current != nullptr) {
        cout << current->element_ << " ";
        current = current->getPrevElement();
    }
    cout << endl;
}

#endif
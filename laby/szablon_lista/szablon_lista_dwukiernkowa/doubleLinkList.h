#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H

#include <iostream>

template <typename T>
class Container;

template <typename T>
class DoubleLinkList{
public:
    DoubleLinkList();
    ~DoubleLinkList();

    void addElementToList(const T& data);
    void deleteElementFromList(T* data);

    void printListFromTheEnd();

private:
    Container<T> * head_;
    Container<T> * tail_;
};

#include "doubleLinkList.cpp"

#endif
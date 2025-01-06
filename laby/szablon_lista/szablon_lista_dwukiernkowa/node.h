#ifndef CONTAINER_H
#define CONTAINER_H

template <typename T>
class Container{
public:
    Container(T* data, Container* next = nullptr, Container* prev = nullptr){
        element_ = data;
        next_element_ = next;
        prev_element_ = prev;
    }
    ~Container(){
        delete next_element_;
        delete prev_element_;
    }
private:
    Container* next_element_;
    Container* prev_element_;
    T element_;
};

#endif
#include "lista.h"

using namespace std;


// All declarations for the class Linker
Linker::Linker(Osoba **ptr, int next, int prev){
    ptr_element_ = ptr;
    next_element_ = next;
    prev_element_ = prev;
}

int Linker::getNextElement() const{
    return next_element_;
}

int Linker::getPrevElement() const{
    return prev_element_;
}

Osoba * Linker::getPtrElement() const{
    return ptr_element_;
}

// All declarations for the class ListaDwukiernukowa


ListaDwukiernukowa::ListaDwukiernukowa(){
    first_element_ = nullptr;
    last_element_ = nullptr;
}

ListaDwukiernukowa::~ListaDwukiernukowa(){
    deleteAllElements();
}

void ListaDwukiernukowa::deleteAllElements(){
    while(first_element_ != nullptr){
        delete first_element_;
        first_element_ = first_element_->getNextElement();
    }
}

void ListaDwukiernukowa::addElement(Osoba *ptr){
    if(first_element_ == nullptr){
        first_element_ = new Linker(&ptr, nullptr, nullptr);
        last_element_ = first_element_;
    }
    else{
        last_element_->setNextElement(new Linker(&ptr, nullptr, last_element_->getPrevElement()));
        last_element_ = last_element_->getNextElement();
    }
}

void ListaDwukiernukowa::deleteElement(string imie_osoby){
    Linker *temp = first_element_;
    while(temp != nullptr){
        if(temp->getPtrElement()->getImie() == imie_osoby){
            if(temp->getPrevElement() == nullptr){
                first_element_ = temp->getNextElement();
            }
            else{
                temp->getPrevElement()->setNextElement(temp->getNextElement());
            }
            if(temp->getNextElement() == nullptr){
                last_element_ = temp->getPrevElement();
            }
            else{
                temp->getNextElement()->setPrevElement(temp->getPrevElement());
            }
            delete temp;
            return;
        }
        temp = temp->getNextElement();
    }
}

void ListaDwukiernukowa::printFromTheBeginningList(){
    Linker *temp = first_element_;
    while(temp != nullptr){
        temp->getPtrElement()->wyswietlOsobe();
        cout << endl;
        temp = temp->getNextElement();
    }
}

void ListaDwukiernukowa::printFromTheEndList(){
    Linker *temp = last_element_;
    while(temp != nullptr){
        temp->getPtrElement()->wyswietlOsobe();
        cout << endl;
        temp = temp->getPrevElement();
    }
}
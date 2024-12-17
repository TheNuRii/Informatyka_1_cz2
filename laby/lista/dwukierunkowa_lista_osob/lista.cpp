#include "lista.h"

using namespace std;


// All declarations for the class Linker
Linker::Linker(Osoba * osoba, Linker * next = nullptr, Linker * prev = nullptr){
    ptr_element_ = osoba;
    next_element_ = next;
    prev_element_ = prev;
}


Linker * Linker::getNextElement() const{
    return next_element_;
}

Linker * Linker::getPrevElement() const{
    return prev_element_;
}

Osoba * Linker::getPtrElement() const{
    return ptr_element_;
}

void Linker::setNextElement(Linker * next){
    next_element_ = next;
}

void Linker::setPrevElement(Linker * prev){
    prev_element_ = prev;
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
        Linker *temp = first_element_;
        first_element_ = first_element_->getNextElement();
        delete temp;
    }
    last_element_ = nullptr;
}

void ListaDwukiernukowa::addElement(Osoba *osoba){
    Linker * new_element = new Linker(osoba);
    if(first_element_ == nullptr){
        last_element_ = first_element_ = new_element;
    }
    else{
        last_element_->setNextElement(new_element);
        new_element->setPrevElement(last_element_);
        last_element_ = new_element;
    }
}

void ListaDwukiernukowa::deleteElement(string imie_osoby){
    Linker *temp = first_element_;
    while(temp != nullptr){
        if(temp->getPtrElement()->getImieOsoby() == imie_osoby){
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
     cout << "Nie znaleziono osoby o imieniu: " << imie_osoby << endl;
}

void ListaDwukiernukowa::printFromTheBeginningList(){
    Linker *temp = first_element_;
    while(temp != nullptr){
        cout << *(temp->getPtrElement()) << "-> ";
        temp = temp->getNextElement();
    }
    cout << "null" << endl;
}

void ListaDwukiernukowa::printFromTheEndList(){
    Linker *temp = last_element_;
    while(temp != nullptr){
       cout << *(temp->getPtrElement()) << "-> ";
       temp = temp->getPrevElement();
    }
    cout << "null" << endl;
}
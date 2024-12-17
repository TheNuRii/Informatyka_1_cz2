#pragma once
#include "string"
#include "osoba.cpp"

using namespace std;

class Linker{
public:
    Linker(Osoba* osoba, Linker* next, Linker* prev);
    ~Linker();

    Linker * getNextElement() const;
    Linker * getPrevElement() const;
    Osoba * getPtrElement() const;

    void setNextElement(Linker* next);
    void setPrevElement(Linker* prev);
private:
    Linker * next_element_;
    Linker * prev_element_;
    Osoba* ptr_element_;
};

class ListaDwukiernukowa{
public:
    ListaDwukiernukowa();
    ~ListaDwukiernukowa();

    void addElement(Osoba * osoba);
    void deleteElement(string imie_osoby);
    void deleteAllElements();

    void printFromTheBeginningList();
    void printFromTheEndList();

private:
    Linker *first_element_;
    Linker *last_element_;
};
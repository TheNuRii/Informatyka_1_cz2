#pragma once
#include "string"
#include "osoba.cpp"

using namespace std;

class Linker{
public:
    Linker(Osoba **ptr, int next, int prev);

    int getNextElement() const;
    int getPrevElement() const;
    Osoba * getPtrElement() const;
private:
    int next_element_;
    int prev_element_;
    Osoba ** ptr_element_;
};

class ListaDwukiernukowa{
public:
    ListaDwukiernukowa();
    ~ListaDwukiernukowa();

    void addElement(Osoba *ptr);
    void deleteElement(string imie_osoby);
    void deleteAllElements();
    void printFromTheBeginningList();
    void printFromTheEndList();
private:
    Linker *first_element_;
    Linker *last_element_;
};
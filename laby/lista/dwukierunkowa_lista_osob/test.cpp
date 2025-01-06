#include <iostream>
#include <string>

using namespace std;

class Osoba {
private:
    string imie;
    int wiek;

public:
    Osoba(string imie, int wiek) : imie(imie), wiek(wiek) {}

    string getImie() const { return imie; }
    int getWiek() const { return wiek; }

    friend ostream& operator<<(ostream& os, const Osoba& osoba) {
        os << osoba.imie << " (" << osoba.wiek << " l.)";
        return os;
    }
};

class Node {
private:
    Osoba* osoba;
    Node* next;
    Node* prev;

public:
    Node(Osoba* osoba, Node* next = nullptr, Node* prev = nullptr)
        : osoba(osoba), next(next), prev(prev) {}

    ~Node() { delete osoba; }

    Node* getNext() const { return next; }
    Node* getPrev() const { return prev; }
    Osoba* getOsoba() const { return osoba; }

    void setNext(Node* n) { next = n; }
    void setPrev(Node* p) { prev = p; }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() { clear(); }

    void addPerson(Osoba* osoba) {
        Node* newNode = new Node(osoba);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->setNext(newNode);
            newNode->setPrev(tail);
            tail = newNode;
        }
    }

    void removePersonByName(const string& imie) {
        Node* current = tail;
        while (current) {
            if (current->getOsoba()->getImie() == imie) {
                if (current->getPrev()) current->getPrev()->setNext(current->getNext());
                if (current->getNext()) current->getNext()->setPrev(current->getPrev());

                if (current == head) head = current->getNext();
                if (current == tail) tail = current->getPrev();

                delete current;
                return;
            }
            current = current->getPrev();
        }
        cout << "Nie znaleziono osoby o imieniu: " << imie << endl;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->getNext();
            delete temp;
        }
        tail = nullptr;
    }

    void displayFromStart() const {
        Node* current = head;
        cout << "Lista od poczatku: ";
        while (current) {
            cout << *(current->getOsoba()) << " -> ";
            current = current->getNext();
        }
        cout << "null" << endl;
    }

    void displayFromStartAfter() const {
        Node* current = head;
        cout << "Lista od poczatku po usunieciu: ";
        while (current) {
            cout << *(current->getOsoba()) << " -> ";
            current = current->getNext();
        }
        cout << "null" << endl;
    }

    void displayFromEndAfter() const {
        Node* current = tail;
        cout << "Lista od konca po usunieciu: ";
        while (current) {
            cout << *(current->getOsoba()) << " -> ";
            current = current->getPrev();
        }
        cout << "null" << endl;
    }

    void displayFromEnd() const {
        Node* current = tail;
        cout << "Lista od konca: ";
        while (current) {
            cout << *(current->getOsoba()) << " -> ";
            current = current->getPrev();
        }
        cout << "null" << endl;
    }

    void displayFromEndClear() const {
        Node* current = tail;
        while (current) {
            cout << *(current->getOsoba()) << " -> ";
            current = current->getPrev();
        }
        cout << "null" << endl;
    }
};

int main() {
    DoublyLinkedList list;
    int m, wiek;
    string imie;

    cout << "Podaj liczbe osob do dodania (M): ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        cout << "Podaj imie: ";
        cin >> imie;
        cout << "Podaj wiek: ";
        cin >> wiek;

        list.addPerson(new Osoba(imie, wiek));
    }

    list.displayFromStart();
    list.displayFromEnd();

    cout << "Podaj imie osoby do usuniecia: ";
    cin >> imie;
    list.removePersonByName(imie);

    list.displayFromStartAfter();
    list.displayFromEndAfter();

    list.clear();
    cout << "Lista od konca po wyczyszczeniu: ";
    list.displayFromEndClear();
}
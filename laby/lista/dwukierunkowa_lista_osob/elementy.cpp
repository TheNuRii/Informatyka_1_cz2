#include <iostream>
#include <cassert>


using namespace std;

class Osoba{
    private:
        string imie_osoby_;
        int wiek_osoby_;
    public:
        Osoba(string imie, int wiek){
            imie_osoby_ = imie;
            wiek_osoby_ = wiek;}
        string getImieOsoby() const{
            return imie_osoby_;
        }
        int getWiekOsoby() const{
            return wiek_osoby_;
        }

        friend ostream& operator<<(ostream& out, const Osoba& osoba) {
            out << osoba.imie_osoby_ << " (" << osoba.wiek_osoby_ << " l.)";
            return out;
        }

};

class Linker{
public:
    Linker(Osoba* ptr, Linker* next = nullptr, Linker* prev = nullptr){
        ptr_element_ = ptr;
        next_element_ = next;
        prev_element_ = prev;
    };
    ~Linker(){
        delete ptr_element_;
    }

    Linker * getNextElement() const{
        return next_element_;    
    }
    Linker * getPrevElement() const{
        return prev_element_;
    }
    Osoba * getPtrElement() const{
        return ptr_element_;}

    void setNextElement(Linker* next){
        next_element_ = next;
    }
    void setPrevElement(Linker* prev){
        prev_element_ = prev;
    }
private:
    Linker * next_element_;
    Linker * prev_element_;
    Osoba* ptr_element_;
};

class ListaDwukierunkowa{
public:
    ListaDwukierunkowa(){
        first_element_ = nullptr;
        last_element_ = nullptr;
    }
    ~ListaDwukierunkowa(){
        deleteAllElements();
    }

    void addElement(Osoba * osoba){
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
    void deleteElement(string imie_osoby){
    Linker* temp = last_element_;
        while (temp != nullptr) {
            if (temp->getPtrElement()->getImieOsoby() == imie_osoby) {
                if (temp->getPrevElement()) {
                    temp->getPrevElement()->setNextElement(temp->getNextElement());
                }
                if (temp->getNextElement()) {
                    temp->getNextElement()->setPrevElement(temp->getPrevElement());
                }

                if (temp == first_element_) first_element_ = temp->getNextElement();
                if (temp == last_element_) last_element_ = temp->getPrevElement();

                delete temp;
                return;
            }
            temp = temp->getPrevElement();
        }
        cout << "Nie znaleziono osoby o imieniu: " << imie_osoby << endl;
    }

    void deleteAllElements(){
    while(first_element_ != nullptr){
        Linker *temp = first_element_;
        first_element_ = first_element_->getNextElement();
        delete temp;
    }
    last_element_ = nullptr;
    }

   

    void printFromTheBeginningList(){
    Linker *temp = first_element_;
    while(temp != nullptr){
        cout << *(temp->getPtrElement()) << " -> ";
        temp = temp->getNextElement();
    }
    cout << "null" << endl;
    }
    void printFromTheEndList(){
    Linker *temp = last_element_;
    while(temp != nullptr){
       cout << *(temp->getPtrElement()) << " -> ";
       temp = temp->getPrevElement();
    }
    cout << "null" << endl;
    }

private:
    Linker *first_element_;
    Linker *last_element_;
};


int main() {
    ListaDwukierunkowa list;
    int m, wiek;
    string imie;

    cout << "Podaj liczbe osob do dodania (M): ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        cout << "Podaj imie: ";
        cin >> imie;
        cout << "Podaj wiek: ";
        cin >> wiek;

        list.addElement(new Osoba(imie, wiek));
    }
    
    cout << "Lista od poczatku: ";
    list.printFromTheBeginningList();
    cout << "Lista od konca: ";
    list.printFromTheEndList();

    cout << "Podaj imie osoby do usuniecia: ";
    cin >> imie;
    list.deleteElement(imie);

    cout << "Lista od poczatku po usunieciu: ";
    list.printFromTheBeginningList();
    cout << "Lista od konca po usunieciu: ";
    list.printFromTheEndList();

    list.deleteAllElements();
    cout << "Lista od konca po wyczyszczeniu: ";
    list.printFromTheEndList();
}
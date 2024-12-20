#include <iostream>
#include <cassert>

using namespace std;

class Produkt{
public:
    Produkt(float cena, string nazwa){
        cena_produktu_ = cena;
        nazwa_produktu_ = nazwa;
    }

    ~Produkt(){
    }

    bool operator==(const Produkt &produkt){
        if(int(nazwa_produktu_[0]) == int(produkt.nazwa_produktu_[0]) && cena_produktu_ == produkt.cena_produktu_){
            return true;
        }
        return false;
    }

    bool operator<(const Produkt &produkt){
        if(int(nazwa_produktu_[0]) == int(produkt.nazwa_produktu_[0])){
            return cena_produktu_ < produkt.cena_produktu_; 
        }
        return int(nazwa_produktu_[0]) >  int(produkt.nazwa_produktu_[0]);
    }    

    friend ostream& operator<<(ostream& out, const Produkt &produkt){
        out << '[' << produkt.nazwa_produktu_ << ',' << produkt.cena_produktu_ << ']';
        return out;
    }

private:
    float cena_produktu_;
    string nazwa_produktu_;
};

template <typename T>
class Node{
public:
    Node(T* data, Node* next = nullptr){
        node_element_ = data;
        next_element_ = next;
    }
    ~Node(){
        delete node_element_;
    }

    T* getNodeElement() const {
        return node_element_;
    }

    Node* getNextElement() const{
        return next_element_;
    }

    void setNodeElement(T* data){
        node_element_ = data;
    }    

    void setNextElement(Node* next){
        next_element_ = next;
    }
private:
    T* node_element_;
    Node* next_element_;
};

template <typename T>
class LinkedList{
public:
    LinkedList(){
        linked_list_head_ = nullptr;
    }

    ~LinkedList(){
        while(linked_list_head_ != nullptr){
            Node<T>* temp = linked_list_head_;
            linked_list_head_ = linked_list_head_->getNextElement();
            delete temp;
        }
    }

    void addElementToList(T* data){
        Node<T>* next = nullptr;
        Node<T>* prev = nullptr; 
        if(linked_list_head_ == nullptr){
            linked_list_head_ = new Node<T>(data, next);
            return;
        }
        else{
            if(*data < *linked_list_head_->getNodeElement()){
                linked_list_head_ = new Node<T>(data, linked_list_head_);
                return;
            }
            prev = linked_list_head_;
            for(next = linked_list_head_->getNextElement(); next; ){
                if(*data < *next->getNodeElement()){
                    prev->setNextElement(new Node<T>(data, next));
                    return;
                }
                prev = next;
                next = next->getNextElement();
            }
            prev->setNextElement(new Node<T>(data, next));
        }
    }

    void deleteElementFromList(T* data){
        Node<T>* temp = linked_list_head_;
        while(temp != nullptr){
            if(temp->getNodeElement() == data){
                temp->getNextElement()->setNextElement(temp->getNextElement());
                delete temp;
                return;
            }
            temp = temp->getNextElement();
        }
    }   

    void printFromTheBeginningList(){
        Node<T>* temp = linked_list_head_;
        while(temp != nullptr){
            cout << ' ' << *(temp->getNodeElement());
            temp = temp->getNextElement();
        }
        cout << endl;
    }
private:
    Node<T>* linked_list_head_;
};

int main(){
    LinkedList<Produkt> lista;
    int M;

    cout << "M=";
    cin >> M;

    for(int i = 0; i < M; i++){
        float cena_nowego_produktu;
        string nazwa_nowego_produktu;
        cout << "nazwa cena:";
        cin >> cena_nowego_produktu >> nazwa_nowego_produktu;
        Produkt * element = new Produkt(cena_nowego_produktu, nazwa_nowego_produktu);
        lista.addElementToList(element);
    }

    lista.printFromTheBeginningList();

    int N;
    cout << "N=";
    cin >> N;

    for(int i = 0; i < N; i++){ 
        float cena_usunietego_produktu;
        string nazwa_usunietego_produktu;
        cout << "nazwa cena:";
        cin >> cena_usunietego_produktu >> nazwa_usunietego_produktu;
        Produkt * element_do_usuniecia = new Produkt(cena_usunietego_produktu, nazwa_usunietego_produktu);
        lista.deleteElementFromList(element_do_usuniecia);
    }

    lista.printFromTheBeginningList();
    return 0;
}
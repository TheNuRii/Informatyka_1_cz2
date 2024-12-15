#include "iostream"
#include "cassert"


using namespace std;

class Link {
public:
    Link * wprowadzWartosc(double wartosc){
        nastepna_komurka_listy_ = new Link(wartosc, nastepna_komurka_listy_);
        return nastepna_komurka_listy_;
    }

    double getWartosc() const{
        return  wartosc_;
    }

    Link * getNastepnaKomurkaListy() const{
        return nastepna_komurka_listy_;
    }

    friend class Lista;

private:
    double wartosc_;
    Link *nastepna_komurka_listy_;

    Link(double wartosc, Link *wskaznik){
        wartosc_ = wartosc;
        nastepna_komurka_listy_ = wskaznik;
    }   
};

class Lista {
public:
    Lista() {
        pierwsza_wartosc_ = NULL;
    }

    virtual void dodajWartoscDoListy(double wartosc){
        pierwsza_wartosc_ = new Link(wartosc, pierwsza_wartosc_);
    }

    virtual void usunListe(){
        Link *nastepne;
        for (Link *ptr = pierwsza_wartosc_; ptr; ptr = nastepne){
            nastepne = ptr->nastepna_komurka_listy_;
            delete ptr;
        }

        pierwsza_wartosc_ = nullptr;
    }


    double pierwszyElementWLiscie() const{
        assert(pierwsza_wartosc_ != nullptr);
        return pierwsza_wartosc_ -> wartosc_;
    }

    virtual void usunWskazanaWartosc(double wartosc){
        for (Link *ptr = pierwsza_wartosc_; ptr; ptr = ptr->nastepna_komurka_listy_){
            if(wartosc == ptr->wartosc_){
                assert(pierwsza_wartosc_ != nullptr);
                Link *wskaznik_na_wartosc = pierwsza_wartosc_;
                pierwsza_wartosc_ = wskaznik_na_wartosc->nastepna_komurka_listy_;
                delete wskaznik_na_wartosc;
            }
        }
       
    }

    bool czyPusta() const{
        return pierwsza_wartosc_ == nullptr;
    }

    friend ostream& operator<<(ostream &out, const Lista&podana_lista) {
    out << podana_lista.pierwsza_wartosc_->getWartosc() << ' ';
    Link* temp = podana_lista.pierwsza_wartosc_;
        while (temp) {
            out << temp->getWartosc() << ' ';
            temp = temp->getNastepnaKomurkaListy();
        }
    return out;  
    }

    friend class Iterator;

protected:
    Link *pierwsza_wartosc_;
};

class Iterator{
public:
    Iterator(Lista &podana_lista);
    
    virtual bool init(){
    poprzednia_komurka_ =nullptr;
    poprzednia_komurka_ = iterowana_lista_.pierwsza_wartosc_;
    return poprzednia_komurka_ != nullptr;
    }


protected:
    Lista &iterowana_lista_;
    Link *poprzednia_komurka_;
    Link *komurka_na_ktorej_sie_znajdujemy_;
};



int main(){
    int M;
    cout << "Podaj liczbe elementow do dodania (M):";
    cin >> M;

    Lista lista;
    for(int i = 0; i < M; i++){
        cout << "Podaj wartosc do dodania:";
        double wartosc;
        cin >> wartosc;
        lista.dodajWartoscDoListy(wartosc);
    }

    cout << "Lista:" << lista << '\n';

    int N;
    cout << "Podaj liczbe elementow do usuniecia (N):";
    cin >> N;

    for(int i = 0; i < N; i++){
        cout << "Podaj wartosc do usuniecia:";
        double wartosc;
        cin >> wartosc;
        lista.usunWskazanaWartosc(wartosc);
    }

    cout << "Lista:" << lista << '\n';

    int L;
    cout << "Podaj liczbe elementow do dodania (L):";
    cin >> L;

    for(int i = 0; i < L; i++){
        cout << "Podaj wartosc do dodania:";
        double wartosc;
        cin >> wartosc;
        lista.dodajWartoscDoListy(wartosc);
    }

    cout << "Lista:" << lista << '\n';

    lista.usunListe();

    cout << "Lista:" << lista << '\n';
    return 0;
}
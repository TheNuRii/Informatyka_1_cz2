#include <iostream>
#include <iomanip>
using namespace std;

class Pracownik {
private:
    string imie_pracownika_;
    string nazwisko_pracowniak_;
    double pensja_pracownika_;

public:
    Pracownik(const string& imie, const string& nazwisko, double pensja){
        imie_pracownika_ = imie;
        nazwisko_pracowniak_ = nazwisko;
        pensja_pracownika_ = pensja;
    }
        

    double getPensja() const {
        return pensja_pracownika_;
    }

    friend ostream& operator<<(ostream& os, const Pracownik& pracownik) {
        os << '|' << pracownik.imie_pracownika_ << ' ' << pracownik.nazwisko_pracowniak_ << ": "
           << fixed << setprecision(2) << pracownik.pensja_pracownika_ << " PLN|";
        return os;
    }
};

class Dzial {
private:
    Pracownik** pracownicy_konkretnego_dzialu_;
    string nazwa_dzialu_;
    int maksymalna_liczba_pracownikow_;
    int aktualna_liczba_pracownikow_;

public:
    Dzial(const string& nazwa_dzialu, int maks_pracownicy){
        nazwa_dzialu_ = nazwa_dzialu;
         maksymalna_liczba_pracownikow_ = maks_pracownicy;
        aktualna_liczba_pracownikow_ = 0;
        pracownicy_konkretnego_dzialu_ = new Pracownik*[maks_pracownicy];
    }

    Dzial(const Dzial& other){
        nazwa_dzialu_ = other.nazwa_dzialu_;
        maksymalna_liczba_pracownikow_ = other.maksymalna_liczba_pracownikow_;
        aktualna_liczba_pracownikow_ = other.aktualna_liczba_pracownikow_;
        pracownicy_konkretnego_dzialu_ = new Pracownik*[maksymalna_liczba_pracownikow_];
        for (int i = 0; i < aktualna_liczba_pracownikow_; ++i) {
            pracownicy_konkretnego_dzialu_[i] = new Pracownik(*other.pracownicy_konkretnego_dzialu_[i]);
        }
    }

    ~Dzial() {
        for (int i = 0; i < aktualna_liczba_pracownikow_; ++i) {
            delete pracownicy_konkretnego_dzialu_[i];
        }
        delete[] pracownicy_konkretnego_dzialu_;
    }

    Dzial& operator=(const Dzial& other) {
        if (this != &other) {
            for (int i = 0; i < aktualna_liczba_pracownikow_; ++i) {
                delete pracownicy_konkretnego_dzialu_[i];
            }
            delete[] pracownicy_konkretnego_dzialu_;

            nazwa_dzialu_ = other.nazwa_dzialu_;
            maksymalna_liczba_pracownikow_ = other.maksymalna_liczba_pracownikow_;
            aktualna_liczba_pracownikow_ = other.aktualna_liczba_pracownikow_;

            pracownicy_konkretnego_dzialu_ = new Pracownik*[maksymalna_liczba_pracownikow_];
            for (int i = 0; i < aktualna_liczba_pracownikow_; ++i) {
                pracownicy_konkretnego_dzialu_[i] = new Pracownik(*other.pracownicy_konkretnego_dzialu_[i]);
            }
        }
        return *this;
    }

    Dzial& operator+=(Pracownik* pracownik) {
        if (aktualna_liczba_pracownikow_ < maksymalna_liczba_pracownikow_) {
            pracownicy_konkretnego_dzialu_[aktualna_liczba_pracownikow_++] = pracownik;
        }
        return *this;
    }

    Dzial& operator-=(Pracownik* pracownik) {
        for (int i = 0; i < aktualna_liczba_pracownikow_; i++) {
            if (pracownicy_konkretnego_dzialu_[i] == pracownik) {
                delete pracownicy_konkretnego_dzialu_[i];
                for (int j = i; j < aktualna_liczba_pracownikow_ - 1; j++) {
                    pracownicy_konkretnego_dzialu_[j] = pracownicy_konkretnego_dzialu_[j + 1];
                }
                aktualna_liczba_pracownikow_--;
                break;
            }
        }
        return *this;
    }

    Pracownik* operator[](int index) const {
        if (index >= 0 && index < aktualna_liczba_pracownikow_) {
            return pracownicy_konkretnego_dzialu_[index];
        }
        return nullptr;
    }

    double sumaPensji() const {
        double suma = 0.0;
        for (int i = 0; i < aktualna_liczba_pracownikow_; ++i) {
            suma += pracownicy_konkretnego_dzialu_[i]->getPensja();
        }
        return suma;
    }

    friend ostream& operator<<(ostream& os, const Dzial& dzial) {
        os << "Dzial: " << dzial.nazwa_dzialu_ << endl;
        os << "Pracownicy:" << endl;
        for (int i = 0; i < dzial.aktualna_liczba_pracownikow_; ++i) {
            os << *dzial.pracownicy_konkretnego_dzialu_[i] << ' ';
        }
        os << '\n' <<"Suma pensji: " << fixed << setprecision(2) << dzial.sumaPensji() << " PLN" << '\n';
        return os;
    }
};

int main() {
    int liczba_pracownikow;
    string nazwa_dzialu;
    
    cout << "Liczba pracownikow: ";
    cin >> liczba_pracownikow;
    cout << "Nazwa dzialu: ";
    cin >> nazwa_dzialu;
    
    string imie, nazwisko;
    double pensja;
    
    Dzial dzial(nazwa_dzialu, liczba_pracownikow);
    
    // Tworzenie obiektów pracowników i dodawanie do dzialu
    for (int i = 0; i < liczba_pracownikow; i++)
    {
        cout << "Podaj imie, nazwisko i pensje: ";
        cin >> imie >> nazwisko >> pensja;
        Pracownik* p = new Pracownik(imie, nazwisko, pensja);
        dzial += p;
    }

    // Test konstruktora kopiującego
    Dzial dzialKopia = dzial; // użycie konstruktora kopiującego
    cout << "Kopia dzialu (konstruktor kopiujacy):" << endl;
    cout << dzialKopia;

    // Test operatora przypisania
    Dzial dzialPrzypisany("IT", 2);
    dzialPrzypisany = dzial; // użycie operatora przypisania
    cout << "Dzial po przypisaniu (operator przypisania):" << endl;
    cout << dzialPrzypisany;

    // Modyfikacja oryginalnego działu i sprawdzenie efektu na kopii i przypisaniu
    dzial -= dzial[liczba_pracownikow/2]; // Usuwamy pracownika z oryginalnego działu

    cout << "\nPo usunieciu pracownika z oryginalnego dzialu:" << endl;
    cout << "Oryginalny dzial:" << endl;
    cout << dzial;
    cout << "Kopia dzialu (konstruktor kopiujacy):" << endl;
    cout << dzialKopia;
    cout << "Dzial po przypisaniu (operator przypisania):" << endl;
    cout << dzialPrzypisany;

    return 0;
}
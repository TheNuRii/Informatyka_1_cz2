#include <iostream>
using namespace std;

class Laptop {
private:
    std::string marka;
    std::string model;
    std::string procesor;
    int pamiec_RAM;
    int pojemnosc_dysku;
public:
    Laptop(std::string marka, std::string model, std::string procesor, int pamiec_RAM, int pojemnosc_dysku){
        this->marka = marka;
        this->model =  model;
        this->procesor = procesor;
        this->pamiec_RAM = pamiec_RAM;
        this->pojemnosc_dysku = pojemnosc_dysku;
    }
    void pokaz_specyfikacje(){
        cout << marka << " " << model << " " << procesor << " " << pamiec_RAM << " " << pojemnosc_dysku << endl;
    }

    void zmien_pamiec_RAM(int nowa_pamiec_RAM){
        this->pamiec_RAM = nowa_pamiec_RAM;
    }

    void zmien_pojemnosc_dysku(int nowa_pojemnosc_dysku){
        this->pojemnosc_dysku = nowa_pojemnosc_dysku;
    }

    void setLaptop(std::string marka, std::string model, std::string procesor, int pamiec_RAM, int pojemnosc_dysku){
        this->marka = marka;
        this->model =  model;
        this->procesor = procesor;
        this->pamiec_RAM = pamiec_RAM;
        this->pojemnosc_dysku = pojemnosc_dysku;
    }
};

class Smartfon {
private:
    std::string marka;
    std::string model;
    std::string system_operacyjny;
    int pamiec_RAM;
    float rozmiar_ekranu;
public:
    Smartfon(std::string marka, std::string model, std::string system_operacyjny, int pamiec_RAM, float rozmiar_ekranu){
        this->marka = marka;
        this->model =  model;
        this->system_operacyjny = system_operacyjny;
        this->pamiec_RAM = pamiec_RAM;
        this->rozmiar_ekranu = rozmiar_ekranu;
    }
    void pokaz_dane(){
        cout << marka << " " << model << " " << system_operacyjny << " " << pamiec_RAM << " " << rozmiar_ekranu << endl;
    }

    void zmien_system_operacyjny(std::string nowy_system_operacyjny){
        this->system_operacyjny = nowy_system_operacyjny;
    }

    void zmien_pamiec_RAM(int nowa_pamiec_RAM){
        this->pamiec_RAM = nowa_pamiec_RAM;
    }

    void setSmartfon(std::string marka, std::string model, std::string system_operacyjny, int pamiec_RAM, float rozmiar_ekranu){
        this->marka = marka;
        this->model =  model;
        this->system_operacyjny = system_operacyjny;
        this->pamiec_RAM = pamiec_RAM;
        this->rozmiar_ekranu = rozmiar_ekranu;
    }
};

class Rower {
private:
    std::string marka;
    std::string model;
    std::string typ_roweru;
    int liczba_biegow;
    float waga;
public:
    Rower(std::string marka, std::string model, std::string typ_roweru, int liczba_biegow, float waga){
        this->marka = marka;
        this->model =  model;
        this->typ_roweru = typ_roweru;
        this->liczba_biegow = liczba_biegow;
        this->waga = waga;
    }
    Rower(){
        this->marka = "Kross";
        this->model =  "Hexagon";
        this->typ_roweru = "Gorski";
        this->liczba_biegow = 21;
        this->waga = 12.5;
    }

    void pokaz_dane(){
        cout << marka << " " << model << " " << typ_roweru << " " << liczba_biegow << " " << waga << endl;
    }

    void zmien_typ_roweru(std::string nowy_typ_roweru){
        this->typ_roweru = nowy_typ_roweru;
    }

    void zmien_liczbe_biegow(int nowa_liczba_biegow){
        this->liczba_biegow = nowa_liczba_biegow;
    }

    void zmien_wage(float nowa_waga){
        this->waga = nowa_waga;
    }
};

int main(){
    int zadanie;
    std::string marka;
    std::string model;
    std::string procesor;
    int pamiec_RAM;
    int pojemnosc_dysku;
    std::string system_operacyjny;
    float rozmiar_ekranu;
    std::string typ_roweru;
    int liczba_biegow;
    float waga;
    int nowa_pamiec_RAM;
    int nowa_pojemnosc_dysku;
    std::string nowy_system_operacyjny;
    std::string nowy_typ_roweru;
    int nowa_liczba_biegow;
    float nowa_waga;

    Laptop laptop(marka, model, procesor, pamiec_RAM, pojemnosc_dysku);
    Smartfon smartfon(marka, model, system_operacyjny, pamiec_RAM, rozmiar_ekranu);
    Rower rower;

    cin >> zadanie;

    switch(zadanie){
        case 1:
            cout << "Podaj specyfikacje laptopa=";
            cin >> marka;
            cin >> model;
            cin >> procesor;
            cin >> pamiec_RAM;
            cin >> pojemnosc_dysku;

            laptop.setLaptop(marka, model, procesor, pamiec_RAM, pojemnosc_dysku);
            laptop.pokaz_specyfikacje();

            cout << "RAM=";
            cin >> nowa_pamiec_RAM;
            laptop.zmien_pamiec_RAM(nowa_pamiec_RAM);

            cout << "Dysk=";
            cin >> nowa_pojemnosc_dysku;
            laptop.zmien_pojemnosc_dysku(nowa_pojemnosc_dysku);

            laptop.pokaz_specyfikacje();
            break;
        case 2:
            cout << "Podaj specyfikacje smartfona=";
            cin >> marka;
            cin >> model;
            cin >> system_operacyjny;
            cin >> pamiec_RAM;
            cin >> rozmiar_ekranu;

            smartfon.setSmartfon(marka, model, system_operacyjny, pamiec_RAM, rozmiar_ekranu);
            smartfon.pokaz_dane();

            cout << "OS=";
            cin >> nowy_system_operacyjny;
            smartfon.zmien_system_operacyjny(nowy_system_operacyjny);

            cout << "RAM=";
            cin >> nowa_pamiec_RAM;
            smartfon.zmien_pamiec_RAM(nowa_pamiec_RAM);

            smartfon.pokaz_dane();
            break;
        case 3:
            rower.pokaz_dane();

            cout << "Typ=";
            cin >> nowy_typ_roweru;
            rower.zmien_typ_roweru(nowy_typ_roweru);

            cout << "Liczba biegow=";
            cin >> nowa_liczba_biegow;
            rower.zmien_liczbe_biegow(nowa_liczba_biegow);

            cout << "Waga=";
            cin >> nowa_waga;
            rower.zmien_wage(nowa_waga);

            rower.pokaz_dane();
            break;
        default:
            cout << "Niepoprawny numer zadania" << endl;
    }
    return 0;
}

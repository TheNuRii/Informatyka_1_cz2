#include "iostream"

using namespace std;

class Laptop{
public: 
    Laptop(string marka, string model, string procesor, int pamiec_RAM, int pojemnosc_dysku)
    : marka_laptopa_(marka), model_laptopa_(model), procesor_laptopa_(procesor), pamiec_RAM_laptopa_(pamiec_RAM), pojemnosc_dysku_laptopa_(pojemnosc_dysku){}
    
    void pokarzSpecyfikacjeLaptopa(){
        cout << marka_laptopa_ << ' ' << model_laptopa_ << ' ' << procesor_laptopa_ << ' ';
        cout << pamiec_RAM_laptopa_ << ' ' << pojemnosc_dysku_laptopa_ << '\n';
    }
    
    void setPamiecRam(int nowa_pamiec_RAM){
        pamiec_RAM_laptopa_ = nowa_pamiec_RAM;
    }

    void setPojemoscDysku(int nowa_pojemnosc_dysku){
        pojemnosc_dysku_laptopa_ = nowa_pojemnosc_dysku;
    }

private:
    string marka_laptopa_;
    string model_laptopa_;
    string procesor_laptopa_;
    int pamiec_RAM_laptopa_; 
    int pojemnosc_dysku_laptopa_;
};

class Smartfon{
public:
    Smartfon(string marka, string model, string system_operacyjny, int pamiec_RAM, float rozmiar_ekranu){
        marka_telefonu_ = marka;
        model_telefonu_ = model;
        system_operacyjny_telefonu_ = system_operacyjny;
        pamiec_RAM_telefonu_ = pamiec_RAM;
        rozmiar_ekranu_telefonu_ = rozmiar_ekranu;
    }

    void pokazDaneTelefonu(){
        cout << marka_telefonu_ << ' ' << model_telefonu_ << ' ' << system_operacyjny_telefonu_ << ' ';
        cout  << pamiec_RAM_telefonu_ << ' ' << rozmiar_ekranu_telefonu_ << '\n';
    }

    void setSystemOpercyjny(string nowy_system_operacyjny){
        system_operacyjny_telefonu_ = nowy_system_operacyjny;
    }

    void setPamiecRam(int nowa_pamiec_RAM){
        pamiec_RAM_telefonu_ = nowa_pamiec_RAM;
    }
private:
    string marka_telefonu_;
    string model_telefonu_;
    string system_operacyjny_telefonu_;
    int pamiec_RAM_telefonu_;
    float rozmiar_ekranu_telefonu_;
};

class Rower{
public:
    Rower(string marka, string model, string typ, int liczba_biegow, float waga){
        marka_roweru_ = marka;
        model_roweru_ = model;
        typ_roweru_ = typ;
        liczba_biegow_ = liczba_biegow;
        waga_roweru_ = waga;
    }

    Rower(){
        marka_roweru_ = "Kross";
        model_roweru_ = "Hexagon";
        typ_roweru_ = "Gorkski";
        liczba_biegow_ = 21;
        waga_roweru_ = 12.5;
    }

    void pokazdDaneRoweru(){
        cout << marka_roweru_ << ' ' << model_roweru_ << ' ' << typ_roweru_ << ' ';
        cout << liczba_biegow_ << ' ' << waga_roweru_ << '\n'; 
    }

    void setTypRoweru(string nowy_typ){
        typ_roweru_ = nowy_typ;
    }

    void setLiczbeBiego(int nowa_liczba_biegow){
        liczba_biegow_ = nowa_liczba_biegow;
    }

    void setWagaRoweru(float nowa_waga){
        waga_roweru_ = nowa_waga;
    }
private:
    string marka_roweru_;
    string model_roweru_;
    string typ_roweru_;
    int liczba_biegow_;
    float waga_roweru_;
};

int  main(){
int wybierz_przedmiot;
cin >> wybierz_przedmiot;

switch (wybierz_przedmiot)
{
    case 1:{
        string marka_laptopa, model_laptopa, procesor_laptopa;
        int pamiec_RAM, pojemnosc_dysku;
        
        cout << "Podaj specyfikacje laptopa=";
        cin >> marka_laptopa >> model_laptopa >> procesor_laptopa;
        cin >> pamiec_RAM >> pojemnosc_dysku;

        Laptop nowy_laptop = Laptop(marka_laptopa, model_laptopa, procesor_laptopa, pamiec_RAM, pojemnosc_dysku);

        nowy_laptop.pokarzSpecyfikacjeLaptopa();
        
        int nowa_pamiec_RAM, nowa_pojemnosc_dysku;
        cout << "RAM=";
        cin >> nowa_pamiec_RAM;
        nowy_laptop.setPamiecRam(nowa_pamiec_RAM);

        cout << "Dysk=";
        cin >> nowa_pojemnosc_dysku;
        nowy_laptop.setPojemoscDysku(nowa_pojemnosc_dysku);

        nowy_laptop.pokarzSpecyfikacjeLaptopa();
        break;
    }

    case 2:{
        string marka, model, system_operacyjny;
        int pamiec_RAM;
        float rozmiar_ekranu;

        cout << "Podaj specyfikacje smartfoan=";
        cin >> marka >> model >> system_operacyjny;
        cin >> pamiec_RAM >> rozmiar_ekranu;

        Smartfon nowy_smartfon = Smartfon(marka, model, system_operacyjny, pamiec_RAM, rozmiar_ekranu);

        nowy_smartfon.pokazDaneTelefonu();

        string nowy_system_opercyjny;
        int nowa_pamiec_RAM;

        cout << "OS=";
        cin >> nowy_system_opercyjny;
        nowy_smartfon.setSystemOpercyjny(nowy_system_opercyjny);

        cout << "RAM=";
        cin >> nowa_pamiec_RAM;
        nowy_smartfon.setPamiecRam(nowa_pamiec_RAM);

        nowy_smartfon.pokazDaneTelefonu();
        break;
    }

    case 3: {
        Rower nowy_rower = Rower();
        nowy_rower.pokazdDaneRoweru();

        string nowy_typ;
        int nowa_liczba_biegow;
        float nowa_waga;

        cout << "Typ=";
        cin >> nowy_typ;
        nowy_rower.setTypRoweru(nowy_typ);

        cout << "Liczba biegow=";
        cin >> nowa_liczba_biegow;
        nowy_rower.setLiczbeBiego(nowa_liczba_biegow);

        cout << "Waga=";
        cin >> nowa_waga;
        nowy_rower.setWagaRoweru(nowa_waga);

        nowy_rower.pokazdDaneRoweru();
        break;
    }

    default:{
        cout << "Niepoprawny numer zadania";
        break;
    }
}

return 0;
}
#include <iostream>
#include <iomanip>
#include <vector>
const float PI = 3.14;

using namespace std;



class Ksztalt {
public:
    virtual float obliczObwodKsztaltu() const;
    virtual float obliczPoleKsztaltu() const;
    virtual void wyswietlAtrybutyKsztaltu() const;
    virtual void wprowadzDane(const Ksztalt &ksztalt) const;
    virtual void setNazwa(string nazwa) const;
    virtual void setPierwszyBok(float pierwszy_bok) const;
    virtual void setDrugiBok(float drugi_bok) const;
    virtual void setPromien(float promien) const;
    virtual string getNazwa() const;
    virtual float getPierwszyBok() const;
    virtual float getDrugiBok() const;
    virtual float getPromien() const;

};

class Kolo : public Ksztalt {
public:
    Kolo(){
        nazwa_kola_ = "";
        promien_kola_ = 0;
    }

    float obliczPoleKsztaltu() const override {
        return PI * promien_kola_* promien_kola_;
    }

    float obliczObwodKsztaltu() const override {
        return PI * 2 * promien_kola_;
    }

    void wyswietlAtrybutyKsztaltu() const override {
        cout << '[' << nazwa_kola_ << "r="  << fixed << setprecision(2) << promien_kola_ << " P=";
        cout << fixed << setprecision(2) << obliczPoleKsztaltu() << " O=";
        cout << fixed << setprecision(2) << obliczObwodKsztaltu() << ']';
    }

    
    
   

    void wprowadzDane(const Ksztalt &ksztalt) const override {
        string nowa_nazwa;
        float nowy_promien;

        cout << "Nazwa kola=";
        cin >> nowa_nazwa;
        ksztalt.setNazwa(nowa_nazwa);

        cout << "r=";
        cin >> nowy_promien;
        setPromien(nowy_promien);
    }
private:
    string nazwa_kola_;
    float promien_kola_;
};


class Prostokat : public Ksztalt{
public:
    Prostokat(){
        nazwa_prostokata_ = "";
        pierwszy_bok_prostokata_ = 0;
        drugi_bok_prostokata_ = 0;
    }

    float obliczObwodKsztaltu() const override{
        return 2 * pierwszy_bok_prostokata_ + 2 * drugi_bok_prostokata_;
    }

    float obliczPoleKsztaltu() const override{
        return pierwszy_bok_prostokata_ * drugi_bok_prostokata_;
    }
    void wyswietlAtrybutyKsztaltu() const override{
        cout << '[' << nazwa_prostokata_ << "a="  << fixed << setprecision(2) << pierwszy_bok_prostokata_ << " b=";
        cout << fixed << setprecision(2) << drugi_bok_prostokata_ << " P=";
        cout << fixed << setprecision(2) << obliczPoleKsztaltu() << " O=";
        cout << fixed << setprecision(2) << obliczObwodKsztaltu() << ']';
    }
    void wprowadzDane( const Ksztalt &ksztalt) const override{
        string nowa_nazwa;
        float nowy_pierwszy_bok, nowy_drugi_bok;

        cout << "Nazwa prostokata=";
        cin >> nowa_nazwa;
        ksztalt.setNazwa(nowa_nazwa);

        cout << "a=";
        cin >> nowy_pierwszy_bok;
        ksztalt.setPierwszyBok(nowy_pierwszy_bok);

        cout << "b=";
        cin >> nowy_drugi_bok;
        ksztalt.setDrugiBok(nowy_drugi_bok);
    }

private:
    string nazwa_prostokata_;
    float pierwszy_bok_prostokata_;
    float drugi_bok_prostokata_;
};

int main(){
    int ilosc_wierszy, ilosc_kolumn;
    cout << "W=";
    cin >> ilosc_wierszy;
    cout << "K=";
    cin >> ilosc_kolumn;

    //Ksztalt** macierz_ksztaltow;
    //macierz_ksztaltow = new Ksztalt*[ilosc_wierszy][ilosc_kolumn];
    vector<vector<Ksztalt*>> macierz_ksztaltow(ilosc_wierszy, vector<Ksztalt*>(ilosc_kolumn, nullptr));

    for (int i = 0; i < ilosc_wierszy; i++) {
        for (int j = 0; j < ilosc_kolumn; j++) {
            if (i % 2 == 0) {
                macierz_ksztaltow[i][j] = new Kolo();
            } else {
                macierz_ksztaltow[i][j] = new Prostokat();
            }
            cout << "Entering data for shape at position (" << i << ", " << j << "):" << endl;
            macierz_ksztaltow[i][j]->wprowadzDane(*macierz_ksztaltow[i][j]);
        }
    }
    
    for (int i = 0; i < ilosc_wierszy; i++) {
        for (int j = 0; j < ilosc_kolumn; j++) {
            macierz_ksztaltow[i][j]->wyswietlAtrybutyKsztaltu();
        }
        cout << endl;
    }

    return 0;
}
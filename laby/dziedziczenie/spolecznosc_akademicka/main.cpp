#include<iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

enum Plec { K, M };

class Osoba{
public:
    Osoba() : imie_osoby_("Jan"), nazwisko_osoby_("Kowalski"), wiek_osoby_(20), plec_osoby_(M) {}
    Osoba(string imie_osoby, string nazwisko_osoby, int wiek_osoby, Plec plec_osoby){
        imie_osoby_ = imie_osoby;
        nazwisko_osoby_ = nazwisko_osoby;
        wiek_osoby_ = wiek_osoby;
        plec_osoby_ = plec_osoby;
    }

    virtual void wyswietlOsobe() const {
        cout << imie_osoby_ << ' ' << nazwisko_osoby_;
    }
    
    string getImie() const { return imie_osoby_; }
    string getNazwisko() const { return nazwisko_osoby_; }
    int getWiek() const { return wiek_osoby_; }
    Plec getPlec() const { return plec_osoby_; }
private:
    string imie_osoby_;
    string nazwisko_osoby_;
    int wiek_osoby_;
    Plec plec_osoby_;
};


class Student : public Osoba{
public:
    Student(string imie_ucznia, string nazwisko_ucznia, int wiek, Plec plec_ucznia,  string numer_indeksu_studenta, int rok_studiow_studenta, int liczba_ocen_studenta){
        Osoba(imie_ucznia, nazwisko_ucznia, wiek, plec_ucznia);
        numer_indeksu_studenta_ = numer_indeksu_studenta;
        rok_studiow_studenta_ = rok_studiow_studenta;
        liczba_ocen_studenta_ = liczba_ocen_studenta;
        oceny_studenta_ = new double [liczba_ocen_studenta_];
    }

    double srednia_ocen(){
        double srednia = 0;
        for(int i = 0; i < liczba_ocen_studenta_; i++){
            srednia += oceny_studenta_[i];
        }
        return srednia/liczba_ocen_studenta_;
    }

    int getRokStudiow() const {
        return rok_studiow_studenta_;
    }

    string getNumerIndeksuStudenta() const{
        return numer_indeksu_studenta_;
    }

    double* getOceny() const{
        return oceny_studenta_;
    }

private:
    string numer_indeksu_studenta_;
    int rok_studiow_studenta_;
    int liczba_ocen_studenta_;
    double* oceny_studenta_;
};

class Pracownik : public Osoba{
    
};

class Kierunek{
public:
    Kierunek(string nazwa_kierunku, int maksymalna_liczba_studentow_na_kierunku, int ile_lat_studiow){
        nazwa_kierunku_ = nazwa_kierunku;
        maksymalna_liczba_studentow_na_kierunku_ = maksymalna_liczba_studentow_na_kierunku;
        ile_lat_studiow_ = ile_lat_studiow;
        caly_kierunek_ = new Student*[ile_lat_studiow];
        for(int i = 0; i < ile_lat_studiow; i++){
            rok_studiow_ = new Student*[maksymalna_liczba_studentow_na_kierunku];
            caly_kierunek_[i] = *rok_studiow_;
        }
    }

    Student** getKierunek(){
        return caly_kierunek_;
    }

    Student dodajStudenta(Student student){
        for(int i = 0; i < maksymalna_liczba_studentow_na_kierunku_; i++){
                caly_kierunek_[student.getRokStudiow() - 1][i] = student;
                return caly_kierunek_[student.getRokStudiow() - 1][i];
        }
        return caly_kierunek_[student.getRokStudiow() - 1][maksymalna_liczba_studentow_na_kierunku_ - 1];
    }
    
    void usunStudenta(string numer_indeksu_studenta){
        for(int i = 0; i < ile_lat_studiow_; i++){
            for(int j = 0; j < maksymalna_liczba_studentow_na_kierunku_; j++){
                if(caly_kierunek_[i][j]->getNumerIndeksuStudenta() == numer_indeksu_studenta){
                    caly_kierunek_[i][j] = caly_kierunek_[i][maksymalna_liczba_studentow_na_kierunku_ - 1];
                    caly_kierunek_[i][maksymalna_liczba_studentow_na_kierunku_ - 1] = nullptr;
                }
        }
    }

    void sortujStudentow(int rok_studiow){
        sort(caly_kierunek_[rok_studiow - 1].begin(), caly_kierunek_[rok_studiow - 1].end(),
                  [](Student* a, Student* b) { return a->srednia_ocen() > b->srednia_ocen(); });
    }

    void wyswietlKierunek(int rok_studiow){
        for(int i = 0; i < maksymalna_liczba_studentow_na_kierunku_; i++){
            cout << i + 1 << ". " << caly_kierunek_[rok_studiow - 1][i]->getNumerIndeksuStudenta();
            cout << " " << caly_kierunek_[rok_studiow - 1][i]->wyswietlOsobe() << ' ';
            cout << setprecision(2) << fixed << caly_kierunek_[rok_studiow - 1][i]->srednia_ocen() << '\n';
        }
    }

private:
    string nazwa_kierunku_;
    int ile_lat_studiow_;
    Student** rok_studiow_;
    Student** caly_kierunek_;
    int maksymalna_liczba_studentow_na_kierunku_;
};
int main() {
    
    string nowy_kierunek;
    int ile_lat_studiow;
    int maksymalna_liczba_studentow_na_kierunku;
    cout << "Kierunkek=";
    cin >> nowy_kierunek;
    cout << "Ile lat studiow(1-5)=";
    cin >> ile_lat_studiow;
    cout << "Maksymalna liczba studentow na roku na kierunku=";
    cin >> maksymalna_liczba_studentow_na_kierunku;

    Kierunek kierunek(nowy_kierunek, maksymalna_liczba_studentow_na_kierunku, ile_lat_studiow);
    for (int i = 1; i < ile_lat_studiow + 1; i++){
        cout << "[ROK " << i << "] ";
        int liczba_studentow_na_roku;
        cout << "Liczba studentow na roku=";
        cin >> liczba_studentow_na_roku;

        for (int j = 1; j < liczba_studentow_na_roku + 1; j++){
            cout << "[STUDENT #" << j << "]:'\n";
            string imie_ucznia;
            string nazwisko_ucznia;
            int wiek;
            string numer_indeksu_studenta;
            int rok_studiow_studenta;
            int liczba_ocen_studenta;
            double oceny_studenta;
            Plec plec_osoby;
            char plec;
            cout << "Imie=";
            cin >> imie_ucznia;
            cout << "Nazwisko=";
            cin >> nazwisko_ucznia;
            cout << "Indeks=";
            cout << "Wiek=";
            cin >> wiek;
            cout << "Plec(M, K)";
            cin >> plec;
            cin >> numer_indeksu_studenta;
            cout << "Rok studiow studenta=";
            cin >> rok_studiow_studenta;
            cout << "Liczba ocen studenta=";
            cin >> liczba_ocen_studenta;
            cout << "Oceny studenta=";
            cin >> oceny_studenta;

            plec_osoby = (plec == 'M') ? Plec::M : Plec::K;
            Osoba osoba(imie_ucznia, nazwisko_ucznia, wiek, plec_osoby);
            Student* student = new Student(imie_ucznia, nazwisko_ucznia, wiek, plec_osoby, numer_indeksu_studenta, rok_studiow_studenta,  oceny_studenta);
            Kierunek::dodajStudenta(*student);
        }
        cout << "[ROK " << i << "] ";
        Kierunek::wyswietlKierunek(i);
        Kierunek::sortujStudentow(i);
        cout << "Po sortowaniu:\n";
        Kierunek::wyswietlKierunek(i);
        int rok;
        string id;
        cout << "Podaj rok=";
        cin >> rok;
        cout << "Podaj numer indeksu studenta=";
        cin >> id;
        Kierunek::usunStudenta(rok, id);
        cout << "Student usuniety z listy";
        cout << "[ROK " << i << "] ";
        Kierunek::wyswietlKierunek(i);
    }
    return 0;
}
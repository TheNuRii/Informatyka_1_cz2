#include "iostream"
#include "cassert"
#include "lista.cpp"

using namespace std;

int main() {
    ListaDwukiernukowa list;
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
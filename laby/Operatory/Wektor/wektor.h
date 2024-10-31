#pragma once

class Wektor {
private:
    bool wektor_liczb_rzeczywistych_[100];
    int liczba_elementow_;
public:
    Wektor(int rozmiar_wektora);
    Wektor()
    ~Wektor();

    int getRozmiar();
    void dodajElementDoWektora()
};
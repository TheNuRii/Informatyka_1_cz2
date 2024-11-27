#pragma once

class Ksztalt{
public:
    Ksztalt(int wiersze, int kolumny);
    virtual float obliczPoleKsztaltu();
    virtual float obliczObwodKsztaltu();
    virtual void wyswietlAtrybutyKsztaltu();
    virtual void setPoleKsztaltu(float nowe_pole);
    virtual void setObwodKsztaltu(float nowy_obwod);

private:
    float pole_ksztaltu_;
    float obwod_ksztaltu_;
    Ksztalt macierz_ksztaltow_;
};
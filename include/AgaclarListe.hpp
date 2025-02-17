#ifndef AgaclarListe_hpp
#define AgaclarListe_hpp
#include "ListeDugum.hpp"

class AgaclarListe{
public:
    AgaclarListe();
    void ekle(Agac* agac);
    void sil(Agac* agac);
    void sil(int index);
    void yazdir(int ilk, int index);
    ~AgaclarListe();
    ListeDugum* dugumGetir(int index);
    int agacSayisiGetir();
    int turSayisi;
private:
    
    void cizgiCiz(int ilk, ListeDugum* gec);
    void adresYazdir(int ilk, ListeDugum* gec);
    void agacToplam(int ilk, ListeDugum* gec);
    void sonrakiAdresYazdir(int ilk, ListeDugum* gec);
    void aktifDugumYazdir(int ilk, int index, ListeDugum* gec);
    ListeDugum* dugumIlerle(ListeDugum* gec, int adim);
    ListeDugum* ilkAgac;
    ListeDugum* sonAgac;
    int agacSayisi;
};







#endif
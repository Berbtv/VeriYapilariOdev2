/**
* @file AgaclarListe.cpp
* @description Bu program, tek yönlü bağlı liste içerisinde ikili arama ağaçlarını tutar ve bu veri yapılarıyla alakalı bazı işlemler gerçekleştirir.
* @course 2-A
* @assignment 2.Ödev
* @date 18.12.2024 / 24.12.2024
* @author Berat Yılmaz berat.yilmaz4@ogr.sakarya.edu.tr
*/

#include "AgaclarListe.hpp"
#include <iostream>
#include<iomanip>
using namespace std;

AgaclarListe::AgaclarListe(){
    ilkAgac = NULL;
    sonAgac = NULL;
    agacSayisi = 0;
    turSayisi=0;
}

void AgaclarListe::ekle(Agac* agac){
   ListeDugum* yeniAgac = new ListeDugum(agac);
   
    if(ilkAgac == NULL){
        ilkAgac = yeniAgac;
        sonAgac = yeniAgac;
    }else{
        sonAgac->sonraki = yeniAgac;
        sonAgac = yeniAgac;
    }
    agacSayisi++;
}

void AgaclarListe::sil(Agac* agac) 
{
    ListeDugum* gecici = ilkAgac;
    ListeDugum* onceki = NULL;
    while (gecici != NULL) 
    {
        if (gecici->agac == agac) 
        {
            if (onceki == NULL) 
            {
                ilkAgac = gecici->sonraki;
            } else 
            {
                onceki->sonraki = gecici->sonraki;
            }
            if (gecici == sonAgac) 
            {
                sonAgac = onceki;
            }
            delete gecici;
            agacSayisi--;
            return;
        }
        onceki = gecici;
        gecici = gecici->sonraki;
    }
}
void AgaclarListe::sil(int index) 
{
    if (index < 0)
        return;
    ListeDugum* gecici = ilkAgac;
    ListeDugum* onceki = NULL;
    int sayac = 0;
    while (gecici != NULL) 
    {
        if (sayac == index) 
        {
            if (onceki == NULL) 
            {
                ilkAgac = gecici->sonraki;
            } 
            else 
            {
                onceki->sonraki = gecici->sonraki;
            }
            if (gecici == sonAgac) 
            {
                sonAgac = onceki;
            }
            delete gecici;
            agacSayisi--;
            return;
        }
        onceki = gecici;
        gecici = gecici->sonraki;
        sayac++;
    }
}

void AgaclarListe::cizgiCiz(int ilk, ListeDugum* gec) 
{
    int turSayisi = agacSayisiGetir()/10;  
    if (turSayisi==ilk/10)
    {
       
        for (int j = 0; j < agacSayisiGetir()%10 && gec!=NULL; j++) 
        {
            cout << "........   "; // Çizgi
            gec = gec->sonraki;
        }

        cout<<endl;
        return;
    }
    
        for (int i = 0; i < 10 && gec!=NULL; i++) 
        {

            cout << "........   "; // Çizgi
            gec = gec->sonraki;

        }
        cout<<endl;
    
}

ListeDugum* AgaclarListe::dugumIlerle(ListeDugum* gec, int adim) {
    for (int i = 0; i < adim; i++) {
        if (gec != NULL) gec = gec->sonraki;
    }
    return gec;
}

void AgaclarListe::adresYazdir(int ilk, ListeDugum* gec) {
    gec = dugumIlerle(gec, ilk);
    
    for (int i = 0; i < 10 && gec != NULL; i++) 
    {
        cout << "." << setw(6) << (int)gec%10000 << setw(1) << "." << "   ";
        gec = gec->sonraki;
    }
    
    cout << endl;
}

void AgaclarListe::agacToplam(int ilk, ListeDugum* gec) {
    gec = dugumIlerle(gec, ilk);

    for (int i = 0; i < 10 && gec != NULL; i++) {
        if (gec->agac != NULL) {
           
           int toplam = gec->agac->toplamDeger();
            cout << "." << setw(5) << toplam << setw(2) << "." << "   ";
        }
        gec = gec->sonraki;
    }
    cout << endl;
}


void AgaclarListe::sonrakiAdresYazdir(int ilk, ListeDugum* gec) {
    gec = dugumIlerle(gec, ilk);

    for (int i = 0; i < 10 && gec != NULL; i++) {
        if (gec->sonraki != NULL) 
        {
            cout << "." << setw(6) << (int)(gec->sonraki)%10000 << setw(1) << "." << "   ";
        } 
        else 
        {
            cout << "." << setw(6) << "0" << setw(1) << "." << "   ";
        }
        gec = gec->sonraki;
    }
    cout << endl;
}

void AgaclarListe::aktifDugumYazdir(int ilk, int index, ListeDugum* gec) {
    if (index < 0)
        index = 0;

    gec = dugumIlerle(gec, ilk);

    int sayac = ilk;
    while (gec != NULL && sayac < ilk + 10) {
        if (sayac == index) {
            cout << "^^^^^^^^   ";  
        }
        else 
        {
            cout << "           ";  
        }
        gec = gec->sonraki;
        sayac++;
    }
    cout << endl;

    gec = dugumIlerle(ilkAgac, ilk);

    sayac = ilk;
    while (gec != NULL && sayac < ilk + 10) 
    {
        if (sayac == index) 
        {
            cout << "||||||||   ";  
        }
         else
        {
            cout << "           ";  
        }
        gec = gec->sonraki;
        sayac++;
    }
    cout << endl;
}

void AgaclarListe::yazdir(int ilk, int index) {
    system("CLS"); // Ekranı temizle
    ListeDugum* gec = ilkAgac; // Listenin başını işaret eder

    // Üst çizgiler
    cizgiCiz(ilk, gec);

    // Adresleri yazdır
    adresYazdir(ilk, gec);

    // Alt çizgiler
    cizgiCiz(ilk, gec);

    // Ağaçları yazdır
    agacToplam(ilk, gec);

    // Alt çizgiler
    cizgiCiz(ilk, gec);
    // Sonraki düğüm adreslerini yazdır
    sonrakiAdresYazdir(ilk, gec);

    // Alt çizgiler
    cizgiCiz(ilk, gec);

    // Aktif düğüm işaretleme
    aktifDugumYazdir(ilk, index, gec);
}

AgaclarListe::~AgaclarListe() {
    
    while (ilkAgac != NULL) 
    {
        ListeDugum* temp = ilkAgac;
        ilkAgac = ilkAgac->sonraki;
        delete temp;
        
    }
}
 
ListeDugum* AgaclarListe::dugumGetir (int index)
    {
        if(index<0)
        {
            return dugumGetir(1);
        }
        ListeDugum* gec= ilkAgac;
        int sayac=0;
        while(gec!=0)
        {
            if(sayac==index)
                return gec;
            gec=gec->sonraki;
            sayac++;
        }
        return gec;
    }
int AgaclarListe::agacSayisiGetir()
{
    return agacSayisi;
}




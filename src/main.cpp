/**
* @file main.cpp
* @description Bu program, tek yönlü bağlı liste içerisinde ikili arama ağaçlarını tutar ve bu veri yapılarıyla alakalı bazı işlemler gerçekleştirir.
* @course 2-A
* @assignment 2.Ödev
* @date 18.12.2024 / 24.12.2024
* @author Berat Yılmaz berat.yilmaz4@ogr.sakarya.edu.tr
*/

#include "Agac.hpp"
#include "AgaclarListe.hpp"
#include <iostream>
#include<fstream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	
	ifstream file("Veri.txt");
    

    if (file.is_open()) {
        AgaclarListe* agaclarListe = new AgaclarListe();
        Agac* agac = nullptr;
        char veri;
        while (file >> noskipws>> veri) { // noskipws: boşluk karakterlerini atlamadan okur
            if (veri == '\n') {
                if (agac != nullptr) {
                    // Satır sonuna gelindiğinde, mevcut ağacı listeye ekle
                    agaclarListe->ekle(agac);
                    agac = nullptr;
                }
            } else if (veri != '\r') {
                if (agac == nullptr && veri != ' ') {
                    // Yeni bir satır başladığında yeni bir ağaç oluştur
                    agac = new Agac();
                    //cout<<agac<<endl;
                }
                // Satır sonu karakteri değilse, ağaca ekle
                agac->ekle(veri);
            }
        }
        // Son satırı ekle
        if (agac != nullptr && !agac->bosmu()) {
            agaclarListe->ekle(agac);
        } else {
            delete agac;
        }
        file.close();

        // Ağaçları listeleyelim (örnek olarak inorder traversal)
        
        agaclarListe->yazdir(0, 0);

        int start = 0;
        int index = 0;
        char secim;
        do
        {
            agaclarListe->yazdir(start, index);
            cout<<endl<<endl;
            if (index >= 0 && index < agaclarListe->agacSayisiGetir()) {
        Agac* aktifAgac = agaclarListe->dugumGetir(index)->agac;
        if (aktifAgac != nullptr) {
            agac->agacCizdir(aktifAgac);
        }
    }
            cout<<endl<<endl;
            cout<<"secim...:";
            cin>>secim;
            switch (secim)
            {
            case 'a':
                if(index>1)
                    {
                        index =  index - 1;
                    }
                    else
                    {
                        index = 0;
                    } // Önceki düğüme git
                if (index < start)  
                {
                    if(start>0)
                    {
                        start = start - 10;
                    }
                    else
                    {
                        start = 0;
                    }
                }
                break;

            case 'd':
                index = min(agaclarListe->agacSayisiGetir() - 1, index + 1); // Sonraki düğüme git
                if (index >= start + 10) 
                {
                start = start + 10;
                
                }
                
                break;
            case 's':
                if (index>=0 && index<agaclarListe->agacSayisiGetir()) 
                {
                    agaclarListe->sil(index);
                    // Eğer bir önceki düğüm varsa ona geç
                    if(index>0)
                    {
                        
                        index =  index - 1;
                    }
                    else
                    {
                        index = 0;
                    }
                    // Eğer başlangıç düğümü silindiyse, ekranı uygun şekilde güncelle
                    if (index < start) 
                    {
                        start = max(0, start - 10);
                    }
                }   

                break;
            case 'w':
            {   if (index >= 0 && index < agaclarListe->agacSayisiGetir()) {             
                Agac* aktifAgac = agaclarListe->dugumGetir(index)->agac;
                agac->aynalaHelper(aktifAgac->kokDondur());
                if(aktifAgac != nullptr)
                {
                    agac->agacCizdir(aktifAgac);
                }
            }
                break;
            }
            default:
                break;  
            }
        } while (secim != 'q');
        
        

        // Bellek temizleme
        delete agaclarListe;
    } 
    else 
    {
        cout << "Dosya acilamadi." << endl;
    }

    
    
	return 0;
}
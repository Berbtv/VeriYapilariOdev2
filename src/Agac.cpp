/**
* @file Agac.cpp
* @description Bu program, tek yönlü bağlı liste içerisinde ikili arama ağaçlarını tutar ve bu veri yapılarıyla alakalı bazı işlemler gerçekleştirir.
* @course 2-A
* @assignment 2.Ödev
* @date 18.12.2024 / 24.12.2024
* @author Berat Yılmaz berat.yilmaz4@ogr.sakarya.edu.tr
*/

#include "Agac.hpp"
#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;



AgacDugumu* Agac::kokDondur() const
{
	return kok;
}


void Agac::aynalaHelper(AgacDugumu* dugum) 
{
    if (dugum == nullptr) return;
    AgacDugumu* temp = dugum->sol;
    dugum->sol = dugum->sag;
    dugum->sag = temp;
    aynalaHelper(dugum->sol);
    aynalaHelper(dugum->sag);
}



void Agac::agacCizdir(Agac* agac) {
    if (agac == nullptr || agac->bosmu()) {
        return;
    }

    int h = agac->yukseklik(agac->kokDondur());
    int maxWidth = pow(2, h); // Maksimum genişlik

    Kuyruk kuyruk;
    kuyruk.ekle(agac->kokDondur());

    for (int i = 0; i <= h; i++) {
        int levelNodes = pow(2, i); // Bu seviyedeki düğüm sayısı
        int spaceBetween = maxWidth / levelNodes; // Düğümler arasındaki boşluk
        int initialSpace = maxWidth / (pow(2, i + 1)); // Başlangıç boşluğu

        cout << setw(initialSpace * 2) << " "; // İlk boşluğu yazdır
		

        for (int j = 0; j < levelNodes; j++) {
            AgacDugumu* dugum = kuyruk.cikar();

            if (dugum != nullptr) {
                cout << dugum->veri;
                kuyruk.ekle(dugum->sol);
                kuyruk.ekle(dugum->sag);
            } else {
                kuyruk.ekle(nullptr);
                kuyruk.ekle(nullptr);
            }

            if (j < levelNodes) {
                cout << setw(spaceBetween * 2) << " "; // Düğümler arasındaki boşluğu yazdır
            }
        }
        cout << endl<<endl;
		
		

    }
}


int Agac::toplamDegerHelper(AgacDugumu* dugum) {
    if (dugum == NULL) {
        return 0;
    }

    int solDeger = 0, sagDeger = 0;

    if (dugum->sol != NULL) {
        solDeger += 2 * dugum->sol->veri;
    }
    if (dugum->sag != NULL) {
        sagDeger += dugum->sag->veri;
    }

    int toplam = solDeger + sagDeger;
    toplam += toplamDegerHelper(dugum->sol);
    toplam += toplamDegerHelper(dugum->sag);

    return toplam;
}

int Agac::toplamDeger() {
    return kokDondur()->veri + toplamDegerHelper(kokDondur());
}

void Agac::ekle(AgacDugumu*&aktifDugum,const char& veri){
	if(aktifDugum == NULL) aktifDugum = new AgacDugumu(veri);
	else if(veri < aktifDugum->veri)
		ekle(aktifDugum->sol,veri);
	else if(veri > aktifDugum->veri)
		ekle(aktifDugum->sag,veri);
	else return;
}
bool Agac::bulvesil(AgacDugumu*&aktifDugum,const char& veri){
	if(aktifDugum == NULL) return false;
	if(aktifDugum->veri == veri) return silme(aktifDugum);
	else if(veri < aktifDugum->veri) return bulvesil(aktifDugum->sol,veri);
	else return bulvesil(aktifDugum->sag,veri);
}
bool Agac::silme(AgacDugumu*&aktifDugum){
	AgacDugumu*DelDugum = aktifDugum;
	
	if(aktifDugum->sag == NULL) aktifDugum = aktifDugum->sol;
	else if(aktifDugum->sol == NULL) aktifDugum = aktifDugum->sag;
	else{
		DelDugum = aktifDugum->sol;
		AgacDugumu*ebeveyn = aktifDugum;
		while(DelDugum->sag != NULL){
			ebeveyn = DelDugum;
			DelDugum = DelDugum->sag;
		}
		aktifDugum->veri = DelDugum->veri;
		if(ebeveyn == aktifDugum) aktifDugum->sol = DelDugum->sol;
		else ebeveyn->sag = DelDugum->sol;
	}
	delete DelDugum;
	return true;
}


int Agac::yukseklik(AgacDugumu*aktifDugum){
	if(aktifDugum == NULL) return -1;
	return 1+max(yukseklik(aktifDugum->sol),yukseklik(aktifDugum->sag));
}

bool Agac::bul(AgacDugumu*aktifDugum,const char& item){
	if(aktifDugum == NULL) return false;
	if(aktifDugum->veri == item) return true;
	if(item < aktifDugum->veri) return bul(aktifDugum->sol,item);
	else return bul(aktifDugum->sag,item);
}
Agac::Agac(){
	kok = NULL;
}
bool Agac::bosmu()const{
	return kok == NULL;
}
void Agac::ekle(const char& veri){
	ekle(kok,veri);
}
void Agac::sil(const char &veri){
	if(bulvesil(kok,veri) == false) throw "Item not found.";
}

int Agac::yukseklik(){
	return yukseklik(kok);
}
bool Agac::bul(const char& item){
	return bul(kok,item);
}
void Agac::temizleme(){
	while(!bosmu()) silme(kok);
}
Agac::~Agac(){
	temizleme();
}
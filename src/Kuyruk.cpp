/**
* @file Kuyruk.cpp
* @description Bu program, tek yönlü bağlı liste içerisinde ikili arama ağaçlarını tutar ve bu veri yapılarıyla alakalı bazı işlemler gerçekleştirir.
* @course 2-A
* @assignment 2.Ödev
* @date 18.12.2024 / 24.12.2024
* @author Berat Yılmaz berat.yilmaz4@ogr.sakarya.edu.tr
*/

#include "Kuyruk.hpp"
#include <iostream>
using namespace std;

Kuyruk::Kuyruk() {
    on = nullptr;
    arka = nullptr;
}

Kuyruk::~Kuyruk() {
    while (!bosMu()) {
        cikar();
    }
}

bool Kuyruk::bosMu() const {
    return on == nullptr;
}

void Kuyruk::ekle(AgacDugumu* veri) {
    Dugum* yeniDugum = new Dugum(veri);
    if (bosMu()) {
        on = yeniDugum;
        arka = yeniDugum;
    } else {
        arka->sonraki = yeniDugum;
        arka = yeniDugum;
    }
}


AgacDugumu* Kuyruk::cikar() {
    if (bosMu()) {
        return nullptr;
    }
    Dugum* gecici = on;
    AgacDugumu* veri = on->veri;
    on = on->sonraki;
    delete gecici;
    if (on == nullptr) {
        arka = nullptr;
    }
    return veri;
}

AgacDugumu* Kuyruk::ondugumu() const {
    if (bosMu()) {
        return nullptr;
    }
    return on->veri;
}
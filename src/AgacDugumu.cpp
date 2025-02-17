/**
* @file AgaclarDugumu.cpp
* @description Bu program, tek yönlü bağlı liste içerisinde ikili arama ağaçlarını tutar ve bu veri yapılarıyla alakalı bazı işlemler gerçekleştirir.
* @course 2-A
* @assignment 2.Ödev
* @date 18.12.2024 / 24.12.2024
* @author Berat Yılmaz berat.yilmaz4@ogr.sakarya.edu.tr
*/

#include "AgacDugumu.hpp"

AgacDugumu::AgacDugumu(char veri)
{
    this->veri = veri;
    this->sol = nullptr;
    this->sag = nullptr;
}



#ifndef Kuyruk_hpp
#define Kuyruk_hpp

#include "AgacDugumu.hpp"

class Kuyruk {
private:
    struct Dugum {
        AgacDugumu* veri;
        Dugum* sonraki;
        Dugum(AgacDugumu* veri) : veri(veri), sonraki(nullptr) {}
    };

    Dugum* on;
    Dugum* arka;

public:
    Kuyruk();
    ~Kuyruk();
    bool bosMu() const;
    void ekle(AgacDugumu* veri);
    AgacDugumu* cikar();
    AgacDugumu* ondugumu() const;
};

#endif
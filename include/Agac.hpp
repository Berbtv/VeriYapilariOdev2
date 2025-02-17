#ifndef Agac_hpp
#define Agac_hpp
#include "AgacDugumu.hpp"
#include "Kuyruk.hpp"
class Agac{
private:	
	AgacDugumu* kok;
	
	void ekle(AgacDugumu*&aktifDugum,const char& newItem);
	bool bulvesil(AgacDugumu*&aktifDugum,const char& veri);
	bool silme(AgacDugumu*&aktifDugum);
	
	int yukseklik(AgacDugumu*aktifDugum);
	
    bool bul(AgacDugumu*aktifDugum,const char& item);
	int toplamDegerHelper(AgacDugumu* dugum);
public:            
	Agac();
	int toplamDeger();
	AgacDugumu* kokDondur() const;
	void agacCizdir(Agac* agac);
	bool bosmu()const;
	void ekle(const char& newItem);
	void sil(const char &veri);
	void aynalaHelper(AgacDugumu* dugum);
	int yukseklik();
	bool bul(const char& item);
	void temizleme();
	~Agac();


};

#endif
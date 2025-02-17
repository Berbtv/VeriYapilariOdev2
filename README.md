# İkili Arama Ağaçları ve Tek Yönlü Bağlı Liste
 Bu proje, tek yönlü bağlı liste içerisinde ikili arama ağaçlarını tutar ve bu veri yapılarıyla alakalı bazı işlemler gerçekleştirir. Proje, ikili arama ağaçları üzerinde ekleme, silme, arama ve çizdirme işlemlerini içerir.
 
## Komutlar
* a: Önceki düğüme git
* d: Sonraki düğüme git
* s: Mevcut düğümü sil
* w: Mevcut ağacı aynala (sağ ve sol düğümleri yer değiştir)
* q: Programdan çık

## Fonksiyonlar

### Agac Sınıfı
* Agac(): Agac sınıfının kurucusu. Yeni bir ağaç oluşturur.
* ~Agac(): Agac sınıfının yıkıcısı. Ağacı temizler.
* void ekle(const char& veri): Ağaca yeni bir düğüm ekler.
* void sil(const char& veri): Ağaçtan bir düğüm siler.
* bool bul(const char& item): Ağacın içinde belirli bir veriyi arar.
* bool bosmu() const: Ağacın boş olup olmadığını kontrol eder.
* int yukseklik(): Ağacın yüksekliğini döner.
* void agacCizdir(Agac* agac): Ağacı çizdirir.
* void aynalaHelper(AgacDugumu* dugum): Ağacı aynalar (sağ ve sol düğümleri yer değiştirir).
* void temizleme(): Ağacı temizler.
## AgacDugumu Sınıfı
* AgacDugumu(const char& veri): AgacDugumu sınıfının kurucusu. Yeni bir düğüm oluşturur.
* ~AgacDugumu(): AgacDugumu sınıfının yıkıcısı. Düğümü temizler.
## Kuyruk Sınıfı
* Kuyruk(): Kuyruk sınıfının kurucusu. Yeni bir kuyruk oluşturur.
* ~Kuyruk(): Kuyruk sınıfının yıkıcısı. Kuyruğu temizler.
* void ekle(AgacDugumu* veri): Kuyruğa yeni bir düğüm ekler.
* AgacDugumu* cikar(): Kuyruktan bir düğüm çıkarır.
* bool bosMu() const: Kuyruğun boş olup olmadığını kontrol eder.
## AgaclarListe Sınıfı
* AgaclarListe(): AgaclarListe sınıfının kurucusu. Yeni bir liste oluşturur.
* ~AgaclarListe(): AgaclarListe sınıfının yıkıcısı. Listeyi temizler.
* void ekle(Agac* agac): Listeye yeni bir ağaç ekler.
* void sil(int index): Listeden bir ağacı siler.
* int agacSayisiGetir() const: Listedeki ağaç sayısını döner.
* void yazdir(int start, int index) const: Listeyi yazdırır.
* Dugum* dugumGetir(int index) const: Belirtilen indeksteki düğümü döner

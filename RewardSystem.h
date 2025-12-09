#ifndef REWARDSYSTEM_H
#define REWARDSYSTEM_H

#include <string>
#include <vector>

// GÖREV YAPISI: Bir işin özelliklerini tutar
struct Gorev {
    std::string ad;          // Görevin adı
    int zorlukDerecesi;      // 1-5 arası zorluk
    int beklenenSure;        // Dakika cinsinden planlanan süre
    int bitirmeSuresi;       // Gerçekleşen bitirme süresi
};

// ÇALIŞAN YAPISI: Kullanıcının puan ve rozetlerini tutar
struct Calisan {
    std::string isim;
    int toplamPuan;
    std::vector<std::string> rozetler;
    int hizliBitirmeSayaci;  // Özel rozet için sayaç
};

// Fonksiyonların İmzaları (Gövdesi .cpp dosyasında olacak)
int puanHesapla(Gorev g);
void rozetKontrol(Calisan &kullanici, Gorev g);

#endif

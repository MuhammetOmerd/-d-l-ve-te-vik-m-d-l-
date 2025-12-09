#ifndef REWARDSYSTEM_H
#define REWARDSYSTEM_H

#include <string>
#include <vector>

// GÖREV YAPISI
struct Gorev {
    std::string ad;
    int zorlukDerecesi;
    int beklenenSure;
    int bitirmeSuresi;
};

// ÇALIŞAN YAPISI
struct Calisan {
    std::string isim;
    int toplamPuan;
    std::vector<std::string> rozetler;
    int hizliBitirmeSayaci;
};

// Fonksiyon Tanımları
int puanHesapla(Gorev g);
void rozetKontrol(Calisan &kullanici, Gorev g);

#endif

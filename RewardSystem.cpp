#include "RewardSystem.h"
#include <iostream>

using namespace std;

// Puan Hesaplama Fonksiyonu
int puanHesapla(Gorev g) {
    int tabanPuan = g.zorlukDerecesi * 10;
    int ekPuan = 0;

    // Performans Bonusu
    if (g.bitirmeSuresi < g.beklenenSure) {
        int kazanilanZaman = g.beklenenSure - g.bitirmeSuresi;
        ekPuan = kazanilanZaman / 2; // Her 2 dk artış için 1 puan
        if(ekPuan > 0)
            cout << "\n>> [PERFORMANS]: Harika! Beklenenden hizli bitirdin. (+" << ekPuan << " Bonus)" << endl;
    }
    return tabanPuan + ekPuan;
}

// Rozet Kontrol Fonksiyonu
void rozetKontrol(Calisan &kullanici, Gorev g) {
    // KURAL: Sürenin %80'i altında biterse sayaç artar
    if (g.bitirmeSuresi <= g.beklenenSure * 0.8) {
        kullanici.hizliBitirmeSayaci++;
        cout << ">> [ROZET SISTEMI]: Hizli bitirme serisi! Sayac: " << kullanici.hizliBitirmeSayaci << "/3" << endl;
    }

    // KURAL: Sayaç 3 olursa rozet ver
    if (kullanici.hizliBitirmeSayaci >= 3) {
        bool zatenVar = false;
        // Zaten var mı kontrolü
        for (const string& r : kullanici.rozetler) {
            if (r == "Hizli Cozucu") zatenVar = true;
        }

        if (!zatenVar) {
            kullanici.rozetler.push_back("Hizli Cozucu");
            cout << "\n***********************************" << endl;
            cout << " TEBRIKLER! 'Hizli Cozucu' Rozeti Kazandiniz! " << endl;
            cout << "***********************************\n" << endl;
        }
    }
}

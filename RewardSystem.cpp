#include "RewardSystem.h"
#include <iostream>

using namespace std;

// Puan Hesaplama Fonksiyonu
// Görevin zorluğuna ve bitirme hızına göre puan üretir.
int puanHesapla(Gorev g) {
    // 1. Taban Puan: Zorluk derecesi * 10
    int tabanPuan = g.zorlukDerecesi * 10;
    int ekPuan = 0;

    // 2. Performans Analizi:
    // Eğer beklenen süreden daha hızlı bitirdiyse bonus ver.
    if (g.bitirmeSuresi < g.beklenenSure) {
        // Her kazanılan dakika için basit bir bonus mantığı
        int kazanilanZaman = g.beklenenSure - g.bitirmeSuresi;
        
        // Örnek Formül: Kazanılan her 2 dakika için 1 ekstra puan
        ekPuan = kazanilanZaman / 2;
        
        cout << ">> [SISTEM]: Harika is! Beklenen sureden hizli bitirdigin icin +" << ekPuan << " bonus puan kazandin!" << endl;
    }

    return tabanPuan + ekPuan;
}

// Rozet Kontrol Fonksiyonu
// Çalışanın performans geçmişine bakarak rozet verip vermeyeceğine karar verir.
void rozetKontrol(Calisan &kullanici, Gorev g) {
    // KURAL: Eğer görev, beklenen sürenin %80'i veya daha kısa sürede bittiyse "hızlı" sayılır.
    if (g.bitirmeSuresi <= g.beklenenSure * 0.8) {
        kullanici.hizliBitirmeSayaci++;
        cout << ">> [SISTEM]: Hizli bitirme serisi yakaladin! Sayac: " << kullanici.hizliBitirmeSayaci << "/3" << endl;
    }

    // KURAL: Sayaç 3'e ulaşırsa "Hızlı Çözücü" rozeti verilir.
    if (kullanici.hizliBitirmeSayaci >= 3) {
        // Önce rozetin zaten olup olmadığını kontrol et
        bool zatenVar = false;
        for (const string& r : kullanici.rozetler) {
            if (r == "Hizli Cozucu") zatenVar = true;
        }

        // Eğer rozet yoksa ekle
        if (!zatenVar) {
            kullanici.rozetler.push_back("Hizli Cozucu");
            cout << "\n***********************************" << endl;
            cout << " TEBRIKLER! 'Hizli Cozucu' Rozeti Kazandiniz! " << endl;
            cout << "***********************************\n" << endl;
        }
    }
}

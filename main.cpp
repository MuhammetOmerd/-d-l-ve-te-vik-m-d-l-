#include <iostream>
#include <vector>
#include "RewardSystem.h" // Kendi yazdığımız başlık dosyasını dahil ediyoruz

using namespace std;

int main() {
    // 1. ADIM: Bir çalışan profili oluşturuyoruz
    Calisan ekipUyesi;
    ekipUyesi.isim = "Mehmet Demir"; // Senin veya ekip arkadaşının adı
    ekipUyesi.toplamPuan = 0;
    ekipUyesi.hizliBitirmeSayaci = 0;

    cout << "=== PROJE YONETIM SISTEMI BASLATILDI ===" << endl;
    cout << "Calisan: " << ekipUyesi.isim << " | Baslangic Puani: " << ekipUyesi.toplamPuan << endl << endl;

    // 2. ADIM: Test için 4 farklı görev tanımlıyoruz
    // Format: {Ad, Zorluk(1-5), BeklenenSure, BitirmeSuresi}
    vector<Gorev> gorevListesi = {
        {"Arayuz Tasarimi", 3, 60, 50},  // Hızlı (Bonus alır)
        {"Veritabani Baglantisi", 4, 90, 60},  // Çok Hızlı (Bonus + Sayaç artar)
        {"Rapor Hazirlama", 2, 40, 30},  // Hızlı (Bonus + Sayaç artar)
        {"Sunum Provası", 5, 120, 90}   // Hızlı (Bonus + Sayaç artar -> ROZET GELMELİ)
    };

    // 3. ADIM: Görevleri sırayla işleme alıyoruz (Simülasyon)
    for (int i = 0; i < gorevListesi.size(); i++) {
        Gorev g = gorevListesi[i];
        
        cout << "------------------------------------------" << endl;
        cout << "Gorev " << i+1 << ": " << g.ad << " (Zorluk: " << g.zorlukDerecesi << ")" << endl;
        cout << "Durum: Beklenen " << g.beklenenSure << " dk, Bitirilen " << g.bitirmeSuresi << " dk." << endl;

        // Puan Hesapla
        int kazanilan = puanHesapla(g);
        ekipUyesi.toplamPuan += kazanilan;
        
        cout << "-> Kazanilan Puan: " << kazanilan << endl;
        cout << "-> Guncel Toplam Puan: " << ekipUyesi.toplamPuan << endl;

        // Rozet Kontrolü (Burada 'Hızlı Çözücü' kontrolü yapılıyor)
        rozetKontrol(ekipUyesi, g);
    }

    // 4. ADIM: Final Raporu
    cout << "\n==========================================" << endl;
    cout << " GUN SONU RAPORU " << endl;
    cout << "==========================================" << endl;
    cout << "Isim: " << ekipUyesi.isim << endl;
    cout << "Toplam Puan: " << ekipUyesi.toplamPuan << endl;
    cout << "Kazanilan Rozetler: ";
    
    if (ekipUyesi.rozetler.empty()) {
        cout << "Yok";
    } else {
        for (const string& r : ekipUyesi.rozetler) {
            cout << "[" << r << "] ";
        }
    }
    cout << endl << "==========================================" << endl;

    // Konsol hemen kapanmasın diye (Windows kullanıyorsan)
    // cin.get(); 
    
    return 0;
}

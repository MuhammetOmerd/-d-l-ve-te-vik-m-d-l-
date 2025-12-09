#include <iostream>
#include <vector>
#include <limits> // Hata kontrolü için
#include "RewardSystem.h" // Kendi başlık dosyamızı ekliyoruz

using namespace std;

int main() {
    Calisan sen;
    sen.isim = "Kullanici";
    sen.toplamPuan = 0;
    sen.hizliBitirmeSayaci = 0;

    cout << "=== INTERAKTIF PROJE SISTEMI ===" << endl;
    cout << "Sisteme hos geldin. Gorevlerini gir, puanini kap!" << endl;

    char devamMi = 'e';

    while (devamMi == 'e' || devamMi == 'E') {
        Gorev yeniGorev;

        cout << "\n-----------------------------------" << endl;
        cout << ">> YENI GOREV GIRISI" << endl;
        
        // 1. Görev Adı
        cout << "1. Gorev Adi (Orn: Arayuz Tasarimi): ";
        cin >> ws; // Tampon temizliği
        getline(cin, yeniGorev.ad);

        // 2. Zorluk Derecesi (Hata korumalı)
        cout << "2. Zorluk Derecesi (1-5 arasi): ";
        while(!(cin >> yeniGorev.zorlukDerecesi)){
            cout << "HATA: Lutfen sadece sayi giriniz (1-5): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // 3. Beklenen Süre
        cout << "3. Bu is icin verilen sure (dk): ";
        while(!(cin >> yeniGorev.beklenenSure)){
            cout << "HATA: Lutfen sadece sayi giriniz: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // 4. Bitirme Süresi
        cout << "4. Sen kac dakikada bitirdin?: ";
        while(!(cin >> yeniGorev.bitirmeSuresi)){
            cout << "HATA: Lutfen sadece sayi giriniz: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // --- HESAPLAMA ---
        cout << "\n--- Sonuclar Hesaplaniyor ---" << endl;
        int puan = puanHesapla(yeniGorev);
        sen.toplamPuan += puan;
        rozetKontrol(sen, yeniGorev);

        // --- DURUM RAPORU ---
        cout << "-> Bu Gorevden Puanin: " << puan << endl;
        cout << "-> TOPLAM PUANIN: " << sen.toplamPuan << endl;

        // --- DEVAM ---
        cout << "\nBaska gorev girmek ister misin? (e/h): ";
        cin >> devamMi;
    }

    cout << "\nSistemden cikis yapildi. Iyi calismalar!" << endl;

    return 0;
}

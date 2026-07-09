#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Pemesanan {
private:
    string nama; 
    int total, bayar, kembalian, diskon;

    static const int jumlahMenu = 13;

    string daftarMenu[jumlahMenu] = {
        "Ayam Geprek Original",
        "Ayam Geprek Keju",
        "Ayam Geprek Mozzarella",
        "Ayam Geprek Sambal Matah",
        "Mie Dog-dog",
        "Nasi Goreng",
        "Magelangan",
        "Nasi Omlet",
        "Es Teh",
        "Es Jeruk",
        "Kopi",
        "Air Es",
        "Air Mineral"
    };

    int daftarHarga[jumlahMenu] = {
        15000,
        18000,
        22000,
        17000,
        15000,
        13000,
        11000,
        10000,
        5000,
        5000,
        5000,
        3000,
        3000
    };

    string menuPesanan[50];
    int hargaPesanan[50];
    int jumlahPesanan[50];
    int banyakPesanan = 0;

public:

    string toLowerCase(string teks) {
        for(int i = 0; i < teks.length(); i++) {
            teks[i] = tolower(teks[i]);
        }
        return teks;
    }

    void tampilMenuUrut() {

        string menuTemp[jumlahMenu];
        int hargaTemp[jumlahMenu];

        for(int i = 0; i < jumlahMenu; i++) {
            menuTemp[i] = daftarMenu[i];
            hargaTemp[i] = daftarHarga[i];
        }

        for(int i = 0; i < jumlahMenu - 1; i++) {
            for(int j = i + 1; j < jumlahMenu; j++) {

                if(hargaTemp[i] > hargaTemp[j]) {

                    swap(hargaTemp[i], hargaTemp[j]);
                    swap(menuTemp[i], menuTemp[j]);
                }
            }
        }

        cout << "\n===== MENU TERMURAH - TERMAHAL =====\n\n";

        for(int i = 0; i < jumlahMenu; i++) {
            cout << i + 1 << ". "
                 << menuTemp[i]
                 << " - Rp "
                 << hargaTemp[i]
                 << endl;
        }

        cout << endl;
    }

    void pesanMenu() {

        cin.ignore();

        cout << "\nMasukkan Nama Pelanggan : ";
        getline(cin, nama);

        banyakPesanan = 0;
        total = 0;
        diskon = 0;

        char tambah;

        do {

            string keyword;

            cout << "\nCari menu : ";
            getline(cin, keyword);

            keyword = toLowerCase(keyword);

            int hasil[20];
            int jumlahHasil = 0;

            cout << "\n===== HASIL PENCARIAN =====\n\n";

            for(int i = 0; i < jumlahMenu; i++) {

                string menuKecil = toLowerCase(daftarMenu[i]);

                if(menuKecil.find(keyword) != string::npos) {

                    hasil[jumlahHasil] = i;

                    cout << jumlahHasil + 1
                         << ". "
                         << daftarMenu[i]
                         << " - Rp "
                         << daftarHarga[i]
                         << endl;

                    jumlahHasil++;
                }
            }

            if(jumlahHasil == 0) {

                cout << "Menu tidak ditemukan!" << endl;
                continue;
            }

            int pilih, qty;

            cout << "\nPilih menu : ";
            cin >> pilih;

            if(pilih < 1 || pilih > jumlahHasil) {

                cout << "Pilihan tidak valid!" << endl;
                cin.ignore();
                continue;
            }

            cout << "Jumlah pesanan : ";
            cin >> qty;

            int index = hasil[pilih - 1];

            menuPesanan[banyakPesanan] = daftarMenu[index];
            hargaPesanan[banyakPesanan] = daftarHarga[index];
            jumlahPesanan[banyakPesanan] = qty;

            total += daftarHarga[index] * qty;
            banyakPesanan++;

            cout << "\nTambah pesanan lagi? (Y/T) : ";
            cin >> tambah;
            cin.ignore();

        } while(toupper(tambah) == 'Y');

        if(total > 105000) {

            diskon = total * 30 / 100;
            total -= diskon;

            cout << "\nSelamat! Anda mendapat diskon 30%\n";
        }

        cout << "\nTotal Bayar : Rp " << total << endl;

        do {

            cout << "Masukkan Uang Bayar : ";
            cin >> bayar;

            if(bayar < total) {
                cout << "Uang kurang! Silakan masukkan kembali.\n";
            }

        } while(bayar < total);

        kembalian = bayar - total;

        tampilStruk();
    }

    void tampilStruk() {

        cout << "\n========================================";
        cout << "\n          STRUK PEMESANAN";
        cout << "\n========================================";

        cout << "\nNama Pelanggan : " << nama << endl;

        for(int i = 0; i < banyakPesanan; i++) {

            cout << "\n" << i + 1 << ". "
                 << menuPesanan[i];

            cout << "\n   "
                 << jumlahPesanan[i]
                 << " x Rp "
                 << hargaPesanan[i]
                 << " = Rp "
                 << jumlahPesanan[i] * hargaPesanan[i]
                 << endl;
        }

        cout << "\n----------------------------------------";

        if(diskon > 0) {
            cout << "\nDiskon 30% : Rp " << diskon;
        }

        cout << "\nTotal Bayar : Rp " << total;
        cout << "\nUang Bayar  : Rp " << bayar;
        cout << "\nKembalian   : Rp " << kembalian;

        cout << "\n========================================\n";
    }
};

int main() {

    Pemesanan p;
    int pilihan;

    do {

        cout << "\n===== SISTEM PEMESANAN MAKANAN =====\n";
        cout << "1. Lihat Menu Termurah - Termahal\n";
        cout << "2. Pesan Menu\n";
        cout << "3. Keluar\n";
        cout << "Pilih Menu : ";
        cin >> pilihan;

        switch(pilihan) {

            case 1:
                p.tampilMenuUrut();
                break;

            case 2:
                p.pesanMenu();
                break;

            case 3:
                cout << "\nTerima kasih telah berkunjung.\n";
                break;

            default:
                cout << "\nPilihan tidak tersedia!\n";
        }

    } while(pilihan != 3);

    return 0;
}

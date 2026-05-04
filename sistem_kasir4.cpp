#include <iostream>
using namespace std;
int main() {
	// Deklarasi variabel
    string nama, menu;
    int harga, jumlah, total, bayar, kembalian, diskon = 0, pilihan;
	
	// Input nama pelanggan
    cout << "Masukkan nama pelanggan: ";
    getline(cin, nama);

    // Menampilkan menu makanan
    cout << "\n========= Daftar Menu ===========" << endl;
    cout << " 1. Nasi Ayam Geprek  - Rp 15.000" << endl;
    cout << " 2. Mie Dog-dog       - Rp 15.000" << endl;
    cout << " 3. Nasi Goreng       - Rp 13.000" << endl;
    cout << " 4. Magelangan        - Rp 11.000" << endl;
    cout << " 5. Nasi Omlet        - Rp 10.000" << endl;
    cout << " 6. Es Teh            - Rp  5.000" << endl;
    cout << " 7. Es Jeruk          - Rp  5.000" << endl;
    cout << " 8. Kopi              - Rp  5.000" << endl;
    cout << " 9. Air Es            - Rp  3.000" << endl;
    cout << "10. Air Mineral       - Rp  3.000" << endl;
    cout << "=================================\n" << endl;
    cout << "Masukan Pilihan Menu (1-10): ";
    cin >> pilihan;

    // Validasi & set menu berdasarkan pilihan
    switch (pilihan) {
        case 1:
            menu = "Nasi Ayam Geprek";
            harga = 15000;
            break;
        case 2:
            menu = "Mie Dog-dog";
            harga = 15000;
            break;
        case 3:
            menu = "Nasi Goreng";
            harga = 13000;
            break;
        case 4:
            menu = "Magelangan";
            harga = 11000;
            break;
        case 5:
            menu = "Nasi Omlet";
            harga = 10000;
            break;
        case 6:
            menu = "Es Teh";
            harga = 5000;
            break;
        case 7:
            menu = "Es Jeruk";
            harga = 5000;
            break;
        case 8:
            menu = "Kopi";
            harga = 5000;
            break;
        case 9:
            menu = "Air Es";
            harga = 3000;
            break;
        case 10:
            menu = "Air Mineral";
            harga = 3000;
            break;
        default:
            cout << "Pilihan tidak valid! Masukkan angka 1-10." << endl;
            return 1;
    }

    cout << "Menu dipilih  : " << menu << " - Rp " << harga << endl;

    // Input jumlah pesanan
    cout << "Masukkan jumlah pesanan: ";
    cin >> jumlah;

    // Validasi jumlah
    if (jumlah <= 0) {
        cout << "Jumlah tidak boleh nol atau negatif!" << endl;
        return 1;
    }

    // Proses Total
    total = harga * jumlah;

    // Proses Diskon
    if (total > 105000) {
        diskon = (total * 30) / 100;
        total = total - diskon;
        cout << "Anda mendapat diskon 30%!" << endl;
    }

    cout << "Total tagihan : Rp " << total << endl;

    // Proses Pembayaran
    do {
        cout << "Masukkan jumlah uang bayar: ";
        cin >> bayar;

        if (bayar < total) {
            cout << "Maaf, uang anda kurang. Silakan masukkan kembali." << endl;
        }
    } while (bayar < total);

    kembalian = bayar - total;

    // Output Struk
    cout << "\n===== STRUK PEMESANAN =====" << endl;
    cout << "Nama Pelanggan : " << nama << endl;
    cout << "Menu           : " << menu << endl;
    cout << "Harga Satuan   : Rp " << harga << endl;
    cout << "Jumlah         : " << jumlah << endl;

    // Hanya ditampilkan jika user dapat diskon
    if (diskon > 0) {
        cout << "Diskon (30%)   : Rp " << diskon << endl;
    }

    cout << "Total Bayar    : Rp " << total << endl;
    cout << "Uang Bayar     : Rp " << bayar << endl;
    cout << "Kembalian      : Rp " << kembalian << endl;
    cout << "===========================" << endl;

    return 0;
}

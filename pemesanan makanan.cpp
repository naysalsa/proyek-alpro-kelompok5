#include <iostream>
using namespace std;

int main() {
    string nama, menu;
    int harga, jumlah, total, bayar, kembalian;

    cout << "Masukkan nama pelanggan: ";
    getline(cin, nama);

    cout << "Masukkan nama makanan: ";
    getline(cin, menu);

    cout << "Masukkan harga makanan: ";
    cin >> harga;

    cout << "Masukkan jumlah pesanan: ";
    cin >> jumlah;

    total = harga * jumlah;

    cout << "Masukkan jumlah uang bayar: ";
    cin >> bayar;

    kembalian = bayar - total;

    cout << "\n===== STRUK PEMESANAN =====" << endl;
    cout << "Nama Pelanggan : " << nama << endl;
    cout << "Menu           : " << menu << endl;
    cout << "Harga          : " << harga << endl;
    cout << "Jumlah         : " << jumlah << endl;
    cout << "Total Bayar    : " << total << endl;
    cout << "Uang Bayar     : " << bayar << endl;
    cout << "Kembalian      : " << kembalian << endl;
    cout << "===========================" << endl;

    return 0;
}
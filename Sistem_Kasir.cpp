#include <iostream>
using namespace std;

int main() {
	// Deklarasi variabel
    string nama, menu;
    int harga, jumlah, total, bayar, kembalian, diskon = 0;
	
	// Input 
    cout << "Masukkan nama pelanggan: ";
    getline(cin, nama);

    cout << "Masukkan nama makanan: ";
    getline(cin, menu);

    cout << "Masukkan harga makanan: ";
    cin >> harga;

    cout << "Masukkan jumlah pesanan: ";
    cin >> jumlah;
	
	// Validasi 
	if (harga <= 0 || jumlah <= 0) {
		cout << "Harga atau jumlah tidak boleh negatif ataupun nol";
		return 1; /* Program berhenti saat user mengisi nilai nol 
					atau negatif pada input */
	}
	
	// Proses Total 
    total = harga * jumlah;
	
	// Proses Diskon
	if (total > 105000){
		diskon = (total * 30) / 100;
		total = total - diskon;
		cout << "anda mendapat diskon 30%\n";
	}
	
	cout << "Total tagihan: Rp " << total << endl;
	
	// Proses Pembayaran
	do{
		cout << "Masukkan jumlah uang bayar: ";
    	cin >> bayar;
    	
    	if (bayar < total) {
    		cout << "Maaf uang anda kurang" << endl;
		}
		
		kembalian = bayar - total;
		
	} while (bayar < total);
	
	// Output
    cout << "\n===== STRUK PEMESANAN =====" << endl;
    cout << "Nama Pelanggan : " << nama << endl;
    cout << "Menu           : " << menu << endl;
    cout << "Harga          : " << harga << endl;
    cout << "Jumlah         : " << jumlah << endl;
    
    // Hanya ditampilkan jika user dapat diskon
    if (diskon > 0) {
    	cout << "Diskon (30%)   : " << diskon << endl;
	}
    
    cout << "Total Bayar    : " << total << endl;
    cout << "Uang Bayar     : " << bayar << endl;
    cout << "Kembalian      : " << kembalian << endl;
    cout << "===========================" << endl;

    return 0;
}

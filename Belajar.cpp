#include <iostream>
using namespace std;

// Prosedur untuk menampilkan daftar film
void tampilkanFilm() {
    cout << "\n===== Daftar Film =====\n";
    cout << "1. Spider-Man: No Way Home  (Rp 50,000)\n";
    cout << "2. Avatar: The Way of Water (Rp 60,000)\n";
    cout << "3. The Batman               (Rp 55,000)\n";
    cout << "4. Frozen II                (Rp 45,000)\n";
}

// Fungsi untuk menghitung total harga
float hitungTotalHarga(int jumlahTiket, float hargaPerTiket) {
    return jumlahTiket * hargaPerTiket;
}

// Prosedur untuk mencetak struk pemesanan
void cetakStruk(string nama, string film, int jumlahTiket, float totalHarga) {
    cout << "\n===== Struk Pemesanan =====\n";
    cout << "Nama Pemesan     : " << nama << endl;
    cout << "Film yang Dipilih: " << film << endl;
    cout << "Jumlah Tiket     : " << jumlahTiket << endl;
    cout << "Total Harga      : Rp " << totalHarga << endl;
}

int main() {
    string namaPemesan;
    char pilihanFilm, pemesanan, yt;
    int jumlahTiket;
    float hargaPerTiket;
    string namaFilm, metode;

    cout << "\n===== Selamat Datang di Sistem Pemesanan Tiket Bioskop =====\n";
    cout << "\nMasukkan nama Anda: ";
    getline(cin, namaPemesan);

    do{
    // Menampilkan daftar film
    tampilkanFilm();

    // Input pilihan film
    cout << "\nPilih film (1-4): ";
    cin >> pilihanFilm;

    // Menentukan harga dan nama film berdasarkan pilihan
    switch (pilihanFilm) {
        case '1':
            namaFilm = "Spider-Man: No Way Home";
            hargaPerTiket = 50000;
            break;
        case '2':
            namaFilm = "Avatar: The Way of Water";
            hargaPerTiket = 60000;
            break;
        case '3':
            namaFilm = "The Batman";
            hargaPerTiket = 55000;
            break;
        case '4':
            namaFilm = "Frozen II";
            hargaPerTiket = 45000;
            break;
        default:
            cout << "Pilihan tidak valid! Program dihentikan.\n";
            return 1;
    }

    // Input jumlah tiket
    cout << "Masukkan jumlah tiket: ";
    cin >> jumlahTiket;

    // Validasi jumlah tiket
    if (jumlahTiket <= 0) {
        cout << "Jumlah tiket harus lebih dari 0! Program dihentikan.\n";
        return 1;
    }

    // Menghitung total harga
    float totalHarga = hitungTotalHarga(jumlahTiket, hargaPerTiket);

    // Metode Pembayaran
    cout << "\nSilahkan pilih metode pembayaran anda(D/C):"; cin >> pemesanan;
        if (pemesanan == 'd' || pemesanan == 'D'){
           metode = "Debit";
           totalHarga += 2000; // 2000 adalah biaya admin dari kartu debit

        }else if (pemesanan == 'c'|| pemesanan == 'C'){
           metode = "tunai";
        } else { cout << "Pilihan tidak valid! Program dihentikan.\n";
            return 1;
        }

    // Menampilkan struk pemesanan
    cetakStruk(namaPemesan, namaFilm, jumlahTiket, totalHarga);
    cout << endl;

    // Tanya Kalau Mau Pesan Ulang
    cout << "Apakah mau pesan tiket lagi ?(y/t)"; cin >> yt;
    } while (yt == 'y' || yt == 'Y');
    // Kalau pilih TIDAK/t akan skip ke kata ini
    cout << "Terimakasih Telah Membeli Tiket -- Selamat Menonton\n";

    return 0;
}

#include <iostream>
using namespace std;

const int MAX = 100;

struct Buku {
    string judul;
    string pengarang;
    int halaman;
    string genre;
    string penerbit;
    int tahun_terbit;
};

struct Perpustakaan {
    Buku dataBuku;
    int rakBuku;
};

void tambahBuku(Perpustakaan dataPerpustakaan[], int& jumlahBuku) {
    if (jumlahBuku >= MAX) {
        cout << "Penyimpanan penuh, tidak bisa menambahkan buku lagi." << endl;
        return;
    }

    cout << "Masukkan Judul Buku: ";
    getline(cin, dataPerpustakaan[jumlahBuku].dataBuku.judul);

    cout << "Masukkan Pengarang Buku: ";
    getline(cin, dataPerpustakaan[jumlahBuku].dataBuku.pengarang);

    cout << "Masukkan Halaman Buku: ";
    cin >> dataPerpustakaan[jumlahBuku].dataBuku.halaman;
    cin.ignore();

    cout << "Masukkan Genre Buku: ";
    getline(cin, dataPerpustakaan[jumlahBuku].dataBuku.genre);

    cout << "Masukkan Penerbit Buku: ";
    getline(cin, dataPerpustakaan[jumlahBuku].dataBuku.penerbit);

    cout << "Masukkan Tahun Terbit Buku: ";
    cin >> dataPerpustakaan[jumlahBuku].dataBuku.tahun_terbit;

    cout << "Masukkan Rak Buku: ";
    cin >> dataPerpustakaan[jumlahBuku].rakBuku;
    cin.ignore();

    jumlahBuku++;
    cout << "Buku berhasil ditambahkan." << endl;
}

void tampilkanBuku(Perpustakaan dataPerpustakaan[], int jumlahBuku) {
    if (jumlahBuku == 0) {
        cout << "Belum ada data buku yang tersimpan." << endl;
        return;
    }

    cout << "===== Daftar Buku di Perpustakaan =====" << endl;
    for (int i = 0; i < jumlahBuku; i++) {
        cout << "Buku ke-" << i + 1 << endl;
        cout << "Judul: " << dataPerpustakaan[i].dataBuku.judul << endl;
        cout << "Pengarang: " << dataPerpustakaan[i].dataBuku.pengarang << endl;
        cout << "Halaman: " << dataPerpustakaan[i].dataBuku.halaman << endl;
        cout << "Genre: " << dataPerpustakaan[i].dataBuku.genre << endl;
        cout << "Penerbit: " << dataPerpustakaan[i].dataBuku.penerbit << endl;
        cout << "Tahun Terbit: " << dataPerpustakaan[i].dataBuku.tahun_terbit << endl;
        cout << "Rak Buku: " << dataPerpustakaan[i].rakBuku << endl;
        cout << endl;
    }
}

int main() {
    Perpustakaan dataPerpustakaan[MAX];
    int jumlahBuku = 0;
    int pilihan;

    while (true) {
        cout << "==== Menu Perpustakaan ====" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Tampilkan Buku" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            tambahBuku(dataPerpustakaan, jumlahBuku);
        } else if (pilihan == 2) {
            tampilkanBuku(dataPerpustakaan, jumlahBuku);
        } else if (pilihan == 3) {
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}

#include <iostream>
using namespace std;

struct keretaApi {
    int idGerbong;
    string namaGerbong;
    keretaApi *gerbongLanjutan;
    keretaApi *gerbongSebelumnya;
};

int main() {
    keretaApi *kepalaGerbong = NULL;

    int pilihan;

    do {
        cout << "\n=== MENU CRUD GERBONG KERETA ===\n";
        cout << "1. Tambah Gerbong (Create)\n";
        cout << "2. Tampilkan Gerbong (Read)\n";
        cout << "3. Ubah Nama Gerbong (Update)\n";
        cout << "4. Hapus Gerbong (Delete)\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); // untuk membersihkan newline

        if (pilihan == 1) {
            // CREATE
            keretaApi *gerbongBaru = new keretaApi();
            cout << "Masukkan ID Gerbong: ";
            cin >> gerbongBaru->idGerbong;
            cin.ignore();
            cout << "Masukkan Nama Gerbong: ";
            getline(cin, gerbongBaru->namaGerbong);

            gerbongBaru->gerbongLanjutan = NULL;
            gerbongBaru->gerbongSebelumnya = NULL;

            if (kepalaGerbong == NULL) {
                kepalaGerbong = gerbongBaru;
            } else {
                keretaApi *sementara = kepalaGerbong;
                while (sementara->gerbongLanjutan != NULL) {
                    sementara = sementara->gerbongLanjutan;
                }
                sementara->gerbongLanjutan = gerbongBaru;
                gerbongBaru->gerbongSebelumnya = sementara;
            }

        } else if (pilihan == 2) {
            // READ
            keretaApi *gerbongSekarang = kepalaGerbong;
            int no = 1;
            cout << "\n==== DAFTAR GERBONG ====" << endl;
            while (gerbongSekarang != NULL) {
                cout << no << ". ID: " << gerbongSekarang->idGerbong
                     << ", Nama: " << gerbongSekarang->namaGerbong << endl;
                gerbongSekarang = gerbongSekarang->gerbongLanjutan;
                no++;
            }

        } else if (pilihan == 3) {
            // UPDATE
            int idCari;
            cout << "Masukkan ID Gerbong yang ingin diubah: ";
            cin >> idCari;
            cin.ignore();

            keretaApi *cari = kepalaGerbong;
            bool ditemukan = false;

            while (cari != NULL) {
                if (cari->idGerbong == idCari) {
                    cout << "Nama lama: " << cari->namaGerbong << endl;
                    cout << "Masukkan Nama Baru: ";
                    getline(cin, cari->namaGerbong);
                    ditemukan = true;
                    break;
                }
                cari = cari->gerbongLanjutan;
            }

            if (!ditemukan) {
                cout << "Gerbong dengan ID " << idCari << " tidak ditemukan!" << endl;
            }

        } else if (pilihan == 4) {
            // DELETE
            int idHapus;
            cout << "Masukkan ID Gerbong yang ingin dihapus: ";
            cin >> idHapus;

            keretaApi *hapus = kepalaGerbong;

            while (hapus != NULL) {
                if (hapus->idGerbong == idHapus) {
                    if (hapus->gerbongSebelumnya == NULL && hapus->gerbongLanjutan == NULL) {
                        kepalaGerbong = NULL;
                    } else if (hapus->gerbongSebelumnya == NULL) {
                        kepalaGerbong = hapus->gerbongLanjutan;
                        kepalaGerbong->gerbongSebelumnya = NULL;
                    } else if (hapus->gerbongLanjutan == NULL) {
                        hapus->gerbongSebelumnya->gerbongLanjutan = NULL;
                    } else {
                        hapus->gerbongSebelumnya->gerbongLanjutan = hapus->gerbongLanjutan;
                        hapus->gerbongLanjutan->gerbongSebelumnya = hapus->gerbongSebelumnya;
                    }
                    delete hapus;
                    cout << "Gerbong berhasil dihapus!" << endl;
                    break;
                }
                hapus = hapus->gerbongLanjutan;
            }

            if (hapus == NULL) {
                cout << "Gerbong dengan ID tersebut tidak ditemukan." << endl;
            }
        }

    } while (pilihan != 0);

    return 0;
}
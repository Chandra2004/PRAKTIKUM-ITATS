#include <iostream>
#include <string>

using namespace std;

struct Pegawai {
    int id;
    string nama;
    Pegawai* sebelumnya;
    Pegawai* berikutnya;
};

int main() {
    Pegawai* kepala = nullptr;
    Pegawai* ekor = nullptr;
    int jumlahPegawai;

    cout << "Masukkan jumlah pegawai: ";
    cin >> jumlahPegawai;
    cin.ignore();

    if (jumlahPegawai < 0) {
        cout << "Jumlah pegawai tidak valid!" << endl;
        return 1;
    }

    int idSekarang = 1;
    for (int i = 0; i < jumlahPegawai; ++i) {
        string nama;
        cout << "Masukkan Nama Pegawai ke-" << (i + 1) << ": ";
        getline(cin, nama);

        Pegawai* pegawaiBaru = new Pegawai;
        pegawaiBaru->id = idSekarang++;
        pegawaiBaru->nama = nama;
        pegawaiBaru->sebelumnya = nullptr;
        pegawaiBaru->berikutnya = nullptr;

        if (kepala == nullptr) {
            kepala = pegawaiBaru;
            ekor = pegawaiBaru;
        } else {
            ekor->berikutnya = pegawaiBaru;
            pegawaiBaru->sebelumnya = ekor;
            ekor = pegawaiBaru;
        }
    }

    cout << "\nDaftar Pegawai:\n";
    Pegawai* saatIni = kepala;
    while (saatIni) {
        cout << "ID: " << saatIni->id << ", Nama: " << saatIni->nama << endl;
        saatIni = saatIni->berikutnya;
    }

    char pilihan;
    cout << "\nHapus pegawai dengan ID ganjil atau genap? (g/e): ";
    cin >> pilihan;

    saatIni = kepala;
    switch (tolower(pilihan)) {
        case 'g': {
            while (saatIni) {
                if (saatIni->id % 2 != 0) {
                    Pegawai* hapus = saatIni;
                    if (saatIni->sebelumnya) {
                        saatIni->sebelumnya->berikutnya = saatIni->berikutnya;
                    }
                    if (saatIni->berikutnya) {
                        saatIni->berikutnya->sebelumnya = saatIni->sebelumnya;
                    }
                    if (saatIni == kepala) {
                        kepala = saatIni->berikutnya;
                    }
                    if (saatIni == ekor) {
                        ekor = saatIni->sebelumnya;
                    }
                    saatIni = saatIni->berikutnya;
                    cout << "Pegawai dengan ID " << hapus->id << " dihapus.\n";
                    delete hapus;
                } else {
                    saatIni = saatIni->berikutnya;
                }
            }
            break;
        }
        case 'e': {
            while (saatIni) {
                if (saatIni->id % 2 == 0) {
                    Pegawai* hapus = saatIni;
                    if (saatIni->sebelumnya) {
                        saatIni->sebelumnya->berikutnya = saatIni->berikutnya;
                    }
                    if (saatIni->berikutnya) {
                        saatIni->berikutnya->sebelumnya = saatIni->sebelumnya;
                    }
                    if (saatIni == kepala) {
                        kepala = saatIni->berikutnya;
                    }
                    if (saatIni == ekor) {
                        ekor = saatIni->sebelumnya;
                    }
                    saatIni = saatIni->berikutnya;
                    cout << "Pegawai dengan ID " << hapus->id << " dihapus.\n";
                    delete hapus;
                } else {
                    saatIni = saatIni->berikutnya;
                }
            }
            break;
        }
        default:
            cout << "Pilihan tidak valid!" << endl;
    }

    cout << "\nDaftar Pegawai Setelah Penghapusan:\n";
    if (kepala == nullptr) {
        cout << "Tidak ada pegawai tersisa." << endl;
    } else {
        saatIni = kepala;
        while (saatIni) {
            cout << "ID: " << saatIni->id << ", Nama: " << saatIni->nama << endl;
            saatIni = saatIni->berikutnya;
        }
    }

    saatIni = kepala;
    while (saatIni) {
        Pegawai* temp = saatIni;
        saatIni = saatIni->berikutnya;
        delete temp;
    }
    kepala = nullptr;
    ekor = nullptr;

    return 0;
}
#include <iostream>
using namespace std;

struct Pegawai {
    string nama;

    Pegawai *pegawaiSelanjutnya;
};

int main() {
    Pegawai *ketuaPegawai = NULL;

    int pilihan;
    while(true) {
        cout << "1. Tampilkan Pegawai" << endl;
        cout << "2. Tambah Pegawai" << endl;
        cout << "3. Update Pegawai" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();

        if(pilihan == 1) {
            system("clear");
            Pegawai *pegawaiSekarang = ketuaPegawai;
            int no = 1;
            cout << "\n==== DAFTAR PEGAWAI ====" << endl;
            while(pegawaiSekarang != NULL) {
                cout << no << ". Nama: " << pegawaiSekarang->nama << endl;
                pegawaiSekarang = pegawaiSekarang->pegawaiSelanjutnya;
                no++;
            }
            cout << endl << endl;
        } else if(pilihan == 2) {
            Pegawai *pegawaiBaru = new Pegawai();
            cout << "Nama Pegawai : ";
            getline(cin, pegawaiBaru->nama);

            pegawaiBaru->pegawaiSelanjutnya = NULL;

            if(ketuaPegawai == NULL) {
                ketuaPegawai = pegawaiBaru;
            } else {
                Pegawai *pegawaiSementara = ketuaPegawai;
                while(pegawaiSementara->pegawaiSelanjutnya != NULL) {
                    pegawaiSementara = pegawaiSementara->pegawaiSelanjutnya;
                }
                pegawaiSementara->pegawaiSelanjutnya = pegawaiBaru;
            }
        } else if(pilihan == 3) {
            string cariNama;
            bool namaDitemukan = false;

            cout << "Nama Pegawai yang ingin diupdate: ";
            getline(cin, cariNama);

            Pegawai *cariPegawai = ketuaPegawai;
            while(cariPegawai != NULL) {
                if(cariPegawai->nama == cariNama) {
                    cout << "Nama Lama : " << cariPegawai->nama << endl;
                    cout << "---------------------" << endl;
                    cout << "Nama Baru : ";
                    getline(cin, cariPegawai->nama);
                    namaDitemukan = true;
                    break;
                }
                cariPegawai = cariPegawai->pegawaiSelanjutnya;
            }

            if(!namaDitemukan) {
                cout << "Nama Pegawai Tidak Ditemukan" << endl << endl;
            } else {
                cout << "Nama Berhasil Diganti" << endl << endl;
            }
        } else if(pilihan == 4) {
            return false;
        }
    }    
}
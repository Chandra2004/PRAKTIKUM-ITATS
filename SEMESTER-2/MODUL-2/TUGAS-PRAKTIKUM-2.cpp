#include <iostream>
using namespace std;

struct Pegawai {
    string nama;
    string jabatan;
    string NIP;
    string gaji;
    string kelamin;

    Pegawai *pegawaiSelanjutnya;
    Pegawai *pegawaiSebelumnya;
};

int main() {
    Pegawai *ketuaPegawai = NULL;
    Pegawai *wakilPegawai = NULL;

    int pilihan;

    while(true) {
        cout << "==== Menu Pegawai ====" << endl;
        cout << "1. Tambah Pegawai (Dari Belakang)" << endl;
        cout << "2. Tampilkan Pegawai" << endl;
        cout << "3. Hapus Pegawai (Dari Depan)" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();

        if(pilihan == 1) {
            Pegawai *pegawaiBaru = new Pegawai;
            cout << "Nama Pegawai : ";
            getline(cin, pegawaiBaru->nama);
            cout << "Jabatan Pegawai : ";
            getline(cin, pegawaiBaru->jabatan);
            cout << "NIP Pegawai : ";
            getline(cin, pegawaiBaru->NIP);
            cout << "Gaji Pegawai : ";
            getline(cin, pegawaiBaru->gaji);
            cout << "Kelamin Pegawai : ";
            getline(cin, pegawaiBaru->kelamin);

            pegawaiBaru->pegawaiSelanjutnya = NULL;
            pegawaiBaru->pegawaiSebelumnya = NULL;

            if(ketuaPegawai == NULL) {
                ketuaPegawai = pegawaiBaru;
                wakilPegawai = pegawaiBaru;
            } else {
                Pegawai *pegawaiSementara = ketuaPegawai;
                while(pegawaiSementara->pegawaiSelanjutnya != NULL) {
                    pegawaiSementara = pegawaiSementara->pegawaiSelanjutnya;
                }
                pegawaiSementara->pegawaiSelanjutnya = pegawaiBaru;
                pegawaiBaru->pegawaiSebelumnya = pegawaiSementara;
            }
            system("clear");
        } else if(pilihan == 2) {
            Pegawai *pegawaiSekarang = ketuaPegawai;
            int no = 1;
            cout << "\n==== DAFTAR PEGAWAI ====" << endl;
            while(pegawaiSekarang != NULL) {
                cout << no << ". Nama: " << pegawaiSekarang->nama
                     << ", Jabatan: " << pegawaiSekarang->jabatan
                     << ", NIP: " << pegawaiSekarang->NIP
                     << ", Gaji: " << pegawaiSekarang->gaji
                     << ", Kelamin: " << pegawaiSekarang->kelamin 
                     << ", Karyawan Selanjutnya: " 
                     << (pegawaiSekarang->pegawaiSelanjutnya ? pegawaiSekarang->pegawaiSelanjutnya->nama : "NULL")
                     << ", Karyawan Sebelumnya: " 
                     << (pegawaiSekarang->pegawaiSebelumnya ? pegawaiSekarang->pegawaiSebelumnya->nama : "NULL")
                     << endl;
                pegawaiSekarang = pegawaiSekarang->pegawaiSelanjutnya;
                no++;
            }
            cout << endl << endl;
        } else if(pilihan == 3) {
            if(ketuaPegawai != NULL) {
                Pegawai *hapusPegawai = ketuaPegawai;
                ketuaPegawai = ketuaPegawai->pegawaiSelanjutnya;
                if(ketuaPegawai != NULL) {
                    ketuaPegawai->pegawaiSebelumnya = NULL;
                } else {
                    wakilPegawai = NULL;
                }
                delete hapusPegawai;
                cout << "Pegawai berhasil dihapus!" << endl;
            } else {
                cout << "Tidak ada pegawai untuk dihapus!" << endl;
            }
        } else if(pilihan == 4) {
            return false;
        }
    }
}
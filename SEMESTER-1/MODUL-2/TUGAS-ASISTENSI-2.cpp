#include <iostream>
using namespace std;

int main() {
    int usiaPenduduk;
    float pendapatanPenduduk;
    float tanggunganPenduduk;
    int statusPenduduk;

    cout << "Masukkan usia penduduk: ";
    cin >> usiaPenduduk;

    cout << "1. Bekerja" << endl;
    cout << "2. Sekolah" << endl;
    cout << "Masukkan status : ";
    cin >> statusPenduduk;

    if(usiaPenduduk < 18 && statusPenduduk == 1) {
        cout << "Anda masih dibawah umur";
    }

    if(usiaPenduduk < 18) {
        if(statusPenduduk == 2) {
            cout << "Anda bukan penduduk miskin (Karena masih bersekolah)" << endl;
        } else if(usiaPenduduk > 18) {
            cout << "Anda penduduk miskin" << endl;
        }
    } else {
        if(statusPenduduk == 1) {
            cout << "Masukkan gaji :";
            cin >> pendapatanPenduduk;

            cout << "Masukkan tanggungan :";
            cin >> tanggunganPenduduk;

            pendapatanPenduduk = pendapatanPenduduk / tanggunganPenduduk;

            if(pendapatanPenduduk >= 300000) {
                cout << "Anda bukan penduduk miskin (Karena sudah bekerja)" << endl;
            } else {
                cout << "Tidak Tersisa (Kurang Mampu)" << endl;
            }
        } else {
            cout << "Hanya 2 pilihan yang tersedia";
        }
    } 
}
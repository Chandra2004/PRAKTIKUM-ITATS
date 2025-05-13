#include <iostream>
using namespace std;

int main() {
    string namaUser;
    int hitungNama;


    cout << "==================================" << endl;
    for(int i = 1; i <= 2; i++) {
        cout << "Masukkan sebuah nama : ";
        getline(cin, namaUser);

        hitungNama = namaUser.length();
        cout << "Panjang nama " << namaUser << " adalah " << hitungNama << endl;
        cout << "==================================" << endl;
    }
}
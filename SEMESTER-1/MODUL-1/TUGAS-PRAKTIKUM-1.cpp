#include <iostream>
using namespace std;

int main() {
    float jariJari;
    float tinggi;
    float hasil;

    cout << "==== MENGHITUNG VOLME KERUCUT ====" << endl;
    cout << "Masukkan jari-jari: ";
    cin >> jariJari;
    cout << "Masukkan tinggi: ";
    cin >> tinggi;
    cout << "==================================" << endl;
    hasil = (3.14 * jariJari * jariJari * tinggi) / 3;
    cout << "Volume kerucut adalah: " << hasil << endl;
    cout << "==================================" << endl;

    return 0;
}
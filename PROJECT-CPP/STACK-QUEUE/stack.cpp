#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> tumpukan;

    // Menambahkan elemen
    tumpukan.push(10);
    tumpukan.push(20);
    tumpukan.push(30);
    tumpukan.push(500); // <-- Last In

    // Menampilkan dan menghapus elemen
    // cout << "Atas 1 : " << tumpukan.top() << endl; // <-- First Out
    // tumpukan.pop();
    // tumpukan.pop();
    // cout << "Atas 1 : " << tumpukan.top() << endl;

    //  top() lihat data yang paling atas
    cout << "lala : " << tumpukan.top() << endl;
    




    // while(!tumpukan.empty()) {
    //     cout << "Atas : " << tumpukan.top() << endl;
    //     tumpukan.pop();
    // }

    return 0;
}
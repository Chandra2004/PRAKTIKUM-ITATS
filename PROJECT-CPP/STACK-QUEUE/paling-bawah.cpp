#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    stack<int> temp;
    int angka;

    s.push(200);
    s.push(20);
    s.push(30); // ini paling atas
    s.push(40); // ini yang paling baru / paling atas

    angka = s.top();
    cout << "Elemen belum adalah: " << angka << endl;
    s.pop();
    temp.push(angka);

    angka = s.top();
    cout << "Elemen belum adalah: " << angka << endl;
    s.pop();
    temp.push(angka);

    angka = s.top();
    cout << "Elemen belum adalah: " << angka << endl;
    s.pop();
    temp.push(angka);
    
    angka = s.top();
    cout << "Elemen belum adalah: " << angka << endl;
    s.pop();
    temp.push(angka);

    cout << "Elemen Sudah Dibalik : " << temp.top() << endl;
    temp.pop();
    cout << "Elemen Sudah Dibalik : " << temp.top() << endl;
    temp.pop();
    cout << "Elemen Sudah Dibalik : " << temp.top() << endl;
    temp.pop();
    cout << "Elemen Sudah Dibalik : " << temp.top() << endl;
    temp.pop();

    return 0;
}

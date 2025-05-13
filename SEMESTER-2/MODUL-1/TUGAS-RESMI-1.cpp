#include <iostream> 
using namespace std; 

struct Nilai { 
    float quiz; 
    float uts; 
    float uas; 
    float total; 
    char grade; 
};

struct Mahasiswa { 
    string nama; 
    int nim; 
    Nilai nilai; 
};

int main() { 
    int jumlah; 
    cout << "Masukkan jumlah mahasiswa: "; 
    cin >> jumlah; 
    cin.ignore(); 
    Mahasiswa mhs[jumlah]; 
    for (int i = 0; i < jumlah; i++) { 
        cout << "\nMahasiswa ke-" << i + 1 << endl; 

        cout << "Masukkan nama: "; 
        getline(cin, mhs[i].nama); 
        
        cout << "Masukkan NIM: ";
        cin >> mhs[i].nim; 
        
        cout << "Masukkan nilai QUIZ: "; 
        cin >> mhs[i].nilai.quiz; 
        
        cout << "Masukkan nilai UTS: "; 
        cin >> mhs[i].nilai.uts; 
        
        cout << "Masukkan nilai UAS: "; 
        cin >> mhs[i].nilai.uas; 
        cin.ignore(); 
        
        mhs[i].nilai.total = (mhs[i].nilai.quiz * 0.2) + (mhs[i].nilai.uts * 0.3) + (mhs[i].nilai.uas * 0.5); 

        if (mhs[i].nilai.total >= 80) {
            mhs[i].nilai.grade = 'A'; 
        } else if (mhs[i].nilai.total >= 70) {
            mhs[i].nilai.grade = 'B'; 
        } else if (mhs[i].nilai.total >= 60) {
            mhs[i].nilai.grade = 'C'; 
        } else if (mhs[i].nilai.total >= 50) {
            mhs[i].nilai.grade = 'D'; 
        } else {
            mhs[i].nilai.grade = 'E';
        }
    } 

    cout << "\nData Seluruh Mahasiswa\n"; 
    for (int i = 0; i < jumlah; i++) { 
        cout << "\nMahasiswa ke-" << i + 1 << endl; 
        cout << "Nama: " << mhs[i].nama << endl; 
        cout << "NIM: " << mhs[i].nim << endl; 
        cout << "Nilai QUIZ: " << mhs[i].nilai.quiz << endl; 
        cout << "Nilai UTS: " << mhs[i].nilai.uts << endl; 
        cout << "Nilai UAS: " << mhs[i].nilai.uas << endl; 
        cout << "Total Nilai: " << mhs[i].nilai.total << 
        endl; 
        cout << "Grade: " << mhs[i].nilai.grade << endl; 
    } 
    return 0; 
}
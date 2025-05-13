#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int pilihan, data, posisi;

    do {
        cout << "\n=== MENU DOUBLE LINKED LIST ===\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Tengah (sisipkan)\n";
        cout << "3. Tambah Akhir\n";
        cout << "4. Hapus Depan\n";
        cout << "5. Hapus Tengah\n";
        cout << "6. Hapus Akhir\n";
        cout << "7. Tampilkan\n";
        cout << "8. Ubah Data (Update)\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan data: ";
            cin >> data;
            Node* baru = new Node{data, nullptr, head};
            if (head != nullptr) head->prev = baru;
            head = baru;
            if (tail == nullptr) tail = head;

        } else if (pilihan == 2) {
            cout << "Masukkan data: ";
            cin >> data;
            cout << "Masukkan posisi (mulai dari 1): ";
            cin >> posisi;

            if (posisi <= 1 || head == nullptr) {
                Node* baru = new Node{data, nullptr, head};
                if (head != nullptr) head->prev = baru;
                head = baru;
                if (tail == nullptr) tail = head;
            } else {
                Node* temp = head;
                for (int i = 1; i < posisi - 1 && temp->next != nullptr; ++i) {
                    temp = temp->next;
                }
                Node* baru = new Node{data, temp, temp->next};
                if (temp->next != nullptr) temp->next->prev = baru;
                temp->next = baru;
                if (baru->next == nullptr) tail = baru;
            }

        } else if (pilihan == 3) {
            cout << "Masukkan data: ";
            cin >> data;
            Node* baru = new Node{data, tail, nullptr};
            if (tail != nullptr) tail->next = baru;
            tail = baru;
            if (head == nullptr) head = tail;

        } else if (pilihan == 4) {
            if (head != nullptr) {
                Node* hapus = head;
                head = head->next;
                if (head != nullptr) head->prev = nullptr;
                else tail = nullptr;
                delete hapus;
                cout << "Data paling depan berhasil dihapus.\n";
            } else {
                cout << "List kosong\n";
            }

        } else if (pilihan == 5) {
            cout << "Masukkan posisi yang ingin dihapus: ";
            cin >> posisi;

            if (posisi <= 1 || head == nullptr || head->next == nullptr) {
                cout << "Posisi tidak valid untuk hapus tengah, gunakan hapus awal/akhir\n";
            } else {
                Node* temp = head;
                for (int i = 1; i < posisi && temp != nullptr; ++i) {
                    temp = temp->next;
                }
                if (temp != nullptr && temp != head && temp != tail) {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    cout << "Data pada posisi " << posisi << " berhasil dihapus.\n";
                } else {
                    cout << "Posisi tidak ditemukan atau tidak valid\n";
                }
            }

        } else if (pilihan == 6) {
            if (tail != nullptr) {
                Node* hapus = tail;
                tail = tail->prev;
                if (tail != nullptr) tail->next = nullptr;
                else head = nullptr;
                delete hapus;
                cout << "Data paling akhir berhasil dihapus.\n";
            } else {
                cout << "List kosong\n";
            }

        } else if (pilihan == 7) {
            Node* temp = head;
            cout << "Isi Double Linked List: ";
            while (temp != nullptr) {
                cout << temp->data << " <-> ";
                temp = temp->next;
            }
            cout << "NULL\n";

        } else if (pilihan == 8) {
            cout << "Masukkan posisi data yang ingin diubah: ";
            cin >> posisi;
            cout << "Masukkan nilai baru: ";
            cin >> data;

            Node* temp = head;
            int index = 1;
            while (temp != nullptr && index < posisi) {
                temp = temp->next;
                index++;
            }

            if (temp != nullptr) {
                temp->data = data;
                cout << "Data pada posisi " << posisi << " berhasil diubah.\n";
            } else {
                cout << "Posisi tidak ditemukan.\n";
            }
        }

    } while (pilihan != 0);

    // Bersihkan memori sebelum keluar
    while (head != nullptr) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }

    return 0;
}
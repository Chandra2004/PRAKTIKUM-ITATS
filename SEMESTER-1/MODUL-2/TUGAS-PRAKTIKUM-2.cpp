#include <iostream>
using namespace std;

int main() {
    for(int i = 5; i >= 1; i--) {
        if(i % 2 != 1) {
            for(int j = 5; j >= 6 - i; j--) {
                cout << j << " ";
            }
        }

        if(i % 2 == 1) {
            for(int j = 1; j <= i; j++) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}
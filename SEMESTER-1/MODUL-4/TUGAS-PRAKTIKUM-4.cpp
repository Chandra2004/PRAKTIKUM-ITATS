#include <iostream>
using namespace std;
#include "header.h"

int main() {
    double totalGames;
    double currentWins;
    double targetWinrate;

    cout << "Masukkan jumlah total permainan : ";
    cin >> totalGames;

    cout << "Masukkan jumlah kemenangan : ";
    cin >> currentWins;

    cout << "Winrate saat ini : " << (currentWins * 100.0 / totalGames) << "%" << endl;
    
    cout << "Masukkan winrate target (%) : ";
    cin >> targetWinrate;

    cout << "Jumlah kemenangan yang diperlukan untuk mencapai winrate : " << hitungTarget(totalGames, currentWins, targetWinrate) << endl;
}
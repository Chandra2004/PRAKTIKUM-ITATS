int hitungTarget(double totalGames, double currentWins,double targetWinrate) {
    int kemenanganDiperlukan = 0;
    while(((currentWins + kemenanganDiperlukan) / (totalGames + kemenanganDiperlukan) *100) < targetWinrate) {
        kemenanganDiperlukan++;
    }
    return kemenanganDiperlukan;
}
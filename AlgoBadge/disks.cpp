#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    long long inizio, fine, tempoMAN;
    cin >> inizio >> fine >> tempoMAN;
    long long OreNonUt = 24 - (fine - inizio);

    long long downtime;

    if (tempoMAN <= OreNonUt) {
        downtime = 0;
    } else {
        long long giorni = tempoMAN / 24;
        long long oreRimanenti = tempoMAN % 24;
        if (oreRimanenti <= OreNonUt) {
            downtime = giorni * (fine - inizio);
        } else {
            downtime = giorni * (fine - inizio) + (oreRimanenti - OreNonUt);
        }
    }


    cout << downtime << endl;

    return 0;
}
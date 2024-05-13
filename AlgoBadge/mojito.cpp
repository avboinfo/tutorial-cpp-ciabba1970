//riccardo sabattini
//27/04/24
//nsieme a Marcucci

#include <iostream>
using namespace std;

int main() {
    int Mojito;
    cin >> Mojito;
    for (int t = 1; t <= Mojito; t++) {
        int N, F, C;
        cin >> N >> F >> C;
        int Musica = N / F;
        int canzoni = (N - Musica * F) / C;
        cout << "Caso #" << t << ": " << Musica << " " << canzoni << endl;
    }
    return 0;
}
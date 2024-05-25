#include <iostream>
using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    int prezzi[n]; 
    bool Vettore[n] = {false}; 

    for (int i = 0; i < n; ++i) {
        cin >> prezzi[i];
    }

    int spesaTOT = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (!Vettore[j] && spesaTOT + prezzi[j] <= b) {
                spesaTOT += prezzi[j];
                Vettore[j] = true; 
            }
        }
    }


    cout << "I piatti che Gabrie dovrà ordinare per stare nel budget sono:" << endl;
    for (int i = 0; i < n; ++i) {
        if (Vettore[i]) {
            cout << prezzi[i] << " ¥" << endl;
        }
    }

    return 0;
}

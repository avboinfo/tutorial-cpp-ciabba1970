
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    vector<int> prezzi(n);
    for (int i = 0; i < n; i++) {
        cin >> prezzi[i];
    }

    vector<int> piatti_scelti;
    int spesa_totale = 0;

    for (int i = 0; i < n; i++) {
        int miglior_piatto = -1;
        for (int j = 0; j < n; j++) {
            if (prezzi[j] != -1 && spesa_totale + prezzi[j] <= b && (miglior_piatto == -1 || prezzi[j] > prezzi[miglior_piatto])) {
                miglior_piatto = j;
            }
        }

        if (miglior_piatto != -1) {
            spesa_totale += prezzi[miglior_piatto];
            piatti_scelti.push_back(prezzi[miglior_piatto]);
            prezzi[miglior_piatto] = -1;
        } else {
            break;
        }
    }

    for (int prezzo : piatti_scelti) {
        cout << prezzo << endl;
    }

    return 0;
}


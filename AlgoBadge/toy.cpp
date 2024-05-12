#include <iostream>
#include <vector>
//ancora da finire o rifare
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    int K = 0;

    int pos = 0;
    for (int i = 0; i < N; ++i) {
        if (P[i] == 1) {
            pos = i;
            break;
        }
    }

    K = pos;

    bool ordinato = true;
    for (int i = 1; i < N; ++i) {
        if (P[(pos + i) % N] != i + 1) {
            ordinato = false;
            break;
        }
    }

    if (!ordinato) {
        int suffisso_piu_lungo = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (P[i] == N - suffisso_piu_lungo) {
                suffisso_piu_lungo++;
            } else {
                break;
            }
        }

        K = max(K, N - suffisso_piu_lungo);
    }

    cout << K << endl;

    return 0;
}

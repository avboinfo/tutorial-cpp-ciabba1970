#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N1, N2, N3, N4, M;
        cin >> N1 >> N2 >> N3 >> N4 >> M;

        vector<string> files(4);
        for (int i = 0; i < 4; ++i) {
            cin >> files[i];
        }

        string virus;

        for (int i = 0; i <= N1 - M; ++i) {
            virus = files[0].substr(i, M);

            bool found = true;
            for (int j = 1; j < 4; ++j) {
                if (files[j].find(virus) == string::npos) {
                    found = false;
                    break;
                }
            }

            if (found) {
                cout << "Case #" << t << ": " << i << " ";
                for (int j = 1; j < 4; ++j) {
                    cout << files[j].find(virus) << " ";
                }
                cout << endl;
                break;
            }
        }
    }

    return 0;
}

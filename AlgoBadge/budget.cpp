#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    const int MAX_N = 5000; 
    int n, b;
    cin >> n >> b;

    int tutti_i_prezzi[MAX_N];
    for (int i = 0; i < n; i++) {
        cin >> tutti_i_prezzi[i];
    }
    
    vector<int> massima_spesa_possibile(b + 1, 0);
    vector<vector<bool>> used(n, vector<bool>(b + 1, false));

    for (int i = 0; i < n; i++) {
        for (int j = b; j >= tutti_i_prezzi[i]; j--) {
            if (massima_spesa_possibile[j - tutti_i_prezzi[i]] + tutti_i_prezzi[i] > massima_spesa_possibile[j]) {
                massima_spesa_possibile[j] = massima_spesa_possibile[j - tutti_i_prezzi[i]] + tutti_i_prezzi[i];
                used[i][j] = true;
            }
        }
    }
    
    vector<int> result;
    int budget_che_rimane = b;
    for (int i = n - 1; i >= 0 && budget_che_rimane > 0; i--) {
        if (used[i][budget_che_rimane]) {
            result.push_back(tutti_i_prezzi[i]);
            budget_che_rimane -= tutti_i_prezzi[i];
        }
    }
    
    for (const int & prezzo : result) {
        cout << prezzo << endl;
    }
    
    return 0;
}

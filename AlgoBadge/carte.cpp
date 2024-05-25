#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int scarta(int C, vector<bool> L, vector<bool> D, vector<bool> N) {
    int carte_avanzate = C;
    
    for(int i = 0; i < C; ++i) {
        //carta laminata
        if(L[i] && !D[i] && !N[i]) {
            carte_avanzate--;
        }
        // carta aria
        else if(!L[i] && D[i] && !N[i]) {
            carte_avanzate--;
        }
        // carta nere
        else if(!L[i] && !D[i] && N[i]) {
            carte_avanzate--;
        }
    }
    
    return carte_avanzate;
}

int main() {

  int C;
  cin >> C;

  vector<bool> L(C, false), D(C, false), N(C, false);
  for (int i = 0; i < C; i++) {
    int l, d, n;
    cin >> l >> d >> n;
    if (l) L[i] = true;
    if (d) D[i] = true;
    if (n) N[i] = true;
  }

  cout << scarta(C, L, D, N);

  return 0;
}
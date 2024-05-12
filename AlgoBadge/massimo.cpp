#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int trova_massimo(int N, vector<int> V) {
    int c=0;
    for (int i = 0; i < N; i++)
    {
        if (V[c]<V[i])      
        {
            c=i;
        }
        
    }
    
    

    return V[c];
}
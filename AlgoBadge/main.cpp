#include <stdio.h>
#include <assert.h>

int compra(int N, int M, int A, int B) {
    int carnet_op = 0;
    bool real = false;
    int costo = 0;
    
    if (A < B) {
        real = true;
        carnet_op = A * M;
    }
    
    while (N >= M) {
        if (real) {
            N -= M;
            costo += carnet_op;
        } else {
            N -= M;
            costo += B;
        }
    }
    
    while (N > 0) {
        if (B < A * N) {
            costo += B;
            break;
        } else {
            N--;
            costo += A;
        }
    }
    
    return costo;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;
    fr = fopen("input.txt", "r");
    assert(4 == fscanf(fr, "%d %d %d %d", &N, &M, &A, &B));
    
    int risultato = compra(N, M, A, B);
    
    fw = fopen("output.txt", "w");
    fprintf(fw, "%d\n", risultato);
    
    fclose(fr);
    fclose(fw);
    
    return 0;
}

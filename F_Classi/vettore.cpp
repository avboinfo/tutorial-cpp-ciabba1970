#include <iostream> 
using namespace std;

class Vettore {
protected:
    int dim, len, delta;
    int *v;
public:
    Vettore(int dim, int delta) {
        this->dim = dim;
        this->delta = delta; 
        len = 0;
        v = new int[dim];
    }

    void add(int n){
        if(len == dim) {
            cout << "estendo da " << dim << " a " << dim+delta << endl;
            int *nuovov = new int[dim + delta];
            for(int i = 0; i < dim; i++) nuovov[i] = v[i];
            dim += delta;
            delete[] v; 

            v = nuovov;
        }
        v[len] = n;
        len++;
    }

    void print(){
        cout << "contenuto del vettore:";
        for(int i = 0; i < len; i++) cout << v[i] << " ";
        cout << endl;
    }

    ~Vettore() {
        delete[] v; 
    }
};

int main(int argc, char * argv[]){
    Vettore vett(10, 2);
    for(int i = 0; i < 15; i++) vett.add(33 * i);
    vett.print();
}
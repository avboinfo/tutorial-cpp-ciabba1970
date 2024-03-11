#include <iostream>
using namespace std;

class Pila {
protected: //s
    int dim, len, delta;
    int *v;
public:
    Pila(int dim, int delta) {
        this->dim = dim;
        this->delta = delta;
        len = 0;
        v = new int[dim];
    }

    void push(int n){
        if(len == dim) {
            int *nuovov = new int[dim + delta];
            for(int i = 0; i < dim; i++) nuovov[i] = v[i];
            dim += delta;
            delete[] v;
            v = nuovov;
        }
        v[len] = n;
        len++;
    }

    int pop(){
        if(len==0){cout<<"\nERRORE PILA VUOTA\n";return 0;}
        int result = v[len-1];
        len--;
        return result;
    }
    int getElement(int index){
        return v[index];
    }
    int setElement(int index, int newvalue){
        v[index]= newvalue;
    }
    void print(){
        cout << "contenuto della Pila:";
        for(int i = 0; i < len; i++) cout << v[i] << " ";
        cout << endl;
    }

    ~Pila() {
        delete[] v;
    }
};

int main(int argc, char * argv[]){
    Pila vett(10, 2);
    for(int i = 0; i < 100; i++) vett.push(i);
    for (int i = 0; i < 100; i++){

        cout<<vett.pop()<<" ";
        
    }
    cout<<endl;

    vett.print();
}

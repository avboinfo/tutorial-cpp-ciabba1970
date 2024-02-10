/*
* Legge da un file di input un vettore di stringhe
* e produce un file di output con il vettore ordinato
* Sandro Gallo - 5/2/2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

const string FILENAME = "SortingArray.txt";
int numeroscambi;
const int MAX_SIZE = 100;

void swap(string arr[], int pos1, int pos2){
    string temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
    numeroscambi++;
}

int partition(string arr[], int low, int high, string pivot){
    int i = low;
    int j = low;
    while( i <= high){
        if(arr[i] > pivot){
            i++;
        }
        else{
            swap(arr,i,j);
            i++;
            j++;
        }
    }
    return j-1;
}

void stampaVettore(string vs[], int l) {
    cout << endl;
    for (int i = 0; i < l; i++) cout << vs[i] << "\n";
    cout << endl;
}

void quickSort(string arr[], int low, int high){
    if(low < high){
        string pivot = arr[high];
        int pos = partition(arr, low, high, pivot);
        
        quickSort(arr, low, pos-1);
        quickSort(arr, pos+1, high);
    }
}

int main()
{
    ifstream f;
    f.open(FILENAME);
    if ( f.fail() ) { cout << "Il file di input non esiste"; return -1; }

    int n;
    string s;
    for (n = 0; getline(f, s); n++);
    f.close();
    cout << "Il file di input contiene " << n << " righe" << endl;

    string vs[MAX_SIZE];
    f.open(FILENAME);
    for (int i = 0; i < n; i++) getline(f, vs[i]);

    stampaVettore(vs, n);
    numeroscambi = 0;

    quickSort(vs, 0, n-1);
    cout << "Eseguiti " << numeroscambi << " confronti." << endl;
    stampaVettore(vs, n);

    return 0;
}
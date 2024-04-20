/*
matrici come tipo di variabile
*/

#include <iostream>
#include <time.h>

const int DIM = 10;
const char SHIP = 'X';
const char MISS = 'O';
const char HIT = '*';
const char VOID = '-';


using namespace std;


class BattelField {
    private:
        int m[DIM][DIM];

    public:
        BattelField(){
            for(int i=0;i<DIM;i++){
                for(int j=0;j<DIM;j++){
                    m[i][j] =97 + rand()%26;
                }
            }
        }

        BattelField(char c){
            for(int i=0;i<DIM;i++){
                for(int j=0;j<DIM;j++){
                    m[i][j] = c;
                }
            }
        }

        char get(int x, int y){
            return m[x][y];
        }
        void put(int x,int y, char c){
            m[x][y]=c;
        }

        void stampa() {
            cout<<"--------------------------------------------------------------------------"<<endl;
            for(int i=0;i<DIM;i++){

                for(int j=0;j<DIM;j++){
                    printf("%3c", m[i][j]);
                    //cout<<m[i][j]<<"\t";
                }
            cout<<endl;
            }
            cout<<endl;cout<<"--------------------------------------------------------------------------"<<endl;

        }

        void bomb(){
            int x = rand()%DIM;
            int y = rand()%DIM;
            m[x][y]='*';
        }

        void placeVerticalShip(int len){
            if(len<=0 || len >=DIM) return;
            int x = rand()%DIM;
            int y = rand()%(DIM-len);
            for(int i=0;i<len;i++){
                m[x][y+i] = SHIP;
            }
        }

        void placeHorizontalShip(int len){
            if(len<=0 || len >=DIM) return;
            int x = rand()%DIM;
            int y = rand()%(DIM-len);
            for(int i=0;i<len;i++){
                m[x+i][y] = SHIP;
            }
        }
};
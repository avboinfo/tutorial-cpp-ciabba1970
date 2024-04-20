#include <iostream>
#include "BattleField.cpp"
using namespace std;

class BattleShip{
    
    BattelField mappa;
    BattelField campo;
    
    public: 
     BattleShip(){

        mappa = BattelField(VOID);
        campo = BattelField(VOID);

        campo.placeHorizontalShip(3);
        campo.placeVerticalShip(4);
        campo.placeVerticalShip(2);
        campo.placeHorizontalShip(5);
    }
    
    void play(){
    
    //lancia 20 bombe a caso
    for(int i=0;i<20;i++){
        int x = rand()%DIM;
        int y = rand()%DIM;
        if (campo.get(x,y)==HIT) continue;
        if (campo.get(x,y)==SHIP) {
            mappa.put(x,y,HIT);
            campo.put(x,y,HIT);

        } else mappa.put(x,y,MISS);
    
    }
    mappa.stampa();
    campo.stampa();
    }

    void ask(){
        int x, y;
        cin >> x;
        cin >> y;
        if(campo.get(x,y)==SHIP) {
            mappa.put(x,y,HIT);
            campo.put(x,y,HIT);


        }else mappa.put(x,y,MISS);

    }




};


main:


/**
 * main.cpp - il programma che goca a battaglia navale
 * Dolce Davide - 20/04/20204
*/

#include <iostream>
#include "BattleShip.cpp"
using namespace std;

int main(){

    cout << "Gioco della Battaglia Navale - Buon divertimento"<<endl;
    BattleShip gioco = BattleShip();
    gioco.play();
    cout<<"game over";
}

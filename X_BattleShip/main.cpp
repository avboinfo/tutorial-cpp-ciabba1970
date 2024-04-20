#include <iostream>
 using namespace std;
 #include "BattleShip.cpp"

int main(){
    cout << "gioco della battaglia navale" << endl;

    Battleship gioco = BattleShip();
    gioco.play();
    cout << "game over" << endl;


}
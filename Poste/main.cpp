#include <iostream>
#include "UfficioPostale.cpp"

using namespace std;


int main() {

    UfficioPostale up = UfficioPostale("Saliceto");

    up.nuovoCliente( 'r' );
    up.nuovoCliente( 's' );
    up.nuovoCliente( 'r' );
    up.nuovoCliente( 'r' );
    up.nuovoCliente( 'f' );
    up.nuovoCliente( 'f' );
    up.chiamaCliente( 's' );
    up.nuovoCliente( 'r' );
    up.chiamaCliente( 'r' );
    up.chiamaCliente( 'r' );
    up.chiamaCliente( 'f' );
    up.stampaTabellone();
 
}
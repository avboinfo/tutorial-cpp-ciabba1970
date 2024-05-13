#include <iostream>
#include "Coda.cpp"
using namespace std;

class UfficioPostale {

    private:
        string nome;
        int nR, nS, nF;   
        Coda cR = Coda("ricezione", 1000);
        Coda cS = Coda("spedizione", 1000);
        Coda cF = Coda("finanziari", 1000);

    public:
        UfficioPostale( string nome ) {
            this->nome = nome;
            nR = nS = nF = 100;
        }

        void nuovoCliente( char servizio ) {
            switch ( servizio ) {
                case 'r':
                    cR.enter( nR++ );
                    break;
                case 's':
                    cS.enter( nS++ );
                    break;
                case 'f':
                    cF.enter( nF++ );
                    break;
                default:
                    cout << "Questo servizio te lo fai da solo!!!!!!!!!!!!!!" << endl;
            }
        }

        int chiamaCliente( char servizio ) {
            switch ( servizio ) {
                case 'r':
                    return cR.exit();
                case 's':
                    return cS.exit();
                case 'f':
                    return cF.exit();
                default:
                    cout << "Questo servizio non è previsto!!!!!!!!" << endl;
            }
       }

        void stampaTabellone() {
            cout << "Tabellone dell'Ufficio Postale " << nome << endl;
            cR.stampa();
            cS.stampa();
            cF.stampa();
        }

};
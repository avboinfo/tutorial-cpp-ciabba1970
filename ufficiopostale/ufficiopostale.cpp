#include <iostream>
#include "Coda.cpp"
using namespace std;

class UfficioPostale{

    private:
    string nome;
        Coda cR, cS, cF;
        int nR, nS, nF

    public:
        UfficioPostale(string nome){
            this->nome = nome;
            cR = Coda("ricezione",1000);
            cS = Coda("spedizione",1000);
            cF = Coda("Finanziari",1000);
            nR = nS = nF = 100;

        }

        int NuovoCliente(char servizio){
            switch(servizio) {
                case 'r':
                cR.enter(nR++)
                    break;
                case 's':
                cS.enter(nS++)
                    break;
                case 'f':
                cF.enter(nF++)
                    break;
                default:
                cout << "questo servizio te lo fai da solo." <<;
                }   

        int ChiamaCliente(char servizio){
            switch(servizio) {
                case 'r':
                    return cR.exit();
                case 's':
                    return cS.exit();
                case 'f':
                    return cF.exit();
                    break;
                default:
                cout << "questo servizio non c'è" <<;
                }   

    void StampaTabellone(){
        cout <<"tabbellone dell'ufficio"<< nome << endl;
        cR.stampa();
        cS.Stampa();
        cF.Stampa();



    }



}

}



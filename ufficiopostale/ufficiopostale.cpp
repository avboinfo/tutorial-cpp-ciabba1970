#include <iostream>
#include "Coda.cpp"

class UfficioPostale {

    private:
    Coda codaR = Coda("codaR", 10);
    Coda codaS = Coda("codaS", 10);
    Coda codaF = Coda("codaF", 10);

public:

    void aggiungiPersona(char servizio, int persona) {
        switch(servizio) {
            case 'R':
                codaR.enter(persona);
                break;
            case 'S':
                codaS.enter(persona);
                break;
            case 'F':
                codaF.enter(persona);
                break;
            default:
                std::cout << "Servizio non valido." << std::endl;
        }
    }

    void visualizzaCode() {
        std::cout << "Numero di clienti in coda:" << std::endl;
        codaR.stampa();
        codaS.stampa();
        codaF.stampa();
    }

    void rimuoviPersona(char servizio) {
        switch(servizio) {
            case 'R':
                int personaRimossaR = codaR.exit();
                if (personaRimossaR != 0) {
                    std::cout << "Persona rimossa dalla coda R." << std::endl;
                } else {
                    std::cout << "Coda R vuota." << std::endl;
                }
                break;
            case 'S':
                int personaRimossaS = codaS.exit();
                if (personaRimossaS != 0) {
                    std::cout << "Persona rimossa dalla coda S." << std::endl;
                } else {
                    std::cout << "Coda S vuota." << std::endl;
                }
                break;
            case 'F':
                int personaRimossaF = codaF.exit();
                if (personaRimossaF != 0) {
                    std::cout << "Persona rimossa dalla coda F." << std::endl;
                } else {
                    std::cout << "Coda F vuota." << std::endl;
                }
                break;
            default:
                std::cout << "Servizio non valido." << std::endl;
        }
    }
};

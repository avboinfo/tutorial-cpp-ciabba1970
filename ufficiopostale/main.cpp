#include <iostream>
#include "ufficiopostale.cpp"

int main() {
    UfficioPostale ufficio;

    int scelta = 0;

    while (scelta != 4) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1) Aggiungi una persona in coda" << std::endl;
        std::cout << "2) Rimuovi una persona dalla coda" << std::endl;
        std::cout << "3) Visualizza il numero di clienti in coda per ogni servizio" << std::endl;
        std::cout << "4) Chiudi il programma" << std::endl;
        std::cout << "Scelta: ";
        std::cin >> scelta;

        switch (scelta) {
            case 1:
                int persona;
                char servizio;
                std::cout << "Inserisci il numero del cliente: ";
                std::cin >> persona;
                std::cout << "A quale coda desideri aggiungere la persona? (R, S, F): ";
                std::cin >> servizio;
                ufficio.aggiungiPersona(servizio, persona);
                break;
            case 2:
                char servizioRimozione;
                std::cout << "Da quale coda desideri rimuovere una persona? (R, S, F): ";
                std::cin >> servizioRimozione;
                ufficio.rimuoviPersona(servizioRimozione);
                break;
            case 3:
                ufficio.visualizzaCode();
                break;
            case 4:
                std::cout << "Programma chiuso." << std::endl;
                break;
            default:
                std::cout << "Scelta non valida. Riprova." << std::endl;
        }
    }

    return 0;
}
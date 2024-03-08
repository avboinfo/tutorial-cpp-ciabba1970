#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class mastermind
{
private:
    int numero_mosse;
    std::string ultima_mossa;

    static const int DIM_GIOCATA_VALIDA = 4;
    int mossa_valida[DIM_GIOCATA_VALIDA];
    int codice_segreto[DIM_GIOCATA_VALIDA];

    bool sanifica_input()
    {
        if (DIM_GIOCATA_VALIDA != ultima_mossa.size())
            return false;
        for (int i = 0; i < ultima_mossa.size(); i++)
        {
            char c = ultima_mossa[i];
            if (c >= '0' && c <= '9')
                mossa_valida[i] = c - '0';
            else if (c == '-') // il trattino verra convertio in -1
                mossa_valida[i] = -1;
            else
                return false;
        }
        return true;
    }

    void genera_codice_segreto()
    {
        srand(time(NULL));
        for (int i = 0; i < DIM_GIOCATA_VALIDA; i++)
        {
            codice_segreto[i] = rand() % 10;
        }
    }

public:
    mastermind()
    {
        numero_mosse = 0;
        ultima_mossa = "";
        genera_codice_segreto();
    }

    void nuova_giocata()
    {
        do
        {
            std::cout << numero_mosse + 1 << " ";
            std::getline(std::cin, ultima_mossa); // std:: cin >> ultima mossa; non e i
        } while (!sanifica_input());

        numero_mosse++;
    }

    void risultato_mossa()
    {
        int cifre_corrette = 0;
        int posizione_corretta = 0;

        for (int i = 0; i < DIM_GIOCATA_VALIDA; i++)
        {
            if (mossa_valida[i] == codice_segreto[i])
            {
                posizione_corretta++;
            }
            else
            {
                for (int j = 0; j < DIM_GIOCATA_VALIDA; j++)
                {
                    if (mossa_valida[i] == codice_segreto[j])
                    {
                        cifre_corrette++;
                        break;
                    }
                }
            }
        }

        if (posizione_corretta == DIM_GIOCATA_VALIDA)
        {
            std::cout << "hai indovinato il codice, bravo!" << std::endl;
        }
        else
        {
            std::cout << "cifre giuste: " << cifre_corrette << std::endl;
            std::cout << "cifre messe giuste: " << posizione_corretta << std::endl;
        }
    }
};
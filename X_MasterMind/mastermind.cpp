
#include <iostream>
#include <cstdlib>
#include <ctime>

class mastermind
{

private:
    static const int NUMERO_MOSSE_CONSENTITE = 9;
    int numero_mosse;
    std::string ultima_mossa;

    static const int DIM_GIOCATA_VALIDA = 4;
    int mossa_valida[DIM_GIOCATA_VALIDA];
    int codice_segreto[DIM_GIOCATA_VALIDA];

    bool hai_vinto;

    bool sanifica_input()
    {
        if (DIM_GIOCATA_VALIDA != ultima_mossa.size())
            return false;
        for (int i = 0; i < ultima_mossa.size(); i++)
        {
            char c = ultima_mossa[i];
            if (c >= '0' && c <= '9')
                mossa_valida[i] = c - '0';
            else if (c == '-') /*il trattino viene convertito in -1**/
                mossa_valida[i] = c - -1;
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

    int *copia_vettore(int vettore_originale[])
    {
        static int vettore_copia[DIM_GIOCATA_VALIDA];
        for (int i = 0; i < DIM_GIOCATA_VALIDA; i++)
        {
            vettore_copia[i] = vettore_originale[i];
        }
        return vettore_copia;
    }

    void copia_vettore_bis(int vettore_originale[], int vettore_copia[], int dim_vet)
    {
        for (int i = 0; i < dim_vet; i++)
        {
            vettore_copia[i] = vettore_originale[i];
        }
    }

public:
    mastermind()
    {
        numero_mosse = 0;
        ultima_mossa = "";
        hai_vinto = false;
        genera_codice_segreto();
    };

    void nuova_giocata()
    {
        std::cout << numero_mosse + 1 << ": ";

        do
        {
            std::getline(std::cin, ultima_mossa);
        } while (!sanifica_input());
        numero_mosse++;
    }

    void risultato_mossa()
    {
        int strike, ball;
        strike = ball = 0;

        int codice_segreto_bis[DIM_GIOCATA_VALIDA];
        copia_vettore_bis(codice_segreto, codice_segreto_bis, DIM_GIOCATA_VALIDA);

        for (int i = 0; i < DIM_GIOCATA_VALIDA; i++)
        {
            for (int j = 0; j < DIM_GIOCATA_VALIDA; j++)
            {
                if (mossa_valida[i] == codice_segreto_bis[j])
                {
                    if (i == j)
                        strike++;
                    else
                        ball++;
                    codice_segreto_bis[j] = -2;
                }
            }
        }

        std::cout << "Il numero di strike fatto in questo round è: " << strike << std::endl;
        std::cout << "Il numero di ball fatto in questo round è: " << ball << std::endl;
    }
};

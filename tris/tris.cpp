#include <iostream>
using namespace std;

class Tris
{
public:
    char griglia[3][3];
    bool turnoGiocatore1;

public:
    Tris()
    {
        resettaGriglia();
        turnoGiocatore1 = true;
    }

    void resettaGriglia()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                griglia[i][j] = '-';
            }
        }
    }

    void stampaGriglia()
    {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "| ";
            for (int j = 0; j < 3; j++)
            {
                cout << griglia[i][j] << " | ";
            }
            cout << endl;
            cout << "-------------" << endl;
        }
    }

    bool mossa(int riga, int colonna)
    {
        if (riga < 0 || riga > 2 || colonna < 0 || colonna > 2)
        {
            cout << "Mossa non valida! Inserisci coordinate valide." << endl;
            return false;
        }
        if (griglia[riga][colonna] != '-')
        {
            cout << "Cella già occupata! Scegli un'altra mossa." << endl;
            return false;
        }

        if (turnoGiocatore1)
            griglia[riga][colonna] = 'X';
        else
            griglia[riga][colonna] = 'O';

        turnoGiocatore1 = !turnoGiocatore1; // Cambia turno
        return true;
    }

    bool controllaVittoria()
    {
        // Controlla righe, colonne e diagonali per la vittoria
        for (int i = 0; i < 3; i++)
        {
            if (griglia[i][0] != '-' && griglia[i][0] == griglia[i][1] && griglia[i][1] == griglia[i][2])
                return true;
            if (griglia[0][i] != '-' && griglia[0][i] == griglia[1][i] && griglia[1][i] == griglia[2][i])
                return true;
        }
        if (griglia[0][0] != '-' && griglia[0][0] == griglia[1][1] && griglia[1][1] == griglia[2][2])
            return true;
        if (griglia[0][2] != '-' && griglia[0][2] == griglia[1][1] && griglia[1][1] == griglia[2][0])
            return true;

        return false;
    }

    bool isGrigliaPiena()
    {
        // Controlla se la griglia è piena
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (griglia[i][j] == '-')
                    return false; // Se c'è una cella vuota, la griglia non è piena
            }
        }
        return true; // Griglia piena
    }
};

int main()
{
    Tris partita;
    int riga, colonna;

    cout << "Benvenuto nel gioco del Tris!" << endl;

    while (true)
    {
        partita.stampaGriglia();

        // Ottieni la mossa del giocatore corrente
        if (partita.turnoGiocatore1)
            cout << "Turno del Giocatore 1 (X): ";
        else
            cout << "Turno del Giocatore 2 (O): ";

        cout << "Inserisci riga e colonna (0-2): ";
        cin >> riga >> colonna;

        if (partita.mossa(riga, colonna))
        {
            if (partita.controllaVittoria())
            {
                partita.stampaGriglia();
                if (partita.turnoGiocatore1)
                    cout << "Il Giocatore 1 (X) vince!" << endl;
                else
                    cout << "Il Giocatore 2 (O) vince!" << endl;
                break;
            }
            else if (partita.isGrigliaPiena())
            {
                partita.stampaGriglia();
                cout << "Pareggio!" << endl;
                break;
            }
        }
    }

    return 0;
}

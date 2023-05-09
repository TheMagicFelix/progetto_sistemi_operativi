/***********************************/
/*          VR457089               */
/*          Riccardo Felisi        */
/*          VR456079               */
/*          Niccolò Leviani        */
/*          19 - 04 - 2023         */
/***********************************/

/// @file defines.c
/// @brief Contiene l'implementazione delle funzioni
///         specifiche del progetto.

#include "defines.h"
#include "err_exit.h"

char **mat;

void crea_matrice_vuota(int numero_righe, int numero_colonne)
{
    int i = 0;
    int j = 0;

    mat = (char **) malloc(numero_righe * numero_colonne * sizeof(char*));

    for (i = 0; i < numero_righe; i++)
    {
        mat[i] = (char *) malloc(numero_colonne * sizeof(char *));
    }

    for (i = 0; i < numero_righe; i++)
    {
        for (j = 0; j < numero_colonne; j++)
        {
            mat[i][j] = ' ';
        }
    }
}

void stampa_matrice(int numero_righe, int numero_colonne)
{
    for (int i = 0; i < numero_righe; i++)
    {
        for (int j = 0; j < numero_colonne; j++)
        {
            if (j == 0)
            {
                printf("| %c |", mat[i][j]);
            } else
            {
                printf(" %c |", mat[i][j]);
            }
        }
        printf("\n");
    }
}

/// @file fifo.c
/// @brief Contiene l'implementazione delle funzioni
///         specifiche per la gestione delle FIFO.

#include "fifo.h"
#include "defines.h"
#include "err_exit.h"

/* * * * * *  * * * * * */
/* Definizione Costanti */
/* * * * * *  * * * * * */

#define PATH_BUFFER 150

/* * * * * * * * * * * * */
/* Definizione Variabili */
/* * * * * * * * * * * * */

/* * * * * * *  * * * * * * */
/* Implementazione Funzioni */
/* * * * * * *  * * * * * * */

void make_FIFO() {
    int result = mkfifo(
            "/home/felix/Desktop/felix/università/III_anno/progetto_sistemi_operativi/IPCs/FIFO",
            S_IRUSR | S_IWUSR);

    if (result == -1) {
        err_exit("Creazione FIFO fallita");
    }
}
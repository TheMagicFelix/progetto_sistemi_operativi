/***********************************/
/*          VR457089               */
/*          Riccardo Felisi        */
/*          VR456079               */
/*          Niccolò Leviani        */
/*          19 - 04 - 2023         */
/***********************************/

/// @file sender_manager.c
/// @brief Contiene l'implementazione del sender_manager.

#include "defines.h"
#include "shared_memory.h"
#include "err_exit.h"

/* * * * * * * * * * * * */
/* Definizione Strutture */
/* * * * * * * * * * * * */

/* * * * * * * * * * * * */
/* Definizione Variabili */
/* * * * * * * * * * * * */

char *matrice;
int numero_righe;
int numero_colonne;
int server_shmid;
int support_server_shmid = -1; // shared memory di supporto
bool *data_ready = NULL; // puntatore della shared memory di supporto

/* * * * * *  * * * * * */
/* Definizione Funzioni */
/* * * * * *  * * * * * */

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <rows_number> <columns_number>\n", argv[0]);
        return 0;
    }

    numero_righe = atoi(argv[1]);
    numero_colonne = atoi(argv[2]);

    crea_matrice_vuota(numero_righe, numero_colonne);

    /* * * * * *  * * * * * */
    /* Blocco Shared Memory */
    /* * * * * *  * * * * * */

    /* Vado a settare il path assoluto come IPCs */
    char path[PATH_SIZE];
    getcwd(path, PATH_MAX);
    strcat(path, "/");
    strcat(path, "IPCs");

    key_t shared_memory_key = ftok(
            path,
            shared_memory_id);

    if (shared_memory_key == -1)
    {
        err_exit("\n Ftok failed \n");
    }

    // inizializzazione shared memory di supporto
    support_server_shmid = shmget(support_shared_memory_id, 50 * sizeof(bool), IPC_CREAT);
    data_ready = (bool *)get_shared_memory(support_server_shmid, 0);
    for (int i = 0; i < 50; i++)
    {
        data_ready[i] = false;
    }

    size_t size = (5120 * sizeof(char) * 50);

    server_shmid = shmget(shared_memory_key, size, IPC_CREAT | S_IRUSR | S_IWUSR);

    // attach the shared memory in read and write mode

    char *server_pointer_numero_righe = (char *) shmat(server_shmid, NULL, 0);
    char *server_pointer_numero_colonne = (char *) shmat(server_shmid, NULL, 0);
    char *server_pointer_matrice = (char *) shmat(server_shmid, NULL, 0);

    if (server_pointer_numero_righe == NULL)
    {
        err_exit("Attach failed");
    }

    if (server_pointer_numero_colonne == NULL)
    {
        err_exit("Attach failed");
    }

    if (server_pointer_matrice == NULL)
    {
        err_exit("Attach failed");
    }

    server_pointer_numero_righe[numero_righe];
    server_pointer_numero_colonne[numero_colonne];
    server_pointer_matrice[*matrice];

    // detach the shared memory segments

    if (shmdt(server_pointer_numero_righe) == -1)
    {
        err_exit("Shmdt failed");
    }

    if (shmdt(server_pointer_numero_colonne) == -1)
    {
        err_exit("\n Shmdt failed \n");
    }

    if (shmdt(server_pointer_matrice) == -1)
    {
        err_exit("\n Shmdt failed \n");
    }

    return 0;
}
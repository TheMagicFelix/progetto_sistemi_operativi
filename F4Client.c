/***********************************/
/*          VR457089               */
/*          Riccardo Felisi        */
/*          VR456079               */
/*          Niccolò Leviani        */
/*          19 - 04 - 2023         */
/***********************************/

/// @file client.c
/// @brief Contiene l'implementazione del client.

#include "defines.h"
#include "shared_memory.h"
#include "err_exit.h"

/* * * * * * * * * * * * */
/* Definizione Strutture */
/* * * * * * * * * * * * */

/* * * * * * * * * * * * */
/* Definizione Variabili */
/* * * * * * * * * * * * */

int numero_righe;
int numero_colonne;
int client_shmid;

/* * * * * *  * * * * * */
/* Definizione Funzioni */
/* * * * * *  * * * * * */

int main(int argc, char *argv[])
{
    char *first_player;
    char second_player[50];
    char *second_player_pointer = second_player;

    if (argc != 2)
    {
        printf("Usage: %s <first_player_name>.\nIf you don't have a second player because you're lonely and ugly as fuck and you don't have any friends you can put a <*> symbol and you'll play against the computer\n",
               argv[0]);
        return 0;
    }

    first_player = argv[1];

    printf("Second player name: ");
    scanf("%s", second_player_pointer);

    printf("First player: %s\n", first_player);
    printf("Second player: %s\n", second_player);

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

    // mi aggancio alla shmem creata dal server (SUPPORTO E VERA)
    int id_memoria = alloc_shared_memory(shared_memory_key, 50 * sizeof(char ), 0);

    int shm_data_ready = alloc_shared_memory(support_shared_memory_id, 50 * sizeof(bool), 0);
    bool *data_ready = (bool *)get_shared_memory(shm_data_ready, 0);

    size_t size = (5120 * sizeof(char) * 50);

    client_shmid = shmget(shared_memory_key, size, IPC_CREAT | S_IRUSR | S_IWUSR);

    printf("\n <CLIENT> I've created the shared memory segment \n");

    // attach the shared memory in read only mode

    char *client_pointer_numero_righe = (char *) shmat(client_shmid, NULL, 0);
    char *client_pointer_numero_colonne = (char *) shmat(client_shmid, NULL, 0);
    char *client_pointer_matrice = (char *) shmat(client_shmid, NULL, 0);

    printf("\n <CLIENT> I've added three shared memory segments \n");

    if (client_pointer_numero_righe == NULL)
    {
        err_exit("Attach failed");
    }

    if (client_pointer_numero_colonne == NULL)
    {
        err_exit("Attach failed");
    }

    if (client_pointer_matrice == NULL)
    {
        err_exit("Attach failed");
    }

    client_pointer_numero_righe[numero_righe];
    client_pointer_numero_colonne[numero_righe];
    client_pointer_matrice[numero_righe];

    // detach the shared memory segments

    if (shmdt(client_pointer_numero_righe) == -1)
    {
        err_exit("Shmdt failed");
    }

    if (shmdt(client_pointer_numero_colonne) == -1)
    {
        err_exit("Shmdt failed");
    }

    if (shmdt(client_pointer_matrice) == -1)
    {
        err_exit("Shmdt failed");
    }

    printf("\n <CLIENT> I've deleted the shared memory segment \n");

    stampa_matrice(numero_righe, numero_colonne);
    return 0;
}
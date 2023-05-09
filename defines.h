/***********************************/
/*          VR457089               */
/*          Riccardo Felisi        */
/*          VR456079               */
/*          Niccolò Leviani        */
/*          19 - 04 - 2023         */
/***********************************/

#ifndef PROGETTO_SISTEMI_OPERATIVI_DEFINES_H
#define PROGETTO_SISTEMI_OPERATIVI_DEFINES_H

#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

#pragma once

#define message_queue_key 3
#define shared_memory_id 17
#define support_shared_memory_id 94
#define PATH_SIZE 150

/* * * * * * * * * * * * */
/* Definizione Strutture */
/* * * * * * * * * * * * */

/* * * * * * * * * * * * */
/* Definizione Variabili */
/* * * * * * * * * * * * */

//char actual_path[PATH_MAX + 1];

/* * * * * *  * * * * * */
/* Definizione Funzioni */
/* * * * * *  * * * * * */

void sigHandler(int sig);

void crea_matrice_vuota(int numero_righe, int numero_colonne);

void stampa_matrice(int numero_righe, int numero_colonne);

#endif
/***********************************/
/*          VR457089               */
/*          Riccardo Felisi        */
/*          VR456079               */
/*          Niccolò Leviani        */
/*          19 - 04 - 2023         */
/***********************************/

/// @file err_exit.h
/// @brief Contiene la definizione della funzione di stampa degli errori.

#ifndef ERREXIT_HH
#define ERREXIT_HH

#include "defines.h"

#pragma once

/// @brief Prints the error message of the last failed
///         system call and terminates the calling process.

void err_exit(const char *msg);

#endif

/// @file debug.h
/// @brief Contiene la definizioni di variabili
///         e funzioni per il debugging.

#pragma once

#include <stdio.h>
#include <stdlib.h>

/// Flag per abilitare/disabilitare la funzionalita' di DEBUG_PRINT()
#if !defined(DEBUG)
#define DEBUG 3
#endif

#if defined(DEBUG) && DEBUG > 0

/// Visualizza messaggio stile printf ma con ulteriori informazioni per il debugging
#define DEBUG_PRINT(fmt, args...) fprintf( stderr, "\nDEBUG: %s:%d:%s(): "fmt, \
        __FILE__, __LINE__, __func__, ##args)
#else
#define DEBUG_PRINT(fmt, args...) /* Don't do anything in release builds */
#endif

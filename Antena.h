	
#pragma once

/**
 * Estrutura da antena.
 */
typedef struct Antena {
    int id;
    char frequencia;
    int x, y;
    struct Antena* proxima;
} Antena;

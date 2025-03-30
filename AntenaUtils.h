#pragma once

#include "Antena.h"

/**
 * @brief Lê uma matriz de antenas de um ficheiro e cria a lista ligada.
 *
 * @param path Caminho do ficheiro.
 * @return Ponteiro para a lista ligada de antenas.
 */
Antena* ReadAntenaFile(const char* path);

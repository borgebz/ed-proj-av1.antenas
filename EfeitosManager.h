#pragma once

#include "Antena.h"

/**
 * @brief Verifica se duas antenas estão alinhadas (horizontal, vertical ou diagonal)
 */
bool EstaoAlinhadas(Antena* a1, Antena* a2);

/**
 * @brief Verifica se há um ponto com efeito nefasto entre duas antenas alinhadas
 *        e uma delas está a o dobro da distância da outra em relação ao ponto.
 */
void VerificarEfeito(Antena* a1, Antena* a2, Antena** efeitos);

/**
 * @brief Calcula todas as localizações com efeito nefasto a partir da lista de antenas.
 *
 * Para cada par de antenas com a mesma frequência, verifica se estão alinhadas
 * e se há uma posição entre elas onde uma está o dobro da distância da outra.
 * Essas posições são armazenadas numa nova lista ligada.
 *
 * @param lista Lista ligada de antenas.
 * @return Lista ligada com coordenadas das localizações com efeito nefasto.
 */
Antena* CalcularEfeitosNefastos(Antena* lista);


#pragma once

#include "Antena.h"

/**
 * @brief Verifica se duas antenas est�o alinhadas (horizontal, vertical ou diagonal)
 */
bool EstaoAlinhadas(Antena* a1, Antena* a2);

/**
 * @brief Verifica se h� um ponto com efeito nefasto entre duas antenas alinhadas
 *        e uma delas est� a o dobro da dist�ncia da outra em rela��o ao ponto.
 */
void VerificarEfeito(Antena* a1, Antena* a2, Antena** efeitos);

/**
 * @brief Calcula todas as localiza��es com efeito nefasto a partir da lista de antenas.
 *
 * Para cada par de antenas com a mesma frequ�ncia, verifica se est�o alinhadas
 * e se h� uma posi��o entre elas onde uma est� o dobro da dist�ncia da outra.
 * Essas posi��es s�o armazenadas numa nova lista ligada.
 *
 * @param lista Lista ligada de antenas.
 * @return Lista ligada com coordenadas das localiza��es com efeito nefasto.
 */
Antena* CalcularEfeitosNefastos(Antena* lista);


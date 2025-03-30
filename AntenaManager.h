#pragma once

#include "Antena.h"

/**
 * @brief Gera um ID único incremental para uma nova antena.
 * @return Novo ID.
 */
int GenerateId(Antena* lista);

/**
 * @brief Verifica se já existe uma antena com as coordenadas (x, y) na lista.
 *
 * @param lista Lista ligada de antenas.
 * @param x Coordenada X a verificar.
 * @param y Coordenada Y a verificar.
 * @return 1 se existir, 0 se não.
 */
int ExistsCoordinates(Antena* lista, int x, int y);

/**
 * @brief Verifica se um ID já existe na lista de antenas.
 *
 * @param lista Ponteiro para a lista ligada de antenas.
 * @param id ID a verificar.
 * @return 1 se existir, 0 se não.
 */
int ExistsId(Antena* lista, int id);

/**
 * @brief Insere uma nova antena no final da lista ligada.
 *
 * @param lista Ponteiro para o início da lista ligada de antenas.
 * @param novaAntena Estrutura Antena com os dados da antena a inserir (exceto o ponteiro proxima).
 * @return Ponteiro para o início da lista atualizada.
 */
Antena* Insert(Antena* lista, Antena novaAntena);

/**
 * @brief Remove a antena localizada nas coordenadas (x, y).
 *
 * @param lista Ponteiro para o início da lista ligada de antenas.
 * @param x Coordenada X da antena a remover.
 * @param y Coordenada Y da antena a remover.
 * @return Ponteiro para o início da lista atualizada.
 */
Antena* RemoveAt(Antena* lista, int x, int y);

/**
 * @brief Remove uma antena da lista com base no seu ID.
 *
 * @param lista Ponteiro para o início da lista ligada de antenas.
 * @param id Identificador da antena a ser removida.
 * @return Ponteiro para o início da lista atualizada.
 */
Antena* RemoveById(Antena* lista, int id);

/**
 * @brief Mostra na consola todas as antenas da lista.
 *
 * @param lista Ponteiro para o início da lista ligada de antenas.
 */
void ShowAll(Antena* lista);

/**
 * @brief Mostra todas as antenas visualmente numa matriz dinâmica.
 *
 * Cria uma representação visual da cidade com base nas coordenadas das antenas.
 * O tamanho da matriz é definido pelo maior X e Y da lista.
 * Posições sem antenas são preenchidas com '.'.
 *
 * @param lista Ponteiro para a lista ligada de antenas.
 */
void ShowAllVisual(Antena* lista);

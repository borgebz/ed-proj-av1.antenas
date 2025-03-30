#include <stdio.h>
#include <stdlib.h>
#include "AntenaManager.h"

static int currentId = 0;

int GenerateId(Antena* lista) {
    currentId++;

    if (ExistsId(lista, currentId)) {
        return GenerateId(lista);  // chamada recursiva
    }
    return currentId;
}

int ExistsId(Antena* lista, int id) {
    while (lista != NULL) {
        if (lista->id == id)
            return 1;
        lista = lista->proxima;
    }
    return 0;
}

int ExistsCoordinates(Antena* lista, int x, int y) {
    while (lista) {
        if (lista->x == x && lista->y == y) {
            return 1;
        }
        lista = lista->proxima;
    }
    return 0;
}

Antena* Insert(Antena* lista, Antena novaAntena) {
    Antena* nova = (Antena*)malloc(sizeof(Antena));
    if (!nova) return lista;

    nova->id = GenerateId(lista);
    nova->frequencia = novaAntena.frequencia;
    nova->x = novaAntena.x;
    nova->y = novaAntena.y;
    nova->proxima = NULL;

    if (lista == NULL) {
        return nova;
    }

    Antena* atual = lista;
    while (atual->proxima != NULL) {
        atual = atual->proxima;
    }
    atual->proxima = nova;

    return lista;
}

Antena* RemoveAt(Antena* lista, int x, int y) {
    Antena* atual = lista;
    Antena* anterior = NULL;

    while (atual != NULL) {
        if (atual->x == x && atual->y == y) {
            if (anterior == NULL) {
                lista = atual->proxima;
            }
            else {
                anterior->proxima = atual->proxima;
            }
            free(atual);
            return lista;
        }
        anterior = atual;
        atual = atual->proxima;
    }

    return lista;
}

Antena* RemoveById(Antena* lista, int id) {
    Antena* atual = lista;
    Antena* anterior = NULL;

    while (atual != NULL) {
        if (atual->id == id) {
            if (anterior == NULL) {
                lista = atual->proxima;
            }
            else {
                anterior->proxima = atual->proxima;
            }
            free(atual);
            return lista;
        }
        anterior = atual;
        atual = atual->proxima;
    }

    return lista;
}

void ShowAll(Antena* lista) {
    printf("=== Lista de Antenas ===\n");
    while (lista != NULL) {
        printf("ID: %d | Freq: %c | Coordenadas: (%d, %d)\n",
            lista->id, lista->frequencia, lista->x, lista->y);

        lista = lista->proxima;
    }
}

void ShowAllVisual(Antena* lista) {
    if (!lista) {
        printf("Lista vazia.\n");
        return;
    }

    int maxX = 0, maxY = 0;
    Antena* aux = lista;

    // 1. Descobrir o maior X e Y
    while (aux) {
        if (aux->x > maxX) maxX = aux->x;
        if (aux->y > maxY) maxY = aux->y;
        aux = aux->proxima;
    }

    int largura = maxX + 1;
    int altura = maxY + 1;

    // 2. Criar matriz dinâmica de caracteres
    char** matriz = (char**)malloc(altura * sizeof(char*));
    for (int y = 0; y < altura; y++) {
        matriz[y] = (char*)malloc(largura * sizeof(char));
        for (int x = 0; x < largura; x++) {
            matriz[y][x] = '.';  // valor default
        }
    }

    // 3. Preencher matriz com frequências
    aux = lista;
    while (aux) {
        matriz[aux->y][aux->x] = aux->frequencia;
        aux = aux->proxima;
    }

    // 4. Mostrar matriz no terminal
    printf("=== Visualização da Matriz ===\n");
    for (int y = 0; y < altura; y++) {
        for (int x = 0; x < largura; x++) {
            printf("%c", matriz[y][x]);
        }
        printf("\n");
    }

    // 5. Libertar memória da matriz
    for (int y = 0; y < altura; y++) {
        free(matriz[y]);
    }
    free(matriz);
}
#include <stdio.h>
#include "AntenaUtils.h"
#include "AntenaManager.h"

Antena* ReadAntenaFile(const char* path) {
    FILE* f = fopen(path, "r");
    if (!f) {
        perror("Erro ao abrir ficheiro");
        return NULL;
    }

    Antena* lista = NULL;
    char linha[256];
    int y = 0;

    while (fgets(linha, sizeof(linha), f)) {
        for (int x = 0; linha[x] != '\0' && linha[x] != '\n'; x++) {
            char c = linha[x];
            if (c != '.' && c != ' ') {
                Antena nova = { 0, c, x, y, NULL };
                lista = Insert(lista, nova);
            }
        }
        y++;
    }

    fclose(f);
    return lista;
}
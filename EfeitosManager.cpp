#include <stdlib.h>
#include "EfeitosManager.h"
#include "AntenaManager.h"
#include <math.h>

bool EstaoAlinhadas(Antena* a1, Antena* a2) {
    int dx = abs(a1->x - a2->x);
    int dy = abs(a1->y - a2->y);
    return (dx == 0 || dy == 0 || dx == dy);
}

void AddAntena(Antena* origem, Antena** destino) {
    if (!ExistsCoordinates(*destino, origem->x, origem->y)) {
        Antena copia = { 0, origem->frequencia, origem->x, origem->y, NULL };
        *destino = Insert(*destino, copia);
    }
}

void VerificarEfeito(Antena* a1, Antena* a2, Antena** efeitos) {
    AddAntena(a1, efeitos);
    AddAntena(a2, efeitos);

    // Só continua se estiverem alinhadas e mesma frequência
    if (a1->frequencia != a2->frequencia || !EstaoAlinhadas(a1, a2)) return;

    int dx = a2->x - a1->x;
    int dy = a2->y - a1->y;

    int dist = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    if (dist == 1 || dist == 2) {
        // Criar efeito "antes da primeira antena"
        int dirX = (dx == 0 ? 0 : (dx / abs(dx)));
        int dirY = (dy == 0 ? 0 : (dy / abs(dy)));

        int x1 = a1->x - dirX * 2;
        int y1 = a1->y - dirY * 2;
        if (!ExistsCoordinates(*efeitos, x1, y1)) {
            Antena efeito1 = { 0, '#', x1, y1, NULL };
            *efeitos = Insert(*efeitos, efeito1);
        }

        // Criar efeito "depois da segunda antena"
        int x2 = a2->x + dirX * 2;
        int y2 = a2->y + dirY * 2;
        if (!ExistsCoordinates(*efeitos, x2, y2)) {
            Antena efeito2 = { 0, '#', x2, y2, NULL };
            *efeitos = Insert(*efeitos, efeito2);
        }
    }
    else if (dist == 4) {
        // Criar efeito no meio
        int xL = (a1->x + a2->x) / 2;
        int yL = (a1->y + a2->y) / 2;

        if (!ExistsCoordinates(*efeitos, xL, yL)) {
            Antena efeito = { 0, '#', xL, yL, NULL };
            *efeitos = Insert(*efeitos, efeito);
        }
    }
}

Antena* CalcularEfeitosNefastos(Antena* lista) {
    Antena* efeitos = NULL;
    for (Antena* a1 = lista; a1 != NULL; a1 = a1->proxima) {
        for (Antena* a2 = a1->proxima; a2 != NULL; a2 = a2->proxima) {
            VerificarEfeito(a1, a2, &efeitos);
        }
    }
    return efeitos;
}
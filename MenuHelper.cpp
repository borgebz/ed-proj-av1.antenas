#include "MenuHelper.h"
#include <stdio.h>
#include <stdlib.h>

void EnterAndNext() {
    printf("\n\nPressione ENTER para voltar ao menu...");
    while (getchar() != '\n');
    system("cls");
}
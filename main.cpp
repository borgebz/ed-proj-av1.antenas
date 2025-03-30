/*****************************************************************//**
 * \file   ED.Antenas.cpp
 * \brief  Projeto de gestão de antemas de uma cidade, com analise
 *			ao efeitos nefastos produzido por cada antena.
 * 
 * \author joaob
 * \date   March 2025
 *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Antena.h"
#include "AntenaManager.h"
#include "AntenaUtils.h"
#include "EfeitosManager.h"
#include "MenuHelper.h"

int main()
{
    Antena* lista = NULL;
    Antena* efeitos = NULL;
    int opcao;
    char ficheiro[256];

    do {
        printf("\n===== MENU ANTENAS =====\n");
        printf("1. Ler antenas de ficheiro\n");
        printf("2. Mostrar lista de antenas (tabela)\n");
        printf("3. Mostrar antenas (visual)\n");
        printf("4. Mostrar efeitos nefastos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
        case 1:
            printf("Digite o nome do ficheiro (ex: antenas.txt): ");
            fgets(ficheiro, sizeof(ficheiro), stdin);
            ficheiro[strcspn(ficheiro, "\n")] = 0;
            lista = ReadAntenaFile(ficheiro);
            printf("Antenas carregadas com sucesso.\n");

            EnterAndNext();
            break;
        case 2:
            ShowAll(lista);

            EnterAndNext();
            break;
        case 3:
            ShowAllVisual(lista);

            EnterAndNext();
            break;
        case 4:
            efeitos = CalcularEfeitosNefastos(lista);

            printf("\n--- Visualização efeitos nefastos:\n");
            ShowAllVisual(efeitos);

            if (efeitos) {
                Antena* temp;
                while (efeitos) {
                    temp = efeitos;
                    efeitos = efeitos->proxima;
                    free(temp);
                }
            }

            EnterAndNext();
            break;
        case 0:
            printf("A sair...\n");
            break;
        default:
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    // libertar memória final
    Antena* temp;
    while (lista) {
        temp = lista;
        lista = lista->proxima;
        free(temp);
    }
    while (efeitos) {
        temp = efeitos;
        efeitos = efeitos->proxima;
        free(temp);
    }

    return 0;
}





#include "copa.h"
#include <stdio.h>
#include<locale.h>

typedef enum { SAIR, CADASTRAR_SELECAO, ALTERAR_SELECAO,
LISTAR_SELECOES, LISTAR_SELECOES_GRUPO, CADASTRAR_JOGOS,
LISTAR_JOGOS_GRUPO, LISTAR_JOGOS_DATA } opcoes_menu;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op;
    system("cls");
    do {
        printf("----------------------------------------\n\n\t\tCOPA DA RÚSSIA\n\n");
        printf("\t<1> Cadastrar seleções\n");
        printf("\t<2> Alterar seleção\n");
        printf("\t<3> Listar seleções cadastradas\n");
        printf("\t<4> Listar seleções de um grupo\n");
        printf("\t<5> Cadastrar jogos de um grupo\n");
        printf("\t<6> Listar jogos de um grupo\n");
        printf("\t<7> Listar jogos de uma data\n");
        printf("\t<0> Sair do programa\n");
        printf("\n\n----------------------------------------\n\n");
            printf("\tOpção: ");
            scanf("%d", &op);


        switch (op) {
            case CADASTRAR_SELECAO:
                cad_selecao();
                break;
            case ALTERAR_SELECAO:
                alterar_selecao();
                break;
            case LISTAR_SELECOES:
                list_selecoes();
                break;
           case LISTAR_SELECOES_GRUPO:
                list_selecoes_grupo();
                break;
            case CADASTRAR_JOGOS:
                cad_jogo();
                break;
            case LISTAR_JOGOS_GRUPO:
                list_jogos_grupo();
                break;
            case LISTAR_JOGOS_DATA:
                list_jogos_data();
                break;
            case SAIR:
                break;
            default:
                system("cls");
                printf("\n\n\t\tOpção inválida!\n\t\tPressione 'Enter' e tente novamente!");
                getch();
                system("cls");
        }
    } while (op != SAIR);
    return 0;
}

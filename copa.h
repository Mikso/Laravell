#ifndef _COPA_H
#define _COPA_H
#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#define ARQ_SEL "selecoes.dat"
#define ARQ_JOGO "jogos.dat"
#define ARQ_LIST_JOGOS "jogos.txt"

typedef struct {
    int dia;
    int mes;
} tdata;

typedef struct {
    int id;
    char nome[31];
    char grupo;
} tselecao;

typedef struct {
    char grupo;
    tdata data;
    char estadio[21];
    int id_mandante;
    int id_visitante;
} tjogo;

/* cadastra as seleções de um grupo */
void cad_selecao(void);

/* altera o nome de uma seleção dado seu id */
void alterar_selecao(void);

/* lista no vídeo todas as seleções cadastradas */
void list_selecoes(void);

/* lista no vídeo as seleções de um grupo */
void list_selecoes_grupo(void);

/* cadastra os jogos da 1ª fase da Copa da Rússia */
void cad_jogo(void);

/* lista no vídeo/arquivo os jogos de um grupo */
void list_jogos_grupo(void);

/* lista no vídeo os jogos de uma data */
void list_jogos_data(void);

#endif

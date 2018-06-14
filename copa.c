#include "copa.h"

/* cadastra as seleções de um grupo */

void cad_selecao(){

    FILE * arquivo;
    arquivo = fopen(ARQ_SEL, "ab");
    int j = 0;

    char c;
    tselecao selecao;
    system("cls");

    printf("--------------------------------------------------------\n|\t\tCadastrar grupo e seleções\t\t|");
        printf("\n--------------------------------------------------------\n");
    if(arquivo == NULL)
        printf("\t\tProblemas na abertura do arquivo!");
    else{
        do{

          /*  Através dessa opção é possível cadastrar as seleções de um grupo
da Copa. O sistema deve solicitar o grupo (um caractere de ‘A’ a ‘H’), caso as seleções
deste grupo ainda não tenham sido cadastradas, o sistema deve solicitar o nome das 4
seleções deste grupo. O identificador da seleção (membro id da estrutura tselecao)
é um número sequencial gerado automaticamente, sendo assim, o identificador da
primeira seleção cadastrada será igual a 1, a da segunda igual a 2, e assim por diante,
até o id 32. As seleções (estruturas do tipo tselecao) devem ser gravadas em um
arquivo binário cujo nome é definido pela constante ARQ_SEL.
            */

            //fflush(stdin);
            printf("\nInforme o grupo utilizando as letras de 'A' a 'H' : ");
            scanf(" %c", &selecao.grupo);
            fseek(arquivo, 0, SEEK_END);
            selecao.id = ftell(arquivo)/sizeof(tselecao)+1;
            printf("\nInforme o nome da %dª seleção deste grupo %c : ",selecao.id, selecao.grupo);
            scanf(" %[^\n]", selecao.nome);
            fwrite(&selecao,sizeof(tselecao),1,arquivo);
            selecao.id = ftell(arquivo)/sizeof(tselecao)+1;
            for(j=0;j<3;j++){
                printf("\nId da selecao : %d\n", selecao.id);
                //fflush(stdin);
                printf("\nInforme o nome da %dª seleção deste grupo %c : ",selecao.id, selecao.grupo);
                scanf(" %[^\n]", selecao.nome);
                fwrite(&selecao,sizeof(tselecao),1,arquivo);
                selecao.id++;
            }
            printf("\n\n<Cadastro realizado com sucesso!>");
            getch();
            system("cls");
            printf("--------------------------------------------------------\n|\t\tCadastrar grupo e seleções\t\t|");
            printf("\n--------------------------------------------------------\n");
            printf("\n\n<Deseja continuar cadastrando as seleções?\n  Digite S para sim ou N para não :  >");
            scanf(" %c",&c);
            if(c == 110 || c == 78)
                break;
        }while(selecao.id < 32);

        fclose(arquivo);
    }
    system("cls");

}

/* altera o nome de uma seleção dado seu id

Alterar seleção: esta funcionalidade deve ser implementada através da função
alterar_selecao(). Através dessa opção o usuário pode alterar o nome de uma das
seleções cadastradas. Para isso, o sistema deve solicitar o id da seleção, se este id for
válido (houver uma seleção cadastrada com esse id), mostrar o nome da seleção e
solicitar o nome correto desta seleção. Se o id for inválido, o sistema deve exibir uma
mensagem de erro.*/
void alterar_selecao(){
    system("cls");
    FILE * arquivo;
    arquivo = fopen(ARQ_SEL, "r+b");
    int cont, n, pos=0;
    cont=1;
    tselecao selecao;

    if(arquivo == NULL)
        printf("\t\tProblemas na abertura do arquivo!");
    else{

        printf("--------------------------------------------------------\n|\t\tAlterar o nome da seleção\t\t|");
        printf("\n--------------------------------------------------------\n");
        fflush(stdin);
        printf("\nInforme o Id da seleção que pretende editar\n");
        scanf("%d",&n);
        fread(&selecao, sizeof(tselecao),1,arquivo);
        do{
            // Pega o id digitado e mostra a selecao que o representa
            if(n == selecao.id){
                printf("\nEste id se refere a seleção %s : ",selecao.nome);
                pos = cont+1;
                break;
            }
            cont++;
        }while(fread(&selecao, sizeof(tselecao), 1, arquivo)==1);

        printf("\nCont = %d\n", cont);
        getch();

// Se nao exibido alguma id - selecao, retornara a msg
        if(pos == 0){
            system("cls");
            printf("Id não encontrado\n");
            getch();
            system("cls");
        }
        else{
                // Se encontrado o id correspondente, pedira o novo nome para a selecao
            fflush(stdin);
            printf("\nInforme o novo nome desta seleção : ");
            scanf("%[^\n]", selecao.nome);
            fseek(arquivo, sizeof(tselecao) * (selecao.id-1), SEEK_SET);
            fwrite(&selecao,sizeof(tselecao),1,arquivo);
            system("cls");
            printf("\n\t<\tAlteração realizada com sucesso!\t>");
            getch();
            system("cls");
        }

    }
    fclose(arquivo);
}

/* lista no vídeo todas as seleções cadastradas
Listar seleções cadastradas: esta funcionalidade deve ser implementada através da
função list_selecoes(). O sistema deverá exibir no vídeo o id, nome e grupo de
todas as seleções cadastradas no formato de uma tabela. Caso não haja nenhuma
seleção cadastrada, exibir uma mensagem de erro.*/
void list_selecoes(){

    FILE * arquivo;
    arquivo = fopen(ARQ_SEL, "rb");
    int j = 0;

    tselecao selecao;
    system("cls");
    printf("----------------------------------------------------------------\n|\t\tGrupos e seleções cadastrados\t\t\t|");
        printf("\n----------------------------------------------------------------\n\n");
    if(arquivo == NULL)
        printf("\t\tProblemas na abertura do arquivo!");
    else{

        fread(&selecao, sizeof(tselecao), 1, arquivo);
    //Ira listar as selecoes de seus respectivos grupos
        do{
            printf("\n\t--------------------------------------------------------\n\t|\t\t\tGrupo %c   \t\t\t|", selecao.grupo);
            printf("\n\t--------------------------------------------------------\n\t|\t\t\t\t|\t\t\t|");
            printf("\n\t|Seleções\t\t\t|\t  Id\t\t|");
            printf("\n\t|%-31s|\t  %d\t\t|", selecao.nome, selecao.id);
            for(j=0;j<3;j++){
                fread(&selecao, sizeof(tselecao), 1, arquivo);
                printf("\n\t|%-31s|\t  %d\t\t|", selecao.nome, selecao.id);

            }
            printf("\n\t---------------------------------------------------------\n\t\t\t\t\t");
            printf("\n");

        }while(fread(&selecao, sizeof(tselecao), 1, arquivo) == 1);
    }
    fclose(arquivo);
    printf("\n\n<Pressione 'Enter' para voltar ao menu principal!>");
    getch();
    system("cls");
}

/* lista no vídeo as seleções de um grupo
Listar seleções de um grupo: esta funcionalidade deve ser implementada através da
função list_selecoes_grupo(). O sistema deve solicitar o grupo (um caractere de
‘A’ a ‘H’), caso as seleções deste grupo já tenham sido cadastradas, exibir no vídeo em
formato de tabela o id e nome de todas as seleções do grupo informado. Caso as
seleções do grupo não tenham sido cadastradas, exibir uma mensagem de erro.
*/
void list_selecoes_grupo(){

    FILE * arquivo;
    arquivo = fopen(ARQ_SEL, "rb");
    int j = 0 ;
    bool aux = false; // armazena se a funcao foi atingida = true
    char grupo;
    tselecao selecao;
    system("cls");
    printf("--------------------------------------------------------\n|\t\tListar seleções por grupo\t\t|");
        printf("\n--------------------------------------------------------\n");
    if(arquivo == NULL)
        printf("\t\tProblemas na abertura do arquivo!");

    else{
        printf("\nInforme o grupo que deseja listar: ");
        scanf(" %c", &grupo);

        do{
                // Exibe as selecoes de um grupo
            fread(&selecao, sizeof(tselecao), 1, arquivo);
            if(selecao.grupo == grupo){
            printf("\n\t--------------------------------------------------------\n\t|\t\t\tGrupo %c   \t\t\t|", selecao.grupo);
            printf("\n\t--------------------------------------------------------\n\t|\t\t\t\t|\t\t\t|");
            printf("\n\t|Seleções\t\t\t|\t  Id\t\t|");
            printf("\n\t|%-31s|\t  %d\t\t|", selecao.nome, selecao.id);
            for(j=0;j<3;j++){
                fread(&selecao, sizeof(tselecao), 1, arquivo);
                printf("\n\t|%-31s|\t  %d\t\t|", selecao.nome, selecao.id);
                aux = true;
            }
            printf("\n\t---------------------------------------------------------\n\t\t\t\t\t");
            printf("\n");
                break;
            }

        }while(fread(&selecao, sizeof(tselecao), 1, arquivo)==1);
    }

    if(aux == false){
    printf("\nGrupo não encontrado!");//Se exibido algum grupo, não dispara a msg
    }

    fclose(arquivo);

    printf("\n\n<Pressione 'Enter' para voltar ao menu principal!>");
    getch();
    system("cls");

}

/* cadastra os jogos da 1ª fase da Copa da Rússia
Cadastrar jogos de um grupo: esta funcionalidade deve ser implementada através da
função cad_jogos(). O sistema deve solicitar o grupo, data, estádio e adversários de
um dos jogos da 1ª fase da Copa. Sugere-se a interface mostrada na figura abaixo para
esta funcionalidade. Após solicitar o grupo, data e estádio do jogo, o sistema deve exibir
uma lista com o id e nome das seleções do grupo e solicitar ao usuário o id da seleção mandante,depois
fazer o mesmo para a seleção visitante. A seleção visitante não pode ser igual à seleção
mandante. Deve ser possível cadastrar vários jogos do mesmo grupo, até o limite de 6.
Os jogos (estruturas do tipo tjogo) devem ser gravados no arquivo binário cujo nome
é definido pela constante ARQ_JOGO.*/
void cad_jogo(void){
    FILE * arquivo, * arquivo2;
    arquivo = fopen(ARQ_SEL, "rb");
    arquivo2 = fopen(ARQ_JOGO, "ab");
    int i,j;
    i = 0;
    int aux = 0;
    char grupo;
    tselecao selecao;
    tjogo jogo;

    system("cls");
    printf("-----------------------------------------------------------------\n|\t   Cadastros de jogos de um grupo da 1ª fase\t\t|");
    printf("\n-----------------------------------------------------------------\n\n");
    if(arquivo == NULL)
        printf("\t\tProblemas na abertura do arquivo!");
    else{
        printf("\nInforme o grupo que deseja listar: ");
        scanf(" %c", &grupo);
        // Aqui chama aquela função que valida se as letras sao A a H

        do{
            fread(&selecao, sizeof(tselecao), 1, arquivo);
             if(selecao.grupo == grupo){
                do{
                        // Ira esperar a entrada da data e o mes, o estadio
                    jogo.grupo = selecao.grupo;
                    printf("\nInforme a data do jogo, no formato dd/mm, separando-os com 'Espaço': ");
                    scanf(" %d %d", &jogo.data.dia, &jogo.data.mes);
                    printf("\nInforme o estadio do jogo: ");
                    scanf(" %s", jogo.estadio);
                    printf("\n\t--------------------------------------------------------\n\t|\t\t\t\t|\t\t\t|");
                    printf("\n\t|Seleções\t\t\t|\t  Id\t\t|");
                    printf("\n\t|%-31s|\t  %d\t\t|", selecao.nome, selecao.id);
                    for(j=0;j<3;j++){
                        fread(&selecao, sizeof(tselecao), 1, arquivo);
                        printf("\n\t|%-31s|\t  %d\t\t|", selecao.nome, selecao.id);
                    }
                    // Cadastra a selecao mandante
                    printf("\n\t---------------------------------------------------------\n\t\t\t\t\t");
                    printf("\n");
                    printf("\n\nInforme o id do mandante do jogo: ");
                    scanf(" %d", &jogo.id_mandante);
                    fseek(arquivo, 0, SEEK_SET);
                    fseek(arquivo, sizeof(tselecao) * (jogo.id_mandante-1), SEEK_SET);
                    fread(&selecao,sizeof(tselecao),1,arquivo);
                    printf("\nMandante: %s\n\n", selecao.nome);



                    // Cadastra selecao visitante
                    printf("\n\t--------------------------------------------------------\n\t|\t\t\t\t|\t\t\t|");
                    printf("\n\t|Seleções\t\t\t|\t  Id\t\t|");
                    printf("\n\t|%-31s|\t  %d\t\t|", selecao.nome, selecao.id);
                    for(j=0;j<3;j++){
                        fread(&selecao, sizeof(tselecao), 1, arquivo);
                        printf("\n\t|%-31s|\t  %d\t\t|", selecao.nome, selecao.id);
                    }
                    printf("\n\t---------------------------------------------------------\n\t\t\t\t\t");
                    printf("\n");
                    printf("\n\nInforme o id do visitante do jogo: ");
                    scanf(" %d", &jogo.id_visitante);
                    fseek(arquivo, 0, SEEK_SET);
                    fseek(arquivo, sizeof(tselecao) * (jogo.id_visitante-1), SEEK_SET);
                    fread(&selecao,sizeof(tselecao),1,arquivo);
                    printf("\nVisitante: %s", selecao.nome);
                    fwrite(&jogo,sizeof(tjogo),1,arquivo2);
                    i++;

                    printf("\n\n\tJogo gravado com sucesso!\n\n");

                    printf("\n\n<Deseja salvar a listagem acima em um arquivo de texto?\n  Digite 1 para sim ou 2 para não :  >");
                    scanf(" %d",&aux); // Armazena a opcao de continuar ou sair da funcao de cadastro
                    if(aux != 1){
                        //Continua com novos cadastros
                    }else{
                        aux = 1; // Encerra a funcao de cadastro
                        break;
                    }
                    system("cls");
                    printf("-----------------------------------------------------------------\n|\t   Cadastros de jogos de um grupo da 1ª fase\t\t|");
                    printf("\n-----------------------------------------------------------------\n\n");
                }while(aux != 1);

             }
        }while(fread(&selecao, sizeof(tselecao), 1, arquivo) == 1 && aux != 1 );

    fclose(arquivo);
    fclose(arquivo2);
    printf("\n\n<Pressione 'Enter' para voltar ao menu principal!>");
    getch();
    system("cls");
    }
}

/* lista no vídeo/arquivo os jogos de um grupo
Listar jogos de um grupo: esta funcionalidade deve ser implementada através da
função list_jogos_grupo(). O sistema deve solicitar um grupo e exibir no vídeo a
data, estádio e adversários de todos os jogos do grupo. Depois o sistema deve
perguntar ao usuário se ele deseja gerar a mesma listagem em um arquivo, caso
afirmativo, o sistema deve gerar a listagem em um arquivo do tipo texto cujo nome é
definido pela constante ARQ_LIST_JOGOS.*/
void list_jogos_grupo(void){
    FILE * arquivo, * arquivo2;
    arquivo = fopen(ARQ_SEL, "rb");
    arquivo2 = fopen(ARQ_JOGO, "rb");
    int i = 0, n = 0;
    char grupo;
    tselecao selecao;
    tjogo jogo;
    system("cls");
    printf("-----------------------------------------------------------------\n|\t  Lista de jogos cadastros  de um grupo da 1ª fase\t|");
    printf("\n-----------------------------------------------------------------\n\n");
    if(arquivo == NULL)
        printf("\t\tProblemas na abertura do arquivo!");
    else{
        do{
            printf("\nInforme o grupo que deseja listar:  ");
            scanf(" %c", &grupo);
            fread(&jogo, sizeof(tjogo), 1, arquivo2);
            n = ftell(arquivo2)/sizeof(tjogo)+1;
            char mandante[31], visitante[31];

            //Lista os jogos de um grupo
             if(jogo.grupo == grupo){
                printf("-----------------------------------------------------------------\n|\t\tJogos do grupo %c da 1ª fase\t\t\t|", jogo.grupo);
                printf("\n-----------------------------------------------------------------\n\n");
                do{
                    printf("\t-------------------------------------------------\n\t|\t           Data: %d/ %d/2018\t\        |", jogo.data.dia, jogo.data.mes);
                    printf("\n\t-------------------------------------------------\n\n");

                    printf("\t-------------------------------------------------\n\t|\t\t  Estadio : %-15s\t|", jogo.estadio);
                    printf("\n\t-------------------------------------------------\n\n");


                    fseek(arquivo, sizeof(tselecao) * (jogo.id_mandante-1), SEEK_SET);
                    fread(&selecao,sizeof(tselecao),1,arquivo);
                    strcpy(mandante,selecao.nome);
                    fseek(arquivo, sizeof(tselecao) * (jogo.id_visitante-1), SEEK_SET);
                    fread(&selecao,sizeof(tselecao),1,arquivo);
                    strcpy(visitante,selecao.nome);
                    printf("\-------------------------------------------------------------------------\n|       Mandante => %-15s X %15s <= Visitante \t|", mandante, visitante);
                    printf("\n\-------------------------------------------------------------------------\n\n");

                    fread(&jogo, sizeof(tjogo), 1, arquivo2);
                    i++;
                }while(fread(&jogo, sizeof(tjogo), 1, arquivo2)==1);
            }

            char c;
            printf("\n\n<Deseja salvar a listagem acima em um arquivo de texto?\n  Digite S para sim ou N para não :  >");
            scanf(" %c",&c);
            if(c == 115 || c == 83){
                FILE * arquivo3;
                arquivo3 = fopen(ARQ_LIST_JOGOS, "a");
                if(arquivo3 == NULL)
                    printf("\t\tProblemas na abertura do arquivo!");
                else{
                    fseek(arquivo2, 0, SEEK_SET);
                    fseek(arquivo, 0, SEEK_SET);
                    fprintf(arquivo3, "    Jogos do grupo %c\n\n",jogo.grupo);
                    do{

                        fseek(arquivo, sizeof(tselecao) * (jogo.id_mandante-1), SEEK_SET);
                        fread(&selecao,sizeof(tselecao),1,arquivo);
                        strcpy(mandante,selecao.nome);
                        fseek(arquivo, sizeof(tselecao) * (jogo.id_visitante-1), SEEK_SET);
                        fread(&selecao,sizeof(tselecao),1,arquivo);
                        strcpy(visitante,selecao.nome);
                        fprintf(arquivo3,"Data : %d/ %d/ 2018\nEstadio: %s\nMandante: %s\nVisitante: %s\n\n\n",
                                jogo.data.dia,
                                jogo.data.mes, jogo.estadio, mandante, visitante);
                    }while(fread(&jogo, sizeof(tjogo), 1, arquivo2)==1);

                    printf("\nOk, o arquivo de texto foi gerado com sucesso!");
                }
                fclose(arquivo3);
            }
            else{
                printf("\nOk, o arquivo de texto Não será gerado!");
            }
            fclose(arquivo);
            fclose(arquivo2);

            printf("\n\n<Pressione 'Enter' para voltar ao menu principal!>");
            getch();
            system("cls");
        }while(fread(&jogo, sizeof(tjogo), 1, arquivo2)==1);

    }
}
/* lista no vídeo os jogos de uma data
Listar jogos de uma data: esta funcionalidade deve ser implementada através da
função list_jogos_data(). O sistema deve solicitar uma data e exibir no vídeo o
grupo, estádio e adversários de todos os jogos que ocorrem na data informada pelo
usuário.*/
void list_jogos_data(void){
    FILE * arquivo, * arquivo2;
    arquivo = fopen(ARQ_SEL, "rb");
    arquivo2 = fopen(ARQ_JOGO, "rb");
    int i = 0;

    tselecao selecao;
    tjogo jogo;
    system("cls");

    printf("-----------------------------------------------------------------\n|\t  Lista de jogos da 1ª fase por data\t\t\t|");
    printf("\n-----------------------------------------------------------------\n\n");

    if(arquivo == NULL)
        printf("\t\tProblemas na abertura do arquivo!");
    else{
        printf("\nInforme uma data, no formato dd 'Espaço' mm,  para visualizar os jogos deste dia:  ");
        scanf(" %d", &i);

        // Exibe os jogos da data se houver algum
        do{
            fread(&jogo, sizeof(tjogo), 1, arquivo2);
            char mandante[31], visitante[31];
            if(i == jogo.data.dia){
                printf("-----------------------------------------------------------------\n|\t\tJogo do dia %d/ %d/2018 da 1ª fase\t\t|",
                       jogo.data.dia, jogo.data.mes);
                    printf("\n-----------------------------------------------------------------\n\n");
                    printf("\t-------------------------------------------------\n\t|\t\t  Estadio : %-15s\t|", jogo.estadio);
                    printf("\n\t-------------------------------------------------\n\n");


                    fseek(arquivo, sizeof(tselecao) * (jogo.id_mandante-1), SEEK_SET);
                    fread(&selecao,sizeof(tselecao),1,arquivo);
                    strcpy(mandante,selecao.nome);
                    fseek(arquivo, sizeof(tselecao) * (jogo.id_visitante-1), SEEK_SET);
                    fread(&selecao,sizeof(tselecao),1,arquivo);
                    strcpy(visitante,selecao.nome);
                    printf("\n-------------------------------------------------------------------------\n|       Mandante => %-15s X %15s <= Visitante \t|", mandante, visitante);
                    printf("\n-------------------------------------------------------------------------\n\n");

                    fread(&jogo, sizeof(tjogo), 1, arquivo2);
            }
        }while(fread(&jogo, sizeof(tjogo), 1, arquivo2)==1);
        fclose(arquivo);
        fclose(arquivo2);
        printf("\n\n<Pressione 'Enter' para voltar ao menu principal!>");
        getch();
        fflush(stdin);
        system("cls");
    }
}

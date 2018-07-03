#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "manipulaDados.h"
#include "manipulaString.h"
#include "lde.h"
#include "lse.h"
#include "operacoes.h"

// Função responsável por receber todos os dados do arquivo de entrada e realizar a inserção deles na estrutura correspondente
Info* entradaDados(FILE* entrada)
{
    int qtdTermos = 0;
    char str[601], cidade[100], *termo = NULL;
    Info *dados;
    LSE* listaTermos;

    // Forçando alocação
    do{
        dados = (Info*)malloc(sizeof(Info));
    }while(dados == NULL);

    // Inicialização dos dados
    dados->arvore = criaArvore();
    dados->termos = inicializaLDE();

    //printf("DADOS DE ENTRADA: \n");
    while(fgets(str, 600, entrada))
    {
        // String parse
        converteAcentos(str);
        removeCaracteres(str);

        /* PEGA A CIDADE */
        strcpy(cidade, strtok(str, ";"));

        /* PEGA OS TERMOS */
        listaTermos = inicializaLSE();                          // Zera a lista de termos
        qtdTermos = 0;                                          // Zera os termos
        while((termo = strtok(NULL, ";")))                      // Insere todos os termos da str na lista
        {
            if(termo[strlen(termo) - 1] == '\n')                // Tira o \n caso ele exista
                termo[strlen(termo) - 1] = '\0';

            listaTermos = insereLSE(listaTermos, termo);                // Insere o termo na sua lista
            dados->termos = insereLDENumerico(dados->termos, termo, 1);    // Insere o termo na lista geral
            qtdTermos++;                                                // Incrementa o contador de termos
        }
        dados->arvore = insereNodoArvore(dados->arvore, listaTermos, qtdTermos, cidade);
    }

    return dados;
}


// Função responsável por realizar todas as operações contidas no arquivo de operações utilizando a árvore que possui todos os dados
int realizaOperacoes(FILE* operacoes, FILE* saida, Info* dados)
{
    char str[201], localidade[100], operacao;
    Consulta retorno[TAM_VET] = {0};
    LDE *termos;
    int qtdConsultas = 0;
    int i;
    int tamanho, qtdTermos; //Usado nas operações 'e' & 'f'

    // SETTING
    int size = consultasArquivo(dados->arvore, retorno, TAM_VET);
    // Agora retorno tem os valores corretos

    while(fgets(str, 200, operacoes))
    {
        qtdConsultas++;
        converteAcentos(str);
        removeCaracteres(str);
        operacao =  *(strtok(str, ";")); //Lê a operação a ser realizada

        // Operacoes de consulta no arquivo
        switch(operacao)
        {
        case 'a':
            //Recebe a localidade e a quantidade de consultas
            strcpy(localidade,strtok(NULL, ";"));
            qtdTermos = atoi(strtok(NULL, ";"));

            //printf("\n%d consultas mais realizadas em %s: \n", qtdTermos, localidade);
            consultasPorLocalidade(dados->arvore, localidade, qtdTermos, saida);
            break;
        case 'b':
            //Recebe a quantidade de consultas
            qtdTermos = atoi(strtok(NULL, ";"));

            if(qtdTermos == 0) qtdTermos = size; //Se for 0, printa todos

            for (i = 0; i < qtdTermos && retorno[i].termos; i++)
            {
                fprintf(saida, "%d ",(retorno+i)->qtdeAcessos);
                printaLSE(retorno[i].termos, saida);
            }
            break;
        case 'c':
            //Recebe a localidade e a quantidade de termos
            strcpy(localidade, strtok(NULL, ";"));
            qtdTermos = atoi(strtok(NULL, ";"));

            //printf("\n%d termos que mais aparecem em %s:\n", qtdTermos, localidade);
            termos = termosPorLocalidade(dados->arvore,  inicializaLDE(), localidade);
            printaLDE(termos, qtdTermos, saida);
            break;
        case 'd':
            //Devolve os n termos mais consultados no arquivo
            qtdTermos = atoi(strtok(NULL, ";"));

            //printf("\n%d termos mais consultados no arquivo:\n", qtdTermos);
            termos = termosArquivo(dados->termos);
            printaLDE(termos, qtdTermos, saida);
            break;
        case 'e':
            //Média de termos por consulta em uma dada localidade
            strcpy(localidade,strtok(NULL, ";"));
            tamanho = mediaTamanhoConsultasLocalidade(dados->arvore, localidade);
            fprintf(saida, "Media de termos %d\n", tamanho);
            break;
        case 'f':
            // Média de termos por consulta em todo o arquivo
            tamanho = mediaTamanhoConsultasArquivo(dados->arvore);
            fprintf(saida, "Media de termos %d\n", tamanho);
            break;
        }
    }

    return qtdConsultas;
}

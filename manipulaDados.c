#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "manipulaDados.h"
#include "manipulaString.h"
#include "lde.h"
#include "lse.h"

/* DEFINES PARA A FLAG DE INSERÇÃO */
#define PENDING 0
#define EXISTE 1
#define NOVO 2

/// Função responsável por receber todos os dados do arquivo de entrada e realizar a inserção deles na estrutura correspondente
/// INPUT:
///         FILE*                ->  Ponteiro para o arquivo com os dados de entrada
/// OUTPUT:
///         Consulta*            ->  Árvore binária contendo todos os dados do arquivo de entrada
Consulta* entradaDados(FILE* entrada)
{
    int qtdTermos = 0;
    char str[201], cidade[100], *termo = NULL;
    Consulta *arvore = criaArvore();
    LSE* listaTermos;

    //printf("DADOS DE ENTRADA: \n");
    while(fgets(str, 200, entrada))
    {
        // String parse
        converteAcentos(str);
        removeCaracteres(str);

        /* PEGA A CIDADE */
        strcpy(cidade, strtok(str, ";"));
        //printf("\nCIDADE: --> %s\n", cidade);

        /* PEGA OS TERMOS */
        listaTermos = inicializaLSE();                          // Zera a lista de termos
        qtdTermos = 0;                                          // Zera os termos
        while((termo = strtok(NULL, ";")))                      // Insere todos os termos da str na lista
        {
            if(termo[strlen(termo) - 1] == '\n')                // Tira o \n caso ele exista
                termo[strlen(termo) - 1] = '\0';

            listaTermos = insereLSE(listaTermos, termo);        // Insere o termo na sua lista
            qtdTermos++;                                        // Incrementa o contador de termos
        }

        arvore = insereNodoArvore(arvore, listaTermos, qtdTermos, cidade);
    }

    return arvore;
}


/// Função responsável por realizar todas as operações contidas no arquivo de operações utilizando a árvore que possui todos os dados
/// INPUT:
///         FILE*                ->  Ponteiro para o arquivo com as operações a serem realizadas na árvore
///         Consulta*            ->  Árvore contendo todos os dados
void realizaOperacoes(FILE* operacoes, Consulta* arvore)
{

    char str[201];

    //printf("\nOPERACOES A SEREM REALIZADAS: \n");
    while(fgets(str, 200, operacoes))
    {
        converteAcentos(str);
        removeCaracteres(str);
        //printf("%s", str);
    }

    return;
}

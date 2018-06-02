#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manipulaDados.h"
#include "manipulaString.h"
#include "lde.h"
#include "lse.h"

/// Função responsável por receber todos os dados do arquivo de entrada e realizar a inserção deles na estrutura correspondente
/// INPUT:
///         FILE*                ->  Ponteiro para o arquivo com os dados de entrada
/// OUTPUT:
///         Consulta*            ->  Árvore binária contendo todos os dados do arquivo de entrada
Consulta* entradaDados(FILE* entrada)
{

    int qtdTermos = 0;
    char str[201], *termo;
    Consulta* arvore = criaArvore();
    LSE* listaTermos;

    printf("DADOS DE ENTRADA: \n");
    while(fgets(str, 200, entrada))
    {
        // String parse
        converteAcentos(str);
        removeCaracteres(str);
        printf("%s", str);

        if(arvore)
        {

        }
        else
        {
            arvore = (Consulta*) malloc(sizeof(Consulta));          // Inicializa um nó
            arvore->cidades = inicializaLDE();                      // Inicializa a LDE das cidades
            listaTermos = inicializaLSE();                          // Variável temporária para guardar os termos
            arvore->esq = NULL;                                     // Arvore da esquerda é nula
            arvore->dir = NULL;                                     // Arvore da direita é nula
            arvore->qtdeAcessos = 1;                                // Primeira vez que essa árvore é acessada
            arvore->qtdeTermos = 0;                                 // Zera o contador de termos para poder ser incrementado abaixo

            /* INSERÇÃO DA CIDADE */
            arvore->cidades = insereLDE(arvore->cidades, strtok(str,";"));   // Insere a cidade (primeiro token da str) na sua lista
            printf("\n***CIDADE***\n%s", arvore->cidades->nome);

            /* INSERÇÃO DOS TERMOS */
            while((termo = strtok(NULL, ";")))                      // Insere todos os termos da str na lista
            {
                if(termo[strlen(termo) - 1] == '\n')                // Tira o \n caso ele exista
                    termo[strlen(termo) - 1] = '\0';

                listaTermos = insereLSE(listaTermos, termo);        // Insere o termo na sua lista
                qtdTermos++;                                        // Incrementa o contador de termos
            }

            arvore->termos = listaTermos;                           // Como eu tenho uma árvore vazia, já tenho o nó no qual vai ser inserido, e posso setá-lo
            arvore->qtdeTermos = qtdTermos;                         // Seto a quantidade de Termos (CHAVE DA ÁRVORE)

            printf("\n***TERMOS***\n");
            printaLSE(arvore->termos);
        }
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

    printf("\nOPERACOES A SEREM REALIZADAS: \n");
    while(fgets(str, 200, operacoes))
    {
        converteAcentos(str);
        removeCaracteres(str);
        printf("%s", str);
    }

    return;
}

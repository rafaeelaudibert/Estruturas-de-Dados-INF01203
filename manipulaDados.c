#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "manipulaDados.h"
#include "manipulaString.h"
#include "lde.h"
#include "lse.h"
#include "operacoes.h"

/// Função responsável por receber todos os dados do arquivo de entrada e realizar a inserção deles na estrutura correspondente
/// INPUT:
///         FILE*                ->  Ponteiro para o arquivo com os dados de entrada
/// OUTPUT:
///         Info*                ->  Estrutura que contem todas as informações recebidas
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
            dados->termos = insereLDENumerico(dados->termos, termo);    // Insere o termo na lista geral
            qtdTermos++;                                                // Incrementa o contador de termos
        }
        dados->arvore = insereNodoArvore(dados->arvore, listaTermos, qtdTermos, cidade);
    }

    return dados;
}


/// Função responsável por realizar todas as operações contidas no arquivo de operações utilizando a árvore que possui todos os dados
/// INPUT:
///         FILE*                ->  Ponteiro para o arquivo com as operações a serem realizadas na árvore
///         Info*                ->  Estrutura contendo toda a informação necessária
void realizaOperacoes(FILE* operacoes, FILE* saida, Info* dados)
{
    char termoCidade[100];
    char str[201], localidadeMedia[100], localidadeTermos[100], operacao;
    LDE *termos, *termosLocal;
    int tamanho, qtdTermos, qtdTermosCidade; //Usado nas operações 'e' & 'f'
    while(fgets(str, 200, operacoes))
    {
        converteAcentos(str);
        removeCaracteres(str);
        operacao =  *(strtok(str, ";"));

        // Operacoes de consulta no arquivo
        switch(operacao)
        {
        case 'a':
            //Recebe a localidade e a quantidade de consultas
            //printf("Operacao A: \n");
            //strcpy(localidadeTermos,strtok(NULL, ";"));
            //qtdTermosCidade = atoi(strtok(NULL, ";"));
            //consultasPorLocalidade(dados->arvore, localidadeTermos, qtdTermosCidade);
            break;
        case 'b':
            //Recebe a quantidade de consultas
            qtdTermos = atoi(strtok(NULL, ";"));
            consultasArquivo(dados->arvore, qtdTermos);
            break;
        case 'c':
            //Recebe a localidade e a quantidade de termos
            //strcpy(termoCidade,strtok(NULL, ";"));
            //termosLocal = termosPorLocalidade(dados->arvore, termoCidade, atoi(strtok(NULL, ";")));
            //printf("Termos na cidade de %s:\n", termoCidade);
            //printaLDE(termosLocal);
            break;
        case 'd':
            //Devolve os n termos mais consultados no arquivo
            termos = termosArquivo(dados->termos, atoi(strtok(NULL, ";")));
            printaLDE(termos);
            break;
        case 'e':
            // Média de termos por consulta em uma dada localidade
            strcpy(localidadeMedia,strtok(NULL, ";"));
            tamanho = mediaTamanhoConsultasLocalidade(dados->arvore, localidadeMedia);
            printf("\nMedia de termos em %s: %d\n", localidadeMedia, tamanho);
            break;
        case 'f':
            // Média de termos por consulta em todo o arquivo
            tamanho = mediaTamanhoConsultasArquivo(dados->arvore);
            printf("\nMedia de termos no arquivo: %d\n", tamanho);
            break;
        }
    }

    return;
}

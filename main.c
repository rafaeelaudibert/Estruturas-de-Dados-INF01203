/* INCLUSÃO DAS BIBLIOTECAS DO C */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
//#include <windows.h> //-> DESCOMENTAR PARA RODAR O BENCHMARK NO WINDOWS


/* INCLUSÃO DAS BIBLIIOTECAS CRIADAS PELO GRUPO */
#include "struct.h"
#include "manipulaString.h"
#include "arvore.h"
#include "lse.h"
#include "manipulaDados.h"
#include "lde.h"

/* DEFINES PARA OS ARQUIVOS - DEVELOPMENT ONLY */
#define F_ENTRADA "data/entrada.txt"
#define F_OPERACOES "data/operaEasy.txt"
#define F_SAIDA "data/saida.txt"

/* PROTÓTIPO DA FUNÇÃO BENCHMARK */
Info* infoBenchmark(Info*(*function)(FILE*), FILE*);

/* MAIN */
int main(int argc, char **argv){

    FILE *entrada, *operacoes, *saida;

    Info* dados = NULL;
    setlocale(LC_ALL, "Portuguese");
    printf("    \n");

    // Abertura dos arquivos, com checagem dos erros
    if(!(entrada = fopen(F_ENTRADA, "r"))){
       printf("Erro na abertura do arquivo de entrada");
       return 1;
    }
    if(!(operacoes = fopen(F_OPERACOES, "r"))){
       printf("Erro na abertura do arquivo das operacoes");
       return 2;
    }
    if(!(saida = fopen(F_SAIDA, "w"))){
       printf("Erro na abertura do arquivo de saída");
       return 3;
    }

    dados = entradaDados(entrada); // Entrada dos dados padrão
    //printf("\n\nMaior nivel: %d", percorreArvore(dados->arvore, 1)); //DEBUG ONLY

    //printaLDE(dados->termos);
    //dados = infoBenchmark(entradaDados, entrada); // Entrada dos dados com benchmark do tempo -> SÓ FUNCIONA NO WINDOWS

    realizaOperacoes(operacoes, saida, dados); // Realiza operacoes com os dados

    // Fechamento dos arquivos
    fclose(entrada);
    fclose(operacoes);
    fclose(saida);

    return 0;
}


/// Função que faz o benchmark (tempo gasto em uma função) que retorna uma consulta
/// INPUT:
///         Info*(*function)(FILE*)  -> Função a ser feita o benchmark, deve retornar uma estrutura Info* e receber um arquivo
///         FILE*                        -> Ponteiro para arquivo que a função vai receber
/// OUTPUT:
///         Info*                    -> Retorno da função que foi feita o benchmark
/*Info* infoBenchmark(Info*(*function)(FILE*), FILE* entrada){

    Info *dados;
    double tempoGasto;
    __int64 freq,start,stop;
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq); //Seta a frequencia do processador

    QueryPerformanceCounter((LARGE_INTEGER *)&start);
    dados = function(entrada);
    QueryPerformanceCounter((LARGE_INTEGER *)&stop);
    tempoGasto = ((double)stop-(double)start) / (double)freq * 1000000;

    if(tempoGasto < 1000)
        printf("Tempo gasto na insercao dos dados: %3.8fus (microssegundos)\n", tempoGasto);
    else
        printf("Tempo gasto na insercao dos dados: %3.8fms (milissegundos)\n", tempoGasto/1000);

    return dados;
}*/

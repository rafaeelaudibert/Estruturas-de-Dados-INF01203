/* INCLUSÃO DAS BIBLIOTECAS DO C */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


/* INCLUSÃO DAS BIBLIIOTECAS CRIADAS PELO GRUPO */
#include "struct.h"
#include "manipulaString.h"
#include "arvore.h"
#include "lse.h"
#include "manipulaDados.h"
#include "lde.h"

/* DEFINES PARA OS ARQUIVOS - DEVELOPMENT ONLY */
#define F_ENTRADA "data/entrada.txt"
#define F_OPERACOES "data/operacoes.txt"
#define F_SAIDA "data/saida.txt"

/* PROTÓTIPO DA FUNÇÃO BENCHMARK */
Consulta* consultaBenchmark(Consulta*(*function)(FILE*), FILE*);

/* MAIN */
int main(int argc, char **argv){

    FILE *entrada, *operacoes, *saida;
    Consulta* arvore;

    setlocale(LC_ALL, "Portuguese");

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
       printf("Erro na abertura do arquivo");
       return 3;
    }

    // Entrada dos dados na arvore
    arvore = entradaDados(entrada);

    // Realiza operacoes com os dados colocados na arvore
    realizaOperacoes(operacoes, arvore);
    // Fechamento dos arquivos
    fclose(entrada);
    fclose(operacoes);
    fclose(saida);

    return 0;
}


/// Função que faz o benchmark (tempo gasto em uma função) que retorna uma consulta
/// INPUT:
///         Consulta*(*function)(FILE*)  -> Função a ser feita o benchmark, deve retornar uma consulta e receber um arquivo
///         FILE*                        -> Ponteiro para arquivo que a função vai receber
/// OUTPUT:
///         Consulta*                    -> Retorno da função que foi feita o benchmark
Consulta* consultaBenchmark(Consulta*(*function)(FILE*), FILE* entrada){

    Consulta *arvore;
    //__int64 freq,start,stop;
    //QueryPerformanceFrequency((LARGE_INTEGER *)&freq); //Seta a frequencia do processador

    //QueryPerformanceCounter((LARGE_INTEGER *)&start);
    arvore = function(entrada);
    //QueryPerformanceCounter((LARGE_INTEGER *)&stop);
    //printf("Tempo gasto na insercao dos dados: %.4fus (microssegundos)", ((double)stop-(double)start) / (double)freq * 1000000);

    return arvore;
}

/* INCLUS√ÉO DAS BIBLIOTECAS DO C */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include<sys/time.h>  // -> DESCOMENTAR PARA RODAR O BENCHMARK NO LINUX
//#include <windows.h> //-> DESCOMENTAR PARA RODAR O BENCHMARK NO WINDOWS


/* INCLUS√ÉO DAS BIBLIIOTECAS CRIADAS PELO GRUPO */
#include "struct.h"
#include "manipulaString.h"
#include "arvore.h"
#include "lse.h"
#include "manipulaDados.h"
#include "lde.h"

/* DEFINES PARA OS ARQUIVOS - DEVELOPMENT ONLY */
#define F_ENTRADA "data/input_ANSI.txt"
#define F_OPERACOES "data/operations_ANSI.txt"
#define F_SAIDA "data/saida_ANSI.txt"

/* PROT√ìTIPO DA FUN√á√ÉO BENCHMARK */
Info* infoBenchmark(Info*(*function)(FILE*), FILE*);
void operacoesBenchmark(int(*function)(FILE*, FILE*, Info*), FILE*, FILE*, Info*);

/* MAIN */
int main(int argc, char **argv){

    FILE *entrada, *operacoes, *saida;
    Info* dados = NULL;
    setlocale(LC_ALL, "Portuguese");
    printf("/* MEDICAO DO TEMPO *\\\n");

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
       printf("Erro na abertura do arquivo de sa√≠da");
       return 3;
    }

    dados = infoBenchmark(entradaDados, entrada); // Entrada dos dados com benchmark do tempo
    operacoesBenchmark(realizaOperacoes, operacoes, saida, dados); // Realiza opera√ß√µes com o benchmark de tempo

    // Fechamento dos arquivos
    fclose(entrada);
    fclose(operacoes);
    fclose(saida);

    return 0;
}


/// Fun√ß√£o que faz o benchmark (tempo gasto em uma fun√ß√£o) que retorna uma consulta
/// INPUT:
///         Info*(*function)(FILE*)  -> Fun√ß√£o a ser feita o benchmark, deve retornar uma estrutura Info* e receber um arquivo
///         FILE*                    -> Ponteiro para arquivo que a fun√ß√£o vai receber
/// OUTPUT:
///         Info*                    -> Retorno da fun√ß√£o que foi feita o benchmark
Info* infoBenchmark(Info*(*function)(FILE*), FILE* entrada){

    /* //WINDOWS
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

    */

    //LINUX
    Info *dados;
    struct timeval start, end;
    double tempoGasto;

    gettimeofday(&start, NULL);
    dados = function(entrada);
    gettimeofday(&end, NULL);


    tempoGasto = ((end.tv_sec - start.tv_sec) * 1000000.0) + (end.tv_usec - start.tv_usec);

    if(tempoGasto < 1000){
        printf("Tempo gasto na inserÁ„o dos dados: \t\t%4.3fus (microssegundos)\n",tempoGasto);
    } else {
        printf("Tempo gasto na inserÁ„o dos dados: \t\t%4.3fms (milissegundos)\n",tempoGasto/1000);
    }


    return dados;
}

void operacoesBenchmark(int(*function)(FILE*, FILE*, Info*), FILE* operacoes, FILE* saida, Info* dados){

    /* //WINDOWS
    double tempoGasto;
    __int64 freq,start,stop;
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq); //Seta a frequencia do processador

    QueryPerformanceCounter((LARGE_INTEGER *)&start);
    function(operacoes, saida, dados);
    QueryPerformanceCounter((LARGE_INTEGER *)&stop);
    tempoGasto = ((double)stop-(double)start) / (double)freq * 1000000;

    if(tempoGasto < 1000)
        printf("Tempo gasto na realiza√ßao das operacoes: %3.8fus (microssegundos)\n", tempoGasto);
    else
        printf("Tempo gasto na realiza√ßao das operacoes: %3.8fms (milissegundos)\n", tempoGasto/1000);

    */ //END WINDOWS

    //LINUX
    struct timeval start, end;
    double tempoGasto;
    int qtdOperacoes;

    gettimeofday(&start, NULL);
    qtdOperacoes = function(operacoes, saida, dados);
    gettimeofday(&end, NULL);

    tempoGasto = ((end.tv_sec - start.tv_sec) * 1000000.0) + (end.tv_usec - start.tv_usec);

    if(tempoGasto < 1000){
        printf("Tempo gasto na realizaÁ„o das %d operacıes: \t%4.3fus (microssegundos)\n",qtdOperacoes, tempoGasto);
    } else if((tempoGasto /= 1000) < 1000){
        printf("Tempo gasto na realizaÁ„o das %d operacıes: \t%4.3fms (milissegundos)\n",qtdOperacoes, tempoGasto);
    } else {
        printf("Tempo gasto na realizaÁ„o das %d operacıes: \t%4.3fs (segundos)\n",qtdOperacoes, tempoGasto/1000);
    }

    //END LINUX

    return;

}

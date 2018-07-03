#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>  // -> DESCOMENTAR PARA RODAR O BENCHMARK NO LINUX
//#include <windows.h> //-> DESCOMENTAR PARA RODAR O BENCHMARK NO WINDOWS
#include "benchmark.h"

// Função que faz o benchmark (tempo gasto em uma função) que retorna uma consulta
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
        printf("Tempo gasto na inserção dos dados: \t\t%4.3fus (microssegundos)\n",tempoGasto);
    } else {
        printf("Tempo gasto na inserção dos dados: \t\t%4.3fms (milissegundos)\n",tempoGasto/1000);
    }


    return dados;
}

// Função que faz o benchmark (tempo gasto em uma função) da função que realiza as operações nos dados.
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
        printf("Tempo gasto na realizaçao das operacoes: %3.8fus (microssegundos)\n", tempoGasto);
    else
        printf("Tempo gasto na realizaçao das operacoes: %3.8fms (milissegundos)\n", tempoGasto/1000);

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
        printf("Tempo gasto na realizaçao das %d operacoes: \t%4.3fus (microssegundos)\n",qtdOperacoes, tempoGasto);
    } else if((tempoGasto /= 1000) < 1000){
        printf("Tempo gasto na realizaçao das %d operacoes: \t%4.3fms (milissegundos)\n",qtdOperacoes, tempoGasto);
    } else {
        printf("Tempo gasto na realizaçao das %d operacoes: \t%4.3fs (segundos)\n",qtdOperacoes, tempoGasto/1000);
    }

    //END LINUX

    return;

}

#include <stdio.h>
#include "struct.h"

#define F_ENTRADA "data/entrada.txt"
#define F_OPERACOES "data/operacoes.txt"
#define F_SAIDA "data/saida.txt"

int main(int argc, char **argv){


    FILE *entrada, *operacoes, *saida;

    if(!(entrada = fopen(F_ENTRADA, "r"))){
       printf("Erro na abertura do arquivo de entrada");
    }
    if(!(operacoes = fopen(F_OPERACOES, "r"))){
       printf("Erro na abertura do arquivo das operacoes");
    }
    if(!(saida = fopen(F_SAIDA, "r"))){
       printf("Erro na abertura do arquivo");
    }

    return 0;
}

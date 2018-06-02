/* INCLUSÃO DAS BIBLIOTECAS DO C */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


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

    printf("\nPonteiro da arvore alocado em: %p", arvore);

    // Fechamento dos arquivos
    fclose(entrada);
    fclose(operacoes);
    fclose(saida);

    return 0;
}

#include <stdio.h>
#include <locale.h>
#include "struct.h"
#include "manipulaString.h"

#define F_ENTRADA "data/entrada.txt"
#define F_OPERACOES "data/operacoes.txt"
#define F_SAIDA "data/saida.txt"

int main(int argc, char **argv){

    FILE *entrada, *operacoes, *saida;
    char str[201];

    setlocale(LC_ALL, "Portuguese");

    // Abertura dos arquivos
    if(!(entrada = fopen(F_ENTRADA, "r"))){
       printf("Erro na abertura do arquivo de entrada");
    }
    if(!(operacoes = fopen(F_OPERACOES, "r"))){
       printf("Erro na abertura do arquivo das operacoes");
    }
    if(!(saida = fopen(F_SAIDA, "w"))){
       printf("Erro na abertura do arquivo");
    }

    //Lê cada uma das linhas dos arquivos de entrada e de operacoes
    printf("ENTRADA: \n");
    //entradaDados(entrada);
    while(fgets(str, 200, entrada))
    {
        converteAcentos(str);
        removeCaracteres(str);
        printf("%s", str);
    }

    printf("\nOPERACOES: \n");
    //realizaOperacoes(operacoes);
    while(fgets(str, 200, operacoes))
    {
        printf("%s", str);
    }

    // Fechamento dos arquivos
    fclose(entrada);
    fclose(operacoes);
    fclose(saida);

    return 0;
}

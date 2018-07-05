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
#include "benchmark.h"

/* DEFINES PARA OS ARQUIVOS - DEVELOPMENT ONLY */
#define F_ENTRADA "data/input.txt"
#define F_OPERACOES "data/operations.txt"
#define F_SAIDA "data/saida.txt"

/**
 * @file main.c
 * @author Rafael Baldasso Audibert
 * @author Augusto Zanella Bardini
 * @date 11 Jul 2018
 * @brief Arquivo que contém a main do programa Analytics
 */

 /**
  * @brief Função main do programa Analytics
  *
  * A função main() é a função principal do programa Analytics, e é por ela que o programa começa
  *
  * @param argc Quantidade de argumentos passados para a execução do programa
  * @param **argv Argumentos passados para a execução do programa
  * @return 0 caso tudo ocorra sem problemas
  * @return 1 caso o arquivo de entrada não possa ser aberto;
  * @return 2 caso o arquivo de operações não possa ser aberto;
  * @return 3 caso o arquivo de saída não possa ser criado;
  */
int main(int argc, char **argv){

    FILE *entrada, *operacoes, *saida;
    char fEntrada[100], fOPeracoes[100], fSaida[100];
    Info* dados = NULL;
    setlocale(LC_ALL, "Portuguese");
    printf("/* MEDICAO DO TEMPO *\\\n");

    // Abertura dos arquivos, com checagem dos erros
    if(argc == 4){ // Se eu recebi como argumentos os nomes dos arquivos
      if(!(entrada = fopen(argv[1], "r"))){
         printf("Erro na abertura do arquivo de entrada\n");
         return 1;
      }
      if(!(operacoes = fopen(argv[2], "r"))){
         printf("Erro na abertura do arquivo das operacoes\n");
         return 2;
      }
      if(!(saida = fopen(argv[3], "w"))){
         printf("Erro na abertura do arquivo de saída\n");
         return 3;
      }
    } else { //Usa os nomes default

      if(!(entrada = fopen(F_ENTRADA, "r"))){
         printf("Erro na abertura do arquivo de entrada\n");
         return 1;
      }
      if(!(operacoes = fopen(F_OPERACOES, "r"))){
         printf("Erro na abertura do arquivo das operacoes\n");
         return 2;
      }
      if(!(saida = fopen(F_SAIDA, "w"))){
         printf("Erro na abertura do arquivo de saída\n");
         return 3;
      }
    }

    dados = infoBenchmark(entradaDados, entrada); // Entrada dos dados com benchmark do tempo
    operacoesBenchmark(realizaOperacoes, operacoes, saida, dados); // Realiza operações com o benchmark de tempo

    // Fechamento dos arquivos
    fclose(entrada);
    fclose(operacoes);
    fclose(saida);

    return 0;
}

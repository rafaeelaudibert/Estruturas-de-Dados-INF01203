#include <stdio.h>
#include "manipulaDados.h"
#include "manipulaString.h"

/// Função responsável por receber todos os dados do arquivo de entrada e realizar a inserção deles na estrutura correspondente
/// INPUT:
///         FILE*                ->  Ponteiro para o arquivo com os dados de entrada
/// OUTPUT:
///         Consulta*            ->  Árvore binária contendo todos os dados do arquivo de entrada
Consulta* entradaDados(FILE* entrada){

    char str[201];
    Consulta* arvore = criaArvore();

    printf("DADOS DE ENTRADA: \n");
    while(fgets(str, 200, entrada))
    {
        converteAcentos(str);
        removeCaracteres(str);
        printf("%s", str);
    }

    return arvore;
}


/// Função responsável por realizar todas as operações contidas no arquivo de operações utilizando a árvore que possui todos os dados
/// INPUT:
///         FILE*                ->  Ponteiro para o arquivo com as operações a serem realizadas na árvore
///         Consulta*            ->  Árvore contendo todos os dados
void realizaOperacoes(FILE* operacoes, Consulta* arvore){

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

#include "arvore.h"

/**
 * @file manipulaDados.h
 * @author Rafael Baldasso Audibert
 * @author Augusto Zanella Bardini
 * @date 11 Jul 2018
 * @brief Arquivo que contém as principais funções do programa.
 *
 * Nesse arquivo encontramos as duas principais funções do programa, sendo elas responsáveis por controlar
 * a leitura dos arquivos de entrada e operações, além de realizar toda a manipulação das estruturas e das
 * outras funções.
 */

#ifndef MANIPULA_DADOS_H_
#define MANIPULA_DADOS_H_

/**
 * @brief Leitura dos dados do arquivo
 *
 * A função entradaDados() realiza a leitura dos dados do arquivo de entrada, manipulando as outras funções do programa,
 * fazendo com que cada valor termine em sua devida estrutura, pronta para ser utilizada pela função realizaOperacoes().
 *
 * @param entrada Nome do arquivo de entrada
 *
 * @return @c Info* contendo a árvore com as consultas e a lista de termos totais do arquivo.
 */
Info* entradaDados(FILE* entrada);


/**
 * @brief Realização das operações nos dados recebidos
 *
 * A função realizaOperacoes() realiza a leitura das operacoes, realizando buscas nos dados
 * fazendo com que toda a informação solicitada seja escrita no arquivo de saída.
 *
 * @param operacoes Nome do arquivo que contém as operações a serem realizadas nos @c dados.
 * @param saida Nome do arquivo no qual serão escritos os dados de saída
 * @param dados Informações geradas pela função entradaDados() a partir dos dados que haviam no arquivo de entrada.
 * @return @c int que representa a quantidade de operações realizadas.
 */
int realizaOperacoes(FILE* operacoes, FILE* saida, Info* dados);
#endif // MANIPULA_DADOS_H_

#include "struct.h"

/**
 * @file lse.h
 * @author Rafael Baldasso Audibert
 * @author Augusto Zanella Bardini
 * @date 11 Jul 2018
 * @brief Arquivo que contém funções relacionadas a manipulação de listas simplesmente encadeadas
 */

#ifndef TERMOS_H_
#define TERMOS_H_

/**
 * @brief Cria uma lista simplesmente encadeada
 *
 * A função inicializaLSE() cria uma lista simplesmente encadeada vazia.
 * @return @c NULL sempre é retornado.
 */
LSE* inicializaLSE();

/**
 * @brief Insere um nodo em uma lista simplesmente encadeada
 *
 * A função insereLSE() insere um nodo em uma lista simplesmente encadeada já existente, mantendo-a
 * ordenada em ordem alfabética.
 *
 * @param lista Lista na qual será inserida o novo termo
 * @param termo String do termo que será inserido na lista
 * @return @c LSE* contendo a lista recebido com a adição do novo termo.
 */
LSE* insereLSE(LSE* lista, char* termo);

/**
 * @brief Retorna 1 se duas LSE são identicas
 *
 * A função LSEigual() é responsável por dizer se @c lse1 e @c lse2 são idênticas.
 *
 * @param lse1 Lista 1
 * @param lse2 LIsta 2
 *
 * @return @c 1 se as listas forem idênticas, @c 0 se as listas forem diferentes
 */
int LSEigual(LSE* lse1, LSE* lse2);

/**
 * @brief Logging de informações sobre a lista
 *
 * A função printaLSE() é responsável por printar em um arquivo, informações a respeito da lista.
 * Essa informação é printada no formato "@<termo;termo;termo;...@>".
 *
 * @param lista Lista que iremos printar
 * @param saida Arquivo no qual será printado a informação (pode ser passado stdout, para printar no terminal)
 */
void printaLSE(LSE* lista, FILE* saida);

/**
 * @brief Transforma uma LSE em uma string
 *
 * A função parseLSEtoString() é responsável por transformar uma LSE em uma string formatada.
 * Seu formato é ""@<termo; termo; termo; termo@>".
 *
 * @param lista Lista que iremos transformar em string
 * @param string Ponteiro para o local onde guardaremos a string
 *
 * @return @c *char onde iremos guardar a string
 * @note Não é necessário utilizar o retorno dessa função, já que ela já recebe o ponteiro pra string na qual
 * ela será guardada como parâmetro. Ela é retornada apenas por convenção. 
 */
char *parseLSEtoString(LSE* lista, char *string);
#endif // TERMOS_H_

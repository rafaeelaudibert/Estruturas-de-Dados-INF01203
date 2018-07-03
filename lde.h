#include "struct.h"
#include <stdio.h>

/**
 * @file lde.h
 * @author Rafael Baldasso Audibert
 * @author Augusto Zanella Bardini
 * @date 11 Jul 2018
 * @brief Arquivo que contém funções relacionadas a manipulação de listas duplamente encadeadas
 */

#ifndef CIDADES_H_
#define CIDADES_H_

/**
 * @brief Cria uma lista duplamente encadeada
 *
 * A função inicializaLDE() cria uma lista duplamente encadeada vazia.
 * @return @c NULL sempre é retornado.
 */
LDE* inicializaLDE();


/**
 * @brief Insere um item na LDE, deixando-a em ordem alfabética
 *
 * A função insereLDEAlfabetico() é responsável por inserir um item na LDE, fazendo que com a LDE sempre fique
 * em ordem alfabética. Caso um item seja igual a algum que já está inserido, é incrementado um contador,
 * mostrando que aquele termo foi inserido mais de uma vez.
 * @param lista Lista Duplamente Encadeada na qual será inserido o novo item
 * @param nome String contendo o item que será inserido na lista

 * @return @c *LDE contendo a lista recebida, com a adição/incrementação do novo item.
 */
LDE* insereLDEAlfabetico(LDE* lista, char* nome);


/**
 * @brief Insere um item na LDE, deixando-a em ordem numérica
 *
 * A função insereLDENumerico() é responsável por inserir um item na LDE, fazendo que com a LDE sempre fique
 * em ordem numérica decrescente. Caso um item tenha o mesmo valor numérico que outro, eles são ordenados de forma
 * alfabética. Caso um item com a mesma quantidade numérica e tenha seu nome igual a algum que já está inserido, é incrementado um contador,
 * mostrando que aquele termo foi inserido mais de uma vez.
 * @param lista Lista Duplamente Encadeada na qual será inserido o novo item
 * @param nome String contendo o item que será inserido na lista
 * @param qtde Numero que representa a quantidade de vezes que ele foi chamado.
 * @return @c *LDE contendo a lista recebida, com a adição/incrementação do novo item.
 */
LDE* insereLDENumerico(LDE* lista, char* nome, int qtde);

/**
 * @brief Logging de informações sobre a lista
 *
 * A função printaLDE() é responsável por printar em um arquivo, informações a respeito de @c qtde itens da lista.
 * Se o parâmetro @c qtde for passado como 0, a lista inteira será printada.
 * Essa informação é printada no formato "@<qtde, nome@>".
 *
 * @param lista Lista que iremos printar
 * @param qtde Quantidade de termos da lista que serão printados.
 * @param saida Arquivo no qual será printado a informação (pode ser passado stdout, para printar no terminal)
 */
void printaLDE(LDE* lista, int qtde, FILE* saida);
#endif // CIDADES_H_

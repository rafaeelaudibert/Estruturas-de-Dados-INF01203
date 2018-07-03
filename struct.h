/**
 * @file struct.h
 * @author Rafael Baldasso Audibert
 * @author Augusto Zanella Bardini
 * @date 11 Jul 2018
 * @brief Arquivo que contém as estruturas utilizadas no programa
 */

#ifndef STRUCT_H_
#define STRUCT_H_

/**
 * @brief Lista duplamente encadeada
 *
 * Lista duplamente encadeada, que pode ou não ser circular.
 */
typedef struct lde{
    char nome[100]; /**< String de tamanho máximo 100 */
    int qtde;  /**< Inteiro que armazena quantas vezes esse nodo foi acessado e/ou chamado e/ou requisitado */
    struct lde *prox; /**< Ponteiro que aponta para o próximo elemento da lista */
    struct lde *ant; /**< Ponteiro que aponta para o elemento anterior da lista */
} LDE;

/**
 * @brief Lista simplesmente encadeada
 */
typedef struct lse{
    char termo[100]; /**< String de tamanho máximo 100 */
    struct lse *prox; /**< Ponteiro que aponta para o próximo elemento da lista */
} LSE;

/**
 * @brief Arvore binária
 *
 * Arvore binária de pesquisa responsável por guardar todos os dados das consultas.
 * Cada nodo da árvore representa uma consulta, armazenando os termos da consulta, além das cidades
 * que realizaram essa consulta.
 *
 * @warning A árvore é binária de pesquisa, PORÉM a chave dela não é tão útil para a realização das pesquisas.
 */
typedef struct abp{
    int qtdeAcessos; /**< Quantidade de vezes que essa consulta foi realizada. É a CHAVE da árvore*/
    int qtdeTermos; /**< Tamanho da lista representada por @c termos */
    LSE* termos; /**< @c LSE contendo os termos da pesquisa */
    LDE* cidades; /**< @c LDE contendo as cidades que realizaram essa pesquisa */

    struct abp *esq; /**< Ponteiro que aponta para o elemento-filho esquerdo desse nodo */
    struct abp *dir; /**< Ponteiro que aponta para o elemento-filho direito desse nodo */
} Consulta;

/**
 * @brief Estrutura principal do programa, responsável por guardar TODOS os dados
 *
 * Estrutura principal do programa, que guarda tanto a árvore binária de pesquisa @c arvore, como
 * a lista geral de termos consultados @c termos.
 *
 */
typedef struct descritor{
    Consulta  *arvore; /**< @<struct abp@> contendo todas as informações do arquivo*/
    LDE *termos; /**< Lista duplamente encadeada contendo a lista geral de termos consultados*/
} Info;

/**
 * @brief Estrutura utilizada para guardar uma LSE e um valor numérico arbitrário
 *
 * Estrutura que é utilizada somente na função consultasPorLocalidade() para poder armazenar
 * quantas vezes uma @c LSE* foi chamada.
 *
 */
typedef struct s_qtdCons
{
    int qtd;
    LSE* termos;
} Qtdcons;


#endif

#include "struct.h"

/**
 * @file arvore.h
 * @author Rafael Baldasso Audibert
 * @author Augusto Zanella Bardini
 * @date 11 Jul 2018
 * @brief Arquivo que contém funções relacionadas a manipulação de dados em arvores
 */


#ifndef ARVORE_H_
#define ARVORE_H_

#define QTD_TERMOS 1
#define QTD_ACESSOS 2

/**
 * @brief Cria árvore
 *
 * A função criaArvore() cria uma arvore vazia.
 * @return @c NULL sempre é retornado.
 */
Consulta* criaArvore();


/**
 * @brief Insere um nodo na árvore
 *
 * A função insereNodoArvore() é responsável por inserir um nodo na árvore (ou incrementar ou contador, caso o nodo já exista)
 * @param arvore  Árvore na qual será inserido o novo nodo
 * @param listaTermos Lista dos termos que esse novo nodo irá conter (consulta)
 * @param qtdTermos Tamanho da @p listaTermos
 * @param cidade String com o nome da cidade na qual foi realizada a consulta
 * @return @c *Consulta contendo a arvore recebida, com a adição/incrementação do novo nodo.
 */
Consulta* insereNodoArvore(Consulta *arvore, LSE* listaTermos, int qtdTermos, char* cidade);

/**
 * @brief Logging de informações sobre uma árvore
 *
 * A função percorreArvore() é responsável por printar na tela do terminal, informações a respeito de cada nodo da árvore
 * @param nodo Nodo inicial da árvore
 * @param nivel Valor inicial para o nível da árvore (Para satisfazer ambas convenções de nível inicial = 0 ou 1)
 *
 * @return Altura da arvore - 1 + @c nivel
 */
int percorreArvore(Consulta *nodo, int nivel);
#endif // ARVORE_H_

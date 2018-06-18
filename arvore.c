#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arvore.h"
#include "lde.h"
#include "lse.h"

/// Funçao responsável por criar a árvore
/// OUTPUT:
///         Consulta*            ->  Árvore zerada / Ponteiro NULL
Consulta* criaArvore()
{
    return NULL;
}


/// Função responsável por inserir um nodo na árvore (ou incrementar ou contador, caso o nodo já exista)
/// INPUT:
///         Consulta*           -> Árvore na qual será inserido o novo nodo
///         LSE*                -> Lista dos termos a ser inserido na lista de termos do nodo
///         int                 -> Qtd de termos que tenho no nodo
///         char*               -> String contendo a cidade da qual os termos foram recebidos
Consulta* insereNodoArvore(Consulta *arvore, LSE* listaTermos, int qtdTermos, char* cidade)
{

    if(arvore)  // Se eu tenho arvore aqui
    {

        if(arvore->qtdeTermos == qtdTermos) // Se eu estou em um nó com a mesma quantidade de termos que a minha inserção
        {

            if(LSEigual(listaTermos, arvore->termos)) // Se eu estou em uma consulta com os mesmos termos que a minha inserção
            {
                arvore->cidades = insereLDEAlfabetico(arvore->cidades, cidade);   // Insiro a cidade
                arvore->qtdeAcessos++;    // Aumento a quantidade de acessos a essa consulta


            }
            else
            {
                arvore->dir = insereNodoArvore(arvore->dir, listaTermos, qtdTermos, cidade); // Se não, vou tentar inserir a direita
            }
        }
        else if(arvore->qtdeTermos > qtdTermos) // Se tenho menos termos, tento inserir a direita
        {
            arvore->esq = insereNodoArvore(arvore->esq, listaTermos, qtdTermos, cidade);
        }
        else                                    // Se tenho mais termos, tento inserir a esquerda
        {
            arvore->dir = insereNodoArvore(arvore->dir, listaTermos, qtdTermos, cidade);
        }
    }
    else        // Arvore vazia
    {
        // Força alocação da memória
        do{
            arvore = (Consulta*) malloc(sizeof(Consulta));          // Inicializa um nó
        }while(arvore == NULL);

        arvore->cidades = insereLDEAlfabetico(inicializaLDE(), cidade);   // Inicializa a LDE das cidades
        arvore->termos = listaTermos;                           // Variável temporária para guardar os termos
        arvore->esq = NULL;                                     // Arvore da esquerda é nula
        arvore->dir = NULL;                                     // Arvore da direita é nula
        arvore->qtdeAcessos = 1;                                // Primeira vez que essa árvore é acessada
        arvore->qtdeTermos = qtdTermos;                         // Zera o contador de termos para poder ser incrementado abaixo
    }

    return arvore;
}

/// Função responsável por printar as informações sobre um nodo de uma árvore
/// INPUT:
///         Consulta*           -> Árvore a qual será printada
///         int                 -> Nível atual do nodo
/// OUTPUT:
///         int                 -> Maior grau da árvore
int percorreArvore(Consulta *nodo, int nivel){

    int esq, dir;
    if(nodo){

        printf("\nMeu nivel: %d", nivel);
        printf("\nEu mesmo: %p", nodo);
        printf("\nCidades:\n");
        printaLDE(nodo->cidades, 0);
        printf("Ponteiro para a esquerda/direita: %p/%p", nodo->esq, nodo->dir);
        printf("\nQuantidade de acessos: %d", nodo->qtdeAcessos);
        printf("\nQuantidade de termos: %d", nodo->qtdeTermos);
        printf("\nTermos: ");
        printaLSE(nodo->termos);

        esq = percorreArvore(nodo->esq, nivel+1);
        dir = percorreArvore(nodo->dir, nivel+1);

        return (esq > dir ? esq : dir);
    }

    return nivel - 1;
}

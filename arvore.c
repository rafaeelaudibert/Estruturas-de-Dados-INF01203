#include <stdlib.h>
#include <stdio.h>
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
                arvore->qtdeAcessos++;    // Aumento a quantidade de acessos a essa consulta
                arvore->cidades = insereLDEAlfabetico(arvore->cidades, cidade);   // Insiro a cidade
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
        arvore = (Consulta*) malloc(sizeof(Consulta));          // Inicializa um nó
        arvore->cidades = insereLDEAlfabetico(inicializaLDE(), cidade);   // Inicializa a LDE das cidades
        arvore->termos = listaTermos;                           // Variável temporária para guardar os termos
        arvore->esq = NULL;                                     // Arvore da esquerda é nula
        arvore->dir = NULL;                                     // Arvore da direita é nula
        arvore->qtdeAcessos = 1;                                // Primeira vez que essa árvore é acessada
        arvore->qtdeTermos = qtdTermos;                         // Zera o contador de termos para poder ser incrementado abaixo
    }

    return arvore;
}

/// Função recursiva para printar uma ABP utilizando caminhamento central à esquerda
void printaArvore(Consulta* tree, int grau, int choice)
{

    int i;  // Contador

    if(tree)
    {
        for(i=0; i<grau; i++)   //Printador do grau
            printf("=");

        switch(choice)
        {
        case QTD_TERMOS:
            printf("Termos: %d\n", tree->qtdeTermos);
            break;
        case QTD_ACESSOS:
            printf("Acessos: %d\n", tree->qtdeAcessos);
            break;
        default:
            printf("Impressao com dados invalidos\n");
            return;
        }
        printaArvore(tree->esq, grau+1, choice);
        printaArvore(tree->dir, grau+1, choice);
    }

    return;

}

int percorreArvore(Consulta *nodo, int nivel){

    int esq, dir;
    if(nodo){

        printf("\nMeu nivel: %d", nivel);
        printf("\nEu mesmo: %p", nodo);
        printf("\nCidades:\n");
        printaLDE(nodo->cidades);
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

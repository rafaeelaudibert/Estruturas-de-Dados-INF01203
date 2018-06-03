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

Consulta* insereNodoArvore(Consulta *arvore, LSE* listaTermos, int qtdTermos, char* cidade)
{
    if(arvore)  // Se eu tenho arvore aqui
    {
        if(arvore->qtdeTermos == qtdTermos) // Se eu estou em um nó com a mesma quantidade de termos que a minha inserção
        {
            if(LSEigual(listaTermos, arvore->termos)) // Se eu estou em uma consulta com os mesmos termos que a minha inserção
            {
                arvore->qtdeAcessos++;    // Aumento a quantidade de acessos a essa consulta
                arvore->cidades = insereLDE(arvore->cidades, cidade);   // Insiro a cidade

                //printf("TERMOS (nodo ja existente):\n");
                //printaLSE(arvore->termos);
            }
            else
            {
                arvore->dir = insereNodoArvore(arvore->dir, listaTermos, qtdTermos, cidade);
            }
        }
        else if(arvore->qtdeTermos < qtdTermos)
        {
            arvore->esq = insereNodoArvore(arvore->esq, listaTermos, qtdTermos, cidade);
        }
        else
        {
            arvore->dir = insereNodoArvore(arvore->dir, listaTermos, qtdTermos, cidade);
        }
    }
    else        // Arvore vazia
    {
        arvore = (Consulta*) malloc(sizeof(Consulta));          // Inicializa um nó
        arvore->cidades = insereLDE(inicializaLDE(), cidade);                      // Inicializa a LDE das cidades
        arvore->termos = listaTermos;                           // Variável temporária para guardar os termos
        arvore->esq = NULL;                                     // Arvore da esquerda é nula
        arvore->dir = NULL;                                     // Arvore da direita é nula
        arvore->qtdeAcessos = 1;                                // Primeira vez que essa árvore é acessada
        arvore->qtdeTermos = qtdTermos;                         // Zera o contador de termos para poder ser incrementado abaixo

        //printf("TERMOS (nodo novo!):\n");
        //printaLSE(arvore->termos);
    }

    return arvore;
}

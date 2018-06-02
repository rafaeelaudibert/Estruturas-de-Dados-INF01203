#include "lde.h"
#include <stdlib.h>
#include <string.h>

/// Função responsável por inicializar uma Lista Duplamente Encadeada
/// OUTPUT:
///         LDE*            ->  Lista duplamente encadeada vazia / Ponteiro NULL
LDE* inicializaLDE()
{
    return NULL;
}

/// Função chamada quando uma consulta foi feita para um determinado elemento da LDE, decide o que fazer com o elemento
/// Caso já tenha acontecido uma consulta idêntica nesse elemento, incrementa o contador de consultas
/// Caso contrário, insere um novo elemento no final da lista
/// INPUT:
///         LDE*                ->  Lista duplamente encadeada
///         char*               ->  String
/// OUTPUT:
///         LDE*                ->  Lista duplamente encadeada, com a inserção do novo elemento (ou incremento do seu contador)
LDE* insereLDE(LDE* lista, char *nome)
{

    LDE *novo, *auxiliar = lista;
    int adicionado = 0;

    // Se ja tenho uma lista
    if(auxiliar)
    {

        // Vou iterar pela lista
        while(auxiliar->prox && !adicionado)
        {
            //  Se o nome passado for o mesmo que a posicao atual da lista, aumenta em 1 sua quantidade
            if(!(strcmp(nome, auxiliar->nome)))
            {
                auxiliar->qtde++;   // Aumento a quantidade
                adicionado = 1;     // Ligo a flag para poder sair do laço
            }
            auxiliar = auxiliar->prox;    // Sempre aponto para o próximo na lista
        }

        // Se eu cheguei ate o final sem adicionar nada, coloco novo no inicio da lista
        if(!adicionado)
        {

            //  Checo se o último da lista é o que preciso inserir
            if(!(strcmp(nome, auxiliar->nome)))
            {
                auxiliar->qtde++;   // Aumento a quantidade
            }
            else     // Caso contrario, vou inserir no final da lista
            {
                novo = (LDE*) malloc(sizeof(LDE));  // Aloco o espaço
                novo->qtde = 1;                             // Primeira vez que a cidade aparece
                strcpy(novo->nome, nome);                 // Salvo o nome da cidade

                novo->prox = NULL;                         // Próximo na lista é vazio
                novo->ant = auxiliar;                       // Anterior é o auxiliar

                auxiliar->prox = novo;                      // Ponho o novo no final da lista
            }
        }
    }
    else    // Senão, crio um novo nodo
    {
        novo = (LDE*) malloc(sizeof(LDE));
        novo->prox = NULL;
        novo->ant = NULL;
        novo->qtde = 1;
        strcpy(novo->nome, nome);
        lista = novo;
    }

    return lista;
}

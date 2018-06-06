#include "lde.h"
#include <stdlib.h>
#include <stdio.h>
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
    int adicionado=0;

    // Se ja tenho uma lista
    if(auxiliar)
    {
        if(*nome >= 'l' && *nome <= 'z')    //Insere de tras pra frente
        {
            auxiliar = auxiliar->ant;
            do
            {

                if(strcmp(auxiliar->nome, nome) == 0)
                {
                    auxiliar->qtde++;
                    adicionado = 1;
                }
                else if(strcmp(nome, auxiliar->nome) > 0)    //Se tenho um texto "maior" que aquele, insiro depois do auxiliar
                {
                    novo = (LDE*) malloc(sizeof(LDE));
                    novo->qtde = 1;
                    strcpy(novo->nome, nome);
                    novo->prox = auxiliar->prox;
                    novo->ant = auxiliar;
                    auxiliar->prox->ant = novo;
                    auxiliar->prox = novo;
                    adicionado = 1;
                }

                auxiliar = auxiliar->ant;
            }
            while(auxiliar != lista && !adicionado);

            if(auxiliar == lista && !adicionado){ //Se saí do loop, pode ser que precise inserir ainda
                if(strcmp(lista->nome, nome) == 0){
                    lista->qtde++;
                } else if(strcmp(lista->nome, nome) > 0){ //Lista é maior, então o novo vai antes de lista
                    novo = (LDE*) malloc(sizeof(LDE));
                    novo->qtde = 1;
                    strcpy(novo->nome, nome);
                    novo->ant = lista->ant;
                    novo->prox = lista;
                    lista->ant->prox = novo;
                    lista->ant = novo;
                    lista = novo;
                } else { //Novo vai depois da lista
                    novo = (LDE*) malloc(sizeof(LDE));
                    novo->qtde = 1;
                    strcpy(novo->nome, nome);
                    novo->ant = lista;
                    novo->prox = lista->prox;
                    lista->prox->ant = novo;
                    lista->prox = novo;
                }
            }

        }
        else        //Insere de frente pra tras
        {

            do
            {
                if(strcmp(auxiliar->nome, nome) == 0)
                {
                    auxiliar->qtde++;
                    adicionado = 1;
                }
                else if(strcmp(nome, auxiliar->nome) < 0)    //Se tenho um texto "menor" que aquele, insiro antes
                {
                    novo = (LDE*) malloc(sizeof(LDE));
                    novo->qtde = 1;
                    strcpy(novo->nome, nome);
                    novo->prox = auxiliar;
                    novo->ant = auxiliar->ant;
                    auxiliar->ant->prox = novo;
                    adicionado = 1;

                    if (auxiliar == lista)
                        lista = novo;
                }

                auxiliar = auxiliar->ant;
            }
            while(auxiliar->prox != lista && !adicionado);

            if(auxiliar->prox == lista && !adicionado){ //Se saí do loop, pode ser que precise inserir ainda
                if(strcmp(auxiliar->nome, nome) == 0){
                    auxiliar->qtde++;
                } else if(strcmp(nome, auxiliar->nome) > 0){ //Novo é maior que o fim da lista, vai pro final
                    novo = (LDE*) malloc(sizeof(LDE));
                    novo->qtde = 1;
                    strcpy(novo->nome, nome);
                    novo->ant = lista->ant;
                    novo->prox = lista;
                    lista->ant->prox = novo;
                    lista->ant = novo;
                } else { //Novo vai antes do final
                    novo = (LDE*) malloc(sizeof(LDE));
                    novo->qtde = 1;
                    strcpy(novo->nome, nome);
                    novo->prox = auxiliar;
                    novo->ant = auxiliar->ant->prox;
                    auxiliar->ant->prox = novo;
                    auxiliar->ant = novo;
                }
            }
        }

    }
    else    // Senão, crio um novo nodo
    {
        novo = (LDE*) malloc(sizeof(LDE));
        novo->prox = novo;
        novo->ant = novo;
        novo->qtde = 1;
        strcpy(novo->nome, nome);
        lista = novo;
    }

    return lista;
}

void printaLDE(LDE* lista)
{

    LDE* auxiliar = lista;

    printf("Lista de cidades: \n");
    if(lista)
    {
        while(auxiliar->prox != lista)
        {
            printf("Cidade: %s - Qtde:%d\n", auxiliar->nome, auxiliar->qtde);
            auxiliar = auxiliar->prox;
        }
        printf("Cidade: %s - Qtde: %d\n", auxiliar->nome, auxiliar->qtde);
    }
}

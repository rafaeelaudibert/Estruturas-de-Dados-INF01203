#include "lde.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Função responsável por inicializar uma Lista Duplamente Encadeada
LDE* inicializaLDE()
{
    return NULL;
}

// Função chamada quando uma consulta foi feita para um determinado elemento da LDE, decide o que fazer com o elemento
// Caso já tenha acontecido uma consulta idêntica nesse elemento, incrementa o contador de consultas
// Caso contrário, insere um novo elemento respeitando a ordem alfabética dos nomes
LDE* insereLDEAlfabetico(LDE* lista, char *nome)
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
                    // Força alocação de memória
                    do
                    {
                        novo = (LDE*) malloc(sizeof(LDE));
                    }
                    while(novo == NULL);

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

            if(auxiliar == lista && !adicionado)  //Se saí do loop, pode ser que precise inserir ainda
            {
                if(strcmp(lista->nome, nome) == 0)
                {
                    lista->qtde++;
                }
                else if(strcmp(lista->nome, nome) > 0)    //Lista é maior, então o novo vai antes de lista
                {
                    // Força alocação de memória
                    do
                    {
                        novo = (LDE*) malloc(sizeof(LDE));
                    }
                    while(novo == NULL);

                    novo->qtde = 1;
                    strcpy(novo->nome, nome);
                    novo->ant = lista->ant;
                    novo->prox = lista;
                    lista->ant->prox = novo;
                    lista->ant = novo;
                    lista = novo;
                }
                else     //Novo vai depois da lista
                {
                    // Força alocação de memória
                    do
                    {
                        novo = (LDE*) malloc(sizeof(LDE));
                    }
                    while(novo == NULL);

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
                if(strcmp(nome, auxiliar->nome) == 0)
                {
                    auxiliar->qtde++;
                    adicionado = 1;
                }
                else if(strcmp(nome, auxiliar->nome) < 0)    //Se tenho um texto "menor" que aquele, insiro antes
                {
                    // Força alocação de memória
                    do
                    {
                        novo = (LDE*) malloc(sizeof(LDE));
                    }
                    while(novo == NULL);

                    novo->qtde = 1;
                    strcpy(novo->nome, nome);
                    novo->prox = auxiliar;
                    novo->ant = auxiliar->ant;
                    //asdasdasdasd
                    auxiliar->ant->prox = novo;
                    auxiliar->ant = novo;
                    adicionado = 1;

                    if (auxiliar == lista)
                        lista = novo;
                }
                auxiliar = auxiliar->prox;
            }
            while(auxiliar->prox != lista && !adicionado);

            if(auxiliar->prox == lista && !adicionado)  //Se saí do loop, pode ser que precise inserir ainda
            {
                if(strcmp(auxiliar->nome, nome) == 0)
                {
                    auxiliar->qtde++;
                }
                else if(strcmp(nome, auxiliar->nome) > 0)    //Novo é maior que o fim da lista, vai pro final
                {
                    // Força alocação de memória
                    do
                    {
                        novo = (LDE*) malloc(sizeof(LDE));
                    }
                    while(novo == NULL);

                    novo->qtde = 1;
                    strcpy(novo->nome, nome);
                    novo->ant = lista->ant;
                    novo->prox = lista;
                    lista->ant->prox = novo;
                    lista->ant = novo;
                }
                else     //Novo vai antes do final
                {
                    // Força alocação de memória
                    do
                    {
                        novo = (LDE*) malloc(sizeof(LDE));
                    }
                    while(novo == NULL);

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
        // Força alocação de memória
        do
        {
            novo = (LDE*) malloc(sizeof(LDE));
        }
        while(novo == NULL);

        novo->prox = novo;
        novo->ant = novo;
        novo->qtde = 1;
        strcpy(novo->nome, nome);
        lista = novo;
    }

    return lista;
}

// Função chamada quando uma consulta foi feita para um determinado elemento da LDE, decide o que fazer com o elemento
// Caso já tenha acontecido uma consulta idêntica nesse elemento, incrementa o contador de consultas e reordena a lista em ordem decrescente de Qtde
LDE* insereLDENumerico(LDE* lista, char *nome, int qtde)
{

    LDE *novo, *auxiliar = lista, *anterior;
    char strAux[100] = "";
    int numAux, flagInsercao = 0;

    if(auxiliar) //Tenho algum nodo na lista
    {
        if(strcmp(nome, auxiliar->nome) == 0) // Se for o primeiro, somente incrementa o contador
            auxiliar->qtde += qtde;
        else                                // Caso contrario, vai iterar pela lista procurando minha posição
        {
            if((auxiliar = auxiliar->prox) == NULL)  // Se só tenho UM termo na lista
            {
                // Força alocação de memória
                do
                {
                    novo = (LDE*) malloc(sizeof(LDE));
                }
                while(novo == NULL);

                novo->qtde = qtde;
                strcpy(novo->nome, nome);

                // Se o meu novo nodo tiver menos acessos que a raiz, ou um nome "menor"
                if(lista->qtde > 1 || strcmp(lista->nome, novo->nome) < 0)
                {
                    novo->prox = NULL;
                    novo->ant = lista;
                    lista->prox = novo;
                }
                else // Caso contrário, inverte eles de lugar
                {
                    novo->prox = lista;
                    novo->ant = NULL;
                    lista->ant = novo;
                    lista = novo;
                }
            }
            else //Varios termos na lista
            {
                anterior = auxiliar->ant; //Mantenho sempre um tracking do anterior
                while(auxiliar)
                {
                    if (strcmp(auxiliar->nome, nome) == 0){ // Se eu tenho o mesmo nome, então posso parar meu laço
                        flagInsercao = 1; //Preciso aumentar a quantidade do nodo que eu parei
                        break;
                    } else if (auxiliar->qtde < qtde){
                      flagInsercao = 2; //Preciso me inserir antes do auxiliar
                      break;
                    }
                    anterior = auxiliar;
                    auxiliar = auxiliar->prox;
                }

                if(auxiliar && flagInsercao == 1)  //Se saí por um break com flag 1, encontrei o nodo pra aumentar
                {
                    auxiliar->qtde+=qtde;

                    // Preciso ordenar por numero e por nome
                    if(auxiliar->ant)
                    {

                        // ORDENAÇÃO NUMÉRICA
                        while(auxiliar->ant && auxiliar->ant->qtde < auxiliar->qtde)
                        {

                            strcpy(strAux, auxiliar->nome);
                            strcpy(auxiliar->nome, auxiliar->ant->nome);
                            strcpy(auxiliar->ant->nome, strAux);

                            numAux = auxiliar->qtde;
                            auxiliar->qtde = auxiliar->ant->qtde;
                            auxiliar->ant->qtde = numAux;

                            auxiliar = auxiliar->ant;
                        }

                        // ORDENAÇÃO ALFABÉTICA
                        while(auxiliar->ant && auxiliar->ant->qtde == auxiliar->qtde && strcmp(auxiliar->nome, auxiliar->ant->nome) < 0)
                        {
                            strcpy(strAux, auxiliar->nome);
                            strcpy(auxiliar->nome, auxiliar->ant->nome);
                            strcpy(auxiliar->ant->nome, strAux);

                            auxiliar = auxiliar->ant;
                        }
                    }
                } else if(auxiliar && flagInsercao == 2)  //Se saí por um break com flag 2, preciso me inserir antes do auxiliar
                {
                  // Força alocação de memória
                  do
                  {
                      novo = (LDE*) malloc(sizeof(LDE));
                  }
                  while(novo == NULL);

                  novo->qtde = qtde;
                  strcpy(novo->nome, nome);

                  novo->prox = auxiliar;
                  novo->ant = auxiliar->ant;
                  auxiliar->ant->prox = novo;
                  auxiliar->ant = novo;

                  // ORDENAÇÃO ALFABÉTICA
                  while(auxiliar->ant && auxiliar->ant->qtde == auxiliar->qtde && strcmp(auxiliar->nome, auxiliar->ant->nome) < 0)
                  {
                      strcpy(strAux, auxiliar->nome);
                      strcpy(auxiliar->nome, auxiliar->ant->nome);
                      strcpy(auxiliar->ant->nome, strAux);

                      auxiliar = auxiliar->ant;
                  }
                }
                else     // Se não, preciso me adicionar no final
                {
                    // Força alocação de memória
                    do
                    {
                        novo = (LDE*) malloc(sizeof(LDE));
                    }
                    while(novo == NULL);

                    novo->qtde = qtde;
                    strcpy(novo->nome, nome);

                    novo->prox = NULL;
                    novo->ant = anterior;
                    anterior->prox = novo;
                }
            }
        }
    }
    else // Lista vazia
    {
        // Força alocação de memória
        do
        {
            novo = (LDE*) malloc(sizeof(LDE));
        }
        while(novo == NULL);

        novo->prox = NULL;
        novo->ant = NULL;
        novo->qtde = qtde;
        strcpy(novo->nome, nome);
        lista = novo;
    }

    return lista;
}


// Função iterativa para printar uma determinada quantidade dos nomes e valores armazenados em uma lista duplamente encadeada [circular ou não]
void printaLDE(LDE* lista, int qtde, FILE* saida)
{
    // Ponteiro auxiliar para percorrer a lista
    LDE* auxiliar = lista;

    // Se tenho uma lista, irei tentar printa-la
    if(auxiliar)
    {

        if(qtde == 0) //Printa toda a lista
        {
            while(auxiliar->prox != lista && auxiliar->prox)
            {
                fprintf(saida, "%d %s\n", auxiliar->qtde, auxiliar->nome); //Printa "string valor"
                auxiliar = auxiliar->prox;
            }
            fprintf(saida, "%d %s\n", auxiliar->qtde, auxiliar->nome);  // Printa o que estava faltando
        }
        else // Printa a quantidade vezes passada em qtde
        {

            while(auxiliar->prox != lista && auxiliar->prox && --qtde > 0)  // Decrementa o contador, para printar somente 'qtde' nodos
            {
                fprintf(saida, "%d %s\n", auxiliar->qtde, auxiliar->nome);
                auxiliar = auxiliar->prox;
            }
            fprintf(saida, "%d %s\n", auxiliar->qtde, auxiliar->nome);
        }
    }
    else

    {
        printf("Lista Vazia!");
    }
}

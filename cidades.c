#include "cidades.h"
#include <stdlib.h>
#include <string.h>

/// Função responsável por inicializar a lista de cidades
/// OUTPUT:
///         Consulta*            ->  Lista simplesmente encadeada vazia / Ponteiro NULL
Cidades* inicializaCidades()
{
    return NULL;
}

/// Função chamada quando uma consulta foi feita para uma determinada cidade, decide o que fazer com as cidades
/// Caso já tenha acontecido uma consulta idêntica nessa cidade, incrementa o contador de consultas
/// Caso contrário, insere uma nova cidade no início da lista
/// INPUT:
///         Cidades*                ->  Lista simplesmente encadeada das cidades
///         char*                   ->  String contendo o nome de uma cidade
/// OUTPUT:
///         Cidades*                ->  Lista simplesmente encadeada das cidades, com a inserção da nova cidade
Cidades* insereCidade(Cidades* lista, char *cidade)
{

    Cidades *novo, *inicio = lista;
    int adicionado = 0;

    // Se ja tenho uma lista
    if(lista)
    {

        // Vou iterar pela lista
        while(lista && !adicionado)
        {
            //  Se o nome da cidade for o mesmo que a posicao atual da lista, aumenta em 1 sua quantidade
            if(!(strcmp(cidade, lista->nome)))
            {
                lista->qtde++;      // Aumento a quantidade
                adicionado = 1;     // Ligo a flag para poder sair do laço
            }
            lista = lista->prox;    // Aponto para o próximo na lista
        }

        // Se eu cheguei at� o final sem adicionar nada, coloco novo no inicio da lista
        if(!adicionado){
            novo = (Cidades*) malloc(sizeof(Cidades));  // Aloco o espaço
            novo->qtde = 1;                             // Primeira vez que a cidade aparece
            strcpy(novo->nome, cidade);                 // Salvo o nome da cidade

            novo->prox = inicio;                         // Próximo na lista é o antigo início da lista anterior
            inicio = novo;                               // Seto o novo inicio da lista
        }
    }
    else
    {
        novo = (Cidades*) malloc(sizeof(Cidades));
        novo->prox = NULL;
        novo->qtde = 1;
        strcpy(novo->nome, cidade);
        inicio = novo;
    }

    return inicio;
}

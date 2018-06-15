#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lse.h"

/// Função responsável por inicializar uma Lista Simplesmente Encadeada
/// OUTPUT:
///         LDE*            ->  Lista simplesmente encadeada vazia / Ponteiro NULL
LSE* inicializaLSE()
{
    return NULL;
}

/// Função chamada quando inserimos um novo termo na LSE, inserindo em ordem alfabetica
/// INPUT:
///         LDE*                ->  Lista simplesmente encadeada
///         char*               ->  String
/// OUTPUT:
///         LDE*                ->  Lista simplesmente encadeada, com a inserção do novo elemento
LSE* insereLSE(LSE* lista, char* termo)
{
    int found = 0;
    LSE *novo = (LSE*)malloc(sizeof(LSE)), *auxiliar = lista, *anterior = NULL;
    strcpy(novo->termo, termo);

    do{
        novo = (LSE*)malloc(sizeof(LSE));
    }while(novo == NULL);

    if (auxiliar)                       // Se tiver uma lista, procuro a posição alfabetica para inserir o novo termo
    {

        while(auxiliar && !found)       // Enquanto existe lista, e não encontrei o nodo percorro a lista
        {
            if(strcmp(auxiliar->termo, termo) > 0)
                found = 1;              // Encontrei, e vou ter o nó que preciso em auxiliar
            else                        // Caso contrario, continuo procurando, passando a lista pra frente
            {
                anterior = auxiliar;
                auxiliar = auxiliar->prox;
            }
        }

        if(anterior)                        // Se eu tenho um anterior, ou seja, não é na primeira iteração que eu encontrei
        {
            novo->prox = anterior->prox;    // Coloco o novo depois do anterior
            anterior->prox = novo;
        }
        else
        {
            novo->prox = lista;             // Caso nao tinha anterior, coloco o novo como inicio da lista
            lista = novo;
        }

    }
    else                                    // Caso eu não tenha nada na lista, apenas digo que a lista começa em novo
    {
        lista = novo;
    }

    return lista;
}

/// Função que retorna se duas LSE's tem os mesmos termos
/// OBS.: Essa função só pode ser chamada se as duas LSE's tiverem o mesmo tamanho
/// INPUT:
///         LSE*                ->  Lista simplesmente encadeada
///         LSE*                ->  Lista simplesmente encadeada
/// OUTPUT:
///         int                 ->  1 se as strings forem iguais em toda LSE, 0 se não forem
int LSEigual(LSE* lse1, LSE* lse2)
{
    if(lse1 && lse2)   // Se ainda tenho string NOS DOIS
    {
        // Se as strings forem diferentes, retorno 0, pois a afirmação é falsa
        if(strcmp(lse1->termo, lse2->termo))
        {
            return 0;
        }
        else  // Strings iguais, vou verificar a proxima string
        {
            return LSEigual(lse1->prox, lse2->prox);
        }

        // return strcmp(lse1->termo, lse2->termo) ? 0 : LSEigual(lse1->prox, lse2->prox);  //Operador ternario
    }
    else // Se os dois são NULL, cheguei até o fim, LSE's são iguais
    {
        return 1;
    }

    /* Alternativa de retorno para essa função usando operador ternario
     return lse1 && lse2 ? (strcmp(lse1->termo, lse2->termo) ? 0 : LSEigual(lse1->prox, lse2->prox)) : 1
    */
}

/// Função iterativa para printar uma LSE
void printaLSE(LSE* lista)
{

    while(lista)
    {
        printf("%s\n", lista->termo);
        lista = lista->prox;
    }

    return;
}



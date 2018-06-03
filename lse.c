#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lse.h"

LSE* inicializaLSE()
{
    return NULL;
}

LSE* insereLSE(LSE* lista, char* termo)
{

    LSE *novo = (LSE*)malloc(sizeof(LSE)),
    *auxiliar = lista;
    strcpy(novo->termo, termo);
    novo->prox = NULL;

    if (auxiliar)                   // Se tiver uma lista, procuro o ultimo da lista para dar um append do meu termo
    {
        while(auxiliar->prox)
        {
            auxiliar = auxiliar->prox;
        }
        auxiliar->prox = novo;      // Coloco ele no final
    }
    else                            // Caso eu não tenha nada na lista, apenas digo que a lista começa em novo
    {
        lista = novo;
    }

    return lista;
}

/// Função que retorna se duas LSE's tem os mesmos termos
/// INPUT:
///         LSE*                ->  Lista simplesmente encadeada
///         LSE*                ->  Lista simplesmente encadeada
/// OUTPUT:
///         int                 ->  1 se as strings forem iguais em toda LSE, 0 se não forem
int LSEigual(LSE* lse1, LSE* lse2)
{
    /* OBS.: Essa função só pode ser chamada se as duas LSE's tiverem o mesmo tamanho */

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

    /* Operador ternario para essa função
     return lse1 && lse2 ? strcmp(lse1->termo, lse2->termo) ? 0 : LSEigual(lse1->prox, lse2->prox); : 1
    */
}

void printaLSE(LSE* lista)
{
    if(lista)
    {
        printf("%s\n", lista->termo);
        printaLSE(lista->prox);
    }

    return;
}



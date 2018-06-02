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

void printaLSE(LSE* lista)
{
    if(lista)
    {
        printf("%s\n", lista->termo);
        printaLSE(lista->prox);
    }

    return;
}

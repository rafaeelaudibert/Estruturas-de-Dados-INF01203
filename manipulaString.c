#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "manipulaString.h"

void converteAcentos(char *str)
{

    int i, j;
    char comAcento[] = "àâêôûãõáéíóúçüÀÂÊÔÛÃÕÁÉÍÓÚÇ";
    char semAcento[] = "aaeouaoaeioucuAAEOUAOAEIOUC";

    for(i=0; i<strlen(str)-1; i++)
    {
        for(j=0; j<strlen(comAcento)-1; j++)
        {
            if(str[i] == comAcento[j])
            {
                str[i] = semAcento[j];
            }
        }
        //str[i] = tolower(str[i]);
    }
}

// Arruma a string
void puxaChar(char *c)
{
    if(*(c - 1) != '\0')
    {
        //printf("Trocarei %c por %c\n", *c, *(c + 1));
        *c = *(c + 1);
        puxaChar(c+1);
    }
}

// Remove caracteres desnecessarios
void removeCaracteres(char *str)
{
    int i;
    int size = strlen(str);

    for(i=0; i<size; i++)
    {
        if((str[i] > 'z' || str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a')) && str[i] != ';' && str[i] != ' ' && str[i] != '\n')
        {
            puxaChar(&str[i]);
            size--;
        }
    }
}


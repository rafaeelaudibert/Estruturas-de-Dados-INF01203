#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "manipulaString.h"

// Função responsável por tirar o acento de uma string, modificando a própria string
void converteAcentos(char *str)
{

    int i, j;
    char comAcento[] = "àâêôûãõáéíóúçÀÂÊÔÛÃÕÁÉÍÓÚÇ";
    char semAcento[] = "aaeouaoaeioucAAEOUAOAEIOUC";

    for(i=0; i<strlen(str)-1; i++)
    {
        for(j=0; j<strlen(comAcento)-1; j++)
        {
            if(str[i] == comAcento[j])
            {
                str[i] = semAcento[j];
            }
        }
        str[i] = tolower(str[i]);   // Transforma tudo em minuscula
    }
}

// Remove caracteres desnecessarios
void removeCaracteres(char *str)
{
    int i;
    int size = strlen(str);

    for(i=0; i<size; i++)
    {
        // Se não for letras, numeros, pontos e virgulas, espaços ou quebra de linhas, preciso remover aquele caractere dali
        if((str[i] > 'z' || str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a')) && str[i] != ';' && str[i] != ' ' && str[i] != '\n' && (str[i] < '0' || str[i] > '9'))
        {
            puxaChar(&str[i]);
            size--;
        }
    }
}

// Função (recursiva) auxiliar da removeCaracteres
// Puxa todos os próximos caracteres da string, fazendo com que o caracter atual seja excluido
void puxaChar(char *c)
{
    if(*(c - 1) != '\0')
    {
        *c = *(c + 1);
        puxaChar(c+1);
    }
}

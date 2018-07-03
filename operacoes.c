#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacoes.h"
#include "lse.h"
#include "lde.h"

// Função que encontra e coloca no arquivo as consultas mais realizadas em determinada cidade
// Se for passado 0 como qtdConsultas, escreve no arquivo todas consultas realizadas naquela localidade
void consultasPorLocalidade(Consulta* arvore, char* cidade, int qtdConsultas, FILE* saida)
{

    char strParse1[500] = {0}, strParse2[500] = {0};    //strings usadas no ordenamento
    int vetor[TAM_VET] = {0};                           //usado no ordenamento
    int i, j, contador = 0;                             //contadores
    Qtdcons qtdCons[TAM_VET], aux;                      //vetor de struct com a quantidade de cada consulta

    if(qtdConsultas == 0)                               //caso a quantidade pedida seja 0
    {
        //torna ela a quantidade máxima possível
        qtdConsultas = TAM_VET;
    }

    //copia todas as quantidades de acesso de cada consulta da arvore pra um vetor qtdCons
    contador = achaVetorRepsLocalidade(arvore, vetor, contador, cidade, qtdCons);

    //bubble sort modificado (não necessariamente para melhor) que ordena o vetor de qtdCons com duas regras, sendo que,
    //a primeira tem precedencia sobre a segunda:
    //1. quantidade de aparições da consulta
    //2. ordem alfabetica da consulta
    for(i=0; i<TAM_VET && (qtdCons+i)->termos != NULL; i++)
    {
        //transforma a lista de termos a ser comparada em string strParse1
        strcpy(strParse1, "");
        strcpy(strParse1, parseLSEtoString((qtdCons+i)->termos, strParse1));
        for(j=0; j<TAM_VET && (qtdCons+j)->termos != NULL; j++)
        {
            //transforma a lista de termos a ser comparada em string strParse2
            strcpy(strParse2, "");
            strcpy(strParse2, parseLSEtoString((qtdCons+j)->termos, strParse2));

            //para cada comparação de listas,
            //se a quantidade de aparições for maior ou
            //se a quantidade de aparições for maior e a ordem alfabetica estiver invertida
            //troca as posições de cada pesquisa no vetor ordenado
            if(((qtdCons+i)->qtd > (qtdCons+j)->qtd) || (((qtdCons+i)->qtd == (qtdCons+j)->qtd) && strcmp(strParse1, strParse2) < 0))
            {
                aux = *(qtdCons+i);
                *(qtdCons+i) = *(qtdCons+j);
                *(qtdCons+j) = aux;
            }
        }

    }

    //printa no arquivo as consultas ordenadas no vetor
    for(i=0; i<TAM_VET && ((qtdCons+i)->qtd) != 0 && i < qtdConsultas; i++)
    {
        fprintf(saida, "%d ", (qtdCons+i)->qtd);
        printaLSE((qtdCons+i)->termos, saida);
    }
    return;
}





// Função que retorna as consultas mais consultadas em todo o arquivo
// Se for passado 0 como qtdConsultas, retorna todas as consultas realizadas
int consultasArquivo(Consulta* arvore, Consulta retorno[TAM_VET], int qtdConsultas)
{
    Consulta aux;
    int vezesRep = 0, contador = 0, changed = 0, size = 0, maximo, mudancas = 1;
    int vetor[TAM_VET] = {0}, i;                                //vetor de ordenamento
    int vetorOrdenado[TAM_VET];                                 //vetor de ordenamento
    char strConsulta[TAM_VET][500]= {0};                        //vetor para consultas em formato string
    char auxChar[500]= {0};                                     //vetor utilizado no sort

    //copia todas as quantidades de acesso de cada consulta da arvore pra um vetor
    contador = achaVetorReps(arvore, vetor, contador);

    //ordena o vetor de quantidades de acesso
    quick_sort(vetor, 0, TAM_VET-1);
    for(i=0; i<TAM_VET; i++)
    {
        if((vetorOrdenado[i] = vetor[TAM_VET-1-i]) != 0)
            size++;
    }

    //após isso, para cada posição do vetor ordenado por quantidade de acesso,
    //vai percorrer a árvore procurando pelos nodos cuja
    //quantidade de acesso sejam iguais as do vetor ordenado
    //salva esses nodos da arvore em um outro vetor de Consultas
    for (i = 0; i < size; i++)
    {
        if(i != 0)
        {
            if(vetorOrdenado[i-1] == vetorOrdenado[i])
                vezesRep++;
            else
                vezesRep = 0;
        }
        //copia os nodos com mais acesso para o vetor
        copiaArvore(arvore, retorno, vetorOrdenado, qtdConsultas, i, vezesRep);
    }

    //clona todas as LSE de consultas para string
    for(i=0; i<size && (retorno+i)->termos != NULL; i++)
    {
        parseLSEtoString((retorno+i)->termos, strConsulta[i]);
    }
    maximo = size;

    //bubble sort de ordenamento do vetor de quantidades + vetor de consultas
    //ao final, tem-se um vetor de consultas no arquivo ordenado por quantidade de consultas
    do
    {
        changed = 0;
        for(i=1; i<maximo; i++)
        {
            if((retorno[i].qtdeAcessos == retorno[i-1].qtdeAcessos) && strcmp(strConsulta[i], strConsulta[i-1]) < 0)
            {
                aux = retorno[i];
                retorno[i] = retorno[i-1];
                retorno[i-1] = aux;

                strcpy(auxChar,strConsulta[i]);
                strcpy(strConsulta[i],strConsulta[i-1]);
                strcpy(strConsulta[i-1],auxChar);
                changed = mudancas = 1;
            }
            else
            {
                mudancas++;
            }
        }

        maximo-= mudancas;
    }
    while(changed);

    return size;
}





// Função que retorna os termos mais consultados em uma determinada localidade
// Se for passado 0 como qtdConsultas, retorna todas as consultas realizadas naquela localidade
LDE* termosPorLocalidade(Consulta* arvore, LDE *lista, char cidade[])
{
    int quantidade;

    if(arvore)
    {
        quantidade = temCidadeNaLista(cidade, arvore->cidades);
        //percorre recursivamente a arvore procurando pela
        //quantidade de vezes que aparece a cidade na lista de cidades de cada nodo

        //se a quantidade existir, entao exite o termo em tal cidade, logo
        //adiciona os termos na lista.
        if(quantidade)
        {
            lista = insereTermosNodo(lista, arvore->termos, quantidade);
        }

        lista = termosPorLocalidade(arvore->esq, lista, cidade);
        lista = termosPorLocalidade(arvore->dir, lista, cidade);
    }

    return lista;
}




// Função que retorna os termos mais consultados em todo o arquivo
LDE* termosArquivo(LDE* listaTermos)
{
    return listaTermos;
}



// Função que retorna a média do tamanho das consultas realizadas em uma determinada localidade
int mediaTamanhoConsultasLocalidade(Consulta* arvore, char* cidade)
{
    int totalTermos = 0, totalConsultas = 0;

    // Função auxiliar que vai contar o total de termos e o total de consultas;
    auxiliarMediaTamanhoConsultasLocalidade(arvore, &totalTermos, &totalConsultas, cidade);

    // Faz a média divindo o total de termos pelo total de consultas
    return totalTermos / totalConsultas;
}





// Função que retorna a média do tamanho das consultas realizadas em todo o arquivo
int mediaTamanhoConsultasArquivo(Consulta* arvore)
{
    int totalTermos = 0, totalConsultas = 0;

    // Função auxiliar que vai contar o total de termos e o total de consultas;
    auxiliarMediaTamanhoConsultasArquivo(arvore, &totalTermos, &totalConsultas);

    // Faz a média divindo o total de termos pelo total de consultas
    return totalTermos / totalConsultas;
}






//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
/*                                      FUNÇÕES AUXILIARES                                                     */
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------





// Função que encontra as repetições de uma consulta por localidade
int achaVetorRepsLocalidade(Consulta* arvore, int *vetor, int contador, char *cidade, Qtdcons *qtdCons)
{
    if(arvore == NULL)
    {
        printf("O arquivo de entrada está vazio");
        return contador;
    }

    int temCidade = temCidadeNaLista(cidade, arvore->cidades);

    //temCidade recebe a quantidade de vezes que a cidade aparece na consulta
    //por consequencia, esse é o numero de vezes que a consulta foi feita naquela cidade, portanto
    //se a cidade está na lista de cidades da consulta
    //adiciona a consulta ao vetor
    if(temCidade > 0)
    {
        (qtdCons+contador)->qtd = temCidade;
        (qtdCons+contador)->termos = arvore->termos;
        contador++;
    }

    //apos isso, faz as recursividades necessrias para percorrer toda a árvore

    if(arvore->esq != NULL)
    {
        contador = achaVetorRepsLocalidade(arvore->esq, vetor, contador, cidade, qtdCons);
    }
    if(arvore->dir != NULL)
    {
        contador = achaVetorRepsLocalidade(arvore->dir, vetor, contador, cidade, qtdCons);
    }
    return contador;
}


// Copia a quantidade de acessos de cada nodo da arvore pra posições de um vetor
int achaVetorReps(Consulta* arvore, int *vetor, int contador)
{
    if(arvore == NULL)
        return contador;
    //pra cada n da arvore encontrado recursivamente,
    //copia a quantidade de acessos para um vetor
    vetor[contador] = arvore->qtdeAcessos;
    contador++;
    if(arvore->esq != NULL)
    {
        contador = achaVetorReps(arvore->esq, vetor, contador);
    }
    if(arvore->dir != NULL)
    {
        contador = achaVetorReps(arvore->dir, vetor, contador);
    }
    return contador;
}

// Copia os nodos das arvore de consultas para a arvore de retorno utilizando o vetor ordenado
// de quantidade de acessos de cada nodo;
int copiaArvore(Consulta* arvore, Consulta* retorno, int *vetor, int qtd, int pos, int vezesRep)
{
    if(arvore == NULL)
    {
        return vezesRep;
    }

    //pra cada nodo da arvore percorrido recursivamente
    if (pos < qtd)
    {
        //se as quantidades de acesso forem iguais no vetor de entrada e na arvore
        if (vetor[pos] == arvore->qtdeAcessos)
        {
            if(vezesRep <= 0)
            {
                //copia a consulta da arvore para o vetor de retorno
                retorno[pos] = *arvore;
                return 10000000;
            }
            else
            {
                --vezesRep;
            }
        }
        //recursões
        if(arvore->esq != NULL && qtd != -1)
            vezesRep = copiaArvore(arvore->esq, retorno, vetor, qtd, pos, vezesRep);
        if(arvore->dir != NULL && qtd != -1)
            vezesRep = copiaArvore(arvore->dir, retorno, vetor, qtd, pos, vezesRep);
    }
    return vezesRep;
}



// Calcula a quantidade total de consultas e a quantidade total de termos
void auxiliarMediaTamanhoConsultasArquivo(Consulta *arvore, int *totTermos, int *totConsultas)
{

    // Se tenho um nodo da arvore
    if (arvore)
    {
        *totTermos += arvore->qtdeTermos;   // Somo ao total de termos, a qtde de termos desse nodo
        *totConsultas += 1;                 // Somo 1 ao total de nodos da arvore
        auxiliarMediaTamanhoConsultasArquivo(arvore->esq, totTermos, totConsultas);     // Recursão para avore esquerda
        auxiliarMediaTamanhoConsultasArquivo(arvore->dir, totTermos, totConsultas);     // Recursão para arvore direita
    }

    return;
}


// Quick sort de vetores int genericos
void quick_sort(int *a, int left, int right)
{
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j)
    {
        while(a[i] < x && i < right)
        {
            i++;
        }
        while(a[j] > x && j > left)
        {
            j--;
        }
        if(i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left)
    {
        quick_sort(a, left, j);
    }
    if(i < right)
    {
        quick_sort(a, i, right);
    }

}

// Insere termos de uma LSE em uma LDE
LDE* insereTermosNodo(LDE *lista, LSE* termos, int qtde)
{
    while(termos)
    {
        lista = insereLDENumerico(lista, termos->termo, qtde);
        termos = termos->prox;
    }
    return lista;
}


// Função que retorna a quantidade de vezes que a cidade aparece ou 0 se uma cidade estiver ou nao em uma lista, respectivamente
int temCidadeNaLista(char* cidade, LDE* lista)
{
    LDE* auxiliar = lista;
    int quantidade = 0;
    if(auxiliar)
    {
        while(auxiliar->prox != lista && auxiliar->prox)
        {
            if(strcmp(auxiliar->nome,cidade) == 0)
            {
                quantidade = auxiliar->qtde;
                break;
            }
            auxiliar = auxiliar->prox;
        }
        if(strcmp(auxiliar->nome,cidade) == 0)  quantidade = auxiliar->qtde;
    }

    return quantidade;
}



// Calcula a quantidade total de consultas e a quantidade total de termos em uma localidade
void auxiliarMediaTamanhoConsultasLocalidade(Consulta *arvore, int *totTermos, int *totConsultas, char* cidade)
{

    // Se tenho um nodo da arvore
    if (arvore)
    {
        if(temCidadeNaLista(cidade, arvore->cidades))
        {
            *totTermos += arvore->qtdeTermos;   // Somo ao total de termos, a qtde de termos desse nodo
            *totConsultas += 1;                 // Somo 1 ao total de nodos da arvore
        }
        auxiliarMediaTamanhoConsultasLocalidade(arvore->esq, totTermos, totConsultas, cidade);     // Recursão para avore esquerda
        auxiliarMediaTamanhoConsultasLocalidade(arvore->dir, totTermos, totConsultas, cidade);     // Recursão para arvore direita
    }
    return;
}

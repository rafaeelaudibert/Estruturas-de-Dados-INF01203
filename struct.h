#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct cidades{
    char nome[100];
    int qtde;
    struct cidades *prox;
} Cidades;

typedef struct termos{
    char termo[100];
    struct termos *prox;
} Termos;

typedef struct consulta{
    int qtdeAcessos;
    int qtdeTermos;
    Termos* termos;
    Cidades* cidades;

    struct consulta *esq;
    struct consulta *dir;
} Consulta;



#endif

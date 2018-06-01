#ifndef STRUCT_H_
#define STRUCT_H_

/* LISTA SIMPLESMENTE ENCADEADA RESPONSÁVEL POR GUARDAR INFORMAÇÃO SOBRE AS CIDADES */
typedef struct cidades{
    char nome[100];
    int qtde;
    struct cidades *prox;
} Cidades;


/* LISTA SIMPLESMENTE ENCADEADA RESPONSÁVEL POR GUARDAR OS TERMOS DE CADA CONSULTA */
typedef struct termos{
    char termo[100];
    struct termos *prox;
} Termos;


/* ÁRVORE BINÁRIA RESPONSÁVEL POR GUARDAR TODOS OS DADOS DAS CONSULTAS */
typedef struct consulta{
    int qtdeAcessos;
    int qtdeTermos;
    Termos* termos;
    Cidades* cidades;

    struct consulta *esq;
    struct consulta *dir;
} Consulta;



#endif

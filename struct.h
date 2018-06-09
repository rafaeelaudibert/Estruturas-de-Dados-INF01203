#ifndef STRUCT_H_
#define STRUCT_H_

/* LISTA SIMPLESMENTE ENCADEADA RESPONSÁVEL POR GUARDAR INFORMAÇÃO SOBRE AS CIDADES */
typedef struct lde{
    char nome[100];
    int qtde;
    struct lde *prox;
    struct lde *ant;
} LDE;


/* LISTA SIMPLESMENTE ENCADEADA RESPONSÁVEL POR GUARDAR OS TERMOS DE CADA CONSULTA */
typedef struct lse{
    char termo[100];
    struct lse *prox;
} LSE;


/* ÁRVORE BINÁRIA RESPONSÁVEL POR GUARDAR TODOS OS DADOS DAS CONSULTAS */
typedef struct abp{
    int qtdeAcessos;
    int qtdeTermos;
    LSE* termos;
    LDE* cidades;

    struct abp *esq;
    struct abp *dir;
} Consulta;


/* ESTRUTURA PRINCIPAL VISANDO FACILITAR ALGUMAS FUNÇÕES */
typedef struct descritor{
    Consulta  *arvore;
    LDE *termos;
} Info;



#endif

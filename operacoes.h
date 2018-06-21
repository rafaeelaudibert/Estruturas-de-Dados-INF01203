#include "struct.h"

#ifndef OPERACOES_H_
#define OPERACOES_H_

void consultasPorLocalidade(Consulta* arvore, char* cidade, int qtdConsultas, FILE* saida);
void consultasArquivo(Consulta* arvore, int qtdConsultas, FILE* saida);
LDE* termosPorLocalidade(Consulta* arvore, LDE *lista, char cidade[]);
LDE* insereTermosNodo(LDE *lista, LSE* termos, int qtde);
LDE* termosArquivo(LDE* listaTermos);
int mediaTamanhoConsultasLocalidade(Consulta* arvore, char* cidade);//, char* cidade);
int mediaTamanhoConsultasArquivo(Consulta* arvore);

/* FUNÇÕES AUXILIARES */
void auxiliarMediaTamanhoConsultasArquivo(Consulta*, int*, int*);

void auxiliarMediaTamanhoConsultasLocalidade(Consulta *arvore, int *totTermos, int *totConsultas, char* cidade);
int temCidadeNaLista(char* cidade, LDE* lista);

int achaVetorReps(Consulta* arvore, int *vetor, int contador);
int achaVetorRepsLocalidade(Consulta* arvore, int *vetor, int contador, char *cidade, Qtdcons *qtdCons);
void double_quick_sort(int *a, int *b, int left, int right);
void quick_sort(int *a, int left, int right);
int copiaArvoreLocalidade(Consulta* arvore, Consulta* retorno, int *vetor, int qtd, int pos, int vezesRep, char *cidade);
int copiaArvore(Consulta* arvore, Consulta* retorno, int *vetor, int qtd, int pos, int vezesRep);
#endif // OPERACOES_H_

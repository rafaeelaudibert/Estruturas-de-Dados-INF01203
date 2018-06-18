#include "struct.h"

#ifndef OPERACOES_H_
#define OPERACOES_H_

void consultasPorLocalidade(Consulta* arvore, char* cidade, int qtdConsultas);
void consultasArquivo(Consulta* arvore, int qtdConsultas);
LDE* termosPorLocalidade(Consulta* arvore, char* cidade, int qtdTermos);
LDE* termosArquivo(LDE* listaTermos, int qtdTermos);
int mediaTamanhoConsultasLocalidade(Consulta* arvore, char* cidade);//, char* cidade);
int mediaTamanhoConsultasArquivo(Consulta* arvore);

/* FUNÇÕES AUXILIARES */
void auxiliarMediaTamanhoConsultasArquivo(Consulta*, int*, int*);

void auxiliarMediaTamanhoConsultasLocalidade(Consulta *arvore, int *totTermos, int *totConsultas, char* cidade);
int temCidadeNaLista(char* cidade, LDE* lista);

//int achaVetorReps(Consulta* arvore, int *vetor);

//void achaVetorRepsLocalidade(Consulta* arvore, int *vetor, int pos, char *cidade, int* qtdReps);
void double_quick_sort(int *a, int *b, int left, int right);
void quick_sort(int *a, int left, int right);
//void copiaArvoreLocalidade(Consulta* arvore, Consulta* retorno, int *vetor, int qtd, int pos, int vezesRep, char *cidade);
#endif // OPERACOES_H_

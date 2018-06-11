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

void achaVetorReps(Consulta* arvore, int *vetor, int pos);
void copiaArvore(Consulta* arvore, Consulta* retorno, int *vetor, int qtd, int pos);

#endif // OPERACOES_H_

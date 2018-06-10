#include "struct.h"

#ifndef OPERACOES_H_
#define OPERACOES_H_

void consultasPorLocalidade(Consulta* arvore, char* cidade, int qtdConsultas);
void consultasArquivo(Consulta* arvore, int qtdConsultas);
void termosPorLocalidade(Consulta* arvore, char* cidade, int qtdTermos);
LDE* termosArquivo(LDE* listaTermos, int qtdTermos);
int mediaTamanhoConsultasLocalidade(Consulta* arvore, char* cidade);
int mediaTamanhoConsultasArquivo(Consulta* arvore);

/* FUNÇÕES AUXILIARES */
void auxiliarMediaTamanhoConsultasArquivo(Consulta*, int*, int*);
#endif // OPERACOES_H_

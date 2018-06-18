#include "struct.h"

#ifndef ARVORE_H_
#define ARVORE_H_

#define QTD_TERMOS 1
#define QTD_ACESSOS 2

Consulta* criaArvore();
Consulta* insereNodoArvore(Consulta *arvore, LSE* listaTermos, int qtdTermos, char* cidade);
void printaArvore(Consulta*, int, int);
int percorreArvore(Consulta *nodo, int nivel);
#endif // ARVORE_H_

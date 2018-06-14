#include "struct.h"

#ifndef ARVORE_H_
#define ARVORE_H_

#define QTD_TERMOS 1
#define QTD_ACESSOS 2

Consulta* criaArvore();
Consulta* insereNodoArvore(Consulta *arvore, LSE* listaTermos, int qtdTermos, char* cidade);
void printaArvore(Consulta*, int, int);
void printaInfoNodo(Consulta*);
#endif // ARVORE_H_

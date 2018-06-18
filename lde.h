#include "struct.h"

#ifndef CIDADES_H_
#define CIDADES_H_

LDE* inicializaLDE();
LDE* insereLDEAlfabetico(LDE* lista, char* nome);
LDE* insereLDENumerico(LDE* lista, char* nome, int qtde);
void printaLDE(LDE* lista);
#endif // CIDADES_H_

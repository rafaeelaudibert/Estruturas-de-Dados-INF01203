#include "struct.h"

#ifndef CIDADES_H_
#define CIDADES_H_

LDE* inicializaLDE();
LDE* insereLDEAlfabetico(LDE*, char*);
LDE* insereLDENumerico(LDE*, char*, int);
void printaLDE(LDE*, int);
#endif // CIDADES_H_

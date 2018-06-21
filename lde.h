#include "struct.h"
#include <stdio.h>

#ifndef CIDADES_H_
#define CIDADES_H_

LDE* inicializaLDE();
LDE* insereLDEAlfabetico(LDE*, char*);
LDE* insereLDENumerico(LDE*, char*, int);
void printaLDE(LDE*, int, FILE*);
#endif // CIDADES_H_

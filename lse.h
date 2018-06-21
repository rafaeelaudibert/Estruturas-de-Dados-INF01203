#include "struct.h"

#ifndef TERMOS_H_
#define TERMOS_H_

LSE* inicializaLSE();
LSE* insereLSE();
void printaLSE(LSE* lista, FILE* saida);
int LSEigual(LSE* lse1, LSE* lse2);
char *parseLSEtoString(LSE*, char*);
#endif // TERMOS_H_

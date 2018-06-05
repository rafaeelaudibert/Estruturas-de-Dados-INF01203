#include "struct.h"

#ifndef TERMOS_H_
#define TERMOS_H_

LSE* inicializaLSE();
LSE* insereLSE();
void printaLSE(LSE* lista);
int LSEigual(LSE* lse1, LSE* lse2);
LSE* bubbleSort(LSE* lista);
#endif // TERMOS_H_

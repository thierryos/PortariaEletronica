#ifndef TECLADOFUNCOES_H_
#define TECLADOFUNCOES_H_

#include "main.h"

#define LOW 0
#define HIGH 1

char scanForClick(unsigned long *tecladoOut, unsigned long *tecladoIn, int N,
		int M);
int colPressed(unsigned long *tecladoIn, int M);
char getDigito(unsigned long *tecladoOut, unsigned long *tecladoIn, int N, int M);
char numPressed(int linha, int coluna);

#endif /* TECLADOFUNCOES_H_ */

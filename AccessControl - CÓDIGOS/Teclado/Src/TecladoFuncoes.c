#include "TecladoFuncoes.h"

char scanForClick(unsigned long *tecladoOut, unsigned long *tecladoIn, int N,
		int M) {
	for (int i = 0; i < N; i++) {
		HAL_GPIO_WritePin(GPIOA, tecladoOut[i], LOW);
	}

	while (1) {
		HAL_GPIO_WritePin(GPIOA, tecladoOut[N - 1], LOW);

		for (int i = 0; i < N; i++) {
			HAL_GPIO_WritePin(GPIOA, tecladoOut[i], HIGH);

			if (i > 0)
				HAL_GPIO_WritePin(GPIOA, tecladoOut[i - 1], LOW);

			int col = colPressed(tecladoIn, M);

			if (col >= 0) {
				return numPressed(i, col);
			}
		}
	}
}

int colPressed(unsigned long *tecladoIn, int M) {
	for (int i = 0; i < M; i++) {
		if (HAL_GPIO_ReadPin(GPIOA, tecladoIn[i])) {
			return i;
		}
	}

	return -1;
}

char getDigito(unsigned long *tecladoOut, unsigned long *tecladoIn, int N, int M) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
	char digito = scanForClick(tecladoOut, tecladoIn, N, M);
	while (colPressed(tecladoIn, 4) != -1)
			;

	return digito;
}

char numPressed(int linha, int coluna) {
	char mat[4][4] = { { '1', '2', '3', 'A' }, { '4', '5', '6', 'B' }, { '7', '8', '9', 'C' },
			{ '*', '0', '#', 'D' } };

	return mat[linha][coluna];
}

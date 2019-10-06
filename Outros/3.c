#include <stdio.h>
#include <stdlib.h>

void diferenca(double conjX[10], double conjY[10], double conjD[10], int* tamConj) {
	int i, j, verifica;
	(*tamConj) = 0;

	for (i = 0; i < 10; ++i) {
		verifica = 0;

		for (j = 0; j < 10 && !verifica; ++j) {
			if(conjX[i] == conjY[j]) {
				verifica = 1;
			}
		}

		if(verifica == 0)
			conjD[(*tamConj)++] = conjX[i];
	}
}

void carregaConjunto (double conjX[10], double conjY[10]){
	int i, p, tamConj;
	double numx, numy;

	tamConj = 0;

	printf("Digite uma sequencia de 10 numeros reais para o vetor X:\n");

	while (tamConj < 10){
		p = 0;

		printf("Este e o numero %d faltam %d\n", tamConj+1, 9-tamConj);
		scanf("%lf", &numx);

		for (i = 0; i < tamConj; i++){
			if(numx == conjX[i]) {
				p = 1;
			}
		}

		if(p == 0) {
			conjX[tamConj++] = numx;
		} else {
			printf("Voce digitou o mesmo numero! Por favor, digite outro:\n");
		}
	}
        printf("[");
		for (i = 0; i < 10; i++){
		printf("%.2lf", conjX[i]);
		if(i+1 != 10)
			printf(", ");
	}
	printf("]\n");

	printf("\n");

	tamConj = 0;

	printf("Digite uma sequencia de 10 numeros reais para o vetor Y:\n");

	while (tamConj < 10){
		p = 0;

		printf("Este e o numero %d faltam %d\n", tamConj+1, 9-tamConj);
		scanf("%lf", &numy);

		for (i = 0; i < tamConj; i++){
			if(numy == conjY[i]) {
				p = 1;
			}
		}

		if(p == 0) {
			conjY[tamConj++] = numy;
		} else {
			printf("Voce digitou o mesmo numero! Por favor, digite outro:\n");
		}
	}

	printf("[");
	for (i = 0; i < 10; i++){
		printf("%.2lf ", conjY[i]);
		if(i+1 != 10)
			printf(", ");
	}
	printf("]");

	printf("\n");
}


void imprimeConjunto(double conj[10], int tam) {
	int i;

	printf("\n");
	printf("O vetor diferenca de X e Y e:\n");
	printf("[");
	for (i = 0; i < tam; ++i) {
		printf("%.1lf", conj[i]);
		if(i+1 != tam)
			printf(", ");
	}
	printf("]\n");
}

int main()
{
	double X[10], Y[10], D[10];
	int tamConjD;

	carregaConjunto(X, Y);
	diferenca(X, Y, D, &tamConjD);

	imprimeConjunto(D, tamConjD);

	return 0;
}

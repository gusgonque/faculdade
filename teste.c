#include <stdio.h>

int comparador(int num1, int num2){
	if(num1 < num2) return num2;
	else
	if(num1 > num2) return num1;
	else
	if(num1 == num2) return num1;
}

int maior_elemento(int v[], int tamanho){
	int aux;
	for(int i = 0; i+1 < tamanho; i++){
		aux = comparador(v[i], v[i+1]);
	}
	return aux;
}

void encheVet(int v[], int num){
	for(int i = 0; i < num; i++){
		scanf("%d", &v[i]);
	}
}

int main(){
	int tamanho_vetor, maior;
	scanf("%d", &tamanho_vetor);

	int vetor[tamanho_vetor];

	encheVet(vetor, tamanho_vetor);
	maior = maior_elemento(vetor, tamanho_vetor);
	printf("%d\n", maior);
	return 0;
}

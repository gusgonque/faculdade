#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void limpaStdin(){
	char c;
	while ((c=getchar()) != '\n' && c!=EOF);
}

struct memoria{
	double quantidade;
	char unidade[255];
};
typedef struct memoria ram;

struct celular{
	char marca[255];
	double preco;
	ram mem;
	int peso;
	int chips;
};
typedef struct celular celular;

void leituraCelular(struct celular *c){

	printf("Digite a marca/modelo do celular: \n");

	fgets((*c).marca, 255, stdin);
	strtok((*c).marca, "\n");

	printf("Digite o preco do aparelho\n");
	scanf("%lf", &(*c).preco);

	printf("Digite a quantidade de memoria do aparelho\n");
	scanf("%lf", &((*c).mem.quantidade));
	limpaStdin();

	printf("Digite a unidade de memoria do aparelho\n");
	fgets((*c).mem.unidade, 255, stdin);
	strtok((*c).mem.unidade,"\n");

	printf ("Digite o peso do aparelho em gramas\n");
	scanf("%d", &(*c).peso);

	printf("Digite o numero de chips\n");
	scanf("%d", &(*c).chips);
	limpaStdin();
}

int compara (struct celular c1, struct celular c2, int cam){
	int res=0;

	if(cam==2){
		if((c1.preco) < (c2.preco)){
			res=1;
		}
		else if((c1.preco) > (c2.preco)){
			res=2;
		}
		else{
			res=3;
		}
	return res;
	}

	if(cam==3){
		int aux1=0;
		int aux2=0;
			if((stricmp(c1.mem.unidade, "gb"))==0){
				aux1=c1.mem.quantidade*1000000000;
			}
			else if((stricmp(c1.mem.unidade,"mb"))==0){
				aux1=c1.mem.quantidade*1000000;
			}
			if((stricmp(c2.mem.unidade,"gb"))==0){
				aux2=c2.mem.quantidade*1000000000;
			}
			else if ((stricmp(c2.mem.unidade,"mb"))==0){
				aux2=c2.mem.quantidade*1000000;
			}

			if(aux1<aux2){
				res=2;
			}
			else if(aux1>aux2){
				res=1;
			}
			else{
				res=3;
			}
	}

	if (cam==4){
		if(c1.peso<c2.peso){
			res=1;
		}
		else if(c1.peso>c2.peso){
			res=2;
		}
		else{
			res=3;
		}
	}

	if(cam==5){
		if(c1.chips > c2.chips){
			res=1;
		}
		else if(c1.chips<c2.chips){
			res=2;
		}
		else{
			res=3;
		}
	}
	if(cam<2 || cam>5){
		res=0;
	}

	return res;
}


void imprimeCelular(struct celular c){
	printf("Marca: %s\n", c.marca);
	printf("Preco: %.2lf\n", c.preco);
	printf("Memoria RAM: %.2lf %s\n", c.mem.quantidade, c.mem.unidade);
	printf("Peso: %d\n", c.peso);
	printf("Numero de chips: %d\n", c.chips);
}

int main(){
	struct celular celular1;
	struct celular celular2;
	int cam;
	int resultado;


	printf("Digite os dados do primeiro aparelho\n");
	leituraCelular(&celular1);

	printf("\n");
	printf("Digite os dados do segundo aparelho\n");
	leituraCelular(&celular2);

	printf("Digite o numero correspondente ao dado a ser analisado\n");
	printf("Digite 2 para preco\n");
	printf("Digite 3 para memoria\n");
	printf("Digite 4 para peso\n");
	printf("Digite 5 para numero de chips\n");
	printf("\n");
	scanf("%d",&cam);
	printf("\n");

	while(resultado==0){
		printf("Erro de comparacao. Digite um valor de 2 a 5\n");
		scanf("%d",&cam);
		resultado=compara(celular1, celular2, cam);
		}

	printf("Para o parametro: %d o melhor aparelho e: %d\n", cam, resultado);

	if(resultado==1){
		imprimeCelular(celular1);
	}
	else if(resultado==2){
		imprimeCelular(celular2);
	}
	else if(resultado==3){
		imprimeCelular(celular1);
		imprimeCelular(celular2);
	}
	else if(resultado==0){
	}

	return 0;

}

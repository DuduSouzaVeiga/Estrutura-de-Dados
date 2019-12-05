#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 20

int partition(int *pontarr, int menor, int maior){
	int pivo = pontarr[maior];
	int aux;
	int i = menor-1;

	for (int j = menor; j <= maior-1;j++){
		if (pontarr[j]<pivo){
			i++;
			aux = pontarr[i];
			pontarr[i] = pontarr[j];
			pontarr[j] = aux;
		}
	}
	aux = pontarr[i+1];
	pontarr[i+1] = pontarr[maior];
	pontarr[maior] = aux;

	return (i+1);
}

void quicksort(int *pontarr, int menor, int maior){
	if (menor < maior){
		int div = partition(pontarr,menor,maior);
		
		quicksort(pontarr, menor, div-1);
		quicksort(pontarr,div+1, maior);
	}
}

void printas(int *pontarr){
	for(int j = 0;j<tam;j++){
		printf("%d ",pontarr[j]);
	}
	printf("\n");
}

int main(void){
	clock_t Ticks[2];
    Ticks[0] = clock();
	int arr[tam] = {159206, 53217, 491590, 385613, 278375, 339464, 244153, 145700, 333487, 331302, 206342, 429887, 417511, 438789, 486480, 148050, 199512, 386431, 346251, 26651};
	int *pontarr = arr;
	quicksort(pontarr, 0, tam-1);
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
	printas(pontarr);
	printf("Tempo gasto: %g ms.", Tempo);

	return 0;
}
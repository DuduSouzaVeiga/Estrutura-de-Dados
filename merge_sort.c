#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 20

void merge(int *pontlista, int inicio, int meio, int fim){
	int lenEsquerda = meio+1-inicio;
	int lenDireita = fim-meio;
	int arrayEsquerda[lenEsquerda], arrayDireita[lenDireita];

	for (int i = 0;i<lenEsquerda;i++){
		arrayEsquerda[i] = pontlista[inicio+i];
	}
	for(int i = 0;i<lenDireita;i++){
		arrayDireita[i] = pontlista[meio+1+i];
	}
	int i = 0;
	int j = 0;
	int m = inicio;
	while(i<lenEsquerda && j<lenDireita){
		if (arrayEsquerda[i]<=arrayDireita[j]){
			pontlista[m] = arrayEsquerda[i];
			i++;
		}
		else{
			pontlista[m] = arrayDireita[j];
			j++;
		}
		m++;
	}
	while(i<lenEsquerda){
		pontlista[m] = arrayEsquerda[i];
		m++;
		i++;
	}
	while(j<lenDireita){
		pontlista[m] = arrayDireita[j];
		m++;
		j++;
	}
}

void mergesort(int *pontlista,int inicio,int fim){
	if (inicio<fim){
		int meio = ((fim+inicio)/2);
		mergesort(pontlista,inicio,meio);
		mergesort(pontlista,meio+1,fim);
		merge(pontlista,inicio,meio,fim);
	}
}

int main(void){
	clock_t Ticks[2];
    Ticks[0] = clock();
	int inicio = 0;
	int fim = tam-1;
	int array[tam] = {172644, 327473, 179076, 176851, 79554, 169136, 282991, 66237, 440887, 95213, 288418, 247130, 441112, 385377, 69450, 331793, 288911, 21491, 81948, 22245};
	int *pontlista = array;
	mergesort(pontlista,inicio,fim);
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    for (int i=0; i < tam; i++){
    	printf("%d ", pontlista[i]);
    } 
    printf("\n");
    printf("Tempo gasto: %g ms.", Tempo);
}
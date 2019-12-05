#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define len 20

int *heapify(int *pont,int i,int varlen){
	int aux = 0;
	int direita = (i*2)+2;
	int esquerda = (i*2)+1;
	if (i>varlen){
		return pont;
	}
	else if(esquerda<varlen){
		if (direita<varlen){
			if(pont[i]<pont[esquerda]){
				if(pont[esquerda]<pont[direita]){
					aux = pont[i];
					pont[i] = pont[direita];
					pont[direita] = aux;
					i = direita;
					pont = heapify(pont,i,varlen);
					return pont;
				}
				else{
					aux = pont[i];
					pont[i] = pont[esquerda];
					pont[esquerda] = aux;
					i = esquerda;
					pont = heapify(pont,i,varlen);
					return pont;
				}
			}
			else if(pont[i]<pont[direita]){
				aux = pont[i];
				pont[i] = pont[direita];
				pont[direita] = aux;
				i = direita;
				pont = heapify(pont,i,varlen);
				return pont;
			}
		}
		else if (pont[i]<pont[esquerda]){
			aux = pont[i];
			pont[i] = pont[esquerda];
			pont[esquerda] = aux;
			i = esquerda;
			pont = heapify(pont,i,varlen);		
			return pont;	
		}
	}
	else{
		return pont;
	}
	return pont;
}

int *maxheap(int *pont, int varlen){
	for (int j=(len/2)-1;j>=0;j--){
		pont = heapify(pont, j,len);
	}
	return pont;
}

void printar(int * pont){
	for (int i=0;i<len;i++){
		printf("%d ", pont[i]);
	}
	printf("\n");
}

int main(void){
	clock_t Ticks[2];
    Ticks[0] = clock();
	int arr[len] = {398, 71, 684, 164, 268, 834, 701, 7, 607, 202, 949, 926, 222, 108, 841, 264, 959, 883, 566, 211};
	int *pont = arr;
	int aux;
	int varlen = len-1;
	pont = maxheap(pont,varlen);
	for(int varlen = len-1;varlen>=0;varlen--){
		int i = 0;
		aux = arr[0];
		arr[0]=arr[varlen];
		arr[varlen]=aux;
		pont = heapify(pont,i,varlen);
	}
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
	printar(pont);
	printf("\n");
	printf("Tempo gasto: %g ms.", Tempo);
	printf("\n");
	return 0;
}
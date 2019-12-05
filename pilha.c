#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha{
		struct elementos_linkados *inicio;
		int len_pilha;
	}marcador;

typedef struct elementos_linkados {
		struct elementos_linkados *proximo;
		int info;
	}elemento;

int empilhar(marcador *alfa_omega, int *dado) {
		struct elementos_linkados *new;
		new = malloc(sizeof(struct elementos_linkados));
		new->proximo = NULL;
		new->info = *dado;

		if (alfa_omega->inicio == NULL) {
			alfa_omega->inicio = new;
		}
		 else {
			new->proximo = alfa_omega->inicio;
			alfa_omega->inicio = new;
			
		}
		alfa_omega->len_pilha++;
		return 1;
	}

int desempilhar(marcador *alfa_omega) {
		struct elementos_linkados *aux;
		aux = alfa_omega->inicio;
		alfa_omega->inicio = alfa_omega->inicio->proximo;
		alfa_omega->len_pilha--;
		free(aux);
}

void printar (marcador *pilha) {
		struct elementos_linkados *setemares;
		setemares = pilha->inicio;
		int i;
		for(i = 0;i <= pilha->len_pilha;i++){
			if(setemares->proximo == NULL){
				printf("%d",setemares->info);
				break;
				}
			else{ 
				printf("%d ",setemares->info);
				setemares = setemares->proximo;
				}		
		}
		printf("\n");
	}

int main() {
		marcador struct1;
		struct1.inicio = NULL;
		struct1.len_pilha = 0;
		int value = 0;
		char acao[12]; 
		while(1) {
			scanf("%s",&acao);
			if (strcmp(acao,"Empilhar") == 0){
				scanf("%d",&value);
				empilhar(&struct1,&value);
			}
			else if (strcmp(acao,"Imprimir") == 0){
				printar(&struct1);
			}
			else if (strcmp(acao,"Desempilhar") == 0){
				desempilhar(&struct1);
			}
			else if (strcmp(acao,"Finalizar") == 0){
				break;
			}

		}
}
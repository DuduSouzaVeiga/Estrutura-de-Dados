#include <stdio.h>
#include <stdlib.h>

struct elementos_linkados
{
	struct elementos_linkados *proximo;
	int info;
};

typedef struct fila_de_fato
{
	struct elementos_linkados *inicio;
	struct elementos_linkados *fim;
	int len_fila;
}marcador;

int insert(marcador *alfa_omega, int *dado) {
	struct elementos_linkados *new;
	new = malloc(sizeof(struct elementos_linkados));

	new->proximo = NULL;
	new->info = *dado;
	if (alfa_omega->inicio == NULL) {
		alfa_omega->inicio = new;
		alfa_omega->fim = new;
	}
	 else {
		alfa_omega->fim->proximo = new;
		alfa_omega->fim = new;
	}
	alfa_omega->len_fila++;
	return 1;

}
int remove_lista(marcador *alfa_omega, int *dado){
	struct elementos_linkados *setemares;
	setemares = alfa_omega->inicio;
	if(alfa_omega->inicio->info == *dado){
		alfa_omega->inicio = alfa_omega->inicio->proximo;
		if(alfa_omega->inicio == NULL){
			alfa_omega->fim = NULL;
		}
	alfa_omega->len_fila--;
	return 0;
	}
	else{
		while(setemares != NULL && setemares->proximo != NULL){
			if(setemares->proximo->info == *dado){
				setemares->proximo = setemares->proximo->proximo;
				if(setemares->proximo == NULL){
					alfa_omega->fim = setemares;
				}	
			alfa_omega->len_fila--;
			return 0;
			}
			setemares = setemares->proximo;

		}
	}
	return 0;
}
int print(marcador lista){
		struct elementos_linkados *setemares;
		setemares = lista.inicio;
		for(int j = 0;j < lista.len_fila;j++){
			printf("%d ",setemares->info);
			setemares = setemares->proximo;
		}
	return 0;
	}	 	
int main(){
		int qntde_total;
		int indentificadores;
		int qntde_vaciloes;
		int vaciloes = 0;

		scanf("%d",&qntde_total);
		marcador struct1;
		struct1.inicio = NULL;
		struct1.fim = NULL;
		struct1.len_fila = 0;
		 for (int y = 0;y < qntde_total;y++){
		 	scanf("%d",&indentificadores);
		 	insert(&struct1, &indentificadores);
		
		}
		scanf("%d",&qntde_vaciloes);
		 for (int y = 0;y < qntde_vaciloes;y++){
		 	scanf("%d",&vaciloes);
		 	remove_lista(&struct1, &vaciloes);		
		}
	print(struct1);
}
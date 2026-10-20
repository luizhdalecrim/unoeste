#include <stdio.h>

#define QTD 5
#define TAM 100

int main(void) {
	FILE * arq;
	char nome[TAM];
	int i;
	
	arq = fopen("participantes.txt", "w");
	
	if (arq == NULL) {
		printf("\nFATAL: Arquivo nao pode ser carregado!\n");
		
		return -1;
	}
	
	printf("\nLOG: O arquivo foi aberto!\n");
	
	for (i = 0; i < QTD; i++) {
		printf("Nome do participante %d -> ", i + 1);
		fgets(nome, sizeof(nome), stdin);
		printf("\nLOG: Escrevendo dados...\n\n");
		fputs(nome, arq);
	}
	
	fclose(arq);
	printf("\nLOG: O Arquivo foi fechado!\n\n");
	
	return 0;
}

#include <stdio.h>

int main(void) {
	FILE * arq;
	char nome[20] = "Hoonigan";
	int idade = 30;
	float altura = 1.74;
	
	printf("\nLOG: Abrindo arquivo...\n");
	arq = fopen("arqgrav.txt", "w");
	
	if (arq == NULL) {
		printf("\nFATAL: Erro ao abrir o arquivo.\n\n");
		
		return 1;
	}
	printf("LOG: Concluido!\n\n");
	
	printf("\nLOG: Gravando...\n");
	fprintf(arq, "Nome: %s\n", nome);
	fprintf(arq, "Idade: %d\n", idade);
	fprintf(arq, "Altura: %.2f\n", altura);
	printf("LOG: Concluido!\n\n");
	
	printf("\nLOG: Arquivo criado!\n\n");
	
	fclose(arq);
	
	
	
	return 0;
}

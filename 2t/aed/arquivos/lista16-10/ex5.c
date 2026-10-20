#include <stdio.h>

#define TAM 100

int main(void) {
	FILE * arq;
	char nome[TAM];
	char data[TAM];
	
	arq = fopen("aniversario.txt", "w");
	
	if (arq == NULL) {
		printf("\nFATAL: Arquivo nao pode ser carregado!\n");
		
		return -1;
	}
	
	printf("\nLOG: O arquivo foi aberto!\n");
	
	printf("Digite o seu nome -> ");
	fgets(nome, sizeof(nome), stdin);
	
	printf("Digite a data do seu aniversario (dd/mm/aaaa) -> ");
	fgets(data, sizeof(data), stdin);

	printf("\nLOG: Escrevendo dados...\n\n");	
	fputs("Nome: ", arq);
	fputs(nome, arq);
	fputs("Aniversario: ", arq);
	fputs(data, arq);
	
	fclose(arq);
	printf("\nLOG: O Arquivo foi fechado!\n\n");
	
	return 0;
}

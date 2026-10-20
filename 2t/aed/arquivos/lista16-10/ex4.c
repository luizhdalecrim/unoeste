#include <stdio.h>
#include <ctype.h>

#define TAM 100

int ehVogal(char c) {
	c = tolower((unsigned char) c);
	
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(void) {
	FILE * arq;
	char linha[TAM];
	int i;
	int total = 0;
	
	arq = fopen("alfa.txt", "r");
	
	if (arq == NULL) {
		printf("\nFATAL: Arquivo alfa.txt nao pode ser carregado!\n");
		printf("FATAL: Execute o exercicio 3 antes para criar o arquivo.\n\n");
		
		return -1;
	}
	
	printf("\nLOG: O arquivo foi aberto!\n");
	printf("LOG: Lendo dados...\n\n");
	
	while (fgets(linha, sizeof(linha), arq) != NULL) {
		for (i = 0; linha[i] != '\0'; i++) {
			if (ehVogal(linha[i])) {
				total++;
			}
		}
	}
	
	fclose(arq);
	printf("LOG: O Arquivo foi fechado!\n\n");
	
	printf("Quantidade de vogais no arquivo: %d\n\n", total);
	
	return 0;
}

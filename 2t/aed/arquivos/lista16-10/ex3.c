#include <stdio.h>
#include <ctype.h>

#define TAM 100

int ehVogal(char c) {
	c = tolower((unsigned char) c);
	
	return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
}

int main(void) {
	FILE * arq;
	char texto[TAM];
	char vogais[TAM];
	char resp[10];
	int i;
	int qtd = 0;
	
	printf("\nDigite o nome (atividade ou coordenador) -> ");
	fgets(texto, sizeof(texto), stdin);
	
	for (i = 0; texto[i] != '\0'; i++) {
		if (ehVogal(texto[i])) {
			vogais[qtd] = texto[i];
			qtd++;
		}
	}
	vogais[qtd] = '\0';
	
	printf("\nLOG: Quantidade de vogais: %d\n", qtd);
	printf("LOG: Vogais encontradas: %s\n\n", vogais);
	
	printf("Deseja gravar as vogais em alfa.txt? (s/n) -> ");
	fgets(resp, sizeof(resp), stdin);
	
	if (tolower((unsigned char) resp[0]) == 's') {
		arq = fopen("alfa.txt", "a");
		
		if (arq == NULL) {
			printf("\nFATAL: Arquivo nao pode ser carregado!\n");
			
			return -1;
		}
		
		printf("\nLOG: O arquivo foi aberto!\n");
		printf("LOG: Escrevendo dados...\n\n");
		fputs(vogais, arq);
		fputs("\n", arq);
		
		fclose(arq);
		printf("LOG: O Arquivo foi fechado!\n\n");
	} else {
		printf("\nLOG: Nada foi gravado.\n\n");
	}
	
	return 0;
}

#include <stdio.h>

int main(void) {
	FILE * evento;
	char atividade[100];
	
	evento = fopen("evento.txt", "w");
	
	if (evento == NULL) {
		printf("\nFATAL: Arquivo nao pode ser carregado!\n");
		
		return -1;
	}
	
	printf("\nLOG: O arquivo foi aberto!\n");
	
	printf("Digite o nome da sua primeira atividade no evento de TI -> ");
	fgets(atividade, sizeof(atividade), stdin);
	printf("LOG: Escrevendo dados...\n\n");
	fputs(atividade, evento);
	printf("\n");
	
	fclose(evento);
	printf("\nLOG: O Arquivo foi fechado!\n\n");
	
	return 0;
}

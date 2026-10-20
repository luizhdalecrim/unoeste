#include <stdio.h>

int main(void) {
	FILE * data;
	char ch;
	
	data = fopen("data.dat", "w");
	
	if (data == NULL) {
		printf("\nFATAL: Arquivo nao pode ser carregado!\n");
		fclose(data);
		
		return -1;
	} else {
		printf("\nLOG: O arquivo foi aberto!\n");
		printf("LOG: Escrevendo dados...\n\n");
		
		printf("Digite um caractere -> ");
		fflush(stdin);
		scanf("%c", &ch);
		putc(ch, data);
		printf("\n");
	}
	fclose(data);
	printf("\nLOG: O Arquivo foi fechado!\n\n");
	
	return 0;
}

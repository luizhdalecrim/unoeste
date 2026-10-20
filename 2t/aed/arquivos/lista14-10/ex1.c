#include <stdio.h>

int main(void) {
	FILE * data;
	char ch[] = "abcdefghijklmnopqrstuvwxyz";
	
	data = fopen("dados.txt", "w");
	
	if (data == NULL) {
		printf("\nFATAL: Arquivo nao pode ser carregado!\n");
		fclose(data);
		
		return -1;
	} else {
		printf("\nLOG: O arquivo foi aberto!\n");
		printf("LOG: Escrevendo dados...\n\n");
		
		int i = 0;
		do {
			putc(ch[i], data);
			i++;
		} while (ch[i] != "z");

		printf("\n");
	}
	fclose(data);
	printf("\nLOG: O Arquivo foi fechado!\n\n");
	
	return 0;
}

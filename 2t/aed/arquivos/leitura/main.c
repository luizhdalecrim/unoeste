#include <stdio.h>

int main(void) {
	FILE * data;
	char ch;
	
	data = fopen("data.dat", "r");
	
	if (data == NULL) {
		printf("\nFATAL: Arquivo nao pode ser carregado!\n");
		fclose(data);
		
		return -1;
	} else {
		printf("\nLOG: O arquivo foi aberto!\n");
		printf("LOG: Lendo dados...\n\n");
		
		while (ch != EOF) {
			ch = fgetc(data);
			printf("%c", ch);
		}
		printf("\n");
	}
	fclose(data);
	printf("\nLOG: O Arquivo foi fechado!\n\n");
	
	return 0;
}

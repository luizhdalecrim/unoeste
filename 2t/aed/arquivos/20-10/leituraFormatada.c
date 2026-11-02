#include <stdio.h>

int main(void) {
	FILE * arq;
	char texto[20], nome[20];
	int idade;
	float altura;
	
	arq = fopen("arqgrav.txt", "r");
	if (arq == NULL) {
		printf("FATAL: Erro ao abrir o arquivo.");
		
		return 1;
	}
	fscanf(arq, "%s%s", &texto, &nome);
	printf("%s %s\n", texto, nome);
	fscanf(arq, "%s%d", &texto, &idade);
	printf("%s %d\n", texto, idade);
	fscanf(arq, "%s%f", &texto, &altura);
	printf("%s %.2f\n", texto, altura);
	
	fclose(arq);
	
	return 0;
}

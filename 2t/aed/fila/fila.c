#include <stdio.h>
#include <windows.h>

#define MAXTAM 10

int inicio, fim, fila[MAXTAM];

void menu() {
	printf("1 - Criar Fila\n");
	printf("2 - Inserir Elemento Fila\n");
	printf("3 - Exibir Fila\n");
	printf("4 - Remove Elemento Fila\n");
	printf("5 - Sair\n");
}

void cria_fila() {
	inicio = 0;
	fim = -1;
}

int fila_vazia() {
	if (fim < inicio)
		return 1;
	else
		return 0;
}

int fila_cheia() {
	if ((fim - inicio) == (MAXTAM - 1))
		return 1;
	else
		return 0;
}

void insere_fila(int elem) {
	if (fila_cheia())
		printf("A fila esta cheia\n");
	else {
		fim++;
		fila[fim] = elem;
	}
}

void exibe_fila() {
	int i;
	if (!fila_vazia()) {
		for (i = inicio; i <= fim; i++)
			printf("Elemento %d\n", fila[i]);
	}
	else
		printf("A fila esta vazia\n");
}

int remove_fila() {
	int v;
	
	if (!fila_vazia()) {
		v = fila[inicio];
		inicio++;
		
		return v;
	}
	else {
		printf("A fila esta vazia\n");
		
		return -1;
	}
}

int main(void) {
	int op, elem, r;
	
	menu();
	
	printf("Escolha a opcao: ");
	scanf("%d", &op);
	
	while (op != 5) {
		switch (op) {
			case 1:
				cria_fila();
				break;
			case 2:
				printf("Informe o Elemento: ");
				scanf("%d", &elem);
				insere_fila(elem);
				break;
			case 3:
				exibe_fila();
				break;
			case 4:
				if (!fila_vazia()) {
					r = remove_fila();
					printf("O elemento %d foi removido.\n", r);
				
				}
				else {
					printf("Fila Vazia.\n");
				}
				break;
		}
		system("pause");
		system("cls");
		
		menu();
		scanf("%d", &op);
	}
	
	return 0;
}


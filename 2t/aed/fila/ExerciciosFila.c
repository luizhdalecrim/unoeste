#include <stdio.h>
#include <windows.h>

#define MAXTAM 10

int inicio, fim, fila[MAXTAM];

void menu() {
	printf("1 - Criar Fila\n");
	printf("2 - Inserir Elemento Fila\n");
	printf("3 - Exibir Fila\n");
	printf("4 - Remove Elemento Fila\n");
	printf("5 - Exibir Elementos maiores que 10 e múltiplos de 5\n");
	printf("6 - Exibir Elementos Pares\n");
	printf("7 - Exibir Elementos Impares\n");
	printf("8 - Exibir Elemento a Frente\n");
	printf("0 - Sair\n");
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
		
		if (inicio > fim)
			cria_fila();
		
		return v;
	}
	else {
		printf("A fila esta vazia\n");
		
		return -1;
	}
}

/* LISTA DE EXERCÍCIOS FILA */
/* 
 EX1: função que retorna a quantidade
 de elementos maiores que 10 e múltiplos 
 de 5 da Fila.
*/
int NumElMaiMul() {
	int cont;
	
	if (!fila_vazia()) {
		int i;
		for (i = inicio; i <= fim; i++) {
			if ((fila[i] > 10) && (fila[i] % 5) == 0)
				cont++;
		}
		
		return cont;
	}
	else {
		printf("\nA fila esta vazia.\n");
		
		return -1;
	}
}

/* 
 EX2: função que exibe o(s) elemento(s)
 da Fila se for(em) par(es).
*/
void NumElPar() {
	int cont;
	
	if (!fila_vazia()) {
		printf("\nElementos pares na fila:\n", cont);
		int i;
		for (i = inicio; i <= fim; i++) {
			if ((fila[i] % 2) == 0)
				printf("%d\n", fila[i]);
		}
	}
	else {
		printf("\nA fila esta vazia.\n");
	}
}

/* 
 EX3: função que retorne a quantidade de
 números ímpares da Fila.
*/
int NumElImp() {
	int cont;
	
	if (!fila_vazia()) {
		int i;
		for (i = inicio; i <= fim; i++) {
			if ((fila[i] % 2) != 0)
				cont++;
		}
		
		return cont;
	}
	else {
		printf("\nA fila esta vazia.\n");
		
		return -1;
	}
}

/* 
 EX4: função que exiba quem está na frente 
 da fila, ou seja o candidato a ser removido.
*/
void ElAFrente() {
	if (!fila_vazia()) {
		printf("\nElemento a frente: %d\n", fila[inicio]);
	}
	else {
		printf("A fila esta vazia.\n");
	}
}

int main(void) {
	int op, elem, r;
	
	cria_fila();
	
	menu();
	
	printf("Escolha a opcao: ");
	scanf("%d", &op);
	
	while (op != 0) {
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
					printf("\nO elemento %d foi removido.\n", r);
				
				}
				else {
					printf("\nFila Vazia.\n");
				}
				break;
			case 5:
				printf("\nQuantidade de elementos maiores que 10 e multiplos de 5: %d\n", NumElMaiMul());
				break;
			case 6:
				NumElPar();
				break;
			case 7:
				printf("\nNumero de elementos impares: %d\n", NumElImp());
				break;
			case 8:
				ElAFrente();
				break;
		}
		system("pause");
		system("cls");
		
		menu();
		scanf("%d", &op);
	}
	
	return 0;
}


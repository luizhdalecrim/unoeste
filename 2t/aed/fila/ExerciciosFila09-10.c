#include <stdio.h>
#include <windows.h>

#define MAXTAM 10

int inicio, fim, fila[MAXTAM];

void menu() {
	printf("1 - Criar Fila\n");
	printf("2 - Inserir Elemento Fila\n");
	printf("3 - Exibir Fila\n");
	printf("4 - Remove Elemento Fila\n");
	printf("5 - Maior, Menor e Media (Ex. 1)\n");
	printf("6 - Buscar Elemento (Ex. 2)\n");
	printf("7 - Esvaziar Fila (Ex. 3)\n");
	printf("8 - Duplicar Fila (Ex. 4)\n");
	printf("9 - Sair\n");
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

/*
 * NOTE:
 * (fim - inicio) == (MAXTAM - 1)
 * A fila NÃO É circular. 
 * Depois de remover um elemento de uma fila 
 * com 10, o programa permitiria inserir em fila[10], 
 * fora do vetor (overflow).
 */
int fila_cheia() {
	if (fim == (MAXTAM - 1))
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

// EX1
void maior_menor_media() {
	int i, maior, menor, soma, qtd;
	float media;
	
	if (fila_vazia()) {
		printf("A fila esta vazia\n");
		return;
	}
	
	maior = fila[inicio];
	menor = fila[inicio];
	soma = 0;
	
	for (i = inicio; i <= fim; i++) {
		if (fila[i] > maior)
			maior = fila[i];
		if (fila[i] < menor)
			menor = fila[i];
		soma += fila[i];
	}
	
	qtd = fim - inicio + 1;
	media = (float) soma / qtd;
	
	printf("Maior elemento: %d\n", maior);
	printf("Menor elemento: %d\n", menor);
	printf("Media aritmetica: %.2f\n", media);
}

// EX2
void busca_fila(int valor) {
	int i;
	
	if (fila_vazia()) {
		printf("A fila esta vazia\n");
		return;
	}
	
	for (i = inicio; i <= fim; i++) {
		if (fila[i] == valor) {
			printf("Valor %d encontrado!\n", valor);
			printf("Indice no vetor: %d\n", i);
			printf("Posicao na fila: %d\n", i - inicio + 1);
			return;
		}
	}
	
	printf("O valor %d nao foi localizado na fila\n", valor);
}

// EX3
void esvazia_fila() {
	if (fila_vazia()) {
		printf("A fila ja esta vazia\n");
	}
	else {
		cria_fila();
		printf("Fila esvaziada com sucesso\n");
	}
}

// EX4
void duplica_fila() {
	int i, qtd, posicao_final;
	
	if (fila_vazia()) {
		printf("A fila esta vazia, nao ha o que duplicar\n");
		return;
	}
	
	qtd = fim - inicio + 1;
	posicao_final = fim + qtd;
	
	if (posicao_final > MAXTAM - 1) {
		printf("Nao ha espaco suficiente: a operacao nao pode ser realizada\n");
		return;
	}
	
	for (i = 0; i < qtd; i++)
		fila[fim + 1 + i] = fila[inicio + i];
	
	fim = posicao_final;
	printf("Fila duplicada com sucesso\n");
}

/*
 * NOTE:
 * int main(void) e return 0 são obrigatórios no 
 * padrão C atual.
 */
int main(void) {
	int op, elem, r;
	
	cria_fila();
	
	menu();
	
	printf("Escolha a opcao: ");
	scanf("%d", &op);
	
	while (op != 9) {
		switch (op) {
			case 1:
				/* 
				 * NOTE:
				 * Se cria_fila() não é chamada aqui, um 
				 * elemento 0 aparece antes da fila ser criada.
				 */
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
			case 5:
				maior_menor_media();
				break;
			case 6:
				printf("Informe o valor a ser buscado: ");
				scanf("%d", &elem);
				busca_fila(elem);
				break;
			case 7:
				esvazia_fila();
				break;
			case 8:
				duplica_fila();
				break;
			default:
				printf("Opcao invalida\n");
		}
		system("pause");
		system("cls");
		
		menu();
		printf("Escolha a opcao: ");
		scanf("%d", &op);
	}
	
	return 0;
}


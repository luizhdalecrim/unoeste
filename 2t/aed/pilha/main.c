#include<stdio.h>
// #include<windows.h>

#define MAXTAM 10

int topo;
int pilha[MAXTAM];

void menu();
void pilha_cria();
int pilha_vazia();
int pilha_cheia();
void insere(int valor);
int exclui();
void exibe_topo();
void mostra_pilha();
int tamanho();

int main(void) {
	int op, valor;
	menu();
	printf("\nEscolha a opcao: ");
	scanf("%d", &op);
	while (op != 7) {
		switch (op) {
                        case 1:
                                pilha_cria();
                                break;
                        case 2:
                                printf("\nInforme um valor: ");
                                scanf("%d", &valor);
                                insere(valor);
                                break;
                        case 3:
                                printf("\nElemento removido %d\n", exclui());
                                break;
                        case 4:
                                exibe_topo();
                                break;
                        case 5:
                                mostra_pilha();
                                break;
                        case 6:
                                if (!pilha_vazia())
                                        printf("\nO tamanho da pilha e %d\n", tamanho());
                                break;
                }
		// system("pause"); //pressione uma tecla para continuar
		// system("cls"); //limpa a tela
                menu();
		printf("\nEscolha a opcao: ");
                scanf("%d", &op);
	}
}

void menu() {
	printf("\n **** Menu Pilha ****\n");
	printf("\n1- Criar Pilha ");
	printf("\n2- Inserir Elemento ");
	printf("\n3- Remover Elemento ");
	printf("\n4- Exibir Topo ");
	printf("\n5- Exibir Pilha ");
	printf("\n6- Tamanho da Pilha ");
	printf("\n7- Sair ");
}

void pilha_cria() {
	topo = -1;
	printf("\nA pilha foi criada!\n");
}

int pilha_vazia() {
	if (topo == -1)
                return 1; //Pilha vazia
	else
                return 0; //Pilha nao vazia  
}

int pilha_cheia() {
	if (topo == MAXTAM - 1)
                return 1; // Pilha cheia
	else
                return 0; // Pilha nao cheia   
}

void insere(int valor) {
	if (!pilha_cheia()) {
                topo++;
		pilha[topo] = valor;
	}
	else
                printf("\nA pilha esta cheia!\n");
}
int exclui() {
	int elem = 0;
	if (pilha_vazia())
                printf("\nA pilha esta vazia!\n");
	else {
		elem = pilha[topo];
		topo--;
	}  
	return elem;
}

void exibe_topo() {
	if (!pilha_vazia())
                printf("\nElemento do topo e %d\n", pilha[topo]);
	else
                printf("\nA pilha esta vazia!\n");    
}

void mostra_pilha() {
	int i;
	if (!pilha_vazia()) {
                for (i = topo; i >= 0; i--)
                        printf("\n%d\n", pilha[i]);
	}
	else
                printf("\nA pilha esta vazia!\n");
}

int tamanho() {
	int tam = 0;
	tam = topo + 1;
	return tam;
}


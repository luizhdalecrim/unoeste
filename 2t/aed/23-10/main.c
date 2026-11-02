#include <stdio.h>

typedef struct {
	int dia, mes, ano;
} DATA;
typedef struct {
	char nome[60];
	char tel[15];
	char email[40];
	DATA aniv;
}CONTATO;

void menu() {
	int op;
	printf("\1 - Inserir");
	printf("\2 - Exibir");
	printf("\3 - Alterar");
	printf("\4 - Excluir");
	printf("\5 - Sair");
	printf("\nInforme a opcao desejada -> ");
	scanf("%d", &op);
}

int busca(FILE * arquivo, char nome[]) {
	CONTATO ctt;
	rewind(arquivo);
	fread(&ctt, sizeof(CONTATO), 1, arquivo);
	while ((!feof(arquivo) && stricmp(nome, ctt.nome)) != 0) {
		fread(&ctt, sizeof(CONTATO), 1, arquivo);
	}
	if (!feof(arquivo)) {
		return (ftell(arquivo) - sizeof(CONTATO));
	}
	else {
		
	}
}

void inserir() {
	FILE * arquivo;
	CONTATO ctt;
	int pos;
	arquivo = fopen("agenda.bin","ab+");
	if (arquivo == NULL) {
		printf("Erro no arquivo.");
	}
	else {
		do {
			system("cls");
			printf("\nNome: ");
			fflush(stdin);
			fgets(ctt.nome, sizeof(ctt.nome), stdin);
			pos = busca(arquivo, ctt.nome);
			if (pos == -1) {
				
			}
			else {
				fseek(arquivo, pos, 0);
				fread(&ctt, sizeof(CONTATO), 1, arquivo);
				
			}
		}
	}
}

int main(void) {
	int op;
	op = menu();
	
	return 0;
}

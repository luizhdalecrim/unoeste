#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	int cod;
	char titulo[255];
	char autor[255];
	char genero[255];
	int ano;
	int status;
} LIVRO;

int Menu() {
	int opcao;
	
	printf("\n\n--- GERENCIAMENTO DE ACERVO DA BIBLIOTECA ---\n");
	printf("1. Cadastrar\n");
	printf("2. Exibir\n");
	printf("3. Alterar\n");
	printf("4. Excluir\n");
	printf("0. Encerrar Sistema\n");
	printf("\n-> ");
	scanf("%d", &opcao);
	
	return opcao;
}

int BuscaLivro(FILE *arquivo, char busca[], int tituloOuAutor) {
	LIVRO livro;
	
	rewind(arquivo);
	fread(&livro, sizeof(LIVRO), 1, arquivo);
	if (tituloOuAutor != 1 && tituloOuAutor != 0) {
		tituloOuAutor = 1;
	}
	if (tituloOuAutor = 1) {
		while(!feof(arquivo) && stricmp(busca, livro.titulo) != 0) {
			fread(&livro, sizeof(LIVRO), 1, arquivo);
		}
		if (!feof(arquivo)) {
			return (ftell(arquivo) - sizeof(LIVRO));
		}
		else {
			return -1;
		}
	}
	else {
		while(!feof(arquivo) && stricmp(busca, livro.autor) != 0) {
			fread(&livro, sizeof(LIVRO), 1, arquivo);
		}
		if (!feof(arquivo)) {
			return (ftell(arquivo) - sizeof(LIVRO));
		}
		else {
			return -1;
		}
	}
}

void Inserir() {
	FILE *arquivo;
	LIVRO livro;
	livro.status = 0; // Livro automaticamente disponível após inserir
	int i;
	
	arquivo = fopen("acervo.bin", "ab+");
	if (arquivo == NULL) {
		printf("\n\nERRO: arquivo não pode ser aberto.\n");
	}
	else {
		do {
			printf("\nInsira o nome -> ");
			fflush(stdin);
			fgets(livro.titulo, sizeof(livro.titulo), stdin);
			i = BuscaLivro(arquivo, livro.titulo, 1);
			if (i != -1) {
				fseek(arquivo, i, 0);
				fread(&livro, sizeof(LIVRO), 1, arquivo);
				printf("Livro \"%s\" ja cadastrado.\n", livro.titulo);
			}
			else {
				printf("Autor -> ");
				fflush(stdin);
				fgets(livro.autor, sizeof(livro.autor), stdin);
				printf("Genero -> ");
				fflush(stdin);
				fgets(livro.genero, sizeof(livro.genero), stdin);
				printf("Ano -> ");
				fflush(stdin);
				scanf("%d", livro.ano);
				livro.status = 0;
				fwrite(&livro, sizeof(LIVRO), 1, arquivo);
			}
			printf("Deseja continuar? [S/N] -> ");
		} while (toupper(getche()) == 'S');
		fclose(arquivo);
	}
}

void Exibir() {
	FILE *arquivo;
	LIVRO livro;
	arquivo = fopen("acervo.bin", "rb");
	if (arquivo == NULL) {
		printf("Erro no arquivo.\n");
	}
	else {
		while(fread(&livro, sizeof(LIVRO), 1, arquivo) == 1) {
			printf("Livro encontrado:\n\n");
			
		}
	}
}

int main(void) {
	int opcao;
	
	do {
		opcao = Menu();
		
		switch (opcao) {
			case 1:
				
				break;
			case 2:
				
				break;
			case 0:
				printf("\n\nSaindo...\n");
				break;
			default:
				printf("\n\nEscolha uma opcao valida.\n");
		}
	} while(opcao != 0);
	
	return 0;
}

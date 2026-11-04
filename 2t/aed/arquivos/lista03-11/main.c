#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Você foi contratado por uma empresa de eventos para desenvolver um sistema de
// controle de feiras temáticas. A empresa realiza festas, feiras, shows e festivais ao longo
// do ano. O próximo evento será a Feira de Natal, que acontecerá no dia 15 de
// dezembro, com o objetivo de reunir empreendedores locais para oferecer produtos
// típicos da época e fomentar o comércio regional.
// Seu sistema de controle (CRUD) deverá permitir o cadastro dos expositores da feira
// e conter os seguintes dados:
// 	? Código da barraca
// 	? Nome do responsável
// 	? Pessoa física ou jurídica
// 	? CPF ou CNPJ
// 	? Telefone de contato
// 	? Tipo de produto ofertado (ex: panetones, artesanato natalino, decoração,
// brinquedos, comidas típicas, bebidas, roupas temáticas, entre outros)
// 	? Observações (campo de até 200 caracteres para anotações diversas)
// Além das opções básicas de Inclusão, Listagem e Alteração, o sistema deve permitir
// uma alteração específica do tipo de produto ofertado, caso o responsável pela
// barraca deseje modificar antecipadamente os itens que serão vendidos durante a feira

typedef struct {
	int cod;
	char responsavel[50];
	int pf_ou_pj;
	char doc[14];
	char tel[15];
	char tipo[50];
	char obs[255];	
} EXP;

void Cadastrar() {
	
}

void Buscar() {
	
}

void Alterar() {
	
}

void Excluir() {
	
}

int main(void) {
	int opc;
	
	do {
		printf("\n\n--- Gerenciamento de barraca ---\n");
		printf("1. Cadastrar\n");
		printf("2. Buscar\n");
		printf("3. Alterar\n");
		printf("4. Excluir\n");
		printf("0. Sair\n");
		printf("-> ");
		
		scanf("%d", &opc);
		
		switch(opc) {
			case 1:
				Cadastrar();
				break;
			case 2:
				
				break;
			case 3:
				break;
			case 4:
				break;
			case 0:
				printf("\n\nSaindo...\n");
				break;
		}
	} while(opc != 0);
	
	return 0;
}

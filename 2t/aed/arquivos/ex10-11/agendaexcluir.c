#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>

typedef struct {
	int d, m, a;
} DATA;

typedef struct{
	char nome[60], fone[15], email[40];
	DATA aniv;
} CONTATO;

int menu()
{
	int opc;
	printf("\n1 - Inserir ");
	printf("\n2 - Exibir");
	printf("\n3 - Alterar");
	printf("\n4 - Excluir");
	printf("\n5 - Sair");
	printf("\nInforme a opcao desejada: ");
	scanf("%d", &opc);
	return opc;
}

int busca(FILE *arquivo, char nome[])
{
	CONTATO ctt;
	rewind(arquivo);
	fread(&ctt, sizeof(CONTATO), 1, arquivo);
	while(!feof(arquivo) && stricmp(nome, ctt.nome) != 0)
	{
		fread(&ctt, sizeof(CONTATO), 1, arquivo);
	}
	if(!feof(arquivo))
	   return (ftell(arquivo) - sizeof(CONTATO));
	else
	  return -1;
}
void inserir()
{
	FILE *arquivo;
	CONTATO ctt;
	int pos;
	arquivo = fopen("agenda.bin", "ab+");
	if(arquivo == NULL)
	  printf("Erro no arquivo");
	else
	{
		do
		{
			system("cls");
			printf("\nNome: "); fflush(stdin);
			gets(ctt.nome);
			pos = busca(arquivo, ctt.nome);
			if(pos == -1) // Não achou
			{
				printf("\nTelefone: "); fflush(stdin);
				gets(ctt.fone);
				printf("\nE-mail: "); fflush(stdin);
				gets(ctt.email);
				printf("Aniversario (dd mm aaaa): ");
				scanf("%d%d%d", &ctt.aniv.d, &ctt.aniv.m, &ctt.aniv.a);
				fwrite(&ctt, sizeof(CONTATO), 1, arquivo);
			}
			else
			{
				fseek(arquivo, pos, 0);
				fread(&ctt, sizeof(CONTATO), 1, arquivo);
				printf("\n %s ja esta cadastrad(a)o na agenda", ctt.nome);
				system("pause");
			}
			system("cls");
			printf("\nDeseja continuar S/N? ");
		}while(toupper(getche()) == 'S');
		fclose(arquivo);
	}  
}
void exibir()
{
	FILE *arquivo;
	CONTATO ctt;
	arquivo = fopen("agenda.bin", "rb");
	if(arquivo == NULL)
	   printf("Erro no arquivo");
	else
	{
		system("cls");
		while(fread(&ctt, sizeof(CONTATO), 1, arquivo) == 1)
		{
			printf("\nNome %s",ctt.nome);
			printf("\nTelefone %s", ctt.fone);
			printf("\nE-mail %s", ctt.email);
			printf("\nAniversario %d/%d/%d", ctt.aniv.d, ctt.aniv.m, ctt.aniv.a);
			printf("\n_________________________");
			printf("\n");
		}
	} 
	fclose(arquivo);
	system("pause");
	system("cls");  
}
void alterar(){
	CONTATO ctt;
	int pos, op;
	FILE *arquivo;
	arquivo = fopen("agenda.bin", "rb+");
	system("cls");
	printf("+++++++Alteracao pelo NOME+++++++\n");
	printf("Alterar dados no nome: ");
	fflush(stdin);
	gets(ctt.nome);
	while(stricmp(ctt.nome, "") != 0){
		pos = busca(arquivo, ctt.nome);
		if(pos == -1)
			printf("\n Nao cadastrado!");
		else{
			fseek(arquivo, pos, 0);
			fread(&ctt, sizeof(CONTATO), 1, arquivo);
			printf("__________________");
			printf("\nNome: %s", ctt.nome);
			printf("\nFone: %s\n", ctt.fone);
			printf("__________________");
			printf("\n Deseja alterar: \n1 - Fone \n2 - E-mail\n");
			scanf("%d", &op);
			if(op == 1){
				printf("\n NOVO telefone: ");
				fflush(stdin);
				gets(ctt.fone);
				fseek(arquivo, pos, 0);
				fwrite(&ctt, sizeof(CONTATO), 1, arquivo);
				printf("Registro Atualizado!\n");
				system("cls");
				system("pause");
			}
			if(op == 2){
				printf("\n E-mail NOVO: ");
				fflush(stdin);
				gets(ctt.email);
				fseek(arquivo, pos, 0);
				fwrite(&ctt, sizeof(CONTATO), 1, arquivo);
				printf("Registro Atualizado!\n");
				system("cls");
				system("pause");
			}
		}
	getch();
	printf("\n Qual nome para alterar dados? ");
	fflush(stdin);
	gets(ctt.nome);		
	}	
	fclose(arquivo);
}
void excluir()
{
	FILE *arquivo, *temp;
	CONTATO ctt;
	int pos;
	char nome[60];
	arquivo = fopen("agenda.bin", "rb");
	if(arquivo == NULL)
	  printf("Erro no arquivo");
    system("cls");
	printf("Informe o nome do contato a excluir: "); fflush(stdin);
	gets(nome);
	pos = busca(arquivo,nome);
	if(pos == -1)	  
	  printf("Contato nao encontrado!\n");
	else
	{
		fseek(arquivo, pos, 0);
		fread(&ctt, sizeof(CONTATO), 1, arquivo);
		printf("\nNome: %s", ctt.nome);
		printf("\nTelefone: %s", ctt.fone);
		printf("\nE-mail: %s", ctt.email);
		printf("\nAniversario: %d/%d/%d", ctt.aniv.d, ctt.aniv.m, ctt.aniv.a);
		printf("\n-------------------");
		printf("\nDeseja excluir? S/N");
		if(toupper(getche()) == 'S')
		{
		   temp = fopen("auxiliar.bin", "wb");
		   rewind(arquivo);
		   while(fread(&ctt, sizeof(CONTATO), 1, arquivo) == 1)
		   if(strcmp(ctt.nome, nome) != 0)
		     fwrite(&ctt, sizeof(CONTATO), 1, temp);
		}
	} 
	fclose(temp);
	fclose(arquivo);
	remove("agenda.bin");
	rename("auxiliar.bin", "agenda.bin");
	printf("\nO contato foi excluido com sucesso. <ENTER para voltar ao menu");
	getchar(); // system("pause");
	system("cls");
}
main()
{
	int op;
	do
	{
		op = menu();
		switch(op)
		{
			case 1:
				inserir();
			    break;
			case 2:
				exibir();
			    break;
		    case 3:
				alterar();		      
		        break;
		    case 4:
				excluir();     
		        break;
		    case 5:
				printf("\nEncerrando a agenda...");
			    break;
		    default:
				printf("\nOpcao invalida!");		      
		}
	}while(op!=5);
}

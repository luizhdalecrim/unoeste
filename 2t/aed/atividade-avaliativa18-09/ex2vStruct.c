#include <stdio.h>

typedef struct Ambiente {
        float largura;
	float comprimento;
	float area;
	int tipo;
	int btu;
} amb;

float CalculaArea(amb *amb);
float CalculaBTU(amb *amb);

int main(void)
{
        amb *amb;

        float area;
        int btu;

        int opcao;
	do
	{
		printf("\n-- Ambiente: Calculo de area --");
		printf("\nComprimento -> ");
		scanf("%f", &amb->comprimento);
		printf("\nLargura -> ");
		scanf("%f", &amb->largura);
		
		amb->area = CalculaArea(amb);
		
		printf("%.2f", amb->area);
		
		printf("\n-- Ambiente: Calculo de BTU --");
		printf("\nTipo -> ");
		scanf("%d", &amb->tipo);
		
		amb->btu = CalculaBTU(amb);
		
		printf("BTU: %d", amb->btu);
		
		printf("\nContinuar? (Sim: 1; Nao: 0) -> ");
		scanf("%d", &opcao);
		
	} while(opcao != 0);
	
	return 0;
}

float CalculaArea(amb *amb)
{
	amb->area = amb->largura * amb->comprimento;
	
	return amb->area;
}

float CalculaBTU(amb *amb)
{
        int btupm2 = 0;

	switch(amb->tipo)
	{
		case 0:
			btupm2 = 600;
			break;
		case 1:
			btupm2 = 700;
			break;
		case 2:
			btupm2 = 750;
			break;
	}
	
	amb->btu = amb->area * btupm2;

        return amb->btu;
}

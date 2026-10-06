#include <stdio.h>

float CalculaArea(float largura, float comprimento);
float CalculaBTU(float area, int tipo);

int main(void)
{
	float largura;
	float comprimento;
	float area;
	int tipo;
	int btu;

	int opcao;
	
	do
	{
		printf("\n-- Ambiente: Calculo de area --");
		printf("\nComprimento -> ");
		scanf("%f", &comprimento);
		printf("\nLargura -> ");
		scanf("%f", &largura);
		
		area = CalculaArea(largura, comprimento);
		
		printf("%.2f", area);
		
		printf("\n-- Ambiente: Calculo de BTU --");
		printf("\nTipo -> ");
		scanf("%d", &tipo);
		
		btu = CalculaBTU(area, tipo);
		
		printf("BTU: %d", btu);
		
		printf("\nContinuar? (Sim: 1; Nao: 0) -> ");
		scanf("%d", &opcao);
		
	} while(opcao != 0);
	
	return 0;
}

float CalculaArea(float largura, float comprimento)
{
        float area;

	area = largura * comprimento;
	
	return area;
}

float CalculaBTU(float area, int tipo)
{
        int btupm2 = 0;
        int btu;

	switch(tipo)
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
	
	btu = area * btupm2;

        return btu;
}

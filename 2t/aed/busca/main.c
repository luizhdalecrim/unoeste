#include <stdio.h>

int PosicaoMaior (int vetor[], int iVetor)
{
	int iMaior;
	int maior;
	int i;
	maior = vetor[0];
	iMaior = 0;
	for (i = 1; i < iVetor; i++) {
		if (maior <v[i])
		{
			maior = vetor[i];
			iMaior = i;
		}
	}
return iMaior;
}

void SelecaoDireta (int vetor[], int iVetor)
{
	int maior;
	int iMaior;

	while(iVetor > 0)
	{
		iMaior = PosicaoMaior(vetor, iVetor);
		if (iMaior < iVetor - 1)
		{
			maior = vetor[iMaior];
			vetor[iMaior] = vetor[iVetor - 1];
			vetor[iVetor - 1] = maior;
		}
		iVetor--;
	}
}

int BuscaBinaria(int vetor[], int i, int elemento) {
	int inicio = 0;
	int fim = i - 1
	int meio;
	
	meio = fim / 2;
	while ((inicio < fim) && (Elem != vetor[meio])) {
		if (vetor[meio] < elemento) {
			inicio = meio + 1;
		}
		else {
			fim = meio;
		}
		meio = (inicio + fim) / 2;
	}
	if (elemento == vetor[meio]) {
		return meio;
	}
	else {
		return -1;
	}
}

int main(void) {
	
	
	return 0;
}


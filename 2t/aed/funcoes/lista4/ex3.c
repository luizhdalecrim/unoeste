#include <stdio.h>

float calculaConsumoKWh(float potenciaWatts, float tempoHoras);

int main(void) {
    float potencia, tempo, consumo;

    printf("Digite a potencia em watts: ");
    scanf("%f", &potencia);

    printf("Digite o tempo de uso em horas: ");
    scanf("%f", &tempo);

    consumo = calculaConsumoKWh(potencia, tempo);

    printf("Consumo: %.3f kWh\n", consumo);

    return 0;
}

float calculaConsumoKWh(float potenciaWatts, float tempoHoras) {
    float consumoKWh;
    consumoKWh = (potenciaWatts * tempoHoras) / 1000;
    return consumoKWh;
}

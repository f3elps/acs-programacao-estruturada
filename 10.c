#include <stdio.h>

int main() {
    const char *dias[] = {"Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sábado"};
    float faturamento[7];
    float total = 0.0;
    float media = 0.0;
    float maior_faturamento = 0.0;
    int dia_maior = 0;
    int dias_acima_1000 = 0;
    int dias_abaixo_1000 = 0;

    for (int i = 0; i < 7; i++) {
        printf("Digite o faturamento de %s: ", dias[i]);
        scanf("%f", &faturamento[i]);

        total += faturamento[i];

        if (i == 0 || faturamento[i] > maior_faturamento) {
            maior_faturamento = faturamento[i];
            dia_maior = i;
        }

        if (faturamento[i] > 1000.00) {
            dias_acima_1000++;
        } else if (faturamento[i] < 1000.00) {
            dias_abaixo_1000++;
        }
    }

    media = total / 7.0;

    printf("\n--- RESULTADOS DA SEMANA ---\n");
    printf("Total arrecadado: R$ %.2f\n", total);
    printf("Média diária de faturamento: R$ %.2f\n", media);
    printf("Maior faturamento: R$ %.2f\n", maior_faturamento);
    printf("Dia do maior faturamento: %s\n", dias[dia_maior]);
    printf("Dias com faturamento acima de 1000.00: %d\n", dias_acima_1000);
    printf("Dias com faturamento abaixo de 1000.00: %d\n", dias_abaixo_1000);

    if (media >= 1000.00) {
        printf("Classificação: Semana Boa\n");
    } else {
        printf("Classificação: Semana Ruim\n");
    }

    return 0;
}

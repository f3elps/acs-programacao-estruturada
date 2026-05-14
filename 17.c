#include <stdio.h>

#define STR_LEN 50

int main() {
  int quantidade_veiculos;
  float kms_percorridos[STR_LEN];
  float litros_consumidos_semana[STR_LEN];
  float consumo_medio[STR_LEN];
  int maior_consumo_indice;
  int menor_consumo_indice;

  float menor_consumo = 100000;
  float maior_consumo = 0;

  printf("Digite a quantidade de veículos a serem cadastrados: ");
  scanf("%d", &quantidade_veiculos);

  getchar();

  char modelo[quantidade_veiculos][STR_LEN];

  for (int i = 0; i < quantidade_veiculos; i++) {
    printf("Digite o modelo do veículo %d: ", i + 1);
    fgets(modelo[i], STR_LEN, stdin);

    printf("Digite a quantidade de quilômetros percorridos pelo veículo %d: ",
           i + 1);
    scanf("%f", &kms_percorridos[i]);

    printf("Digite a quantidade de litros consumidos pelo veículo %d: ", i + 1);
    scanf("%f", &litros_consumidos_semana[i]);

    consumo_medio[i] = kms_percorridos[i] / litros_consumidos_semana[i];
    if (consumo_medio[i] < menor_consumo) {
      menor_consumo = consumo_medio[i];
      menor_consumo_indice = i;
    }
    if (consumo_medio[i] > maior_consumo) {
      maior_consumo = consumo_medio[i];
      maior_consumo_indice = i;
    }

    getchar();
  }

  printf("RELATÓRIO DE CONSUMO DA FROTA");
  for (int i = 0; i < quantidade_veiculos; i++) {
    printf("\nVeículo: %s", modelo[i]);
    printf("\nKm percorridos: %.2f", kms_percorridos[i]);
    printf("\nLitros consumidos: %.2f", litros_consumidos_semana[i]);
    printf("\nConsumo médio: %.2f km/l\n", consumo_medio[i]);
  }
  printf("\nVeículo mais econômico: %s", modelo[menor_consumo_indice]);
  printf("\nConsumo médio: %.2f km/l", menor_consumo);
  printf("\nVeículo menos econômico: %s", modelo[maior_consumo_indice]);
  printf("\nConsumo médio: %.2f km/l", maior_consumo);
}

#include <stdio.h>

#define SEMANA 7

char *getClassificacao(float temperatura) {
  if (temperatura < 15) {
    return "Frio";
  } else if (temperatura >= 15 && temperatura <= 30) {
    return "Agradavel";
  } else {
    return "Quente";
  }
}

int main() {
  char *dias[SEMANA] = {"Domingo", "Segunda", "Terca", "Quarta",
                        "Quinta",  "Sexta",   "Sabado"};
  float maiorTemperatura;
  float menorTemperatura;
  int diaMaiorTemperatura;
  int diaMenorTemperatura;
  float totalTemperaturas = 0;
  float mediaTemperaturas;

  float temperaturas[SEMANA];

  for (int i = 0; i < SEMANA; i++) {
    printf("Digite a temperatura do dia %d: ", i + 1);
    scanf("%f", &temperaturas[i]);

    if (i == 0) {
      maiorTemperatura = temperaturas[i];
      menorTemperatura = temperaturas[i];
      diaMaiorTemperatura = i + 1;
      diaMenorTemperatura = i + 1;
    } else {
      if (temperaturas[i] > maiorTemperatura) {
        maiorTemperatura = temperaturas[i];
        diaMaiorTemperatura = i + 1;
      }
      if (temperaturas[i] < menorTemperatura) {
        menorTemperatura = temperaturas[i];
        diaMenorTemperatura = i + 1;
      }
    }
    totalTemperaturas += temperaturas[i];
  }

  mediaTemperaturas = totalTemperaturas / SEMANA;

  printf("Media semanal: %.2f\n", mediaTemperaturas);
  printf("Maior temperatura: %.2f (%s)\n", maiorTemperatura,
         dias[diaMaiorTemperatura - 1]);
  printf("Menor temperatura: %.2f (%s)\n", menorTemperatura,
         dias[diaMenorTemperatura - 1]);

  int diasAcimaMedia = 0;
  for (int i = 0; i < SEMANA; i++) {
    if (temperaturas[i] > mediaTemperaturas) {
      diasAcimaMedia++;
    }
  }
  printf("Dias acima da media: %d\n\n\n", diasAcimaMedia);

  printf("Classificação por dia: \n");
  for (int i = 0; i < SEMANA; i++) {
    char *classificacao = getClassificacao(temperaturas[i]);
    printf("%s: %.2f °C - %s\n", dias[i], temperaturas[i], classificacao);
  }

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, flag = 0;

  do {
    printf("Digite um número: ");
    scanf("%d", &n);

    if (n % 2 != 0) {
      printf("O número é par");
    } else {
      printf("O número é ímpar");
    }

    printf("Deseja continuar?\n1 - Sim\n0 - Não\n-> ");
    scanf("%d", &flag);

  } while (flag != 1);

  return 0;
}
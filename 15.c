#include <stdio.h>

#define NUM_ALUNOS 5
#define NUM_AVALIACOES 3

int main() {
  // Linhas: Alunos, Colunas: Notas
  int notas[NUM_ALUNOS][NUM_AVALIACOES];
  float media[NUM_ALUNOS];

  for (int i = 0; i < NUM_ALUNOS; i++) {
    float soma_notas = 0;
    printf("Notas do aluno %d\n\n", i + 1);
    for (int j = 0; j < NUM_AVALIACOES; j++) {
      printf("Avaliacao %d: ", j + 1);
      scanf("%d", &notas[i][j]);
      soma_notas += notas[i][j];
    }
    media[i] = soma_notas / NUM_AVALIACOES;
    printf("Media do aluno %d: %.2f\n", i + 1, media[i]);
    printf("\n");
  }

  return 0;
}
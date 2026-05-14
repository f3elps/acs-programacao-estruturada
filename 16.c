#include <stdio.h>

#define NUM_ALUNOS 5
#define MAX_TAMANHO_NOME 100
#define NUM_PROVAS 3

int main() {

  char nome[NUM_ALUNOS][MAX_TAMANHO_NOME];
  float pesos[NUM_PROVAS] = {0.4, 0.3, 0.3};
  float notas[NUM_ALUNOS][3];

  // I = Aluno, J = Prova
  for (int i = 0; i < NUM_ALUNOS; i++) {
    printf("Digite o nome do aluno %d: ", i + 1);
    fgets(nome[i], MAX_TAMANHO_NOME, stdin);

    for (int j = 0; j < NUM_PROVAS; j++) {
      printf("Digite a nota da prova %d: ", j + 1);
      scanf("%f", &notas[i][j]);
      notas[i][j] = notas[i][j] * pesos[j];
    }
    // Consome o \n deixado no buffer pelo scanf para não pular o fgets na próxima iteração
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
  }

  for (int i = 0; i < NUM_ALUNOS; i++) {
    float media = (notas[i][0] + notas[i][1] + notas[i][2]); // Notas já foram multiplicadas pelos pesos

    printf("Aluno: %s\n", nome[i]);
    printf("Notas: %.2f, %.2f, %.2f\n", notas[i][0], notas[i][1], notas[i][2]);
    printf("Media: %.2f\n", media);
    if (media >= 7) {
      printf("Situação: Aprovado\n");
    } else {
      printf("Situação: Reprovado\n");
    }
    printf("\n");
  }

  return 0;
}
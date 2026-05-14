#include <stdio.h>

int main() {
    char nome[50];
    char disciplina[70];
    float nota_p1, nota_p2, nota_ac, media;
    int faltas;

    printf("Digite o nome do aluno: ");
    scanf(" %49[^\n]", nome);

    printf("Digite o nome da disciplina: ");
    scanf(" %69[^\n]", disciplina);

    printf("Digite a nota da prova 1: ");
    scanf("%f", &nota_p1);

    printf("Digite a nota da prova 2: ");
    scanf("%f", &nota_p2);

    printf("Digite a nota de atividade complementar: ");
    scanf("%f", &nota_ac);

    printf("Digite a quantidade de faltas: ");
    scanf("%d", &faltas);

    media = (nota_p1 * 4 + nota_p2 * 4 + nota_ac * 2) / 10.0;

    printf("\n##### NOTAS DO ALUNO #####\n");
    printf("Nome: %s\n", nome);
    printf("Disciplina: %s\n", disciplina);
    printf("Nota AP1: %.1f\n", nota_p1);
    printf("Nota AP2: %.1f\n", nota_p2);
    printf("Nota AC: %.1f\n", nota_ac);
    printf("Faltas: %d\n", faltas);
    printf("Média Final: %.2f\n", media);

    printf("Situação: ");
    if (media >= 7.0 && faltas <= 20) {
        printf("APROVADO!\n");
    } else {
        printf("REPROVADO!\n");
    }

    printf("Conceito: ");
    if (media >= 9.0) {
        printf("A\n");
    } else if (media >= 7.0) {
        printf("B\n");
    } else if (media >= 5.0) {
        printf("C\n");
    } else if (media >= 3.0) {
        printf("D\n");
    } else {
        printf("E\n");
    }

    return 0;
}

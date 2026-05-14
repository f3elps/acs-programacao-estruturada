#include <stdio.h>

int main () {
    char nome_aluno[50];
    char nome_disciplina[70];
    float nota_prova1;
    float nota_prova2;
    float nota_ativ_complementar;

    printf("Digite o seu nome: ");
    fgets(nome_aluno, 50, stdin);

    printf("Digite o nome da disciplina: ");
    fgets(nome_disciplina, 50, stdin);

    printf("Digite a nota da prova 1: ");
    scanf("%f", &nota_prova1);

    printf("Digite a nota da prova 2: ");
    scanf("%f", &nota_prova2);

    printf("Digite a nota da atividade complementar: ");
    scanf("%f", &nota_ativ_complementar);

    printf("##### NOTAS DO ALUNO #####​\n");
    printf("Nome: %s\n", nome_aluno);
    printf("Disciplina: %s\n", nome_disciplina);
    printf("Nota AP1: %.2f\n", nota_prova1);
    printf("Nota AP2: %.2f\n", nota_prova2);
    printf("Nota AC: %.2f\n", nota_ativ_complementar);

    return 0;
}
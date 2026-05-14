#include <stdio.h>

int arredonda_media(float media) {
    int valor_inteiro = (int) media;
    if (media - valor_inteiro >= 0.5) {
        media = valor_inteiro + 1;
    } else {
        media = valor_inteiro;
    }
    return media;
}

int main () {
    char nome_aluno[50];
    char nome_disciplina[70];
    float nota_prova1;
    float nota_prova2;
    float nota_ativ_complementar;

    int peso_prova1 = 4;
    int peso_prova2 = 4;
    int peso_complementar = 2;

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

    float media = (nota_prova1 * peso_prova1 + nota_prova2 * peso_prova2 + nota_ativ_complementar * peso_complementar) / (peso_prova1 + peso_prova2 + peso_complementar);
    float media_arredondada = arredonda_media(media);
    
    printf("##### NOTAS DO ALUNO #####​\n");
    printf("Nome: %s\n", nome_aluno);
    printf("Disciplina: %s\n", nome_disciplina);
    printf("Nota AP1: %.1f\n", nota_prova1);
    printf("Nota AP2: %.1f\n", nota_prova2);
    printf("Nota AC: %.1f\n", nota_ativ_complementar);
    printf("Média Final: %.2f\n", media);
    printf("Média Final arredondada: %.2f\n", media_arredondada);

    return 0;
}
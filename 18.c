#include <stdio.h>
#include <string.h>
#include <math.h>


float calculaJurosSimples(float capital_inicial, float tempo, float taxa) {
    return capital_inicial * (1 + taxa * tempo);
}

float calculaJurosCompostos(float capital_inicial, float tempo, float taxa) {
    return capital_inicial * pow((1 + taxa), tempo);
}

int main () {
    int escolha;

    do {
        printf("\nEscolha uma opcao (digite apenas o número da opção):");
        printf("\n1. Calcular Juros Simples");
        printf("\n2. Calcular Juros Compostos");
        printf("\n3. Encerrar o programa");
        printf("\nOpção: ");
        
        if (scanf("%d", &escolha) != 1) {
            // Se a entrada não for um número, limpa o buffer e continua
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Opção inválida! Por favor, digite um número.\n");
            continue;
        }

        // Limpa o buffer do teclado após ler a opção para o fgets subsequente
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        if (escolha == 3) {
            printf("Saindo...\n");
            break;
        }

        if (escolha != 1 && escolha != 2) {
            printf("Opção inválida!\n");
            continue;
        }

        float montante, tempo, taxa, capital_inicial;
        char nome[50];

        printf("Digite o nome do cliente: ");
        fgets(nome, 50, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        printf("Digite o capital inicial (R$): ");
        scanf("%f", &capital_inicial);

        printf("Digite o tempo (meses): ");
        scanf("%f", &tempo);

        printf("Digite a taxa de juros (%% ao mes, ex: 0.05 para 5%%): ");
        scanf("%f", &taxa);

        if (escolha == 1) {
            montante = calculaJurosSimples(capital_inicial, tempo, taxa);
        } else {
            montante = calculaJurosCompostos(capital_inicial, tempo, taxa);
        }

        printf("\n##### RELATÓRIO FINANCEIRO #####\n");
        printf("Cliente: %s\n", nome);
        printf("Tipo de cálculo: %s\n", escolha == 1 ? "Juros Simples" : "Juros Compostos");
        printf("Capital inicial: R$ %.2f\n", capital_inicial);
        printf("Taxa de juros: %.2f%%\n", taxa * 100);
        printf("Tempo: %.2f meses\n", tempo);
        printf("Montante final: R$ %.2f\n", montante);
        printf("Total de juros: R$ %.2f\n", montante - capital_inicial);
        printf("################################\n");

    } while (escolha != 3);

    return 0;
}

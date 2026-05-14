#include <stdio.h>

int main() {
    int senha_correta = 123;
    int senha_digitada;
    int tentativas = 1;
    int max_tentativas = 3;

    while (tentativas <= max_tentativas) {
        printf("Digite a senha de 3 dígitos (Tentativa %d de %d): ", tentativas, max_tentativas);
        scanf("%d", &senha_digitada);

        if (senha_digitada == senha_correta) {
            printf("Senha correta! Acesso permitido.\n");
            return 0;
        } else {
            printf("Senha incorreta.\n");
            tentativas++;
        }
    }

    printf("Acesso bloqueado! Você excedeu o limite de %d tentativas.\n", max_tentativas);

    return 0;
}

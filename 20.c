#include <math.h>
#include <stdio.h>
#include <string.h>

void registrar_transacao(char *tipo, float valor, float saldo_atualizado) {
  FILE *extrato = fopen("extrato.txt", "a+");

  if (extrato == NULL) {
    printf("Erro ao abrir o arquivo!");
    return;
  } else {
    fprintf(extrato, "%s | %.2f | %.2f\n", tipo, valor, saldo_atualizado);
    fclose(extrato);
    printf("Transação registrada!");
  }
}

void depositar(float *saldo) {
  float valor;
  printf("Valor a ser depositado: ");
  scanf("%f", &valor);
  *saldo += valor;
  registrar_transacao("Deposito", valor, *saldo);
  printf("Deposito concluido!\nValor Depositado: %.2f\nSaldo final: R$ %.2f\n",
         valor, *saldo);
  return;
}

void sacar(float *saldo) {
  float valor;
  printf("Valor a ser sacado: ");
  scanf("%f", &valor);

  if (valor > *saldo) {
    printf("Saldo insuficiente!\n");
  } else {
    *saldo -= valor;
    registrar_transacao("Saque", valor, *saldo);
    printf(
        "Saque realizado com sucesso!\nValor sacado: %.2f\nSaldo final: %.2f\n",
        valor, *saldo);
  }
  return;
}

void transferir(float *saldo) {
  float valor_sem_taxa;
  printf("Digite o valor a ser transferido: ");
  scanf("%f", &valor_sem_taxa);
  int tipo_de_transferencia;
  int num_conta;

  printf("Digite o número da conta que irá receber a transferência: ");
  scanf("%d", &num_conta);

  do {
    printf("\nTipo de Transferência:");
    printf("\n1. PIX: sem taxa, com limite máximo de R$ 500,00 por transação.");
    printf("\n2. DOC: taxa de R$ 5,00, limite máximo de R$ 4.999,99.");
    printf("\n3. TED: taxa de R$ 10,50, sem limite de valor.");
    printf("\n4. Sair");
    printf("\nOpção: ");
    scanf("%d", &tipo_de_transferencia);

    switch (tipo_de_transferencia) {
    case 1:
      if (valor_sem_taxa > 500) {
        printf("Limite de R$ 500,00 excedido!\n");
      } else if (valor_sem_taxa > *saldo) {
        printf("Saldo insuficiente!\n");
      } else {
        *saldo -= valor_sem_taxa;
        registrar_transacao("Transferencia PIX", valor_sem_taxa, *saldo);
        printf("Transferência concluida!\nNumero da conta destino: %d\nValor "
               "transferido: R$ %.2f\nSaldo final: R$ %.2f\n",
               num_conta, valor_sem_taxa, *saldo);
        return;
      }
      break;
    case 2:
      if (valor_sem_taxa > 4999.99) {
        printf("Limite de R$ 4.999,99 excedido!\n");
      } else if (valor_sem_taxa + 5.00 > *saldo) {
        printf("Saldo insuficiente para cobrir o valor e a taxa de R$ 5,00!\n");
      } else {
        *saldo -= valor_sem_taxa + 5.00;
        registrar_transacao("Transferencia DOC", valor_sem_taxa + 5.00, *saldo);
        printf("Transferência concluida!\nNumero da conta destino: %d\nValor "
               "transferido: R$ %.2f\nSaldo final: R$ %.2f\n",
               num_conta, valor_sem_taxa + 5, *saldo);
        return;
      }
      break;
    case 3:
      if (valor_sem_taxa + 10.50 > *saldo) {
        printf(
            "Saldo insuficiente para cobrir o valor e a taxa de R$ 10,50!\n");
      } else {
        *saldo -= valor_sem_taxa + 10.50;
        registrar_transacao("Transferencia TED", valor_sem_taxa + 10.50,
                            *saldo);
        printf("Transferência concluida!\nNumero da conta destino: %d\nValor "
               "transferido: R$ %.2f\nSaldo final: R$ %.2f\n",
               num_conta, valor_sem_taxa + 10.50, *saldo);
        return;
      }
      break;
    case 4:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida!\n");
    }
  } while (tipo_de_transferencia != 4);

  return;
}

int main() {
  char nome[50] = "David Lynch";
  char senha_correta[50] = "8a2M5-1@";
  char senha_inserida[50];

  for (int i = 0; i < 3; i++) {
    printf("Digite a senha: ");
    fgets(senha_inserida, 50, stdin);
    senha_inserida[strcspn(senha_inserida, "\n")] = '\0';

    if (strcmp(senha_inserida, senha_correta) == 0) {
      printf("Senha correta!\n");
      break;
    }

    printf("Senha incorreta! Tentativa: %d\n", i + 1);

    if (i == 2) {
      printf("Limite de tentativas atingido. Conta bloqueada.");
      return 1;
    }
  }

  int escolha;
  float valor;

  do {
    FILE *extrato = fopen("extrato.txt", "r");
    float saldo;

    if (extrato == NULL) {
      // Arquivo não existe, criar ele e popular com saldo inicial
      extrato = fopen("extrato.txt", "w");
      fprintf(extrato, "Saldo inicial | 7000.00 | 7000.00");
      fclose(extrato);
      saldo = 7000;
    } else {
      char tipo_operacao[50];
      float valor_transacao;

      // Se o arquivo existir, lê ele e considera o saldo atual como o último
      // saldo registrado
      while (fscanf(extrato, "%s | %f | %f", tipo_operacao, &valor_transacao,
                    &saldo) != EOF)
        ;
    }

    printf("Bem vindo %s! Saldo atual: R$ %.2f\n", nome, saldo);
    printf("\n1. Depositar\n2. Sacar\n3. Transferir\n4. Exibir saldo\n5. "
           "Sair\nOpção: ");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      depositar(&saldo);
      break;
    case 2:
      sacar(&saldo);
      break;
    case 3:
      transferir(&saldo);
      break;
    case 4:
      printf("Saldo atual: R$ %.2f\n", saldo);
      break;
    case 5:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida!\n");
    }
  } while (escolha != 5);
}
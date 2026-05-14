#include <stdio.h>

int main() {
  float saldo_origem = 3000;
  float saldo_destino = 2300;
  int senha_correta = 8251;
  int tentativas = 3;
  int senha;

  for (int i = 0; i < tentativas; i++) {
    printf("Digite a senha: ");
    scanf("%d", &senha);
    if (senha == senha_correta) {
      break;
    } else {
      if (i == 2) {
        printf("Acesso bloqueado!");
        return 0;
      }
      printf("Senha incorreta. Tentativas restantes: %d\n", tentativas - i - 1);
    }
  }

  float saldo_origem_inicial = saldo_origem;
  float saldo_destino_inicial = saldo_destino;
  int tipo_transferencia;
  float valor_transferencia;
  float taxa = 0.0;
  float limite = -1.0;
  int realizada = 0;
  
  printf("\nEscolha o tipo de transferencia:\n");
  printf("1 - PIX (sem taxa, limite R$ 500.00)\n");
  printf("2 - DOC (taxa R$ 5.00, limite R$ 4999.99)\n");
  printf("3 - TED (taxa R$ 10.50, sem limite)\n");
  printf("Opcao: ");
  scanf("%d", &tipo_transferencia);
  
  printf("Informe o valor da transferencia: ");
  scanf("%f", &valor_transferencia);

  if (tipo_transferencia == 1) {
    taxa = 0.0;
    limite = 500.00;
  } else if (tipo_transferencia == 2) {
    taxa = 5.00;
    limite = 4999.99;
  } else if (tipo_transferencia == 3) {
    taxa = 10.50;
    limite = -1.0;
  } else {
    printf("Tipo de transferencia invalido.\n");
    return 1;
  }

  float valor_total = valor_transferencia + taxa;
  
  if ((limite == -1.0 || valor_transferencia <= limite) && saldo_origem >= valor_total && valor_transferencia > 0) {
    saldo_origem -= valor_total;
    saldo_destino += valor_transferencia;
    realizada = 1;
  }
  
  printf("\n--- Relatorio Final ---\n");
  printf("Saldo inicial da conta de origem: R$ %.2f\n", saldo_origem_inicial);
  printf("Saldo inicial da conta de destino: R$ %.2f\n", saldo_destino_inicial);
  
  printf("Tipo de transferencia escolhido: ");
  if (tipo_transferencia == 1) printf("PIX\n");
  else if (tipo_transferencia == 2) printf("DOC\n");
  else if (tipo_transferencia == 3) printf("TED\n");
  
  if (taxa > 0) {
    printf("Valor da taxa: R$ %.2f\n", taxa);
  } else {
    printf("Valor da taxa: Isento\n");
  }
  
  printf("Valor da transferencia: R$ %.2f\n", valor_transferencia);
  
  if (realizada) {
    printf("Resultado da operacao: Realizada com sucesso.\n");
  } else {
    printf("Resultado da operacao: Negada.\n");
  }
  
  printf("Saldo final da conta de origem: R$ %.2f\n", saldo_origem);
  printf("Saldo final da conta de destino: R$ %.2f\n", saldo_destino);
  
  return 0;
}
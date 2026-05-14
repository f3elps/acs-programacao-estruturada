#include <stdio.h>

// Nome: Felipe Lara Alves Braga
// Curso: Engenharia de Software
// Data de criação do programa: 07/04/2026

int main() {
    char nome_produto[50] = "Notebook";
    char marca_produto[50] = "Lenovo";
    float preco_produto = 2499.99;
    int quantidade_estoque = 200;

    printf("##### DADOS DO PRODUTO #####\n")
    printf("Nome do produto: %s\n", nome_produto);
    printf("Marca do produto: %s\n", marca_produto);
    printf("Preço do produto: R$ %.2f\n", preco_produto);
    printf("Quantidade em estoque: %d\n", quantidade_estoque);

    return 0;
}
#include <stdio.h>

typedef struct Cilindro {
    float altura;
    float raio;
    float volume;
    float area;
};


int main () {
    struct Cilindro a;

    printf("Digite o raio do cilindro: ");
    scanf("%f", &a.raio);

    printf("Digite a altura do cilindro: ");
    scanf("%f", &a.altura);

    a.volume = 3.14159 * a.raio * a.raio * a.altura;
    a.area = 2 * 3.14159 * a.raio * a.altura + 2 * 3.14159 * a.raio * a.raio;

    printf("##### CILINDRO #####​");
    printf("Raio: %.2f\n", a.raio);
    printf("Altura: %.2f\n", a.altura);
    printf("Area: %.2f\n", a.area);
    printf("Volume: %.2f\n", a.volume);

    return 0;
}
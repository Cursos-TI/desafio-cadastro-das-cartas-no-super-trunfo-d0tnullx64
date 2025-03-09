#include <stdio.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;
    char codigo_carta[4];
    char nome_cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos;
    float densidade;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para entrada de dados de uma carta
void entrada(Carta *c) {
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &c->estado);

    printf("Digite o código da Carta (%c01-%c04): ", c->estado, c->estado);
    scanf("%3s", c->codigo_carta);

    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", c->nome_cidade);

    printf("Digite a População: ");
    scanf("%lu", &c->populacao);

    printf("Digite a Área (km²): ");
    scanf("%f", &c->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &c->pib);

    printf("Digite o número de Pontos Turísticos: ");
    scanf("%d", &c->pontos);
}

// Função para calcular densidade populacional, PIB per capita e Super Poder
void calcular(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pib_per_capita = c->pib * 1e9 / c->populacao;
    c->super_poder = c->populacao + c->area + c->pib + c->pontos + c->pib_per_capita + (1 / c->densidade);
}

// Função para exibir os dados de uma carta
void saida(Carta c) {
    printf("\nCarta:\n");
    printf("Estado: %c\n", c.estado);
    printf("Código: %s\n", c.codigo_carta);
    printf("Nome da Cidade: %s\n", c.nome_cidade);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de Pontos Turísticos: %d\n", c.pontos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade);
    printf("PIB per Capita: %.2f reais\n", c.pib_per_capita);
    printf("Super Poder: %.2f\n", c.super_poder);
}

// Função para comparar atributos das cartas
void comparar(float v1, float v2, char *atributo, int inverso) {
    int resultado = (inverso) ? (v1 < v2) : (v1 > v2);
    printf("%s: Carta 1 venceu (%d)\n", atributo, resultado);
}

int main() {
    Carta carta1, carta2;

    printf("\nCadastro da Carta 1\n");
    entrada(&carta1);
    calcular(&carta1);

    printf("\nCadastro da Carta 2\n");
    entrada(&carta2);
    calcular(&carta2);

    saida(carta1);
    saida(carta2);

    printf("\nComparação de Cartas:\n");
    comparar(carta1.populacao, carta2.populacao, "População", 0);
    comparar(carta1.area, carta2.area, "Área", 0);
    comparar(carta1.pib, carta2.pib, "PIB", 0);
    comparar(carta1.pontos, carta2.pontos, "Pontos Turísticos", 0);
    comparar(carta1.densidade, carta2.densidade, "Densidade Populacional", 1);
    comparar(carta1.pib_per_capita, carta2.pib_per_capita, "PIB per Capita", 0);
    comparar(carta1.super_poder, carta2.super_poder, "Super Poder", 0);

    return 0;
}

#include <stdio.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;
    char codigo_carta[4];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos;
    float densidade;
    float pib_per_capita;
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
    scanf("%d", &c->populacao);

    printf("Digite a Área (km²): ");
    scanf("%f", &c->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &c->pib);

    printf("Digite o número de Pontos Turísticos: ");
    scanf("%d", &c->pontos);
}

// Função para calcular densidade populacional e PIB per capita
void calcular(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pib_per_capita = c->pib * 1e9 / c->populacao; // PIB convertido para reais
}

// Função para exibir os dados de uma carta
void saida(Carta c) {
    printf("\nCarta:\n");
    printf("Estado: %c\n", c.estado);
    printf("Código: %s\n", c.codigo_carta);
    printf("Nome da Cidade: %s\n", c.nome_cidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de Pontos Turísticos: %d\n", c.pontos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade);
    printf("PIB per Capita: %.2f reais\n", c.pib_per_capita);
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

    return 0;
}

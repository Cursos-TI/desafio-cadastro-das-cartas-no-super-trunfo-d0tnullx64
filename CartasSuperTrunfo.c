#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
int main() {
    // Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.

    char codigo_carta[4];  // Código da carta no formato A01, B02.
    char nome_cidade[50];  // Nome da cidade
    float populacao;
    float area;
    float pib;
    int pontos;

    // Cadastro das Cartas:
    // Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.

    printf("Digite o codigo da Carta: ");
    scanf("%s", codigo_carta);

    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", nome_cidade);

    printf("Digite a Populacao: ");
    scanf("%f", &populacao);

    printf("Digite a Area: ");
    scanf("%f", &area);

    printf("Digite o PIB: ");
    scanf("%f", &pib);

    printf("Digite quantos Pontos Turisticos: ");
    scanf("%d", &pontos);

    // Exibição dos Dados das Cartas:
    // Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    printf("\nDados da Carta Cadastrada\n");

    printf("CODIGO: %s\n", codigo_carta);
    printf("NOME DA CIDADE: %s\n", nome_cidade);
    printf("POPULACAO: %f\n", populacao);
    printf("AREA: %f km²\n", area);
    printf("PIB: %f\n", pib);
    printf("PONTOS TURISTICOS: %d\n", pontos);

    return 0;
}
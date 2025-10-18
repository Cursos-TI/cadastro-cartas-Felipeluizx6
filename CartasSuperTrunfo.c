#include <stdio.h>
#include <string.h>

typedef struct {
    char codigo[4];             // Ex: A01
    char nome[50];              // Nome da cidade
    int populacao;              // População
    float area;                 // Área em km²
    float pib;                  // PIB em bilhões
    int pontosTuristicos;       // Número de pontos turísticos
    float densidadePopulacional;// Densidade populacional
    float pibPerCapita;         // PIB per capita
    float floa;                 // Carta de superpoder (soma ponderada)
} Carta;

// Função para calcular o superpoder da carta (soma dos principais atributos)
float calcularSuperPoder(Carta c) {
    return (c.populacao / 1000.0) + c.area + (c.pib * 10.0) + 
           (c.pibPerCapita / 1000.0) + (1.0 / (c.densidadePopulacional + 1)) +
           (c.pontosTuristicos * 10.0);
}

// Função de comparação entre duas cartas
int compararCartas(Carta c1, Carta c2, int atributo) {
    float valor1 = 0, valor2 = 0;

    switch (atributo) {
        case 1: // População
            valor1 = c1.populacao; valor2 = c2.populacao; break;
        case 2: // Área
            valor1 = c1.area; valor2 = c2.area; break;
        case 3: // PIB
            valor1 = c1.pib; valor2 = c2.pib; break;
        case 4: // PIB per capita
            valor1 = c1.pibPerCapita; valor2 = c2.pibPerCapita; break;
        case 5: // Densidade populacional (menor vence → invertido)
            valor1 = 1.0 / c1.densidadePopulacional;
            valor2 = 1.0 / c2.densidadePopulacional;
            break;
        case 6: // Pontos turísticos
            valor1 = c1.pontosTuristicos; valor2 = c2.pontosTuristicos; break;
        case 7: // Superpoder floa
            valor1 = c1.floa; valor2 = c2.floa; break;
        default:
            printf("Atributo inválido!\n");
            return -1;
    }

    // Retorna 1 se carta 1 venceu, 0 se carta 2 venceu
    return (valor1 > valor2) ? 1 : 0;
}

int main() {
    Carta cartas[8][4]; // 8 estados, 4 cidades cada
    char estados[] = {'A','B','C','D','E','F','G','H'};

    printf("=== Cadastro de cartas - Super Trunfo: Países (Modo Comparação) ===\n");

    // Cadastro das cidades
    for(int i=0; i<8; i++){
        printf("\n--- Estado %c ---\n", estados[i]);
        for(int j=0; j<4; j++){
            Carta *c = &cartas[i][j];
            sprintf(c->codigo, "%c0%d", estados[i], j+1);

            printf("\nCidade %d do estado %c:\n", j+1, estados[i]);
            printf("Nome: ");
            scanf(" %[^\n]", c->nome);

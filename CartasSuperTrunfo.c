#include <stdio.h>
#include <string.h>

typedef struct {
    char codigo[4]; // Ex: A01
    char nome[50]; // Nome da cidade
    int populacao; // População
    float area; // Área em km²
    float pib; // PIB em bilhões
    int pontosTuristicos; // Número de pontos turísticos
} Carta;

int main() {
    Carta cartas[8][4]; // 8 estados, 4 cidades cada

    char estados[] = {'A','B','C','D','E','F','G','H'};

    printf("=== Cadastro de cartas - Super Trunfo: Países (Novato) ===\n");

    // Cadastro das cidades
    for(int i=0; i<8; i++){
        printf("\n--- Estado %c ---\n", estados[i]);
        for(int j=0; j<4; j++){
            Carta *c = &cartas[i][j];
            sprintf(c->codigo, "%c0%d", estados[i], j+1); // Código da carta

            printf("\nCidade %d do estado %c:\n", j+1, estados[i]);
            printf("Nome: ");
            scanf(" %[^\n]", c->nome); // Lê string com espaços

            printf("População: ");
            scanf("%d", &c->populacao);

            printf("Área (km²): ");
            scanf("%f", &c->area);

            printf("PIB (bilhões): ");
            scanf("%f", &c->pib);

            printf("Número de pontos turísticos: ");
            scanf("%d", &c->pontosTuristicos);
        }
    }

    // Exibindo todas as cartas cadastradas
    printf("\n=== Cartas cadastradas ===\n");
    for(int i=0; i<8; i++){
        printf("\n--- Estado %c ---\n", estados[i]);
        for(int j=0; j<4; j++){
            Carta c = cartas[i][j];
            printf("\nCódigo: %s\n", c.codigo);
            printf("Cidade: %s\n", c.nome);
            printf("População: %d\n", c.populacao);
            printf("Área: %.2f km²\n", c.area);
            printf("PIB: %.2f bilhões\n", c.pib);
            printf("Pontos turísticos: %d\n", c.pontosTuristicos);
        }
    }

    return 0;
}
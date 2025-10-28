#include <stdio.h>
#include <string.h>

/*******************************************************
 *        SUPER TRUNFO INTERATIVO - ATUALIZAÇÃO       *
 *  Idealizador: Luiz Felipe Maduro Silva             *
 *  Versão: menu interativo + comparação avançada    *
 *******************************************************/

// Estrutura que representa cada carta
typedef struct {
    char codigo[4];             // Código da carta (ex: A01)
    char nome[50];              // Nome da cidade
    int populacao;              // População
    float area;                 // Área em km²
    float pib;                  // PIB em bilhões
    int pontosTuristicos;       // Número de pontos turísticos
    float densidadePopulacional;// População / Área
    float pibPerCapita;         // PIB / População
    float floa;                 // Superpoder (soma ponderada)
} Carta;

// Função que calcula o superpoder da carta
float calcularSuperPoder(Carta c) {
    return (c.populacao / 1000.0) + c.area + (c.pib * 10.0) + 
           (c.pibPerCapita / 1000.0) + (1.0 / (c.densidadePopulacional + 1)) +
           (c.pontosTuristicos * 10.0);
}

// Função que compara duas cartas e retorna 1 se carta1 vence, 2 se carta2 vence, 0 se empate
int compararAtributo(float valor1, float valor2, int atributo) {
    if(atributo == 5) { // Densidade demográfica: menor vence
        if(valor1 < valor2) return 1;
        else if(valor1 > valor2) return 2;
        else return 0;
    } else { // Outros atributos: maior vence
        if(valor1 > valor2) return 1;
        else if(valor1 < valor2) return 2;
        else return 0;
    }
}

int main() {
    Carta cartas[8][4];
    char estados[] = {'A','B','C','D','E','F','G','H'};

    printf("*******************************************************\n");
    printf("*             CADASTRO DE CARTAS SUPER TRUNFO        *\n");
    printf("*******************************************************\n");

    // Cadastro das cartas
    for(int i=0; i<8; i++){
        printf("\n--- Estado %c ---\n", estados[i]);
        for(int j=0; j<4; j++){
            Carta *c = &cartas[i][j];
            sprintf(c->codigo, "%c0%d", estados[i], j+1);

            printf("\nCidade %d do estado %c:\n", j+1, estados[i]);
            printf("Nome: ");
            scanf(" %[^\n]", c->nome);

            printf("População (habitantes): ");
            scanf("%d", &c->populacao);

            printf("Área (km²): ");
            scanf("%f", &c->area);

            printf("PIB (bilhões): ");
            scanf("%f", &c->pib);

            printf("Número de pontos turísticos: ");
            scanf("%d", &c->pontosTuristicos);

            // Calcula densidade populacional e PIB per capita
            c->densidadePopulacional = c->populacao / c->area;
            c->pibPerCapita = (c->populacao > 0) ? c->pib / c->populacao : 0;

            // Calcula superpoder
            c->floa = calcularSuperPoder(*c);
        }
    }

    /*******************************************************
     *               MENU INTERATIVO PARA COMPARAÇÃO      *
     *******************************************************/
    int estado1, cidade1, estado2, cidade2, atributo;

    printf("\nEscolha a carta 1 - Estado (0-7) e Cidade (0-3): ");
    scanf("%d %d", &estado1, &cidade1);

    printf("Escolha a carta 2 - Estado (0-7) e Cidade (0-3): ");
    scanf("%d %d", &estado2, &cidade2);

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - PIB per capita\n");
    printf("5 - Densidade demográfica\n");
    printf("6 - Pontos turísticos\n");
    printf("7 - Superpoder\n");
    printf("Opção: ");
    scanf("%d", &atributo);

    // Seleção do valor do atributo de cada carta
    float valor1 = 0, valor2 = 0;

    switch(atributo) {
        case 1:
            valor1 = cartas[estado1][cidade1].populacao;
            valor2 = cartas[estado2][cidade2].populacao;
            break;
        case 2:
            valor1 = cartas[estado1][cidade1].area;
            valor2 = cartas[estado2][cidade2].area;
            break;
        case 3:
            valor1 = cartas[estado1][cidade1].pib;
            valor2 = cartas[estado2][cidade2].pib;
            break;
        case 4:
            valor1 = cartas[estado1][cidade1].pibPerCapita;
            valor2 = cartas[estado2][cidade2].pibPerCapita;
            break;
        case 5:
            valor1 = cartas[estado1][cidade1].densidadePopulacional;
            valor2 = cartas[estado2][cidade2].densidadePopulacional;
            break;
        case 6:
            valor1 = cartas[estado1][cidade1].pontosTuristicos;
            valor2 = cartas[estado2][cidade2].pontosTuristicos;
            break;
        case 7:
            valor1 = cartas[estado1][cidade1].floa;
            valor2 = cartas[estado2][cidade2].floa;
            break;
        default:
            printf("Opção inválida!\n");
            return 0;
    }

    // Chama a função para comparar
    int resultado = compararAtributo(valor1, valor2, atributo);

    // Exibe resultados detalhados
    printf("\nCarta 1: %s\n", cartas[estado1][cidade1].nome);
    printf("Carta 2: %s\n", cartas[estado2][cidade2].nome);
    printf("Valor do atributo escolhido: %.2f x %.2f\n", valor1, valor2);

    if(resultado == 1) printf("Resultado: Carta 1 venceu!\n");
    else if(resultado == 2) printf("Resultado: Carta 2 venceu!\n");
    else printf("Empate!\n");

    return 0;
}

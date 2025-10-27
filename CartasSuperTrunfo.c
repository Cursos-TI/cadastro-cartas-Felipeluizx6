#include <stdio.h>

typedef struct {
    char estado[3];
    char codigo[5];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

int main() {
    // --- Cadastro de duas cartas pré-definidas ---
    Carta carta1 = {"SP", "A01", "São Paulo", 12300000, 1521.0, 699.0, 50, 0, 0};
    Carta carta2 = {"RJ", "B01", "Rio de Janeiro", 6000000, 1182.0, 500.0, 30, 0, 0};

    // --- Cálculos automáticos ---
    carta1.densidadePopulacional = carta1.populacao / carta1.area; // Calcula densidade populacional
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao; // Calcula PIB per capita

    carta2.densidadePopulacional = carta2.populacao / carta2.area; // Calcula densidade populacional
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao; // Calcula PIB per capita

    // --- Atributo para comparação definido no código ---
    // 1 - População, 2 - Área, 3 - PIB, 4 - Densidade Populacional, 5 - PIB per capita
    int atributo = 1; // Exemplo: População

    printf("Comparação de cartas (Atributo: ");
    if (atributo == 1) printf("População)\n"); // IF acrescentado para exibir o nome do atributo
    else if (atributo == 2) printf("Área)\n"); // IF-ELSE acrescentado
    else if (atributo == 3) printf("PIB)\n"); // IF-ELSE acrescentado
    else if (atributo == 4) printf("Densidade Populacional)\n"); // IF-ELSE acrescentado
    else if (atributo == 5) printf("PIB per capita)\n"); // IF-ELSE acrescentado

    // --- Exibe os valores das cartas para o atributo escolhido ---
    printf("Carta 1 - %s (%s): ", carta1.nome, carta1.estado);
    if (atributo == 1) printf("%d\n", carta1.populacao); // IF acrescentado
    else if (atributo == 2) printf("%.2f\n", carta1.area); // IF-ELSE acrescentado
    else if (atributo == 3) printf("%.2f\n", carta1.pib); // IF-ELSE acrescentado
    else if (atributo == 4) printf("%.2f\n", carta1.densidadePopulacional); // IF-ELSE acrescentado
    else if (atributo == 5) printf("%.2f\n", carta1.pibPerCapita); // IF-ELSE acrescentado

    printf("Carta 2 - %s (%s): ", carta2.nome, carta2.estado);
    if (atributo == 1) printf("%d\n", carta2.populacao); // IF acrescentado
    else if (atributo == 2) printf("%.2f\n", carta2.area); // IF-ELSE acrescentado
    else if (atributo == 3) printf("%.2f\n", carta2.pib); // IF-ELSE acrescentado
    else if (atributo == 4) printf("%.2f\n", carta2.densidadePopulacional); // IF-ELSE acrescentado
    else if (atributo == 5) printf("%.2f\n", carta2.pibPerCapita); // IF-ELSE acrescentado

    // --- Lógica de comparação com IF e IF-ELSE ---
    int vencedor = 0; // 1 -> carta1 vence, 2 -> carta2 vence, 0 -> empate

    if (atributo == 4) { // IF acrescentado: Densidade Populacional -> menor vence
        if (carta1.densidadePopulacional < carta2.densidadePopulacional) vencedor = 1; // IF interno acrescentado
        else if (carta1.densidadePopulacional > carta2.densidadePopulacional) vencedor = 2; // IF-ELSE interno acrescentado
        else vencedor = 0; // IF-ELSE interno acrescentado: empate
    } else { // IF-ELSE acrescentado: demais atributos -> maior vence
        if (atributo == 1) { // IF acrescentado para população
            if (carta1.populacao > carta2.populacao) vencedor = 1; // IF interno
            else if (carta1.populacao < carta2.populacao) vencedor = 2; // IF-ELSE interno
            else vencedor = 0; // empate
        } 
        else if (atributo == 2) { // IF-ELSE para área
            if (carta1.area > carta2.area) vencedor = 1;
            else if (carta1.area < carta2.area) vencedor = 2;
            else vencedor = 0;
        }
        else if (atributo == 3) { // IF-ELSE para PIB
            if (carta1.pib > carta2.pib) vencedor = 1;
            else if (carta1.pib < carta2.pib) vencedor = 2;
            else vencedor = 0;
        }
        else if (atributo == 5) { // IF-ELSE para PIB per capita
            if (carta1.pibPerCapita > carta2.pibPerCapita) vencedor = 1;
            else if (carta1.pibPerCapita < carta2.pibPerCapita) vencedor = 2;
            else vencedor = 0;
        }
    }

    // --- Exibe o resultado da comparação ---
    if (vencedor == 1) printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome); // IF acrescentado
    else if (vencedor == 2) printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome); // IF-ELSE acrescentado
    else printf("Resultado: Empate!\n"); // IF-ELSE final para empate

    return 0;
}


#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta
typedef struct {
    char estado[50];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
    float pibPerCapita;
} Carta;

// Retorna o valor do atributo selecionado de uma carta
float pegarValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        case 6: return c.pibPerCapita;
        default: return 0.0f;
    }
}

// Exibe todos os dados de uma carta
void exibirCarta(Carta c) {
    printf("\nEstado: %s", c.estado);
    printf("\nCodigo: %s", c.codigo);
    printf("\nCidade: %s", c.cidade);
    printf("\nPopulacao: %d", c.populacao);
    printf("\nArea: %.2f", c.area);
    printf("\nPIB: %.2f", c.pib);
    printf("\nPontos Turisticos: %d", c.pontosTuristicos);
    printf("\nDensidade Demografica: %.2f hab/km2", c.densidadeDemografica);
    printf("\nPIB per Capita: %.6f mil reais\n", c.pibPerCapita);
}

// Mostra o menu de escolha de atributo, ocultando o ja selecionado
void mostrarMenu(int jaSelecionado) {
    printf("\nEscolha o atributo:\n");
    if (jaSelecionado != 1) printf("1 - Populacao\n");
    if (jaSelecionado != 2) printf("2 - Area\n");
    if (jaSelecionado != 3) printf("3 - PIB\n");
    if (jaSelecionado != 4) printf("4 - Pontos Turisticos\n");
    if (jaSelecionado != 5) printf("5 - Densidade Demografica\n");
    if (jaSelecionado != 6) printf("6 - PIB per Capita\n");
}

int main() {
    // --- Cadastro das cartas pré-definidas ---
    Carta carta1 = {"SP", "SP001", "Sao Paulo",       44411238, 248219.485f, 3130.0f, 12};
    Carta carta2 = {"RJ", "RJ001", "Rio de Janeiro",   16055174,  43750.425f, 1150.0f, 8};

    // --- Cálculo de atributos derivados ---
    carta1.densidadeDemografica = carta1.populacao / carta1.area;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;
    carta1.pibPerCapita         = carta1.pib / carta1.populacao;
    carta2.pibPerCapita         = carta2.pib / carta2.populacao;

    // --- Exibição das cartas ---
    printf("=== Carta 1 ===");
    exibirCarta(carta1);
    printf("\n=== Carta 2 ===");
    exibirCarta(carta2);

    int escolha1 = 0, escolha2 = 0;

    // --- Escolha do primeiro atributo ---
    do {
        mostrarMenu(0);
        printf("\nDigite o numero do primeiro atributo: ");
        scanf("%d", &escolha1);
    } while (escolha1 < 1 || escolha1 > 6);

    // --- Escolha do segundo atributo (diferente do primeiro) ---
    do {
        mostrarMenu(escolha1);
        printf("\nDigite o numero do segundo atributo: ");
        scanf("%d", &escolha2);
        if (escolha2 == escolha1) {
            printf("Voce ja escolheu esse atributo! Escolha outro.\n");
        }
    } while (escolha2 < 1 || escolha2 > 6 || escolha2 == escolha1);

    // --- Captura dos valores para comparacao ---
    float v1a = pegarValor(carta1, escolha1);
    float v2a = pegarValor(carta2, escolha1);
    float v1b = pegarValor(carta1, escolha2);
    float v2b = pegarValor(carta2, escolha2);

    // --- Exibição dos valores comparados ---
    printf("\n--- Comparando Atributo 1 ---\n");
    printf("Carta 1 (%s): %.2f\n", carta1.cidade, v1a);
    printf("Carta 2 (%s): %.2f\n", carta2.cidade, v2a);

    printf("\n--- Comparando Atributo 2 ---\n");
    printf("Carta 1 (%s): %.2f\n", carta1.cidade, v1b);
    printf("Carta 2 (%s): %.2f\n", carta2.cidade, v2b);

    // --- Soma dos valores ---
    float soma1 = v1a + v1b;
    float soma2 = v2a + v2b;
    printf("\nSoma dos atributos:\n");
    printf("Carta 1 (%s): %.2f\n", carta1.cidade, soma1);
    printf("Carta 2 (%s): %.2f\n", carta2.cidade, soma2);

    // --- Determina o vencedor final usando operador ternario ---
    //   resultado = 1 se carta1 vence, 2 se carta2 vence, 0 se empate
    int resultado = soma1 > soma2 ? 1
                  : soma2 > soma1 ? 2
                  : 0;
    char *vencedorStr = resultado == 1 ? carta1.cidade
                     : resultado == 2 ? carta2.cidade
                     : "Empate";

    if (resultado == 0) {
        printf("\nResultado Final: Empate!\n");
    } else {
        printf("\nResultado Final: %s venceu!\n", vencedorStr);
    }

    // --- Pausa para leitura do resultado ---
    printf("\nPressione ENTER para sair...");
    getchar(); // consome \n pendente
    getchar(); // aguarda ENTER
    return 0;
}

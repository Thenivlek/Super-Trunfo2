#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

// Estrutura para representar uma carta de pais
typedef struct {
    char nome[50];
    int populacao;
    int area;
    int pib;
    int densidade_demografica;
} Carta;

// Funcao para comparar as cartas com base nos dois atributos escolhidos
void comparar_cartas(Carta carta1, Carta carta2, int atributo1, int atributo2) {
    int valor1_atributo1, valor1_atributo2, valor2_atributo1, valor2_atributo2;
    int soma_carta1, soma_carta2;

    // Definindo os valores dos atributos de acordo com a escolha
    switch (atributo1) {
        case 1: valor1_atributo1 = carta1.populacao; break;
        case 2: valor1_atributo1 = carta1.area; break;
        case 3: valor1_atributo1 = carta1.pib; break;
        case 4: valor1_atributo1 = carta1.densidade_demografica; break;
        default: valor1_atributo1 = 0; break;
    }
    switch (atributo2) {
        case 1: valor1_atributo2 = carta1.populacao; break;
        case 2: valor1_atributo2 = carta1.area; break;
        case 3: valor1_atributo2 = carta1.pib; break;
        case 4: valor1_atributo2 = carta1.densidade_demografica; break;
        default: valor1_atributo2 = 0; break;
    }

    switch (atributo1) {
        case 1: valor2_atributo1 = carta2.populacao; break;
        case 2: valor2_atributo1 = carta2.area; break;
        case 3: valor2_atributo1 = carta2.pib; break;
        case 4: valor2_atributo1 = carta2.densidade_demografica; break;
        default: valor2_atributo1 = 0; break;
    }
    switch (atributo2) {
        case 1: valor2_atributo2 = carta2.populacao; break;
        case 2: valor2_atributo2 = carta2.area; break;
        case 3: valor2_atributo2 = carta2.pib; break;
        case 4: valor2_atributo2 = carta2.densidade_demografica; break;
        default: valor2_atributo2 = 0; break;
    }

    // Exibir os atributos escolhidos para comparacao
    printf("\nComparando %s e %s:\n", carta1.nome, carta2.nome);
    printf("%s - Atributo 1: %d, Atributo 2: %d\n", carta1.nome, valor1_atributo1, valor1_atributo2);
    printf("%s - Atributo 1: %d, Atributo 2: %d\n", carta2.nome, valor2_atributo1, valor2_atributo2);

    // Logica de soma dos atributos
    soma_carta1 = valor1_atributo1 + valor1_atributo2;
    soma_carta2 = valor2_atributo1 + valor2_atributo2;

    printf("\nSoma dos atributos para %s: %d\n", carta1.nome, soma_carta1);
    printf("Soma dos atributos para %s: %d\n", carta2.nome, soma_carta2);

    // Comparacao final
    if (soma_carta1 > soma_carta2) {
        printf("\nVencedor: %s\n", carta1.nome);
    } else if (soma_carta2 > soma_carta1) {
        printf("\nVencedor: %s\n", carta2.nome);
    } else {
        printf("\nEmpate!\n");
    }
}

// Funcao para exibir o menu e obter a escolha do jogador para o primeiro atributo
int escolher_atributo(char *atributo1_selecionado) {
    int escolha;

    printf("Escolha o primeiro atributo (1: Populacao, 2: Area, 3: PIB, 4: Densidade Demografica): ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: strcpy(atributo1_selecionado, "Populacao"); break;
        case 2: strcpy(atributo1_selecionado, "Area"); break;
        case 3: strcpy(atributo1_selecionado, "PIB"); break;
        case 4: strcpy(atributo1_selecionado, "Densidade Demografica"); break;
        default:
            printf("Opcao invalida\n");
            return -1;
    }
    return escolha;
}

int main() {
    Carta pais1 = {"Brasil", 211000000, 8515767, 2000000, 25}; // Exemplo de dados
    Carta pais2 = {"Alemanha", 83000000, 357022, 4000000, 200}; // Exemplo de dados

    int atributo1, atributo2;
    char atributo1_nome[50], atributo2_nome[50];

    // Escolher o primeiro atributo
    atributo1 = escolher_atributo(atributo1_nome);
    if (atributo1 == -1) return 0; // Se a escolha for invalida, encerra

    // Escolher o segundo atributo (nao pode ser o mesmo que o primeiro)
    printf("Escolha o segundo atributo (diferente do primeiro): ");
    scanf("%d", &atributo2);
    if (atributo2 == atributo1) {
        printf("Voce nao pode escolher o mesmo atributo duas vezes.\n");
        return 0;
    }

    // Comparar as cartas com base nos atributos escolhidos
    comparar_cartas(pais1, pais2, atributo1, atributo2);

    // Pausa para o usuario ler o resultado (Windows)
    system("pause");

    return 0;
}

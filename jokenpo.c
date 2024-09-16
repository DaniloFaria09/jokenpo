#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrarEscolha(int escolha) {
    switch (escolha) {
        case 1:
            printf("Pedra");
            break;
        case 2:
            printf("Papel");
            break;
        case 3:
            printf("Tesoura");
            break;
        default:
            printf("Escolha inválida");
            break;
    }
}

int main() {
    int jogador, computador;
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    printf("Bem-vindo ao jogo de Jokenpô!\n");
    printf("Escolha uma opção:\n1. Pedra\n2. Papel\n3. Tesoura\n");
    printf("Digite sua escolha (1-3): ");
    scanf("%d", &jogador);

    // Verifica se a escolha do jogador é válida
    if (jogador < 1 || jogador > 3) {
        printf("Escolha inválida. Tente novamente.\n");
        return 1;
    }

    // Escolha aleatória do computador (1 a 3)
    computador = rand() % 3 + 1;

    // Exibe as escolhas
    printf("Você escolheu: ");
    mostrarEscolha(jogador);
    printf("\nO computador escolheu: ");
    mostrarEscolha(computador);
    printf("\n");

    // Verifica o resultado do jogo
    if (jogador == computador) {
        printf("Empate!\n");
    } else if ((jogador == 1 && computador == 3) ||  // Pedra ganha de Tesoura
               (jogador == 2 && computador == 1) ||  // Papel ganha de Pedra
               (jogador == 3 && computador == 2)) {  // Tesoura ganha de Papel
        printf("Você venceu!\n");
    } else {
        printf("O computador venceu!\n");
    }

    return 0;
}
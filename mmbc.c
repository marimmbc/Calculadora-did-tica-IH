/*
 * Autor: Mari
 * Data: 23/08/2024
 * Descrição: Calculadora didática para conversão de bases e ponto flutuante.
 */

#include <stdio.h>
#include <stdlib.h>

void decimal_p_bin(int num) {
    printf("Conversão de %d para binário:\n", num);
    if (num == 0) {
        printf("0\n");
        return;
    }
    int bin[32];
    int i = 0;
    while (num > 0) {
        bin[i] = num % 2;
        num = num / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bin[j]);
    }
    printf("\n");
}

void decimal_p_octal(int num) {
    printf("Conversão de %d para octal:\n", num);
    if (num == 0) {
        printf("0\n");
        return;
    }
    int octal[32];
    int i = 0;
    while (num > 0) {
        octal[i] = num % 8;
        num = num / 8;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

void decimal_p_hexa(int num) {
    printf("Conversão de %d para hexadecimal:\n", num);
    if (num == 0) {
        printf("0\n");
        return;
    }
    char hex[32];
    int i = 0;
    while (num > 0) {
        int temp = 0;
        temp = num % 16;
        if (temp < 10) {
            hex[i] = temp + 48;
        } else {
            hex[i] = temp + 55;
        }
        num = num / 16;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

void decimal_p_BCD(int num) {
    printf("Conversão de %d para BCD:\n", num);
    if (num == 0) {
        printf("0000\n");
        return;
    }
    while (num > 0) {
        int digit = num % 10;
        int bcd[4] = {0, 0, 0, 0};
        int i = 3;
        while (digit > 0) {
            bcd[i] = digit % 2;
            digit = digit / 2;
            i--;
        }
        for (int j = 0; j < 4; j++) {
            printf("%d", bcd[j]);
        }
        printf(" ");
        num = num / 10;
    }
    printf("\n");
}

int main() {
    int opcao, num;

    do {
        printf("\nCalculadora Didática - Conversões de Base\n");
        printf("1 - Decimal para Binário\n");
        printf("2 - Decimal para Octal\n");
        printf("3 - Decimal para Hexadecimal\n");
        printf("4 - Decimal para BCD\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um número decimal: ");
                scanf("%d", &num);
                decimal_p_bin
            (num);
                break;
            case 2:
                printf("Digite um número decimal: ");
                scanf("%d", &num);
                decimal_p_octal
            (num);
                break;
            case 3:
                printf("Digite um número decimal: ");
                scanf("%d", &num);
                decimal_p_hexa(num);
                break;
            case 4:
                printf("Digite um número decimal: ");
                scanf("%d", &num);
                decimal_p_BCD(num);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}

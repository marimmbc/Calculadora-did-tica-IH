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
        int digito = num % 10;
        int bcd[4] = {0, 0, 0, 0};
        int i = 3;
        while (digito > 0) {
            bcd[i] = digito % 2;
            digito = digito / 2;
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

void decimal_para_complemento2(int num) {
    printf("Conversão de %d para complemento a 2 (16 bits):\n", num);
    int bin[16];
    int i = 0;

    if (num >= 0) {
        while (num > 0) {
            bin[i] = num % 2;
            num = num / 2;
            i++;
        }
        while (i < 16) {
            bin[i] = 0;
            i++;
        }
    } else {
        num = abs(num);
        while (num > 0) {
            bin[i] = num % 2;
            num = num / 2;
            i++;
        }
        while (i < 16) {
            bin[i] = 0;
            i++;
        }
        for (int j = 0; j < 16; j++) {
            bin[j] = !bin[j];
        }
        int carry = 1;
        for (int j = 0; j < 16; j++) {
            int soma = bin[j] + carry;
            bin[j] = soma % 2;
            carry = soma / 2;
        }
    }

    for (int j = 15; j >= 0; j--) {
        printf("%d", bin[j]);
    }
    printf("\n");
}

void exibir_bits_float(float num) {
    union {
        float f;
        unsigned int bits;
    } float_converter;

    float_converter.f = num;

    printf("Bits do número em ponto flutuante (float):\n");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (float_converter.bits >> i) & 1);
        if (i == 31) printf(" (sinal) ");
        if (i == 23) printf(" (expoente) ");
        if (i == 0) printf(" (fração) ");
    }
    printf("\n");
}

void exibir_bits_double(double num) {
    union {
        double d;
        unsigned long long bits;
    } double_converter;

    double_converter.d = num;

    printf("Bits do número em ponto flutuante (double):\n");
    for (int i = 63; i >= 0; i--) {
        printf("%d", (double_converter.bits >> i) & 1);
        if (i == 63) printf(" (sinal) ");
        if (i == 52) printf(" (expoente) ");
        if (i == 0) printf(" (fração) ");
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
        printf("5 - Decimal para Complemento a 2 (16 bits)\n");
        printf("6 - Exibir bits de número em float\n");
        printf("7 - Exibir bits de número em double\n");
        printf("8 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("digite um número decimal: ");
                scanf("%d", &num);
                decimal_p_bin
            (num);
                break;
            case 2:
                printf("digite um número decimal: ");
                scanf("%d", &num);
                decimal_p_octal
            (num);
                break;
            case 3:
                printf("digite um número decimal: ");
                scanf("%d", &num);
                decimal_p_hexa(num);
                break;
            case 4:
                printf("digite um número decimal: ");
                scanf("%d", &num);
                decimal_p_BCD(num);
                break;
            case 5:
                printf("digite um número decimal: ");
                scanf("%d", &num);
                decimal_para_complemento2(num);
                break;
            case 6:
                printf("Digite um número real (float): ");
                scanf("%lf", &num);
                exibir_bits_float((float)num);
                break;
            case 7:
                printf("Digite um número real (double): ");
                scanf("%lf", &num);
                exibir_bits_double(num);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 8);

    return 0;
}

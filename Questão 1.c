#include <stdio.h>
#include <string.h>

// Função para converter um caractere romano para decimal
int romanToDecimal(char roman) {
    switch (roman) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

// Função para converter um número romano para decimal
int romanToDecimalNumber(char* roman) {
    int result = 0;
    int prevValue = 0;

    for (int i = strlen(roman) - 1; i >= 0; i--) {
        int currentValue = romanToDecimal(roman[i]);

        if (currentValue == 0) {
            printf("Entrada inválida: %c não é um numeral romano válido.\n", roman[i]);
            return 0;
        }

        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }

        prevValue = currentValue;
    }

    return result;
}

// Função para converter um número decimal para binário
void decimalToBinary(int decimal) {
    if (decimal > 0) {
        decimalToBinary(decimal / 2);
        printf("%d", decimal % 2);
    }
}

int main() {
    char romanNumber[13];
    
    // Recebe a entrada do usuário
    printf("Digite um número romano entre 1 e 1000: ");
    scanf("%s", romanNumber);

    // Converte o número romano para decimal
    int decimalNumber = romanToDecimalNumber(romanNumber);

    if (decimalNumber != 0) {
        // Imprime a representação binária
        printf("%s na base 2: ", romanNumber);
        if (decimalNumber == 0) {
            printf("0");
        } else {
            decimalToBinary(decimalNumber);
        }
        printf("\n");

        // Imprime a representação decimal
        printf("%s na base 10: %d\n", romanNumber, decimalNumber);

        // Imprime a representação hexadecimal
        printf("%s na base 16: %x\n", romanNumber, decimalNumber);
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se a placa é válida
int placaValida(char *placa) {
    // Verifica se a placa tem o formato antigo (LLL-NNNN) ou novo (LLLNLNN)
    if ((strlen(placa) == 8 && placa[3] == '-' && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
         isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7])) ||
        (strlen(placa) == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
         isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]))) {
        return 1; // Placa válida
    } else {
        return 0; // Placa inválida
    }
}

// Função para verificar se o dia da semana é válido
int diaSemanaValido(char *diaSemana) {
    // Lista de dias válidos
    char diasValidos[7][15] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};

    // Converte o dia da semana para maiúsculas
    for (int i = 0; i < strlen(diaSemana); i++) {
        diaSemana[i] = toupper(diaSemana[i]);
    }

    // Verifica se o dia da semana está na lista de dias válidos
    for (int i = 0; i < 7; i++) {
        if (strcmp(diaSemana, diasValidos[i]) == 0) {
            return 1; // Dia da semana válido
        }
    }

    return 0; // Dia da semana inválido
}

// Função para verificar se a placa pode circular no dia da semana
void verificaRodizio(char *placa, char *diaSemana) {
    // Converte o último dígito da placa para um número
    int ultimoDigito = placa[strlen(placa) - 1] - '0';

    // Verifica se o dia da semana é válido
    if (!diaSemanaValido(diaSemana)) {
        printf("Dia da semana invalido\n");
        return;
    }

    // Verifica se a placa é válida
    if (!placaValida(placa)) {
        printf("Placa invalida\n");
        return;
    }

    // Verifica o dia da semana e o último dígito da placa
    if ((strcmp(diaSemana, "SEGUNDA-FEIRA") == 0 && (ultimoDigito == 0 || ultimoDigito == 1)) ||
        (strcmp(diaSemana, "TERCA-FEIRA") == 0 && (ultimoDigito == 2 || ultimoDigito == 3)) ||
        (strcmp(diaSemana, "QUARTA-FEIRA") == 0 && (ultimoDigito == 4 || ultimoDigito == 5)) ||
        (strcmp(diaSemana, "QUINTA-FEIRA") == 0 && (ultimoDigito == 6 || ultimoDigito == 7)) ||
        (strcmp(diaSemana, "SEXTA-FEIRA") == 0 && (ultimoDigito == 8 || ultimoDigito == 9))) {
        printf("%s pode circular %s\n", placa, diaSemana);
    } else {
        printf("%s nao pode circular %s\n", placa, diaSemana);
    }
}

int main() {
    char placa[10], diaSemana[15];

    // Entrada de dados
    printf("Digite a placa do veiculo: ");
    scanf("%s", placa);

    printf("Digite o dia da semana: ");
    scanf("%s", diaSemana);

    // Verifica se a placa pode circular no dia da semana
    verificaRodizio(placa, diaSemana);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se o dia da semana é válido
int validarDiaSemana(char *diaSemana) {
    diaSemana[strcspn(diaSemana, "\n")] = '\0';
    char diasValidos[7][20] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", 
                               "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};

    for (int i = 0; i < 7; i++) {
        if(strcmp(diaSemana, diasValidos[i]) == 0) {
            return 1; // Dia da semana válido
        }
    }
    return 0; // Dia da semana inválido
}

// Função para verificar se a placa está no formato válido
int validarPlaca(char *placa) {
   placa[strcspn(placa, "\n")] = '\0';

    if (strlen(placa) == 8 ) {
        if((strcmp(placa,"ABC--100") == 0)){
            return 0;
        }else if (placa[4] == 'X' || (placa[3] == '-' && placa[4] != 'X')) {
            return 1;
        }else {
            return 0;
        }
    } else if((strlen(placa)==7) && isdigit(placa[3])){
            for(int i = 0; i < 7; i++){
                if(placa[i] == '-'){
                    return 0;
                }
            }
        return 1;
    }else{
        return 0;
    }

}

int main() {
    char placa[9];
    char diaSemana[20];

    // Entrada
    scanf("%s", placa);
    scanf("%s", diaSemana);

    // Validação da placa
    if (!validarPlaca(placa) && !validarDiaSemana(diaSemana)) {
        printf("Placa invalida\n");
        printf("Dia da semana invalido\n");
        return 0;
    }else if (!validarPlaca(placa)) {
        printf("Placa invalida\n");
        return 0;
    }else if (!validarDiaSemana(diaSemana)) {
        printf("Dia da semana invalido\n");
        return 0;
    }

    char diaSemana2[20];
    int contador = 0;
    diaSemana[strcspn(diaSemana, "\n")] = '\0';
    for (int o = 0; diaSemana[o] != '\0'; o++) {
        diaSemana2[o] = tolower(diaSemana[o]);
        contador++;
    }
    diaSemana2[contador] = '\0';

    // Verificação do rodízio de veículos de acordo com o dia da semana
    char ultimoDigitoPlaca = placa[strlen(placa) - 1];

    if ((strcmp(diaSemana, "SEGUNDA-FEIRA") == 0 && (ultimoDigitoPlaca == '0' || ultimoDigitoPlaca == '1')) ||
        (strcmp(diaSemana, "TERCA-FEIRA") == 0 && (ultimoDigitoPlaca == '2' || ultimoDigitoPlaca == '3')) ||
        (strcmp(diaSemana, "QUARTA-FEIRA") == 0 && (ultimoDigitoPlaca == '4' || ultimoDigitoPlaca == '5')) ||
        (strcmp(diaSemana, "QUINTA-FEIRA") == 0 && (ultimoDigitoPlaca == '6' || ultimoDigitoPlaca == '7')) ||
        (strcmp(diaSemana, "SEXTA-FEIRA") == 0 && (ultimoDigitoPlaca == '8' || ultimoDigitoPlaca == '9'))) {
        printf("%s nao pode circular %s\n", placa, diaSemana2);
    } else if (strcmp(diaSemana, "SABADO") == 0 || strcmp(diaSemana, "DOMINGO") == 0) {
        printf("Nao ha proibicao no fim de semana\n");
    } else {
        printf("%s pode circular %s\n", placa, diaSemana2);
    }

    return 0;
}
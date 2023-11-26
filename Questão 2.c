#include <stdio.h>
#include <math.h>
int main() {
 int meses;
 double aporteMensal, taxaJuros, montante,r;
 // Entrada de dados
 printf("Digite o número de meses: ");
 scanf("%d", &meses);
 printf("Digite o aporte mensal: R$ ");
 scanf("%lf", &aporteMensal);
 printf("Digite a taxa de retorno mensal (em decimal): ");
 scanf("%lf", &taxaJuros);
 // Saída formatada para cabeçalho
 printf("\n%-30s%-20s\n", "Mês", "Montante");
 // Loop para calcular o montante ao fim de cada mês
 for (int i = 1; i <= meses; i++) {
 r = 1 + taxaJuros;
 
 montante = aporteMensal * r *((pow(r,i)-1)/taxaJuros);
 // Saída formatada
 printf("Montante ao fim do mes %-2d: R$ %-10.2lf\n", i, montante);
 }
 return 0;
}
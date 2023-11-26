#include <stdio.h>
#include <math.h>
int main() {
 int meses;
 double aporteMensal, taxaJuros, montante,r;
 // Entrada de dados
 
 scanf("%d", &meses);

 scanf("%lf", &aporteMensal);
 
 scanf("%lf", &taxaJuros);
 
 // Loop para calcular o montante ao fim de cada mês
 for (int i = 1; i <= meses; i++) {
 r = 1 + taxaJuros;
 
 montante = aporteMensal * r *((pow(r,i)-1)/taxaJuros);
 // Saída formatada
 printf("Montante ao fim do mes %d: R$ %0.2lf\n", i, montante);
 }
 return 0;
}
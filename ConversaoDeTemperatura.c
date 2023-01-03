#include<stdio.h>
 
int main() {

float K;
float C;
float F;

scanf("%f", &K);
C = K-273.00;
F = (((K-273.00)*9)/5.0)+32;

printf("%.2f\n", C);
printf("%.2f\n", F);

return 0;

}
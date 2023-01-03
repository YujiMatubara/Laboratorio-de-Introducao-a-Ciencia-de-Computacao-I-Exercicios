#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
  int n, fat; 
  double x, y, cosseno, c;
  cosseno = 0;
  
  scanf("%d %lf", &n, &x);

  for (int a=0; a<n; a++)
  {
    fat = 1;
    for (int b=1; b<=2*a; b++)
    {
      fat = fat*b;
    }
    cosseno = cosseno+pow(-1,a)*pow(x,2*a)/fat;
  }
  
   c = cos(x);
   
   y = fabs(c-cosseno);
   
   printf("%.6lf\n",cosseno);
    printf("%.6e\n",y);
    
    return 0;

  
}

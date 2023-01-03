#include <stdio.h>
#include <stdlib.h>
 
 int main (){
  int a, b;
  char calculo;
  scanf("%d %d\n", &a, &b);
  scanf("%c", &calculo);
  switch (calculo){
	  case '+':
	  printf ("%d\n", a+b);
	  break;
	  
	  case '-':
	  printf ("%d\n", a-b);
	  break;
	  
	  case '*':
	  printf ("%d\n", a*b);
	  break;
	  
	  case '/':
	  printf ("%d\n", a/b);
	  break;
	  
	  default:
	  printf ("Operacao invalida\n");
	  }
   
   return 0;
  
 
 
 }

#include <stdio.h>
#include <stdlib.h>

  int main () {
   int a1, a2, b1, b2, c1, c2, A, B, C;
   scanf("%d %d",&a1, &a2);
   scanf("%d %d",&b1, &b2);
   scanf("%d %d",&c1, &c2);
   A = a1+a2;
   B = b1+b2;
   C = c1+c2;
  
   if ( a1 > 6 || a1 < 1 || a2 > 6 || a2 < 1 || b1 > 6 || b1 < 1 || b2 > 6 || b2 < 1 || c1 > 6 || c1 < 1 || c2 > 6 || c2 < 1 )
   {
   printf("Alguem trapaceou nesse jogo\n");
   }
   else if(A>B && B>C){
   printf("Andreia\nBruno\nCristina\n");
   }
    else if (A>C && C>B){
    printf ("Andreia\nCristina\nBruno\n");
    }
     else if (B>A && A>C) {
     printf ("Bruno\nAndreia\nCristina\n");
     }
      else if (B>C && C>A){
		  printf("Bruno\nCristina\nAndreia\n");
		  }
      else if (C>A && A>B){
		printf("Cristina\nAndreia\nBruno\n");
		}
		  else  {
		  printf ("Cristina\nBruno\nAndreia\n");
		  }
		  
	return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main(){
  int tamVetLucas, tamVetCesar;
  scanf("%d %d", &tamVetLucas, &tamVetCesar);
  int VetLucas[tamVetLucas], VetCesar[tamVetCesar];
  
  int tamVetLucasCesar;
  tamVetLucasCesar = tamVetLucas + tamVetCesar;
  
  for(int i=0; i<tamVetLucas; i++){
  scanf("%d", &VetLucas[i]);
  }
  
  for(int j=0; j<tamVetCesar; j++){
  scanf("%d", &VetCesar[j]);
  }
  
  int VetFinal[tamVetLucasCesar];
  for(int k=0; k<tamVetLucasCesar && k<tamVetLucas && k<tamVetCesar; k++){
  VetFinal[k*2] = VetLucas[k];
  }
  
  for(int l=0; l<tamVetLucasCesar && l<tamVetCesar && l<tamVetLucas; l++){
  VetFinal[1+(2*l)] = VetCesar[l];
  }
  int menor = tamVetLucas;
  if (tamVetCesar < tamVetLucas) menor = tamVetCesar;
  
  int andador = 2*menor;
  for(int p=menor; p<tamVetCesar; p++){
  VetFinal[andador] = VetCesar[p];
  andador++;
  }
  
  for(int p=menor; p<tamVetLucas; p++){
  VetFinal[andador] = VetLucas[p];
  andador++;
  }
  
  printf("%d\n", tamVetLucasCesar);
  
  for(int i=0; i<tamVetLucasCesar; i++){
  printf("%d ", VetFinal[i]);
  }
  
  return 0;
}
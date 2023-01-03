#include <stdio.h>
#include <stdlib.h>

long long int somavetor(long long int* vetor, long long int quantidadevetor, long long int soma)
{
	soma += vetor[quantidadevetor];
	quantidadevetor--;
	if (quantidadevetor < 0)
	{
	return(soma);
	}
	return(somavetor(vetor, quantidadevetor, soma));
}

long long int funcaopotencia(long long int numerovetor, long long int potencia, long long int valor)
{
	valor *= numerovetor;
	potencia--;
	if (potencia <= 1)
	{
		return(valor);
	}
	return(funcaopotencia(numerovetor, potencia, valor));
}

int main(int argc, char const *argv[])
{
	long long int quantidadevetor;
	long long int potencia;
	scanf("%lld", &quantidadevetor);
	scanf("%lld", &potencia);

	long long int* vetornumeros = (long long int *)malloc(quantidadevetor * sizeof(long long int));
	for (int i = 0; i < quantidadevetor; ++i)
	{
		scanf("%lld", &vetornumeros[i]);
	}

	long long int soma = 0;
	soma = somavetor(vetornumeros, quantidadevetor, soma);
	printf("Soma: %lld\n", soma);
	printf("Potencias:");
	for (int i = 0; i < quantidadevetor; ++i)
	{
		long long int valor = vetornumeros[i];
		printf(" %lld", funcaopotencia(vetornumeros[i], potencia, valor));
	}

	return 0;
}
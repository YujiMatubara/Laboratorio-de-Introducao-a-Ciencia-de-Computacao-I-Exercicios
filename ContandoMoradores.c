#include <stdio.h>
#include <stdlib.h>

void free_matriz(int **matriz, int N)
{
	for (int i = 0; i < N; ++i)
	{
		free(matriz[i]);
	}
free (matriz);
}

void update(int **matriz, int N, int M, int I, int J)
{
	if (I<N && J<M && I>=0 && J>=0)
	{
		matriz[I][J]++;
	}
}

int main(int argc, char const *argv[])
{
	int N;
	int M;	

	scanf ("%d", &N);
	scanf ("%d", &M);

	//alocar dinamicamente a matriz
	int **matriz;
	matriz = (int **) calloc(N, sizeof(int *));
	for (int i = 0; i < N; ++i)
	{
		matriz[i] = (int *) calloc(M, sizeof(int));
	}

	int Q;
	scanf ("%d", &Q);
	int posicaocompra[Q][2];

	for (int i = 0; i < Q; ++i)
	{
		scanf ("%d %d", &posicaocompra[i][0], &posicaocompra[i][1]);
	}
	
	for (int i = 0; i < Q; ++i)
	{
		update(matriz, N, M, posicaocompra[i][0], posicaocompra[i][1]);
	}

	//pritando a matriz final
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			printf("%d ", matriz[i][j]);
		}
	printf("\n");
	}

	free_matriz(matriz, N);

	return 0;
}
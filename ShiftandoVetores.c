#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int N;
	int K;
	scanf("%d", &N);
	scanf("%d", &K);

	if (K > 0)
	{
		K = (((K)%N));

		int vet[N];
		for (int i = 0; i < N ; ++i)
		{
			scanf(" %d", &vet[i]);
		}

		for (int i = (N-K); i < N; ++i)
		{
			printf("%d ", vet[i]);
		}

		for (int i = 0; i < (N-K); ++i)
		{
			printf("%d ", vet[i]);
		}
	}

	else
	{	
		K = (abs(K)%N);
		int vet[N];
		for (int i = 0; i < N ; ++i)
		{
			scanf(" %d", &vet[i]);
		}

		for (int i = K; i < N; ++i)
		{
			printf("%d ", vet[i]);
		}

		for (int i = 0; i < K; ++i)
		{
			printf("%d ", vet[i]);
		}

	}


	return 0;
}

#include <stdio.h>
#include <stdlib.h>

void N1(int N, int matriz[][N])
{
	printf("%d", matriz[0][0]);
}

void N2(int N, int matriz[][N])
{
	printf("%d", (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]));
}

void N3(int N, int matriz[][N])
{
	printf("%d", (matriz[0][0] * matriz[1][1] * matriz[2][2]) + (matriz[0][1] * matriz [1][2] * matriz[2][0]) + (matriz[0][2] * matriz[1][0] * matriz [2][1]) - (matriz[2][0] * matriz[1][1] * matriz[0][2]) - (matriz[2][1] * matriz[1][2] * matriz[0][0]) - (matriz[2][2] * matriz[1][0] * matriz[0][1]));
}

int main(int argc, char const *argv[])
{
	int N;
	scanf ("%d", &N);

	int matriz[N][N];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &matriz[i][j]);
		}
	}

	if (N == 1)
	{
		N1(N, matriz);
	}
	else if(N == 2)
	{
		N2(N, matriz);
	}
	else
	{
		N3(N, matriz);
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Pessoa
{
	char *Nome;
	double Altura;
	double Peso;
	char Genero;
	unsigned int ID;
};

char *read_line()
{
    char *s;
    s = NULL;
    
    int contador = 0;

    do
    {
        contador++;
        s = (char *)realloc(s, sizeof(char)*contador);
        scanf("%c", &s[contador - 1]);
    } while ( s[contador - 1] != '\n' && s[contador - 1] != '\r');
    s[contador] = '\0';

    return (s);
}

struct Pessoa** Criador_Vetor(int N)
{
	//vetor que guarda ponteiro de struct
	//vet(Joao, Maria...)
	struct Pessoa** Carinha;
	Carinha = (struct Pessoa **)malloc(N * sizeof(struct Pessoa *));
	for (int i = 0; i < N; ++i)
	{
		Carinha[i] = (struct Pessoa *)malloc (sizeof(struct Pessoa));
	}

	return (Carinha);
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d ", &N);

	struct Pessoa** vetor = Criador_Vetor(N);

	for (int i = 0; i < N; ++i)
	{
		(*vetor[i]).Nome = read_line();
		scanf("%lf ", &(*vetor[i]).Altura);
		scanf("%lf ", &(*vetor[i]).Peso);
		scanf("%c ", &(*vetor[i]).Genero);
		scanf("%u ", &(*vetor[i]).ID);
	}

	int y;
	do
	{
		scanf("%d", &y);
		for (int i = 0; i < N; ++i)
		{
			if (y == (*vetor[i]).ID)
			{
				printf("%s", (*vetor[i]).Nome);
				printf("%.6lf\n", ((*vetor[i]).Peso)/((*vetor[i]).Altura)/((*vetor[i]).Altura));
				double IDM = ((*vetor[i]).Peso)/((*vetor[i]).Altura)/((*vetor[i]).Altura);
				if ((*vetor[i]).Genero == 'F')
				{
					if (IDM < 19.1)
					{
						printf("Abaixo do peso\n");
					}
					else if (IDM <= 25.8)
					{
						printf("Peso ideal\n");
					}
					else if (IDM <= 27.3)
					{
						printf("Pouco acima do peso\n");
					}
					else if (IDM <= 32.3)
					{
						printf("Acima do peso\n");
					}
					else
					{
						printf("Obesidade\n");
					}
				}
				else
				{
					if (IDM < 20.7)
					{
						printf("Abaixo do peso\n");
					}
					else if (IDM <= 26.4)
					{
						printf("Peso ideal\n");
					}
					else if (IDM <= 27.8)
					{
						printf("Pouco acima do peso\n");
					}
					else if (IDM <= 31.1)
					{
						printf("Acima do peso\n");
					}	
					else
					{
						printf("Obesidade\n");
					}
				}
			}
		}
	} while (y != -1);

	for (int i = 0; i < N; ++i)
	{
		free((*vetor[i]).Nome);
		free(vetor[i]);
	}
	free(vetor);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct Funcao
{
	char* pais1;
	char* pais2;
	char* gols1;
	char* gols2;
	int gols1number;
	int gols2number;
}funcao;

typedef struct Pais
{
    int pontos;
    int vitorias;
    int saldogol;
    int totalgols;
    int numerojogos;
}pais;

bool nomesiguais(char *s, char* s2)
{
	int contador = 0;
	int tams = 0;
	int tams2 = 0;
	do
	{
		contador++;
	} while (s[contador] != '\0');
	tams = contador;

	contador = 0;
	do
	{
		contador++;
	} while (s2[contador] != '\0');
	tams2 = contador;
	contador = 0;
	if (tams == tams2)
	{
		for (int i = 0; i < tams; ++i)
		{
			if (s[i] == s2[i])
			{
				contador++;
			}
		}
		if (contador == tams)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

char* read_line()
{
    char *s;
    s = NULL;
    
    int contador = 0;

    do
    {
        contador++;
        s = (char *)realloc(s, sizeof(char)*contador);
        if (contador == 1)
        {
        	scanf(" %c", &s[contador - 1]);
        }
        else
        {
        	scanf("%c", &s[contador - 1]);
        }
    } while ( s[contador - 1] != '\n' && s[contador - 1] != '\r');
    s[contador - 1] = '\0';

    return (s);
}

//funcao que converte integer%c in integer%d
int conversora(char* s, int tamanhos)
{
   int digit = 0;
   for (int i = 0; i < tamanhos; ++i)
   {
   		digit += (s[tamanhos - i - 1] - '0') * (int)pow((double)10, (double)i);
   }
   return digit; 
}

char* read_arq(FILE* fpr)
{
    char *s;
    s = NULL;
    
    int contador = 0;

    do
    {
        contador++;
        s = (char *)realloc(s, sizeof(char)*contador);
        if (contador == 1)
        {
        	fscanf(fpr, " %c", &s[contador - 1]);
        }
        else
        {
        	fscanf(fpr, "%c", &s[contador - 1]);
        }
    } while ( s[contador - 1] != '\n' && s[contador - 1] != '\r');
    s[contador - 1] = '\0';

    return (s);
}

int tamanhostrig(char *s)
{
	int contador = 0;

	while(s[contador] != '\0')
	{
		contador++;
	}

	return contador;
}

bool checandoordem(char *s, char *s2)
{
	int tamanhos;
	int tamanhos2;
	int contador = 0;
	int letra1;
	int letra2;

	tamanhos = tamanhostrig(s);
	tamanhos2 = tamanhostrig(s2);

	if (tamanhos < tamanhos2)
	{
		for (int i = 0; i < tamanhos; ++i)
		{
			letra1 = s[i];
			letra2 = s2[i];
			if (letra1 < letra2)
			{
				contador = 1;
			}
		}
	}
	else
	{
		for (int i = 0; i < tamanhos2; ++i)
		{
			letra1 = s[i];
			letra2 = s2[i];
			if (letra1 < letra2)
			{
				contador = 1;
			}
		}
	}
	if (contador == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main(int argc, char const *argv[])
{
    //ponteiro para o arquivo de leitura (copa.txt)
	FILE *fpr;
	//guardar o nome do arquivo para abri-lo
    char* arquivo = read_line();
    //abrindo o arquivo e colocando um ponteiro para seu primeiro elemento
	fpr = fopen(arquivo, "r");

	int NumeroEquipes;
	scanf("%d", &NumeroEquipes);

	//guardar o nome do pais eparado da struct
	char* vetornomes[NumeroEquipes];
	for (int i = 0; i < NumeroEquipes; i++)
	{
		vetornomes[i] = read_line();
	}
	//vetor de struct
	pais vetor[NumeroEquipes];
	for (int i = 0; i < NumeroEquipes; ++i)
	{
		vetor[i].pontos = 0;
		vetor[i].vitorias = 0;
		vetor[i].saldogol = 0;
		vetor[i].totalgols = 0;
		vetor[i].numerojogos = 0;
	}

	int totaljogos;
	scanf("%d", &totaljogos);

	char* pais1;
	char* gols1char;
	char* gols2char;
	char* pais2;
	int gols1number;
	int gols2number;
	//guardar o que esta escrito na primeira linha num vetor de string
	char* vetorlinha[totaljogos];
	for (int i = 0; i < totaljogos; ++i)
	{
		vetorlinha[i] = read_arq(fpr);
	}

	for (int i = 0; i < totaljogos; ++i)
	{
		pais1 = strtok(vetorlinha[i], "#");
		gols1char = strtok(NULL, "@");
		gols2char = strtok(NULL, "#");
		pais2 = strtok(NULL, "\0");
		
		gols1number = conversora(gols1char, tamanhostrig(gols1char));
		gols2number = conversora(gols2char, tamanhostrig(gols2char));

		for (int i2 = 0; i2 < NumeroEquipes; ++i2)
		{
			if (nomesiguais(vetornomes[i2], pais1))
			{
				vetor[i2].saldogol += gols1number;
				vetor[i2].saldogol -= gols2number;
				vetor[i2].numerojogos++;
				vetor[i2].totalgols += gols1number;
			}
			else if (nomesiguais(vetornomes[i2], pais2))
			{
				vetor[i2].saldogol += gols2number;
				vetor[i2].saldogol -= gols1number;
				vetor[i2].numerojogos++;
				vetor[i2].totalgols += gols2number;
			}
		}
		//somando os pontos
		if (gols1number > gols2number)
		{
			for (int i2 = 0; i2 < NumeroEquipes; ++i2)
			{
				if (nomesiguais(vetornomes[i2], pais1))
				{
					vetor[i2].vitorias++;
					vetor[i2].pontos += 3;
					break;
				}
			}
		}
		else if (gols1number == gols2number)
		{
			for (int i2 = 0; i2 < NumeroEquipes; ++i2)
			{
				if (nomesiguais(vetornomes[i2], pais1))
				{
					vetor[i2].pontos += 1;
				}
				else if (nomesiguais(vetornomes[i2], pais1))
				{
					vetor[i2].pontos += 1;
				}
			}
		}
		else
		{
			for (int i2 = 0; i2 < NumeroEquipes; ++i2)
			{
				if (nomesiguais(vetornomes[i2], pais2))
				{
					vetor[i2].vitorias++;
					vetor[i2].pontos += 3;
					break;
				}
			}
		}
		free(pais1);
	}

	int k = 0;
	int k2 = 0;
	int contador2 = 0;
	int contador1 = 0;

	//verificando pontos
	for (int i = 1; i < NumeroEquipes + 1; ++i)
	{
		if (vetor[i].numerojogos > 0)
		{
			//printf("%d\n", vetor[i-1].pontos);
			if (vetor[k].pontos < vetor[i-1].pontos)
			{
				//o k recebe a posicao do primeiro que tem mais pontos
				k = i;
			}
		}
		//o contador 2 recebe o primeiro que tiver mais pontos
		contador2 = vetor[k].pontos;
	}
	for (int i = 0; i < NumeroEquipes; ++i)
	{
		//se alguem tiver pontos iguais ao primeiro que tem mais pontos e nao for ele mesmo
		if (vetor[i].pontos == contador2 && k != i)
		{
			k = i;
			//para entrar na proxima conticao
			contador2 = -1;
		}
	}
	//-------------------------------------------------------------------------
	for (int i = 1; i < NumeroEquipes + 1; ++i)
	{
		if (vetor[i].numerojogos > 0)
		{
			if (vetor[i-1].pontos < vetor[k2].pontos)
			{
				k2 = i;
			}
		}
		contador1 = vetor[k2].pontos;
	}
	for (int i = 0; i < NumeroEquipes; ++i)
	{
		if (vetor[i].pontos == contador1 && k2 != i)
		{
			k2 = i;
			contador1 = -1;
		}
	}
	//============================================================================

	//verificando vitorias
	if (contador2 == -1)
	{
		contador2 = 0;
		for (int i = 1; i < NumeroEquipes + 1; ++i)
		{
			if (vetor[i].numerojogos > 0)
			{
				if (vetor[k].vitorias < vetor[i-1].vitorias)
				{
					k = i;
				}
			}
			contador2 = vetor[k].vitorias;
		}
		for (int i = 0; i < NumeroEquipes; ++i)
		{
			if (vetor[i].vitorias == contador2 && k != i)
			{
				k = i;
				contador2 = -1;
			}
		}
	}
	//--------------------------------------------------------------------------
	if (contador1 == -1)
	{
		for (int i = 1; i < NumeroEquipes + 1; ++i)
		{
			if (vetor[i].numerojogos > 0)
			{
				if (vetor[i-1].vitorias < vetor[k2].vitorias)
				{
					k2 = i;
				}
			}
			contador1 = vetor[k2].vitorias;
		}
		for (int i = 0; i < NumeroEquipes; ++i)
		{
			if (vetor[i].vitorias == contador1 && k2 != i)
			{
				k2 = i;
				contador1 = -1;
			}
		}
	}
	//===========================================================================

	//checando maior saldo de gol
	if (contador2 == -1)
	{
		contador2 = 0;
		for (int i = 1; i < NumeroEquipes + 1; ++i)
		{
			if (vetor[i].numerojogos > 0)
			{
				if (vetor[k].saldogol < vetor[i-1].saldogol)
				{
					k = i;
				}
			}
			contador2 = vetor[k].saldogol;
		}
		for (int i = 0; i < NumeroEquipes; ++i)
		{
			if (vetor[i].saldogol == contador2 && k != i)
			{
				k = i;
				contador2 = -1;
			}
		}
	}
	//--------------------------------------------------------------------------
	if (contador1 == -1)
	{
		for (int i = 1; i < NumeroEquipes + 1; ++i)
		{
			if (vetor[i].numerojogos > 0)
			{
				if (vetor[i-1].saldogol < vetor[k2].saldogol)
				{
					k2 = i;
				}
			}
			contador1 = vetor[k2].saldogol;
		}
		for (int i = 0; i < NumeroEquipes; ++i)
		{
			if (vetor[i].saldogol == contador1 && k2 != i)
			{
				k2 = i;
				contador1 = -1;
			}
		}
	}
	//===========================================================================

	//checando gols marcados
	if (contador2 == -1)
	{
		contador2 = 0;
		for (int i = 1; i < NumeroEquipes + 1; ++i)
		{
			if (vetor[i].numerojogos > 0)
			{
				if (vetor[k].totalgols < vetor[i-1].totalgols)
				{
					k = i;
				}
			}
			contador2 = vetor[k].totalgols;
		}
		for (int i = 0; i < NumeroEquipes; ++i)
		{
			if (vetor[i].totalgols == contador2 && k != i)
			{
				k = i;
				contador2 = -1;
			}
		}
	}
	//--------------------------------------------------------------------------
	if (contador1 == -1)
	{
		for (int i = 1; i < NumeroEquipes + 1; ++i)
		{
			if (vetor[i].numerojogos > 0)
			{
				if (vetor[i-1].totalgols < vetor[k2].totalgols)
				{
					k2 = i;
				}
			}
			contador1 = vetor[k2].totalgols;
		}
		for (int i = 0; i < NumeroEquipes; ++i)
		{
			if (vetor[i].totalgols == contador1 && k2 != i)
			{
				k2 = i;
				contador1 = -1;
			}
		}
	}
	//===========================================================================

	//checando menos jogos realizados
	if (contador2 == -1)
	{
		contador2 = 0;
		for (int i = 1; i < NumeroEquipes + 1; ++i)
		{
			if (vetor[i].numerojogos > 0)
			{
				if (vetor[k].numerojogos > vetor[i-1].numerojogos)
				{
					k = i;
				}
			}
			contador2 = vetor[k].numerojogos;
		}
		for (int i = 0; i < NumeroEquipes; ++i)
		{
			if (vetor[i].numerojogos == contador2 && k != i)
			{
				k = i;
				contador2 = -1;
			}
		}
	}
	//--------------------------------------------------------------------------
	if (contador1 == -1)
	{
		for (int i = 1; i < NumeroEquipes + 1; ++i)
		{
			if (vetor[i].numerojogos > 0)
			{
				if (vetor[i-1].numerojogos > vetor[k2].numerojogos)
				{
					k2 = i;
				}
			}
			contador1 = vetor[k2].numerojogos;
		}
		for (int i = 0; i < NumeroEquipes; ++i)
		{
			if (vetor[i].numerojogos == contador1 && k2 != i)
			{
				k2 = i;
				contador1 = -1;
			}
		}
	}
	//===========================================================================

	//checando ordem lexicografica
	bool flag = true;
	if (contador2 == -1)
	{
		flag = checandoordem(vetornomes[k], vetornomes[k2]);
	}
	//printando resposta
	if (flag)
	{
		printf("%s\n", vetornomes[k]);
		printf("%s\n", vetornomes[k2]);
	}
	else
	{
		printf("%s\n", vetornomes[k2]);
		printf("%s\n", vetornomes[k]);
	}

	//fechar arquivo
	fclose(fpr);
}
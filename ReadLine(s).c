

#include <stdio.h>
#include <stdlib.h>

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
    } while ( s[contador - 1] != '\n');
    s[contador] = '\0';

    return(s);
}

int lenght(char *s)
{
    int contador = 0;
    do
    {
        contador++;
    } while (s[contador] != '\n');
    return (contador);
}

int equal (char *a, char *b)
{
    int contador = 0;
    int i;
    if (lenght(a) == lenght(b))
    {
        for (i = 0; i < lenght(a); ++i)
        {
            if (a[i] == b[i])
            {
                contador++;
            }
        }
        if (contador == lenght(a))
        {
            return(1);
        }
        else
        {
            return(0);
        }
    }
    else
    {
        return(0);
    }
}

int main(int argc, char const *argv[])
{
    char *s;
    s = read_line();
    char *s2;
    s2 = read_line();
    
	int a;
	a = equal(s, s2);
	
    if (a)
   {
        printf("Linhas 1 e 2: ");
        int i;
        for (i = 0; i < lenght(s); ++i)
        {
            printf("%c", s[i]);
        } 
    }
	else
	{
		printf("Linha 1: ");
        int i;
        for (i = 0; i < lenght(s); ++i)
        {
            printf("%c", s[i]);
        }
        printf("Linha 2: ");
        for (i = 0; i < lenght(s2); ++i)
        {
            printf("%c", s2[i]);
        }
	}
	free(s);
	free(s2);
    return 0;
}

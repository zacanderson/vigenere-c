#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int echo(char *filename)
{
	int c;
	
	FILE *ifp = fopen(filename,"r");

    if (ifp == 0)
        printf("Could not open file\n");

	c = fgetc(ifp); 

    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(ifp); 
    } 
    printf("\n");
    return 0;
}

int standardize(char *filename)
{
    int i, j = 0, k;
	char ch;
	char *presort;

	FILE *ifp = fopen(filename, "r");

	if (ifp == NULL)
	{
		printf("Could not open \"%s\" in standardize().\n", filename);
		return 0;
	}

	presort = malloc(sizeof(char) * 512);

	for (i = 0; i < 512; i++)
	{
		presort[i] = 'x';
	}

	while (fscanf(ifp, "%c", &ch) != EOF)
	{
		if(ispunct(ch) || isspace(ch) || isdigit(ch))
		{
			ch = '0';
		}
		if(isalpha(ch))
		{
			presort[j] = tolower(ch);
			j++;
		}

	}
	fclose(ifp);
	return 0;
}

int standardize_key(char *key)
{
	int i, j = 0, k;
	char ch, var;
	int count = 0;
	char *presort_key;

	FILE *ifp = fopen(key, "r");

	if (ifp == NULL)
	{
		printf("Could not open \"%s\" in standardize().\n", key);
		return 0;
	}

	presort_key = malloc(sizeof(char) * 512);

	for (i = 0; i < 512; i++)
	{
		presort_key[i] = '\0';
	}

	while (fscanf(ifp, "%c", &ch) != EOF)
	{
		if(ispunct(ch) || isspace(ch) || isdigit(ch))
		{
			ch = '0';
		}
		if(isalpha(ch))
		{
			presort_key[j] = tolower(ch);
			j++;
		}
	}
	fclose(ifp); 
	return 0;
}


int vigenere(char *key, char *filename)
{ 
	/*
	int i, j;
	char *postsort;

	postsort = malloc(sizeof(char) * 513);
 
	for(i = 0; i < 512; i++)
	{
		postsort[i] = (((presort[i] + presort_key[i]) % 26) + 'a');
	}

	for(j = 0; j < 512; j++)
	{
		printf("%c", postsort[j]);
	}
	*/
	int i, j = 0, k;
	char ch;
	char *postsort;

	postsort = malloc(sizeof(char) * 513);

	FILE *ifp = fopen(filename, "r");

	if (ifp == NULL)
	{
		printf("Could not open \"%s\" in standardize().\n", filename);
		return 0;
	}

	for (i = 0; i < 512; i++)
	{
		postsort[i] = 'x';
	}

	while (fscanf(ifp, "%c", &ch) != EOF)
	{
		if(ispunct(ch) || isspace(ch) || isdigit(ch))
		{
			ch = '0';
		}
		if(isalpha(ch))
		{
			postsort[j] = tolower(ch) % 26 + 'a';
			j++;
		}

	}
	for(k = 0; k < 512; k++)
	{
		printf("%c", postsort[k]);
	}
	printf("\n");
	fclose(ifp);
	return 0;
	

}

int main(int argc, char **argv)
{
	int i;
	char *key = argv[1];
	char *filename = argv[2];

	echo(key);
	echo(filename);
	standardize(filename);
	standardize_key(key);
	vigenere(key, filename);
/*
	free(presort);
	free(postsort);
	free(presort_key);
	*/
}

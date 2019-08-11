#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
	int c, i = 0;
	long unsigned int character = 0, newline = 0, word = 0;
	while((c = getchar()) != EOF)
	{
		character++;
		if(c == '\n')
		{
			newline++;
		}
		if(i == 1)
		{
			if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c == 39))
			{
				NULL;
			} else
			{
				i = 0;
			}
		} else 
		{
			if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c == 39))
			{
				i = 1;
				word++;
			}
		}
	}
	printf( "%lu %lu %lu\n", character, word, newline );
	return 0;
}
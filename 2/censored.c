#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char const *argv[])
{
	char current_word[128];

	int i, j = 1, k = 0;
	while((i = getchar()) != EOF)
	{
		while(isalnum(i) != 0)
		{
			current_word[k] = i;
			i = getchar();
			k++;
		}
		while(j < argc)
		{
			if (strcmp(current_word, argv[j]) == 0)
			{
				strcpy(current_word, "CENSORED");
			}
			j++;
		}
		printf("%s", current_word);

		printf("%c", i);
		memset(current_word, '\0', sizeof(current_word));
		k = 0;
		j = 1;
	}
	return 0;
}
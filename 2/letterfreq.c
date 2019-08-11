#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
	int letter = 0, ascii = 96;
	unsigned long int i = 0;
	int alpha[26] = {0};
	double freq = 0.0;

	while((letter = getchar()) != EOF)
	{
		if(isalpha(letter))
		{
			letter = tolower(letter);
			i++;
			alpha[letter-'a']++;
		}
	}
	for (int j = 0; j < 26; ++j)
	{
		ascii++;
		if(alpha[j] != 0)
		{
			freq = (double)alpha[j]/(double)i;
			printf("%c %.4f\n", ascii, freq);
		}
		freq = 0.0;
	}
	return 0;
}
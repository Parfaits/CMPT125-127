#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	unsigned int count = 0, j = 0;
	if(strlen(argv[1]) < strlen(argv[2]))
	{
		printf("false\n");
		return 0;
	} else
	{
		for(unsigned int i=0; i<strlen(argv[1]); i++)
		{
			if(argv[1][i] == argv[2][j])
			{	
				unsigned int n = i, m = j;
				while(argv[1][n] == argv[2][m] && n<strlen(argv[1])
				 && m<strlen(argv[2]))
				{
					count++;
					n++;
					m++;
				}
				if(m != strlen(argv[2]))
				{
					count = 0;
				} else if(count == strlen(argv[2]))
				{
					printf("true\n");
					return 0;
				}
			}
		}
	}
	printf("false\n");
	return 0;
}
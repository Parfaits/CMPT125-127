#include <stdio.h>


int main()
{
	int i, j = 0, len = 0;
	int xyz[3];
	while(scanf("%i", &i) != EOF && len <= 3)
	{
		xyz[j] = i;
		j++;
		len++;
	}
	for (int k = 0; k < xyz[1]; ++k)
	{
		for (int h = 0; h < xyz[0]; ++h)
		{
			if(k == 0 || k == xyz[1]-1)
			{
				printf("#");
			} else if(h == 0 || h == xyz[0]-1)
			{
				printf("#");
			} else
			{
				printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}
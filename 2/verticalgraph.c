#include <stdio.h>

int max(int arr[], int len);


int max(int arr[], int len)
{
	int max = 0;
	for (int i = 1; i < len; ++i)
	{
		if(arr[max] < arr[i])
		{
			max = i;
		}
	}
	return max;
}


int main()
{
	int i = 0, cols = 0;
	int barsize[80];
	while(scanf("%i ", &i) != EOF)
	{
		barsize[cols] = i;
		cols++;
	}
	int maxpos = max(barsize, cols);
	for (int i = 0; i < barsize[maxpos]; i++)
	{
		for (int j = 0; j < cols; ++j)
		{
			if(barsize[maxpos] - barsize[j] <= i)
			{
				printf("#");
			} else 
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
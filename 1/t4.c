#include <stdio.h>
#include <math.h>

int main()
{
	float i;
	int sc = scanf("%f", &i);
	if(sc == 1)
	{
		printf("%li %li %li\n", (long int) floor(i),
	 	 (long int) round(i),
	 	 (long int) ceil(i));
	} else {
		printf("scanf error: (%d)\n", sc);
	}
	return 0;
}
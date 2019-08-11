#include <stdio.h>
#include <math.h>

int main()
{
	float i;
	while(scanf("%f", &i) != EOF)
	{
		printf("%i %i %i\n",
		 (int) floorf(i),
	 	 (int) roundf(i),
	 	 (int) ceilf(i));
	}
	printf("Done.\n");
	return 0;
}
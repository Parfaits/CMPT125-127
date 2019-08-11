#include <stdio.h>
#include <math.h>


int main()
{
	double i;
	scanf("%lf", &i);
	printf("%li %li %li\n", (long int) floor(i),
	 (long int) round(i), (long int) ceil(i));
	return 0;
}
#include <stdio.h>


int main()
{
	float m, small = 100000.0,
	 large = -100000.0, sum = 0.0;
	int i = 0;
	while(scanf("%f", &m) != EOF)
	{
		if(m >= large)
		{
			large = m;
		}
		if(m <= small)
		{
			small = m;
		}
		sum += m;
		i++;
	}
	printf("%0.2f %0.2f %0.2f\n",
	 small, large, sum/i);
	return 0;
}
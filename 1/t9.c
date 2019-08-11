#include <stdio.h>
#include <math.h>


int main()
{
    int x, y, z; // 0 length,  width, height
    scanf("%i %i %i", &x, &y, &z);
    int j = z-1;
    int left = floor( j * (x/(2.0*z)) );
    int right = ceil( (x-1) + -j * (x/(2.0*z)) ); 

    for(int k=0; k<left; k++) //rows top
    {
        printf(" ");
    }
    for (int i = 0; i < right-left+1; ++i)
    {
        printf("#");
    }
    printf("\n");
    if(z >= 2)
    {
        for(int j = z-2; j > 0; j--)
        {
            int left = floor( j * (x/(2.0*z)) );
            int right = ceil( (x-1) + -j * (x/(2.0*z)) ); 

            for(int h=1; h < left+1; h++)
            {
                printf(" ");
            }
            printf("#");
            for(int o=1; o < right-left; o++)
            {
                printf(".");
            }
            printf("#");
            printf("\n");
        }
        for (int b = 0; b < x; ++b) //row bottom
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
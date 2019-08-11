#include <stdio.h>
#include <stdlib.h>

#include "point_array.h"


void point_array_init( point_array_t* pa );
void point_array_reset( point_array_t* pa );
int point_array_append( point_array_t* pa, point_t* p );
int point_array_remove( point_array_t* pa, unsigned int i );

void point_array_init( point_array_t* pa )
{
	if(pa != NULL)
	{
		pa->len = 0;
		pa->points = malloc(pa->len*sizeof(point_t));
		pa->reserved = 0;
	}
	
}

void point_array_reset( point_array_t* pa )
{
	if(pa!=NULL)
	{
		free(pa->points);
		free(pa);
	}
}

int point_array_append( point_array_t* pa, point_t* p )
{
	point_t* s = p;
	if(pa == NULL)
	{
		return 1;
	}
	if(pa->reserved < pa->len+1)
	{
		pa->points = realloc(pa->points, (2*pa->len+1)*sizeof(point_t));
		pa->reserved = pa->len*2;
		
	}
	pa->points[pa->len] = *s;
	pa->len++;
	if(pa->points == NULL)
	{
		return 1;
	}
    return 0;
}

int point_array_remove( point_array_t* pa, unsigned int i )
{
	int lastelementindex = pa->len-1;
	if(pa == NULL)
	{
		return 1;
	}
	if(i>= pa->len)
	{
		return 1;
	} else
	{
		pa->points[i] = pa->points[lastelementindex];
		pa->len--;
	}
	/*if(i != lastelementindex && i  pa->len)
	{
		pa->points[i] = pa->points[lastelementindex];
		//pa->points = realloc(pa->points, (pa->len-1)*sizeof(point_t));
		pa->len--;
	} else
	{
		pa->len--;
	}*/
	
	
	if(pa->points == NULL)
	{
		return 1;
	}
    return 0;
}
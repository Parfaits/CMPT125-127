#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "intarr.h"


intarr_t* intarr_create( unsigned int len );
void intarr_destroy( intarr_t* ia );
intarr_result_t intarr_set( intarr_t* ia, 
			    unsigned int index, 
			    int val );
intarr_result_t intarr_get( const intarr_t* ia, 
			    unsigned int index, 
			    int* i );
intarr_t* intarr_copy( const intarr_t* ia );
intarr_result_t intarr_sort( intarr_t* ia );
intarr_result_t intarr_find( intarr_t* ia, int target, int* i );
intarr_result_t intarr_push( intarr_t* ia, int val );
intarr_result_t intarr_pop( intarr_t* ia, int* i );
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen );
intarr_t* intarr_copy_subarray( intarr_t* ia, 
				unsigned int first, 
				unsigned int last );

//task 1
intarr_t* intarr_create( unsigned int len )
{
	intarr_t *array = malloc(sizeof(intarr_t));
	if(array == 0)
	{
		return NULL;
	}
	array->data = malloc(len*sizeof(int));
	if( array->data == 0 )
	{
		free(array);
    	return NULL;
	}
	array->len = len;
	return array;
}

//task 1
void intarr_destroy( intarr_t* ia )
{
	if(ia->data != NULL && ia != NULL)
	{
		free(ia->data);
		free(ia);	
	}
}

//task 2
intarr_result_t intarr_set( intarr_t* ia, 
			    unsigned int index, 
			    int val )
{
	if(ia == NULL)
	{
		return INTARR_BADARRAY;
	}
	if(index < ia->len)
	{
		ia->data[index] = val;
		return INTARR_OK;
	} else
	{
		return INTARR_BADINDEX;
	}
}

intarr_result_t intarr_get( const intarr_t* ia, 
			    unsigned int index, 
			    int* i )
{
	if(ia == NULL)
	{
		return INTARR_BADARRAY;
	}
	if(index < ia->len && i != NULL)
	{
		*i = ia->data[index];
		return INTARR_OK;
	} else
	{
		return INTARR_BADINDEX;
	}
}

//task 3
intarr_t* intarr_copy( const intarr_t* ia )
{
	/*if(ia == NULL)
	{
		return NULL;
	}
	intarr_t *dupe = NULL;

	dupe = malloc(ia->len*sizeof(intarr_t))
	dupe->data = malloc(ia->len*sizeof(int));

	memcpy(dupe->data, ia->data, sizeof(int));
	if(dupe != NULL)
	{
		dupe->len = ia->len;
		return dupe;
	}
	return NULL;*/
	intarr_t *dupe = malloc(sizeof(intarr_t));
	if(dupe == 0)
	{
		return NULL;
	}
	dupe->data = malloc(ia->len*sizeof(int));
	if( dupe->data == 0 )
	{
		free(dupe);
    	return NULL;
	}
	dupe->len = ia->len;
	memcpy(dupe->data, ia->data, dupe->len*sizeof(int));
	return dupe;
}

//task 4
intarr_result_t intarr_sort( intarr_t* ia )
{
	if(ia == NULL)
	{
		return INTARR_BADARRAY;
	}
	for(unsigned int i=1; i<ia->len; i++)
	{
		int x = ia->data[i];
		unsigned int j = i;

		while(j>0 && x<ia->data[j-1])
		{

			ia->data[j] = ia->data[j-1];
			j--;
		}

		ia->data[j] = x;
	}
	return INTARR_OK;
}

//task 5
intarr_result_t intarr_find( intarr_t* ia, int target, int* i )
{
	if(ia == NULL)
	{
		return INTARR_BADARRAY;
	}
	for(unsigned int j=0; j<ia->len; j++)
	{
		if(ia->data[j] == target && i != NULL)
		{
			*i = j;
			return INTARR_OK;
		}
	}
	return INTARR_NOTFOUND;
}

//task 6
intarr_result_t intarr_push( intarr_t* ia, int val )
{
	if(ia == NULL)
	{
		return INTARR_BADARRAY;
	}
	size_t size = sizeof(int);
	
	ia->len++;
	ia->data = realloc(ia->data, (ia->len)*size);
	ia->data[ia->len-1] = val;
	
	if(ia->data[ia->len-1] == val)
	{
		return INTARR_OK;
	} else
	{
		return INTARR_BADALLOC;
	}
}

intarr_result_t intarr_pop( intarr_t* ia, int* i )
{
	if(ia == NULL)
	{
		return INTARR_BADARRAY;
	}
	if(ia->len == 0)
	{
		return INTARR_BADINDEX;
	}
	if(i != NULL)
	{
		*i = ia->data[ia->len-1];
		ia->data[ia->len-1] = 0;
		ia->data = realloc(ia->data, (ia->len-1)*sizeof(int));
		ia->len--;
	}
	return INTARR_OK;
}

//task 7
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen )
{
	if(ia == NULL)
	{
		return INTARR_BADARRAY;
	}
	if(newlen < ia->len)
	{
		ia->len = newlen;
		ia->data = realloc(ia->data, newlen*sizeof(int));
	} else if(newlen > ia->len)
	{
		ia->data = realloc(ia->data, newlen*sizeof(int));
		for (unsigned int i = ia->len; i < newlen; ++i)
		{
			ia->data[i] = 0;
		}
		ia->len = newlen;
	}
	if(ia->data != NULL)
	{
		return INTARR_OK;
	} else
	{
		return INTARR_BADALLOC;
	}
}

//task 8
intarr_t* intarr_copy_subarray( intarr_t* ia, 
				unsigned int first, 
				unsigned int last )
{
	if(ia == NULL || first > last || first >= ia->len || 
		last >= ia->len)
	{
		return NULL;
	}
	
	intarr_t *dupe = malloc(sizeof(intarr_t));
	if(dupe == 0)
	{
		return NULL;
	}
	
	size_t size = (last - first)+1;
	dupe->data = malloc(size*sizeof(int));
	if( dupe->data == 0 )
	{
		free(dupe);
    	return NULL;
	}
	
	dupe->len = size;
	unsigned int j = 0;
	for (unsigned int i = first; i <= last; ++i)
	{
		dupe->data[j] = ia->data[i];
		j++;
	}
	return dupe;
}

//gcc -std=c99 -c intarr.c -W -Wall
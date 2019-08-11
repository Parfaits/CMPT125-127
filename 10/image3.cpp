#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <fstream>

#include "image3.hpp"

using namespace std;


Image::Image()
  : cols(0),   // initialization list 
    rows(0), 
    pixels(NULL) 
{
   // No work to do in constructor body in this example: 
   // the intialization list took care of it. 
   // All  members now have safe initial values.
}

Image::~Image()
{
   // free everything that could have been allocated inside this object
   if( pixels != NULL ) 
   {
      delete[] pixels; 
   }
}

int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor )
{
	
	cols = width;
	rows = height;
	pixels = new uint8_t*[rows];
	for (unsigned int i = 0; i < rows; ++i)
	{
		pixels[i] = new uint8_t[cols];
		for (unsigned int j = 0; j < cols; ++j)
		{
			
			pixels[i][j] = fillcolor;
		}
	}
	return 0;
}

int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color )
{
	if(x>=cols)
	{
		return 1;
	}
	if(y>=rows)
	{
		return 2;
	}
	pixels[y][x] = color;
	return 0;
}

int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp )
{
	if(x>=cols)
	{
		return 1;
	}
	if(y>=rows)
	{
		return 2;
	}
	if(colorp == NULL)
	{
		return 3;
	}
	*colorp = pixels[y][x];
	return 0;
}

int Image::save( const char* filename )
{
	ofstream f(filename);
	if(f == NULL)
	{
		return 1;
	}
	f << cols << " " << rows << " ";
	for (unsigned int i = 0; i < rows; ++i)
	{
		for (unsigned int j = 0; j < cols; ++j)
		{
			f << (unsigned int) pixels[i][j] << " ";   // IMPORTANT CAST!!!
		}
			
	}

	f.close();
	return 0;
}

int Image::load( const char* filename )
{
	if(filename == NULL)
	{
		return 2;
	}
	ifstream f(filename);
	if(f == NULL)
	{
		return 1;
	}
	//printf("%i\n", ftell(f));
	unsigned int a=0, c=0, r=0;
	int holdit; //temp storage important note: has to be int
	while(f >> holdit)
	{
		//printf("%i, ", holdit);
		if(a == 0)
		{
			cols = holdit;
		} else if(a == 1)
		{
			rows = holdit;
			pixels = new uint8_t*[rows];
			for (unsigned int i = 0; i < rows; ++i)
			{
				pixels[i] = new uint8_t[cols];
			}
		} else
		{
			if(a-2 < cols*rows)
			{
				if(c >= cols && r < rows)
				{
					c = 0;
					r++;
				}
				pixels[r][c] = (uint8_t) holdit;
				c++;
			}
		}
		
		//printf("%d\n", arr->data[a]);
		a++;
	}
	//printf("a:%i\n", a);
	f.close();
	return 0;
}

int main()
{
	printf("hilol\n");
	Image *a;
	a = new Image;
	a->pixels = new uint8_t*[4];   //4x4
	for (unsigned int k = 0; k < 4; ++k)
	{
		a->pixels[k] = new uint8_t[4];
	}
	printf("This is totally wrong\n");
	a->cols = 4;
	a->rows = 4;
	printf("%i, %i\n", a->cols, a->rows);
	printf("WUT\n");
	for (unsigned int i = 0; i < a->rows; ++i)
	{
		for (unsigned int l = 0; l < a->cols; ++l)
		{
			a->pixels[i][l] = l;
			printf("%u ", a->pixels[i][l]);
		}
		
	}
	printf("seg fault\n");
	int b = a->save("test.txt");
	printf("%i\n", b);
	a->load("test.txt");
	for (unsigned int j = 0; j < a->rows; ++j)
	{
		for (unsigned int n = 0; n < a->cols; ++n)
		{
			a->pixels[j][n] = n;
			printf("%u ", a->pixels[j][n]);
		}
	}
	return 0;
}
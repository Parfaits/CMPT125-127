#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <fstream>

#include "image2.hpp"

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
	pixels = new uint8_t[width*height];
	for (unsigned int i = 0; i < cols; ++i)
	{
		for (unsigned int j = 0; j < rows; ++j)
		{
			pixels[ j * cols + i ] = fillcolor;
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
	pixels[ y * cols + x ] = color;
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
	*colorp = pixels[ y*cols + x ];
	return 0;
}

int Image::save( const char* filename )
{
	ofstream f(filename);
	if(f == NULL)
	{
		return 1;
	}
	f <<  cols << " " <<  rows << " ";
	for (unsigned int i = 0; i < cols*rows; ++i)
	{
		f << (unsigned int) pixels[i] << " "; // IMPORTANT CAST!!!
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
	unsigned int a=0;
	int holdit; //temp storage important note: has to be int
	int len = 0;
	while(f >> holdit)
	{
		//printf("%i, ", holdit);
		if(a == 0)
		{
			cols =  holdit;
		} else if(a == 1)
		{
			rows =  holdit;
			pixels = new uint8_t[cols*rows];
		} else
		{
			if(a-2 < cols*rows)
			{
				pixels[a-2] = (uint8_t) holdit;
			}
			//printf("%i\n", pixels[a-2]);
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
	a->pixels = new uint8_t[16];
	printf("This is totally wrong\n");
	a->cols = 4;
	a->rows = 4;
	printf("%i, %i\n", a->cols, a->rows);
	printf("WUT\n");
	for (unsigned int i = 0; i < a->cols*a->rows; ++i)
	{
		a->pixels[i] = i;
		printf("%i ", a->pixels[i]);
	}
	//printf("seg fault\n");
	int b = a->save("test.txt");
	printf("%i\n", b);
	Image *c;
	c = new Image;
	c->pixels = new uint8_t[16];
	c->load("test.txt");
	printf("pixels in %ux%u c: \n", c->cols, c->rows);
	for (unsigned int j = 0; j < c->cols*c->rows; ++j)
	{
		//printf("%u ", c->pixels[j]);
	}
	return 0;
}
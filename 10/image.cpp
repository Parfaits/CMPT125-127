#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <fstream>

#include "image.hpp"

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
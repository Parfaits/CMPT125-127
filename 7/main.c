#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main( int argc, char* argv[] )
{
  list_t* list = list_create();

  list_t *a =list_create();
  a->head = NULL;
  list_index(a,6);// t1

  list_t *b = list_create();
  list_prepend(b, 4);
  if(b->tail != b->head)
  {
    printf("SWAG\n");
    return 1; //t4
  }

  list_t *apfail = list_create();
  list_append(apfail, 35);
  list_index(apfail, 7); //6
  

  list_t *elefail = list_create();
  list_append(elefail, 56);
  list_append(elefail, 53);
  list_destroy(elefail);
  list_append(list, 43);
  list_append(list, 54);list_append(list, 2);
  if(list->tail->next != NULL)
  {
    printf("error\n");
    return 1;

  }
  

  list_t *_c_ = list_create();
  list_index(_c_, 10);//t3 
  //list_t *a = list_create();
  //list_append(a, 1);


  for( int i=0; i<5; i++ )
    list_append( list, i );
  
  for( int i=-1; i>-5; i-- )
    list_prepend( list, i );
  
  list_print( list );

  
  int index = 2;
  element_t* el = list_index( list, index );
  
  if( el == NULL )
    {
      printf( "index %d not found\n", index );
      return 1; // fail
    }
  
  printf( "value at index %d is %d\n", index, el->val );
  
  if( el->val != -2 ) 
    return 1;
  
  list_destroy( list );
  printf("CORRECT!!!!!!\n");
  return 0; // tests pass
}

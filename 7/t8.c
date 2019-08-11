#include <stdio.h>
#include <stdlib.h>

#include "list.h"


void list_sort( list_t* list );

void list_sort( list_t* list )
{
	if (list->head == list->tail) {
        return;
    }

    int pivot = list->head->val;
    element_t * pivot_node = list->head;
    list->head = list->head->next;


    list_t * first = list_create();
    list_t * second = list_create();
    element_t * curr = list->head;
    element_t * next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = NULL;
        if (curr->val <= pivot) {
            if (curr != NULL) {
		        curr->next = NULL;
		        if (first->tail == NULL) {
		            first->head = curr;
		            first->tail = curr;
		        } else {
		            first->tail->next = curr;
		            first->tail = curr;
		        }
		    }
        } else {
            if (curr != NULL) {
		        curr->next = NULL;
		        if (second->tail == NULL) {
		            second->head = curr;
		            second->tail = curr;
		        } else {
		            second->tail->next = curr;
		            second->tail = curr;
		        }
		    }
        }
        curr = next;
    }
    list->head = NULL;
    list->tail = NULL;


    list_sort(first);
    list_sort(second);

    if (first->head == NULL) {
        NULL;
    } else if (list->head == NULL) {
        *list = *first;
    } else {
        list->tail->next = first->head;
        list->tail= first->tail;
    }
    free(first);
    if (pivot_node != NULL) {
        pivot_node->next = NULL;
        if (list->tail == NULL) {
            list->head = pivot_node;
            list->tail = pivot_node;
        } else {
            list->tail->next = pivot_node;
            list->tail = pivot_node;
        }
    }
    if (second->head == NULL) {
        NULL;
    } else if (list->head == NULL) {
        *list = *second;
    } else {
        list->tail->next = second->head;
        list->tail= second->tail;
    }
    free(second);
}

int main()
{
	list_t* list = list_create();
	if(list == NULL)
	{
    	printf("create failed\n");
    	free(list);
    	return 1;
  	}
    for (int i = 10; i >= 0 ; --i)
    {
        list_append(list, i);
    }
  	/*int i = 0;
  	int j = -1;

	for( i=0; i<5; i++ )
    	list_append( list, i );
  
	for( j=-1; j>-5; j-- )
    	list_prepend( list, j );
    list_append(list, -5);
*/    list_sort(list);
    list_print(list);
	return 0;
}
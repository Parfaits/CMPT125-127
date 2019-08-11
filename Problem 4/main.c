#include <stdio.h>
#include <stdlib.h>

#include "LL.h"


void reverse(LL_t* L);
unsigned int removeNumber(LL_t* L, int target);
void merge(LL_t* L1, LL_t* L2);

void reverse(LL_t* L)
{
	if(L->tail != NULL)
	{
		//assert L->head != NULL
		node_t *first = L->head;
		node_t *back = L->head->next;
		//printf("%i\n", L->head->data);
		if(back == NULL) return;
		L->head = back;
		reverse(L);
		back->next = first;
		first->next = NULL;
		L->tail = first;
		//printf("%i %i\n", L->tail->data, L->tail->next->data);
	}
}

unsigned int removeNumber(LL_t* L, int target)
{
	node_t *curr = L->head;
	node_t *prev = NULL;
	unsigned int swag = 0;
	while(curr != NULL)
	{
		/*if(prev->data == target)
		{
			free(prev);

		}*/
		if(curr->data == target)
		{
			if(curr == L->head)
			{
				L->head = curr->next;
				free(curr);
				swag++;
			} else
			{
			prev->next = curr->next;
			free(curr);
			swag++;
			}
		}
		prev = curr;
		curr = curr->next;
	}
	if(swag < 1)
	{
		//printf("%i\n", swag);
		return 1;
	}
	return 0;
}

void merge(LL_t* L1, LL_t* L2)
{
	if (L2->head == NULL) {
        NULL;
    } else if (L1->head == NULL) {
        *L1 = *L2;
    } else {
        L1->tail->next = L2->head;
        L1->tail= L2->tail;
    }
    free(L2);
    LLquickSort(L1);
}

int main()
{
	LL_t *a = LLcreate();
	LL_t *b = LLcreate();
	/*for (int i = 0; i <= 10; ++i)
	{
		LLappend(a, i);
	}*/
	//[42 36 14 17 48 36]
	LLappend(a, 42);
	LLappend(a, 36);
	LLappend(a, 14);
	LLappend(a, 17);
	LLappend(a, 48);
	LLappend(a, 36);
	LLappend(a, 52);
	LLappend(a, 4);
	LLappend(a, 43);
	LLappend(b, 42);
	LLappend(b, 67);
	LLappend(b, 6);
	//reverse(a);
	merge(a, b);
	//unsigned int n = removeNumber(a, 0);
	//printf("%i\n", i);
	LLprint(a);
	//printf("bicboi: %i\n", n);
	//printf("%i %i\n", a->head->data, a->tail->data);
	return 0;
}

//gcc -std=c99 LL.o linklist.c -o linklist -W -Wall
#include <stdio.h>
#include <stdlib.h>

#define N 20


typedef struct {
	int data[N];
	int top; // =len
	int bottom; // =0
} stak_t;


int push(stak_t* T, int x);
int height(stak_t* T);
int pop(stak_t* T);
int isEmpty(stak_t* T);
int peek(stak_t* T);
void print(stak_t* T);

int push(stak_t* T, int x)
{
	if(T->top < N && T != NULL)
	{
		T->data[T->top] = x;
		T->top++;
		printf("Push %i, successful\n", x);
		return 0;
	}
	printf("Attempted push. Is full, stack unmodified. Returned -1\n");
	return -1;
}

int pop(stak_t* T)
{
	if(T != NULL && T->top != T->bottom)
	{
		printf("Pop %i, successful\n", T->data[T->top-1]);
		T->data[T->top-1] = 0;
		T->top--;
		return 0;
	}
	printf("Attempted pop. Is empty, stack unmodified. Returned -1\n");
	return -1;
}

int isEmpty(stak_t* T)
{
	if(T->top == T->bottom)
	{
		return 1;
	} else
	{
		return 0;
	}
}

int peek(stak_t* T)
{
	if(T != NULL && T->top != T->bottom)
	{
		return T->data[T->top-1];
	}
	printf("Attempted peek. Stack is empty. Returned -1\n");
	return -1;
}

int height(stak_t* T)
{
	return T->top;
}

void print(stak_t* T)
{
	if (T != NULL)
	{
		printf("Current Stack\n");
		for (int i = T->top-1; i >= 0; --i)
		{
			printf("%i\n", T->data[i]);
		}
	}
}

int main()
{
	stak_t *a = malloc(N*sizeof(stak_t));
	for (int i = 11; i <= 30; ++i)
	{
		push(a, i);
	}
	//printf("len:%i", a->top);
	//push(a, 10);
	//int b = push(a, 12);
	//push(a, 1);
	//push(a, 3);
	//pop(a);
	//push(a, 31);
	print(a);
	printf("height:%i\npeek:%i\nisEmpty:%i\n", height(a), peek(a), isEmpty(a));
	for (int j = a->top; j >= 0; --j) //At j=0 pops the a->data[-1] element(unsuccessful case)
	{
		pop(a);
	}
	print(a);
	printf("height:%i\npeek:%i\nisEmpty:%i\n", height(a), peek(a), isEmpty(a));
	free(a);
	return 0;
}

//gcc -std=c99 ADT.c -o ADT -W -Wall
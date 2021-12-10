/*
Bericht:
ein grosses problem war die undeutliche definierung der Vorgaben.
Vorallem der letzte punkt intepretierte ich am anfang so als m�sste der 
Stack selbst die neu initialisierung vornehmen. jedoch waren die testf�lle
nicht auf diese Implementation ausgelegt.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

typedef struct 
{
	int top = 0;
	bool ripStack = false;
	char data[];
}stack;

typedef enum
{
	success;
	stackEmpty;
	stackFull;
	stackCorrupted
}errorCode;

void stack_init(void)
{
	top = 0;
	ripStack = false;
}

errorCode stack_push(stack* s, char c)
{
	if (ripStack == false)
	{
		if ((c >= '0' && c <= '9') ||
			(c >= 'A' && c <= 'Z') ||
			(c >= 'a' && c <= 'z') ||
			(c == ' '))
		{
			s->data = c;
		}
		else
		{
			data[top] = '*';
		}
		top++;
	}
}

errorCode stack_pop(void)
{
	if (ripStack == false)
	{
		if (top > 0 && top < STACK_SIZE)
		{
			top--;
			return data[top];
		}
		else
		{
			ripStack = true;
		}
	}
	return '\0';
}

char stack_peek(void)
{
	if (ripStack == true)
	{
		return '\0';
	}
	if (top > 0 && top <= STACK_SIZE)
	{
		return data[top - 1];
	}
	else
	{
		return '\0';
	}
}
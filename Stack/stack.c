/*
Bericht:
ein grosses problem war die undeutliche definierung der Vorgaben.
Vorallem der letzte punkt intepretierte ich am anfang so als müsste der 
Stack selbst die neu initialisierung vornehmen. jedoch waren die testfälle
nicht auf diese Implementation ausgelegt.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define STACK_SIZE 100

char contents[STACK_SIZE];
bool ripStack = false;
int top = 0;

void stack_init(void)
{
	top = 0;
	ripStack = false;
}

void stack_push(char c)
{
	if (ripStack == false)
	{
		if ((c >= '0' && c <= '9') ||
			(c >= 'A' && c <= 'Z') ||
			(c >= 'a' && c <= 'z') ||
			(c == ' '))
		{
			contents[top] = c;
		}
		else
		{
			contents[top] = '*';
		}
		top++;
	}
}

char stack_pop(void)
{
	if (ripStack == false)
	{
		if (top > 0 && top < STACK_SIZE)
		{
			top--;
			return contents[top];
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
		return contents[top - 1];
	}
	else
	{
		return '\0';
	}
}
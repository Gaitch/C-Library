#include <stdlib.h> 	
#include <stdio.h> 	
#include "stack.h"

typedef struct
{
	int value;
	struct node* next;
}Node;

typedef struct
{
	Node* top;
}Stack;

Stack* stack;

Stack* initStack()
{
	stack = malloc(sizeof(Stack));
    if(stack != NULL)
    {
	    stack->top = NULL;
    }
}

void insertNode(Node* node)
{
	Node* currentNode = stack->top;
	Node* prevNode = NULL;

	while (currentNode != NULL && currentNode->value < node->value)
	{
		prevNode = currentNode;
		currentNode = currentNode->next;
	}

	if (prevNode)
	{	
		prevNode->next = node;
	}
	else
	{
		stack->top = node;
	}
	node->next = currentNode;
}

Node* createNewNode(int value)
{
	Node* newNode = malloc(sizeof(Node));
    if(newNode != NULL)
    {
        newNode->value = value;
	    newNode->next = NULL;
	    return newNode;
    }
}

void push(int value)
{
	Node* node = createNewNode(value);
	insertNode(node);
}

bool pop(int* value)
{
	if (stack->top == NULL)
	{
		return false;
	}
	else
	{
		Node* tmp = stack->top;
		*value = stack->top->value;
		stack->top = stack->top->next;
		free(tmp);
		return true;
	}
}
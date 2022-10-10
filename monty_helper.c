#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

stack_t *top = NULL;

/**
 * push - add items to stack
 * @value: the value to add
 * @mystack: the stack
 *
 * Return: a stack
 *
 */
stack_t *push(int value, stack_t **mystack)
{
	stack_t *current = *mystack;
	stack_t *new_item = malloc(sizeof(stack_t));

	if (new_item == NULL)
		return (NULL);

	new_item->n = value;
	new_item->prev = NULL;
	new_item->next = NULL;

	if (current == NULL)
	{
		*mystack = new_item;
		top = new_item;
	}
	else
	{
		new_item->next = top;
		top->prev = new_item;

		*mystack = new_item;
		top = new_item;
	}

	return (new_item);
}

/**
 * pall - print all
 * @mystack: the stack
 *
 */
void pall(stack_t *mystack)
{
	stack_t *current = mystack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/* ------------------------------------------------------------------------- */
/*                                 Includes                                  */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "stack.h"



/* ------------------------------------------------------------------------- */
/*                             Local definitions                             */
/* ------------------------------------------------------------------------- */

#define VAL_ALLOC 5
#define VAL_FREE 10



/* ------------------------------------------------------------------------- */
/*                        Local functions prototypes                         */
/* ------------------------------------------------------------------------- */


/**
 * @brief Assigns the value of the second element to the first element.
 * @param elt1 Pointer on an element
 * @param elt2 Pointer on an element
 */
void _assignElements(elt_t* elt1, elt_t* elt2);

/**
 * @brief Prints an element.
 * @param element The element to print
 */
void _printElement(elt_t element);



/* ------------------------------------------------------------------------- */
/*                           Functions definitions                           */
/* ------------------------------------------------------------------------- */

void _assignElements(elt_t* elt1, elt_t* elt2)
{
    *elt1 = *elt2;
}



void _printElement(elt_t element)
{
    printf("%d", element);
}



void Stack_init(stack_t* stack)
{
    assert(stack != NULL);
    stack->top = 0;
    stack->size = 0;
    stack->data = (elt_t*)malloc(sizeof(elt_t));
}



elt_t Stack_pop(stack_t* stack)
{
    elt_t e;
    assert(stack->top != 0);
    _assignElements(&e, &stack->data[--stack->top]);

    if (stack->size - stack->top == VAL_FREE) {
        stack->size -= VAL_FREE;
        stack->data = (elt_t*)realloc(stack->data, stack->size * sizeof(elt_t));
        assert(stack->data != NULL);
    }

    return e;
}



void Stack_push(stack_t* stack, elt_t e)
{
    if (stack->size == stack->top) {
        stack->size += VAL_ALLOC;
        stack->data = (elt_t*)realloc(stack->data, stack->size * sizeof(elt_t));
        assert(stack->data != NULL);
    }
    _assignElements(&stack->data[stack->top++], &e);
}



void Stack_print(stack_t* stack)
{
    if (Stack_isEmpty(*stack)) {
        printf("[Empty stack]\n");
        return;
    }

    for (int i = 0; i < stack->top; i++) {
        printf("%d : ", i);
        _printElement(stack->data[i]);
        printf("\n");
    }
}



elt_t Stack_top(stack_t stack)
{
    return stack.top;
}



int Stack_size(stack_t stack)
{
    return stack.size;
}



bool Stack_isEmpty(stack_t stack)
{
    return stack.top == 0;
}



elt_t Stack_valueOf(stack_t stack, unsigned int index)
{
    stack_t saveStack;
    Stack_init(&saveStack);

    // Pop elements and save them in the save stack
    for (unsigned int j = Stack_top(stack); j > index + 1; j--)
        Stack_push(&saveStack, Stack_pop(&stack));

    // Stock the value of desired element, then put it in the save stack
    elt_t value = Stack_pop(&stack);
    Stack_push(&saveStack, value);

    // Push back elements on the base stack
    while (!Stack_isEmpty(saveStack))
        Stack_push(&stack, Stack_pop(&saveStack));

    return value;
}

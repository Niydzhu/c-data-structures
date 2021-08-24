/**
 * @file    stack.h
 * @brief   Dynamic stack's data structure implementation.
 * @date    2021-08-07
 *
 */

#ifndef STACK_H
#define STACK_H

/* ------------------------------------------------------------------------- */
/*                                 Includes                                  */
/* ------------------------------------------------------------------------- */

#include <stdbool.h>



/* ------------------------------------------------------------------------- */
/*                                Definitions                                */
/* ------------------------------------------------------------------------- */

/**
 * @typedef elt_t
 * @brief Element type
 */
typedef int elt_t;

/**
 * @typedef struct_t
 * @brief Stack type
 */
typedef struct stack stack_t;

/**
 * @struct stack
 * @brief Stack's struct
 * @var stack::data Adress of the data array
 * @var stack::top Index of the top of the stack
 * @var stack::size Size of the stack
 */
struct stack
{
    elt_t* data;
    int top;
    int size;
};



/* ------------------------------------------------------------------------- */
/*                                Prototypes                                 */
/* ------------------------------------------------------------------------- */

/**
 * @brief Initializes a stack.
 * @param stack The stack
 */
void Stack_init(stack_t* stack);

/**
 * @brief Removes an element from a stack and returns it.
 * @param stack The stack
 * @return The removed element
 */
elt_t Stack_pop(stack_t* stack);

/**
 * @brief Adds an element on top of the stack.
 * @param stack The stack
 * @param e The element to push
 */
void Stack_push(stack_t* stack, elt_t e);

/**
 * @brief Prints the values of the elements of the stack.
 * @param stack The stack
 */
void Stack_print(stack_t* stack);

/**
 * @brief Returns the index of the top of a stack.
 * @param stack The stack
 * @return The index of the top of the stack
 */
elt_t Stack_top(stack_t stack);

/**
 * @brief Returns the size of a stack.
 * @param stack The stack
 * @return The size of the stack
 */
int Stack_size(stack_t stack);

/**
 * @brief Determines if a stack is empty.
 * @param stack The stack
 * @return True if the stack is empty, false if not
 */
bool Stack_isEmpty(stack_t stack);

/**
 * @brief Returns the value of an element in a stack,
 * from it's index.
 * @param stack The stack
 * @param index The index of the element
 * @return The value of the desired element
 */
elt_t Stack_valueOf(stack_t stack, unsigned int index);

#endif

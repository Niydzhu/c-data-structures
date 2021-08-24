/* ------------------------------------------------------------------------- */
/*                                 Includes                                  */
/* ------------------------------------------------------------------------- */

#include <stdio.h>

#include "./src/stack.h"



/* ------------------------------------------------------------------------- */
/*                               Main function                               */
/* ------------------------------------------------------------------------- */

int main()
{
    stack_t stack;
    Stack_init(&stack);

    Stack_push(&stack, 5);
    Stack_push(&stack, 1);
    Stack_push(&stack, 0);
    Stack_push(&stack, 4);
    Stack_push(&stack, 18);

    Stack_pop(&stack);

    Stack_print(&stack);

    printf("\nSize : %d\n", Stack_size(stack));

    return 0;
}

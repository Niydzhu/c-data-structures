/* ------------------------------------------------------------------------- */
/*                                 Includes                                  */
/* ------------------------------------------------------------------------- */

#include <stdio.h>

#include "./src/vector.h"



/* ------------------------------------------------------------------------- */
/*                               Main function                               */
/* ------------------------------------------------------------------------- */

int main()
{
    vector_t vector;
    Vector_init(&vector);

    Vector_push(&vector, 4);
    Vector_push(&vector, 8);
    Vector_push(&vector, 16);
    Vector_push(&vector, 32);
    Vector_push(&vector, 64);
    Vector_pop(&vector);
    Vector_set(&vector, 0, 99);
    Vector_remove(&vector, 1);

    for (int i = 0; i < Vector_size(vector); i++)
        printf("%d ", Vector_get(&vector, i));

    return 0;
}

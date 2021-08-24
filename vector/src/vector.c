/* ------------------------------------------------------------------------- */
/*                                 Includes                                  */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "vector.h"



/* ------------------------------------------------------------------------- */
/*                        Local functions prototypes                         */
/* ------------------------------------------------------------------------- */


/**
 * @brief Assigns the value of the second element to the first element.
 * @param elt1 Pointer on an element
 * @param elt2 Pointer on an element
 */
void _assignElements(elt_t* elt1, elt_t* elt2);



/* ------------------------------------------------------------------------- */
/*                           Functions definitions                           */
/* ------------------------------------------------------------------------- */

void _assignElements(elt_t* elt1, elt_t* elt2)
{
    *elt1 = *elt2;
}



void Vector_init(vector_t* vector)
{
    assert(vector != NULL);
    vector->size = 0;
    vector->data = NULL;
}



void Vector_free(vector_t* vector)
{
    if (vector != NULL)
        free(vector->data);
}



int Vector_size(vector_t vector)
{
    return vector.size;
}



bool Vector_push(vector_t* vector, elt_t e)
{
    if (vector->size == VECTOR_MAX_SIZE)
        return false;


    vector->data = (elt_t*)realloc(vector->data, (vector->size + 1) * sizeof(elt_t));
    assert(vector->data != NULL);
    _assignElements(&vector->data[vector->size], &e);
    vector->size++;
    return true;
}



elt_t Vector_pop(vector_t* vector)
{
    assert(vector->size > 0);
    elt_t e;
    _assignElements(&e, &vector->data[vector->size]);
    vector->size--;
    vector->data = (elt_t*)realloc(vector->data, (vector->size) * sizeof(elt_t));
    return e;
}



elt_t Vector_remove(vector_t* vector, int index)
{
    assert(index >= 0 && vector->size > index);
    elt_t e;
    _assignElements(&e, &vector->data[index]);

    // Fill the empty space from the removed element by moving all elements
    // to the right of the removed element to the left
    for (int i = index; i < vector->size - 1; i++)
        _assignElements(&vector->data[i], &vector->data[i + 1]);

    vector->size--;
    vector->data = (elt_t*)realloc(vector->data, (vector->size) * sizeof(elt_t));
    return e;
}



elt_t Vector_get(vector_t* vector, int index)
{
    return vector->data[index];
}



bool Vector_set(vector_t* vector, int index, elt_t e)
{
    if (index >= 0 && vector->size > index) {
        _assignElements(&vector->data[index], &e);
        return true;
    }
    return false;
}

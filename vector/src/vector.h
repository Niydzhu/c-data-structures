/**
 * @file    vector.h
 * @brief   Vector's data structure implementation. (Dynamic array)
 * @date    2021-08-09
 *
 */

#ifndef VECTOR_H
#define VECTOR_H

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
 * @typedef vector_t
 * @brief Vector type
 */
typedef struct vector vector_t;

/**
 * @struct vector
 * @brief Vector's struct
 * @var vector::data Pointer to the data array
 * @var vector::size Size of the vector
 */
struct vector {
    elt_t* data;
    int size;
};

#ifndef VECTOR_MAX_SIZE
#define VECTOR_MAX_SIZE 100 // Max size of a vector
#endif



/* ------------------------------------------------------------------------- */
/*                                Prototypes                                 */
/* ------------------------------------------------------------------------- */

/**
 * @brief Initializes a vector.
 * @param vector The vector
 */
void Vector_init(vector_t* vector);

/**
 * @brief Deletes a vector and frees all allocated memory.
 * @param vector The vector
 */
void Vector_free(vector_t* vector);

/**
 * @brief Returns the size of a vector.
 * @param vector The vector
 * @return The size of the vector
 */
int Vector_size(vector_t vector);

/**
 * @brief Pushes an element into the end of a vector.
 * @param vector The vector
 * @param e The element to push
 * @return True if the element was added, false if not
 */
bool Vector_push(vector_t* vector, elt_t e);

/**
 * @brief Removes the element at the end of a vector and returns it.
 * @param vector The vector
 * @return The removed element at the end of the vector
 */
elt_t Vector_pop(vector_t* vector);

/**
 * @brief Removes an element of a vector from it's index.
 * @param vector The vector
 * @param index The index of the element to remove
 * @return The removed element
 */
elt_t Vector_remove(vector_t* vector, int index);

/**
 * @brief Returns an element from it's index.
 * @param vector The vector
 * @param index The index of the element to retrieve
 * @return The element
 */
elt_t Vector_get(vector_t* vector, int index);

/**
 * @brief Sets a new value for an element of a vector from it's index.
 * @param vector The vector
 * @param index The index of the element to replace the value of
 * @param e The element with the new value
 * @return True if the replacement worked, false if not
 */
bool Vector_set(vector_t* vector, int index, elt_t e);

#endif

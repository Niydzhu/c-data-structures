/**
 * @file    queue.h
 * @brief   Queue's data structure implementation.
 * @date    2021-08-07
 *
 */

#ifndef QUEUE_H
#define QUEUE_H

/* ------------------------------------------------------------------------- */
/*                                 Includes                                  */
/* ------------------------------------------------------------------------- */

#include <stdbool.h>



/* ------------------------------------------------------------------------- */
/*                                Definitions                                */
/* ------------------------------------------------------------------------- */

#ifndef QUEUE_MAX_SIZE
#define QUEUE_MAX_SIZE 10
#endif

/**
 * @typedef elt_t
 * @brief Element type
 */
typedef int elt_t;

/**
 * @typedef queue_t
 * @brief Queue type
 */
typedef struct queue queue_t;

/**
 * @struct queue
 * @brief Queue's struct
 * @var queue::data Adress of the data array
 * @var queue::left Index of the head of the queue
 * @var queue::right Index of the tail of the queue
 */
struct queue
{
    elt_t data[QUEUE_MAX_SIZE];
    int head;
    int tail;
};



/* ------------------------------------------------------------------------- */
/*                                Prototypes                                 */
/* ------------------------------------------------------------------------- */

/**
 * @brief Initializes a queue.
 * @param stack The queue
 */
void Queue_init(queue_t* queue);

/**
 * @brief Removes an element from the head of a queue.
 * @param queue The queue
 * @param e An element in which the value of the removed element
 * will be stored
 * @return True if the dequeue worked successfully, false if not
 */
bool Queue_dequeue(queue_t* queue, elt_t* e);

/**
 * @brief Adds an element to the tail of a queue.
 * @param queue The queue
 * @param e The element to add
 * @return True if the enqueue worked successfully, false if not
 */
bool Queue_enqueue(queue_t* queue, elt_t* e);

/**
 * @brief Determines if a queue is empty.
 * @param queue The queue
 * @return True if the queue is empty, false if not
 */
bool Queue_isEmpty(const queue_t* queue);

/**
 * @brief Determines if a queue is full.
 * @param queue The queue
 * @return True if the queue is full, false if not
 */
bool Queue_isFull(const queue_t* queue);

/**
 * @brief Returns the value first element of a queue
 * without removing it.
 * @param queue The queue
 * @return The value of first element of the queue
 */
elt_t Queue_peek(queue_t* queue);

/**
 * @brief Prints the values of a queue.
 * @param queue The queue
 */
void Queue_print(queue_t* queue);

#endif

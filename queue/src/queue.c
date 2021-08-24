/* ------------------------------------------------------------------------- */
/*                                 Includes                                  */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdbool.h>

#include "queue.h"



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



void Queue_init(queue_t* queue)
{
    queue->head = -1;
    queue->tail = -1;
}



bool Queue_dequeue(queue_t* queue, elt_t* e)
{
    if (Queue_isEmpty(queue))
        return false;

    _assignElements(e, &queue->data[queue->head + 1]);
    for (int i = queue->head + 1; i <= queue->tail; i++)
        _assignElements(&queue->data[i], &queue->data[i + 1]);
    queue->tail--;

    return true;
}



bool Queue_enqueue(queue_t* queue, elt_t* e)
{
    if (Queue_isFull(queue))
        return false;

    // New queue (after being initialized)
    if (queue->head == -1) {
        queue->head++;
        queue->tail++;
    }
    queue->tail++;
    _assignElements(&queue->data[queue->tail], e);

    return true;
}



bool Queue_isEmpty(const queue_t* queue)
{
    return queue->tail <= 0;
}



bool Queue_isFull(const queue_t* queue)
{
    return queue->tail == QUEUE_MAX_SIZE - 1;
}



elt_t Queue_peek(queue_t* queue)
{
    return queue->data[queue->head + 1];
}



void Queue_print(queue_t* queue)
{
    if (Queue_isEmpty(queue)) {
        printf("[Empty queue]\n");
        return;
    }

    for (int i = queue->head + 1; i <= queue->tail; i++) {
        printf("%d : ", i);
        _printElement(queue->data[i]);
        printf("\n");
    }
}

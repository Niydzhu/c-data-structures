/* ------------------------------------------------------------------------- */
/*                                 Includes                                  */
/* ------------------------------------------------------------------------- */

#include <stdio.h>

#include "./src/queue.h"



/* ------------------------------------------------------------------------- */
/*                               Main function                               */
/* ------------------------------------------------------------------------- */

int main()
{
    elt_t tempElement;
    queue_t queue;
    Queue_init(&queue);

    elt_t e1 = 4;
    elt_t e2 = 1;
    elt_t e3 = 81;
    elt_t e4 = 12;
    elt_t e5 = 34;

    Queue_enqueue(&queue, &e1);
    Queue_enqueue(&queue, &e2);
    Queue_enqueue(&queue, &e3);
    Queue_enqueue(&queue, &e4);
    Queue_enqueue(&queue, &e5);

    Queue_dequeue(&queue, &tempElement);

    Queue_print(&queue);

    return 0;
}

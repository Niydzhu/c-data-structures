/* ------------------------------------------------------------------------- */
/*                                 Includes                                  */
/* ------------------------------------------------------------------------- */

#include <stdio.h>

#include "./src/linkedList.h"



/* ------------------------------------------------------------------------- */
/*                               Main function                               */
/* ------------------------------------------------------------------------- */

int main()
{
    node_t* list = LinkedList_createNode(4, NULL);
    LinkedList_insertElement(82, &list, 'H');
    LinkedList_insertElement(19, &list, 'T');

    LinkedList_print(list);

    return 0;
}

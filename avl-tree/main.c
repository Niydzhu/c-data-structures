/* ------------------------------------------------------------------------- */
/*                                 Includes                                  */
/* ------------------------------------------------------------------------- */

#include <stdio.h>

#include "./src/AVL.h"



/* ------------------------------------------------------------------------- */
/*                               Main function                               */
/* ------------------------------------------------------------------------- */

int main()
{
    node_t* tree = AVL_createNode(7, NULL, NULL);
    AVL_insert(63, tree);
    AVL_insert(3, tree);
    AVL_insert(0, tree);
    AVL_insert(11, tree);

    AVL_print(tree);
    printf("\n");

    AVL_printReverse(tree);
    printf("\n\n");

    printf("Includes 3 : %s\n", AVL_includes(3, tree) ? "true" : "false");
    printf("Is balanced : %s\n", AVL_includes(3, tree) ? "true" : "false");
    printf("Height : %d\n", AVL_height(tree));
    printf("Size : %d\n\n", AVL_size(tree));

    tree = AVL_removeTree(tree);
    printf("Removed tree : ");
    AVL_print(tree);
    printf("\n");

    return 0;
}

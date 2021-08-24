/* ------------------------------------------------------------------------- */
/*                                 Includes                                  */
/* ------------------------------------------------------------------------- */

#include <stdio.h>

#include "./src/binarySearchTree.h"



/* ------------------------------------------------------------------------- */
/*                               Main function                               */
/* ------------------------------------------------------------------------- */

int main()
{
    node_t* tree = BST_createNode(7, NULL, NULL);
    BST_insert(63, tree);
    BST_insert(3, tree);
    BST_insert(0, tree);
    BST_insert(11, tree);

    BST_print(tree);
    printf("\n");

    BST_printReverse(tree);
    printf("\n\n");

    printf("Includes 3 : %s\n", BST_includes(3, tree) ? "true" : "false");
    printf("Height : %d\n", BST_height(tree));
    printf("Size : %d\n\n", BST_size(tree));

    tree = BST_removeTree(tree);
    printf("Removed tree : ");
    BST_print(tree);
    printf("\n");

    return 0;
}

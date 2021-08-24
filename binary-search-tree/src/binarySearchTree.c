/* ------------------------------------------------------------------------- */
/*                                 Includes                                  */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "binarySearchTree.h"



/* ------------------------------------------------------------------------- */
/*                             Local definitions                             */
/* ------------------------------------------------------------------------- */

#define DATA(t)     (t->data)
#define RIGHT(t)    (t->right)
#define LEFT(t)     (t->left)
#define	MAX(t1, t2) (t1 >= t2 ? t1 : t2)
#define EMPTY(t)    (t == NULL)
#define IS_LEAF(t)  (t->left == NULL && t->right == NULL)
#define IS_INNER(t) (t->left != NULL || t->right != NULL)



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
 * @brief Compare the value of 2 elements.
 * @param elt1 The first element
 * @param elt2 The second element
 * @return An integer greater than 0 if the first element
 * is greater than the second. An integer fewer than 0 if the first element
 * is smaller than the second. 0 if both elements are equal.
 */
int _compareElements(elt_t elt1, elt_t elt2);

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



int _compareElements(elt_t elt1, elt_t elt2)
{
    return elt1 - elt2;
}



void _printElement(elt_t element)
{
    printf("%d", element);
}



void BST_print(const node_t* tree)
{
    if (EMPTY(tree))
        return;

    BST_print(LEFT(tree));
    _printElement(DATA(tree));
    printf(" ");
    BST_print(RIGHT(tree));
}



void BST_printReverse(const node_t* tree)
{
    if (EMPTY(tree))
        return;

    BST_printReverse(RIGHT(tree));
    _printElement(DATA(tree));
    printf(" ");
    BST_printReverse(LEFT(tree));
}



unsigned int BST_size(const node_t* tree)
{
    if (EMPTY(tree))
        return 0;

    return 1 + BST_size(LEFT(tree)) + BST_size(RIGHT(tree));
}



bool BST_includes(elt_t e, const node_t* tree)
{
    if (EMPTY(tree))
        return false;
    if (_compareElements(DATA(tree), e) == 0)
        return true;
    if (_compareElements(e, DATA(tree)) > 0)
        return BST_includes(e, RIGHT(tree));
    return BST_includes(e, LEFT(tree));
}



node_t* BST_createNode(elt_t e, node_t* left, node_t* right)
{
    node_t* node;
    node = (node_t*)malloc(sizeof(node_t));
    if (node != NULL) {
        _assignElements(&node->data, &e);
        node->left = left;
        node->right = right;
    }
    return node;
}



node_t* BST_insert(elt_t e, node_t* tree)
{
    if (EMPTY(tree))
        return tree = BST_createNode(e, NULL, NULL);

    // If the value is already in the tree : failed to insert
    if (_compareElements(DATA(tree), e) == 0)
        return tree;

    if (_compareElements(DATA(tree), e) > 0)
        LEFT(tree) = BST_insert(e, LEFT(tree));
    else
        RIGHT(tree) = BST_insert(e, RIGHT(tree));

    return tree;
}



node_t* BST_copy(const node_t* tree)
{
    if (EMPTY(tree))
        return NULL;
    return BST_createNode(DATA(tree), BST_copy(LEFT(tree)), BST_copy(RIGHT(tree)));
}



node_t* BST_removeTree(node_t* tree)
{
    if (IS_LEAF(tree))
        free(tree);
    else {
        if (!EMPTY(LEFT(tree)))
            BST_removeTree(LEFT(tree));
        if (!EMPTY(RIGHT(tree)))
            BST_removeTree(RIGHT(tree));
    }
    return NULL;
}



node_t* BST_remove(elt_t e, node_t* tree)
{
    if (EMPTY(tree))
        return NULL;

    // If the element is inferior than the one of the current node, continue searching in the left sub-tree
    if (_compareElements(e, DATA(tree)) < 0)
        LEFT(tree) = BST_remove(e, LEFT(tree));

    // If the element is greater than the one of the current node, continue searching in the right sub-tree
    else if (_compareElements(e, DATA(tree)) > 0)
        RIGHT(tree) = BST_remove(e, RIGHT(tree));

    else {
        // The node has only one child
        if (EMPTY(LEFT(tree))) {
            node_t* temp = RIGHT(tree);
            tree = NULL;
            return temp;
        }

        else if (EMPTY(RIGHT(tree))) {
            node_t* temp = LEFT(tree);
            tree = NULL;
            return temp;
        }

        // The node has 2 children
        node_t* successor = BST_successor(RIGHT(tree));

        // Replace the data of the node to delete with the data of the successor
        _assignElements(&DATA(tree), &DATA(successor));

        // Remove the successor
        RIGHT(tree) = BST_remove(DATA(successor), RIGHT(tree));
    }

    return tree;
}



node_t* BST_successor(node_t* tree)
{
    node_t* current = BST_copy(tree);
    while (!EMPTY(LEFT(current)))
        current = LEFT(current);
    return current;
}



int BST_height(const node_t* tree)
{
    if (EMPTY(tree))
        return 0;
    return MAX(1 + BST_height(LEFT(tree)), 1 + BST_height(RIGHT(tree)));
}



bool BST_areEqual(const node_t* tree1, const node_t* tree2)
{
    // Compare both trees, also true of both are NULL
    if (tree1 == tree2)
        return true;

    // If only one node is empty
    if (EMPTY(tree1) || EMPTY(tree2))
        return false;

    // Verify that both nodes have the same data + recursion
    return (_compareElements(DATA(tree1), DATA(tree2)) == 0
        && BST_areEqual(LEFT(tree1), LEFT(tree2))
        && BST_areEqual(RIGHT(tree1), RIGHT(tree2)));
}

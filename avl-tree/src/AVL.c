/* ------------------------------------------------------------------------- */
/*                                 Includes                                  */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "AVL.h"



/* ------------------------------------------------------------------------- */
/*                             Local definitions                             */
/* ------------------------------------------------------------------------- */

#define DATA(t)         (t->data)
#define RIGHT(t)        (t->right)
#define LEFT(t)         (t->left)
#define	MAX(t1, t2)     (t1 >= t2 ? t1 : t2)
#define EMPTY(t)        (t == NULL)
#define IS_LEAF(t)      (t->left == NULL && t->right == NULL)
#define IS_INNER(t)     (t->left != NULL || t->right != NULL)
#define BAL(t)          (t->balance)
#define VALID_BAL(bal)  (bal >= -1 && bal <= 1)



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

/**
 * @brief Performs a left rotation from the root of an AVL tree
 * or sub-tree.
 * @param tree The AVL tree
 * @return The pointer to the tree after the rotation
 */
node_t* _leftRotation(node_t* tree);

/**
 * @brief Performs a right rotation from the root of an AVL tree
 * or sub-tree.
 * @param tree The AVL tree
 * @return The pointer to the tree after the rotation
 */
node_t* _rightRotation(node_t* tree);

/**
 * @brief Balances an AVL tree or sub-tree (AVL method)
 * @param tree The AVL tree
 * @return The pointer to the tree after the balancing
 */
node_t* _balance(node_t* tree);



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



node_t* _leftRotation(node_t* tree)
{
    node_t* newTree = RIGHT(tree);
    RIGHT(tree) = LEFT(newTree);
    LEFT(newTree) = tree;

    // Update tree and newTree's balances
    BAL(tree) += 1 - MAX(0, BAL(newTree));
    BAL(newTree) += 1 + MAX(0, BAL(tree));

    return newTree;
}



node_t* _rightRotation(node_t* tree)
{
    node_t* newTree = LEFT(tree);
    LEFT(tree) = RIGHT(newTree);
    RIGHT(newTree) = tree;

    // Update tree and newTree's balances
    BAL(tree) -= 1 + MAX(0, BAL(newTree));
    BAL(newTree) -= 1 - MAX(0, BAL(tree));

    return newTree;
}



node_t* _balance(node_t* tree)
{
    if (BAL(tree) == 2) {
        if (BAL(LEFT(tree)) == -1)
            LEFT(tree) = _leftRotation(LEFT(tree));
        tree = _rightRotation(tree);
    }

    if (BAL(tree) == -2) {
        if (BAL(RIGHT(tree)) == 1)
            RIGHT(tree) = _rightRotation(RIGHT(tree));
        tree = _leftRotation(tree);
    }

    return tree;
}



void AVL_print(const node_t* tree)
{
    if (EMPTY(tree))
        return;

    AVL_print(LEFT(tree));
    _printElement(DATA(tree));
    printf(" ");
    AVL_print(RIGHT(tree));
}



void AVL_printReverse(const node_t* tree)
{
    if (EMPTY(tree))
        return;

    AVL_printReverse(RIGHT(tree));
    _printElement(DATA(tree));
    printf(" ");
    AVL_printReverse(LEFT(tree));
}



unsigned int AVL_size(const node_t* tree)
{
    if (EMPTY(tree))
        return 0;

    return 1 + AVL_size(LEFT(tree)) + AVL_size(RIGHT(tree));
}



bool AVL_includes(elt_t e, const node_t* tree)
{
    if (EMPTY(tree))
        return false;
    if (_compareElements(DATA(tree), e) == 0)
        return true;
    if (_compareElements(e, DATA(tree)) > 0)
        return AVL_includes(e, RIGHT(tree));
    return AVL_includes(e, LEFT(tree));
}



bool AVL_isBalanced(const node_t* tree)
{
    if (EMPTY(tree))
        return true;
    if (!VALID_BAL(BAL(tree)))
        return false;
    return AVL_isBalanced(LEFT(tree)) && AVL_isBalanced(RIGHT(tree));
}



node_t* AVL_createNode(elt_t e, node_t* left, node_t* right)
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



node_t* AVL_insert(elt_t e, node_t* tree)
{
    if (EMPTY(tree))
        return tree = AVL_createNode(e, NULL, NULL);

    // If the value is already in the tree : failed to insert
    if (_compareElements(DATA(tree), e) == 0)
        return tree;

    if (_compareElements(DATA(tree), e) > 0)
        LEFT(tree) = AVL_insert(e, LEFT(tree));
    else
        RIGHT(tree) = AVL_insert(e, RIGHT(tree));

    if (IS_INNER(tree))
        BAL(tree) = AVL_height(LEFT(tree)) - AVL_height(RIGHT(tree));

    if (!VALID_BAL(BAL(tree)))
        tree = _balance(tree);

    return tree;
}



node_t* AVL_copy(const node_t* tree)
{
    if (EMPTY(tree))
        return NULL;
    return AVL_createNode(DATA(tree), AVL_copy(LEFT(tree)), AVL_copy(RIGHT(tree)));
}



node_t* AVL_removeTree(node_t* tree)
{
    if (IS_LEAF(tree))
        free(tree);
    else {
        if (!EMPTY(LEFT(tree)))
            AVL_removeTree(LEFT(tree));
        if (!EMPTY(RIGHT(tree)))
            AVL_removeTree(RIGHT(tree));
    }
    return NULL;
}



node_t* AVL_remove(elt_t e, node_t* tree)
{
    if (EMPTY(tree))
        return NULL;

    // If the element is inferior than the one of the current node, continue searching in the left sub-tree
    if (_compareElements(e, DATA(tree)) < 0)
        LEFT(tree) = AVL_remove(e, LEFT(tree));

    // If the element is greater than the one of the current node, continue searching in the right sub-tree
    else if (_compareElements(e, DATA(tree)) > 0)
        RIGHT(tree) = AVL_remove(e, RIGHT(tree));

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
        node_t* successor = AVL_successor(RIGHT(tree));

        // Replace the data of the node to delete with the data of the successor
        _assignElements(&DATA(tree), &DATA(successor));

        // Remove the successor
        RIGHT(tree) = AVL_remove(DATA(successor), RIGHT(tree));
    }

    BAL(tree) = AVL_height(LEFT(tree)) - AVL_height(RIGHT(tree));

    if (!VALID_BAL(BAL(tree)))
        tree = _balance(tree);

    return tree;
}



node_t* AVL_successor(node_t* tree)
{
    node_t* current = AVL_copy(tree);
    while (!EMPTY(LEFT(current)))
        current = LEFT(current);
    return current;
}



int AVL_height(const node_t* tree)
{
    if (EMPTY(tree))
        return 0;
    return MAX(1 + AVL_height(LEFT(tree)), 1 + AVL_height(RIGHT(tree)));
}



bool AVL_areEqual(const node_t* tree1, const node_t* tree2)
{
    // Compare both trees, also true of both are NULL
    if (tree1 == tree2)
        return true;

    // If only one node is empty
    if (EMPTY(tree1) || EMPTY(tree2))
        return false;

    // Verify that both nodes have the same data + recursion
    return (_compareElements(DATA(tree1), DATA(tree2)) == 0
        && AVL_areEqual(LEFT(tree1), LEFT(tree2))
        && AVL_areEqual(RIGHT(tree1), RIGHT(tree2)));
}

/**
 * @file    AVL.h
 * @brief   AVL tree's data structure implementation.
 * @date    2021-08-08
 *
 */

#ifndef AVL_H
#define AVL_H

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
 * @typedef node_t
 * @brief AVL tree node type
 */
typedef struct node node_t;

/**
 * @struct node
 * @brief AVL tree node's struct
 * @var node::data Data element
 * @var node::balance Imbalance factor
 * @var node::left Pointer to the left sub-tree
 * @var node::right Pointer to the left sub-tree
 */
struct node
{
    elt_t data;
    int balance;
    struct node* left;
    struct node* right;
};



/* ------------------------------------------------------------------------- */
/*                                Prototypes                                 */
/* ------------------------------------------------------------------------- */

/**
 * @brief Prints the content of an AVL tree. (Infix)
 * @param tree The AVL tree
 */
void AVL_print(const node_t* tree);

/**
 * @brief Prints the content of an AVL tree. (Postfix)
 * @param tree The AVL tree
 */
void AVL_printReverse(const node_t* tree);

/**
 * @brief Returns the size of an AVL tree (number of nodes).
 * @param tree The AVL tree
 * @return The size of the AVL tree
 */
unsigned int AVL_size(const node_t* tree);

/**
 * @brief Determines if an element is contained is an AVL tree.
 * @param e The element to search
 * @param tree The AVL tree
 * @return True if the element is contained in the AVL
 * tree, false if not
 */
bool AVL_includes(elt_t e, const node_t* tree);

/**
 * @brief Determines if an AVL tree is balanced.
 * @param tree The AVL tree
 * @return True if the AVL tree is balanced, false if not
 */
bool AVL_isBalanced(const node_t* tree);

/**
 * @brief Creates a new AVL tree node.
 * @param e The element to put as the data of the node
 * @param left Pointer to the node's left node
 * @param right Pointer to the node's right node
 * @return The pointer to the created node, or NULL if
 * memory allocation failed
 */
node_t* AVL_createNode(elt_t e, node_t* left, node_t* right);

/**
 * @brief Insert an element in a binary tree search.
 * @param e The element to insert
 * @param tree The AVL tree
 * @return The pointer to the new root of the AVL
 * tree (after the insertion)
 */
node_t* AVL_insert(elt_t e, node_t* tree);

/**
 * @brief Returns a copy of an AVL tree.
 * @param tree The AVL tree to copy
 * @return The copy of the AVL tree
 */
node_t* AVL_copy(const node_t* tree);

/**
 * @brief Removes an AVL tree and frees
 * all previously occupied memory.
 * @param tree
 * @return NULL
 */
node_t* AVL_removeTree(node_t* tree);

/**
 * @brief Removes an element from an AVL tree
 * and frees previously occupied memory.
 * @param e The element to remove
 * @param tree The AVL tree
 * @return The pointer to the AVL tree after
 * the removing of the element
 */
node_t* AVL_remove(elt_t e, node_t* tree);

/**
 * @brief Returns the successor of an AVL tree or sub-tree
 * (Min. value of the right part).
 * @param tree The AVL tree
 * @return The successor node
 */
node_t* AVL_successor(node_t* tree);

/**
 * @brief Returns the height of an AVL tree.
 * @param tree The AVL tree
 * @return The height of the AVL tree
 */
int AVL_height(const node_t* tree);

/**
 * @brief Determines of two AVL trees are equal.
 * @param tree1 an AVL tree
 * @param tree2 an AVL tree
 * @return True if both AVL trees are equal, false if not
 */
bool AVL_areEqual(const node_t* tree1, const node_t* tree2);

#endif

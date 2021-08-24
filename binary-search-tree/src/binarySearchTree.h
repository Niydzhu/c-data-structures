/**
 * @file    binarySearchTree.h
 * @brief   Binary search tree's data structure implementation.
 * @date    2021-08-08
 *
 */

#ifndef BST_H
#define BST_H

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
 * @brief Binary search tree node type
 */
typedef struct node node_t;

/**
 * @struct node
 * @brief Binary search tree node's struct
 * @var node::data Data element
 * @var node::left Pointer to the left sub-tree
 * @var node::right Pointer to the left sub-tree
 */
struct node
{
    elt_t data;
    struct node* left;
    struct node* right;
};



/* ------------------------------------------------------------------------- */
/*                                Prototypes                                 */
/* ------------------------------------------------------------------------- */

/**
 * @brief Prints the content of a binary search tree. (Infix)
 * @param tree The binary search tree
 */
void BST_print(const node_t* tree);

/**
 * @brief Prints the content of a binary search tree. (Postfix)
 * @param tree The binary search tree
 */
void BST_printReverse(const node_t* tree);

/**
 * @brief Returns the size of a binary search tree (number of nodes).
 * @param tree The binary search tree
 * @return The size of the binary search tree
 */
unsigned int BST_size(const node_t* tree);

/**
 * @brief Determines if an element is contained is a binary search tree.
 * @param e The element to search
 * @param tree The binary search tree
 * @return True if the element is contained in the binary search
 * tree, false if not
 */
bool BST_includes(elt_t e, const node_t* tree);

/**
 * @brief Creates a new binary search tree node.
 * @param e The element to put as the data of the node
 * @param left Pointer to the node's left node
 * @param right Pointer to the node's right node
 * @return The pointer to the created node, or NULL if
 * memory allocation failed
 */
node_t* BST_createNode(elt_t e, node_t* left, node_t* right);

/**
 * @brief Insert an element in a binary tree search.
 * @param e The element to insert
 * @param tree The binary search tree
 * @return The pointer to the new root of the binary search
 * tree (after the insertion)
 */
node_t* BST_insert(elt_t e, node_t* tree);

/**
 * @brief Returns a copy of a binary search tree.
 * @param tree The binary search tree to copy
 * @return The copy of the binary search tree
 */
node_t* BST_copy(const node_t* tree);

/**
 * @brief Removes a binary search tree and frees
 * all previously occupied memory.
 * @param tree
 * @return NULL
 */
node_t* BST_removeTree(node_t* tree);

/**
 * @brief Removes an element from a binary search tree
 * and frees previously occupied memory.
 * @param e The element to remove
 * @param tree The binary search tree
 * @return The pointer to the binary search tree after
 * the removing of the element
 */
node_t* BST_remove(elt_t e, node_t* tree);

/**
 * @brief Returns the successor of a binary search tree or sub-tree
 * (Min. value of the right part).
 * @param tree The binary search tree
 * @return The successor node
 */
node_t* BST_successor(node_t* tree);

/**
 * @brief Returns the height of a binary search tree.
 * @param tree The binary search tree
 * @return The height of the binary search tree
 */
int BST_height(const node_t* tree);

/**
 * @brief Determines of two binary search trees are equal.
 * @param tree1 A binary search tree
 * @param tree2 A binary search tree
 * @return True if both binary search trees are equal, false if not
 */
bool BST_areEqual(const node_t* tree1, const node_t* tree2);

#endif

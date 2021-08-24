/**
 * @file    linkedList.h
 * @brief   Linked list's data structure implementation.
 * @date    2021-08-07
 *
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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
 * @brief Linked list node type
 */
typedef struct node node_t;

/**
 * @struct node
 * @brief Linked list node's struct
 * @var node::data Data element
 * @var node::next Next node of the list
 */
struct node
{
    elt_t data; // Data element
    struct node* next; // Next node of the list 
};



/* ------------------------------------------------------------------------- */
/*                                Prototypes                                 */
/* ------------------------------------------------------------------------- */

/**
 * @brief Creates a linked list node.
 * @param e The element data contained in the node
 * @param next A pointer to the next node of the list (NULL if this is the last node)
 * @return The created node
 */
node_t* LinkedList_createNode(elt_t e, node_t* next);

/**
 * @brief Returns the list's head element.
 * @param list The linked list
 * @return The list's head element
 */
elt_t LinkedList_head(node_t* list);

/**
 * @brief Insert an element in a linked list.
 * @param e The element to insert
 * @param list The linked list
 * @param mode Insertion mode ['H' in head | 'T' in tail]
 */
void LinkedList_insertElement(elt_t e, node_t** list, char mode);

/**
 * @brief Removes the last element of a linked list.
 * @param list The linked list
 */
void LinkedList_removeLast(node_t** list);

/**
 * @brief Removes the first element of a linked list
 * @param list The linked list
 */
void LinkedList_removeFirst(node_t** list);

/**
 * @brief Prints the values of a linked list.
 * @param list The linked list
 */
void LinkedList_print(node_t* list);

/**
 * @brief Returns the size of a linked list (number of nodes).
 * @param list The linked list
 * @return The size of the linked list
 */
int LinkedList_size(node_t* list);

/**
 * @brief Returns the last node of a linked list.
 * @param list The linked list
 * @return The last node
 */
node_t* LinkedList_lastNode(node_t* list);

/**
 * @brief Returns a copy of a linked list.
 * @param list The linked list
 * @return The copy of the linked list
 */
node_t* LinkedList_copy(node_t* list);

/**
 * @brief Returns a linked list without it's first node
 * @param list The linked list
 * @return The linked list without the first node
 */
node_t* LinkedList_exceptFirst(node_t* list);

/**
 * @brief Determines if an element is contained in a linked list.
 * @param e The element to find
 * @param list The linked list
 * @return True if the element is contained is the linked list, false if not
 */
bool LinkedList_includes(elt_t e, node_t* list);

#endif

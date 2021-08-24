/* ------------------------------------------------------------------------- */
/*                                 Includes                                  */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "linkedList.h"



/* ------------------------------------------------------------------------- */
/*                             Local definitions                             */
/* ------------------------------------------------------------------------- */

#define EMPTY(node) (node == NULL)
#define DATA(node)  (node->data)
#define NEXT(node)  (node->next)



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
 * @brief Insert an element in head of a linked list.
 * @param e The element to insert
 * @param list The linked list
 */
void _insertElementInHead(elt_t e, node_t** list);

/**
 * @brief Insert an element in tail of a linked list.
 * @param e The element to insert
 * @param list The linked list
 */
void _insertElementInTail(elt_t e, node_t** list);



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



node_t* LinkedList_createNode(elt_t e, node_t* next)
{
    // Create node
    node_t* new = (node_t*)malloc(sizeof(node_t));
    assert(new != NULL);

    // Initialize node
    _assignElements(&new->data, &e);
    new->next = next;

    return new;
}



elt_t LinkedList_head(node_t* list)
{
    return list->data;
}



void LinkedList_insertElement(elt_t e, node_t** list, char mode)
{
    if (EMPTY(*list)) {
        *list = LinkedList_createNode(e, *list);
        return;
    }

    switch (mode) {
    case 'H': // Insert element in head
        _insertElementInHead(e, list);
        break;

    case 'T': // Insert element in tail
        _insertElementInTail(e, list);
        break;
    }
}



void _insertElementInHead(elt_t e, node_t** list)
{
    *list = LinkedList_createNode(e, *list);
}



void _insertElementInTail(elt_t e, node_t** list)
{
    if (EMPTY(NEXT((*list)))) {
        NEXT((*list)) = LinkedList_createNode(e, NEXT((*list)));
        return;
    }
    _insertElementInTail(e, &NEXT((*list)));
}



void LinkedList_removeLast(node_t** list)
{
    // Stop condition
    if (EMPTY(list))
        return;

    // Last element found
    if (EMPTY(NEXT((*list)))) {
        node_t* aux = *list;
        *list = NULL;
        free(aux);
        return;
    }

    // Recursion
    LinkedList_removeLast(&NEXT((*list)));
}



void LinkedList_removeFirst(node_t** list)
{
    if (EMPTY(list)) return;
    node_t* aux = *list;
    *list = NEXT((*list));
    free(aux);
}



void LinkedList_print(node_t* list)
{
    node_t* temp = list;
    int i = 0;
    while (!EMPTY(temp)) {
        printf("%d : ", i);
        _printElement(DATA(temp));
        printf("\n");
        temp = NEXT(temp);
        i++;
    }
}



int LinkedList_size(node_t* list)
{
    node_t* temp = list;
    int size = 0;
    while (!EMPTY(temp)) {
        size++;
        temp = NEXT(temp);
    }
    return size;
}



node_t* LinkedList_lastNode(node_t* list)
{
    if (EMPTY(list))
        return NULL;

    // Last element found
    if (EMPTY(NEXT(list)))
        return list;

    // Recursion
    return LinkedList_lastNode(NEXT(list));
}



node_t* LinkedList_copy(node_t* list)
{
    if (EMPTY(list))
        return NULL;
    return LinkedList_createNode(DATA(list), LinkedList_copy(NEXT(list)));
}



node_t* LinkedList_exceptFirst(node_t* list)
{
    return LinkedList_createNode(DATA(NEXT(list)), NEXT(NEXT(list)));
}



bool LinkedList_includes(elt_t e, node_t* list)
{
    // Element found
    if (_compareElements(DATA(list), e) == 0)
        return true;

    // End of list
    if (EMPTY(NEXT(list)))
        return false;

    // Recursion
    return LinkedList_includes(e, LinkedList_exceptFirst(list));
}

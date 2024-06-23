#ifndef LINKED_CIRC_LIST_H
#define LINKED_CIRC_LIST_H
#include <stdbool.h>

typedef struct Node Node;

typedef struct CircularList CircularList;

/**
 * Creates a new CircularList.
 *
 * @return A pointer to the newly created CircularList.
 */
CircularList* CircularList_creat();

/**
 * Creates a new Node with the specified size.
 *
 * @param size The size of the Node.
 * @return A pointer to the newly created Node.
 */
Node* creatNode(int size);

/**
 * Inserts a new element with the specified data into the CircularList.
 *
 * @param list The CircularList to insert the element into.
 * @param data The data of the element to be inserted.
 */
void CircularList_Insert(CircularList* list, int data);

/**
 * Prints the elements of the CircularList.
 *
 * @param list The CircularList to print.
 */
void CircularList_Print(CircularList* list);

/**
 * Removes the element with the specified data from the CircularList.
 *
 * @param list The CircularList to remove the element from.
 * @param data The data of the element to be removed.
 */
void CircularList_Remove(CircularList* list, int data);

/**
 * Performs a specific operation on the CircularList.
 *
 * @param list The CircularList to perform the operation on.
 * @param info Additional information for the operation.
 */
void CircularEDMundo(CircularList* list, int info);

/**
 * Predefines the CircularList with a specific size.
 *
 * @param list The CircularList to predefine.
 * @param size The size of the CircularList.
 */
void CircularPredefine(CircularList* list, int size);


#endif
#ifndef LINKED_CIRC_LIST_H
#define LINKED_CIRC_LIST_H
#include <stdbool.h>

typedef struct Node Node;

typedef struct CircularList CircularList;

CircularList* CircularList_creat();

Node* creatNode(int size);

void CircularList_Insert(CircularList* list, int data);

void CircularList_Print(CircularList* list);

void CircularList_Remove(CircularList* list, int data);

void CircularEDMundo(CircularList* list,int info);

void CircularPredefine(CircularList*list,int size);



#endif
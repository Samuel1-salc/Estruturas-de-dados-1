#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct CircularList
{
    Node* begin;
    int size;
} CircularList;

CircularList* CircularList_creat()
{
    CircularList* list = (CircularList*)malloc(sizeof(CircularList));
    list->begin = NULL;
    list->size = 0;
    return list;
}

Node* creatNode(int size){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = size;
    node->next = NULL;
    return node;

}

void CircularList_Insert(CircularList* list, int data)
{
    Node* node = creatNode(data);
    

    if (list->begin == NULL)
    {
        list->begin = node;
        node->next = list->begin;
    }
    else
    {
        Node* temp = list->begin;
        while (temp->next != list->begin)
        {
            temp = temp->next;
        }
        temp->next = node;
        node->next = list->begin;
    }
    list->size++;
}

void CircularList_Print(CircularList* list)
{
    Node* temp = list->begin;
    if (list->begin != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != list->begin);
    }
    printf("\n");
}

void CircularList_Remove(CircularList* list, int data)
{
    Node* temp = list->begin;
    Node* prev = NULL;
    if (list->begin != NULL)
    {
        do
        {
            if (temp->data == data)
            {
                if (prev == NULL)
                {
                    Node* aux = list->begin;
                    while (aux->next != list->begin)
                    {
                        aux = aux->next;
                    }
                    aux->next = list->begin->next;
                    list->begin = list->begin->next;
                    free(temp);
                    list->size--;
                    return;
                }
                else
                {
                    prev->next = temp->next;
                    free(temp);
                    list->size--;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        } while (temp != list->begin);
        printf("%d\n",list->begin->data);
    }
    
}

void CircularEDMundo(CircularList* list,int info){
 
    
    Node* temp2 = list->begin;
      do
        {

            for (int i = 0; i < info; i++)
            {
                temp2 = temp2->next;
                
            }
            printf(" %d\n",temp2->data);
            Node* aux = temp2->next;
            CircularList_Remove(list,temp2->data);
            temp2 = aux;
            
          
        } while (list->size > 1);

        printf("o escolhido foi %d\n",temp2->data);

}
void CircularPredefine(CircularList*list,int size){
    int count = 0;
    do
     {
        count++;
        CircularList_Insert(list,count);
       
            
    } while (count < size);
    
}

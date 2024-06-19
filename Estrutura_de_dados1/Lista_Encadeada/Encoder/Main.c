#include "Libraly.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int main()
{
    
    TLinkedList* lista1 = TLinkedList_creat();
    char String[] = "111111000000011100";
    TLinkedList_Binarios(lista1,String);

    TLinkedList_Print(lista1);
    
    TLinkedList_Allocate(lista1);
    free(lista1);

    
}



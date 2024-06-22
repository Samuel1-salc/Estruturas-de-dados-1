#include "Libraly.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int limite = 6;
    int contador = 0;
    TLinkedList* lista1 = TLinkedList_creat();
    
    TLinkedList_Experimento(lista1);
  
   
       

   TLinkedList_Print(lista1);

    
   


    TLinkedList_Allocate(lista1);
    free(lista1);
    return 0 ;

    
}







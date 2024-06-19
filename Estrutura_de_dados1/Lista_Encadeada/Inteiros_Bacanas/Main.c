#include "Libraly.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int experimento;
    int limite = 100;
    int count = 0;
    TLinkedList* lista1 = TLinkedList_creat();
    TLinkedList_Insert(lista1,1);
     TLinkedList_Insert(lista1,9);
    TLinkedList_Insert(lista1,0);
    TLinkedList_Insert(lista1,0);

    do{
        teste1(lista1);
        experimento = teste2(lista1);
        separate_values(lista1);
        if(count >= limite){
            printf("esse numero nao e bacana\n");
            break;
        }else if(experimento == 1){
            printf("\nesse numero e bacana\n");
        }
        count++;
    }while(experimento !=1);
    

    TLinkedList_Allocate(lista1);
    free(lista1);
    return 0 ;

    
}





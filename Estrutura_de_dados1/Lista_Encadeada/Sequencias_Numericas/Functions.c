#include "Libraly.h"
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h>

struct no{
    int info;
    struct no *next;
};
struct list
{
    TNo *begin ;
};


TNo *createNfill(int element){
    TNo *new = malloc(sizeof(TNo));
    if(new){
        new->info = element;
        new->next = NULL;
    }
    return new; 
}

TLinkedList* TLinkedList_creat(){
    TLinkedList *list = malloc(sizeof(TLinkedList));
    if(list != NULL)
    {
        list->begin = NULL;
    }else{
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(1);
    }
    return list;
}



bool TLinkedList_Insert(TLinkedList* lista, int valor){
    TNo* newNode = createNfill(valor);
    if(newNode == NULL){
        return false;
    }
    //Inserir no Inicio
     if(lista->begin == NULL){
        lista->begin = newNode;
        printf("Valor insrido no inicio: %d \n", valor);
        return true;
    }
 
    //inserir no meio
    /*
    if(newNode->info < lista->begin->info){
        newNode->next = lista->begin;
        lista->begin = newNode;
        printf("Valor insrido no meio: %d \n", valor);
        return true;
    }
    */
    
    //inserir no final
    
    TNo* y = lista->begin;
    while (y->next != NULL /*&&y->next->info < newNode->info*/){ 
        y = y->next;
    }
    newNode->next = y->next;
    y->next = newNode;
     printf("Valor insrido no final: %d \n", valor);
    return true;
    
}


void TLinkedList_Print(TLinkedList *list){
        TNo *aux;
        for(aux = list->begin; aux != NULL; aux = aux->next){
            printf("%d->",aux->info);
        }
}

bool TLinkedList_Delete(TLinkedList* lista, int valor) {
    if (lista->begin == NULL) {
        return false; // Lista está vazia
    }

    // Verificar se o primeiro nó é o valor a ser removido
    if (lista->begin->info == valor) {
        TNo* temp = lista->begin;
        lista->begin = lista->begin->next;
        free(temp);
        return true;
    }

    TNo* aux = lista->begin;
    TNo* prev = NULL;

    // Percorrer a lista
    while (aux != NULL) {
        if (aux->info == valor) {
            if (aux->next == NULL) {
                // Remoção do último nó
                if (prev != NULL) {
                    prev->next = NULL;
                }
                free(aux);
                return true;
            } else {
                // Remoção de um nó do meio
                if (prev != NULL) {
                    prev->next = aux->next;
                }
                free(aux);
                return true;
            }
        }
        prev = aux;
        aux = aux->next;
    }

    return false; // Valor não encontrado
}


void TLinkedList_Experimento(TLinkedList* lista){
 
    TNo* aux = lista->begin;
    while( aux != NULL){
    
        if(aux != NULL){
            if(aux->info % 2 == 0){
                aux->info = aux->info/2;
            }else if(aux->info % 2 == 1){
             
                 aux->info = aux->info + 1;
              
                
            }
        }
        /*
         if(lista->begin->next == NULL){
            if(aux->info % 2 == 0){
                aux->info = aux->info/2;
            }else if(aux->info % 2 == 1){
                aux->info = aux->info + 1;
            }
        }
        */
        
        
        aux = aux->next;
        
        TLinkedList_Print(lista);

        
    }
}
void separate_values(TLinkedList* lista) {
    TNo* temp = lista->begin;
    if (temp == NULL) return;

    int combined_value = temp->info;
    lista->begin = NULL;
    free(temp);

    if (combined_value == 0) {
        TLinkedList_Insert(lista, 0);
        return;
    }

    while (combined_value > 0) {
        int digit = combined_value % 100;
        TLinkedList_Insert(lista, digit);
        combined_value /= 100;
    }
}

void TLinkedList_Decompose(TLinkedList* lista){
    TNo* aux = lista->begin;
    if(aux->next != NULL){
        
            aux->info = (aux->info*10) + aux->next->info;
            TLinkedList_Delete(lista,aux->next->info);
             
            
            aux->next->info = (aux->next->info*10) + aux->next->next->info;
            TLinkedList_Delete(lista,aux->next->next->info);
            if(aux != NULL){
                if(aux->info % 2 == 0){
                 aux->info = aux->info/2;
                }else if(aux->info % 2 == 1 ){
             
                 aux->info = aux->info + 1;  
                }
            }
            
            
                if(aux->next->info % 2 == 0){
                    aux->next->info = aux->next->info/2;
                }else{
                    aux->next->info = aux->next->info + 1;  
                }       
            aux->info = (aux->info*100) + aux->next->info;
            TLinkedList_Delete(lista,aux->next->info);
                             
            
    }
  
}
void TLinkedList_Decompose2(TLinkedList* lista){
    TNo* aux = lista->begin;
    if(aux->next != NULL){
            aux->info = (aux->info*10) + aux->next->info;
            TLinkedList_Delete(lista,aux->next->info);                  
            
    }
}

void TLinkedList_Allocate(TLinkedList* lista){
    TNo* current = lista->begin;
    while (current != NULL) {
        TNo* temp = current;
        current = current->next;
        free(temp);
    }
    lista->begin = NULL;
}
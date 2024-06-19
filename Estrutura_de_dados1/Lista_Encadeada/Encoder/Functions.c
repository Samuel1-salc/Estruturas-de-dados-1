#include "Libraly.h"
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<math.h>


struct no{
    int info;
    char byte;
    struct no *next;
};
struct list
{
    TNo *begin ;
};


TNo *createNfill(int element,char byte){
    TNo *new = malloc(sizeof(TNo));
    if(new){
        new->info = element;
        new->byte = byte;
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



bool TLinkedList_Insert(TLinkedList* lista, int valor, char byte){
    TNo* newNode = createNfill(valor,byte);
    if(newNode == NULL){
        return false;
    }
    //Inserir no Inicio
     if(lista->begin == NULL){
        lista->begin = newNode;
        
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
    
    return true;
    
}


void TLinkedList_Print(TLinkedList *list){
        TNo *aux;
        for(aux = list->begin; aux != NULL; aux = aux->next){
            printf("[%d,%c]->",aux->info,aux->byte);
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


void teste1(TLinkedList* lista){
  
    TNo* aux = lista->begin;
    while( aux != NULL ){
        aux->info = pow(aux->info,2);
        aux = aux->next;
    }
}
int  teste2(TLinkedList*lista){
    TNo* temp = lista->begin;
    while(temp != NULL && temp->next != NULL) {
        TNo* node_to_delete = temp->next;
        temp->info += node_to_delete->info;
        temp->next = node_to_delete->next;
        free(node_to_delete);
        // temp now points to the next node, which is already updated
    }
    TLinkedList_Print(lista);
    return temp->info;

}

void TLinkedList_Binarios(TLinkedList* lista, char* string){
    int countOne = 0;
    int countZero = 0;
    int countString = 0;
    TNo*aux = lista->begin;
    do{
        for(int i = 0 ; i < strlen(string) ; i++){
            if(string[i] = '1'){
                countOne++;
                countString++;
            } else break;
        }
        TLinkedList_Insert(lista,countOne,'1');
        if(aux != NULL){
            aux->byte = '1';
        }
        countOne = 0;
         for(int i = 0 ; i < strlen(string) ; i++){
            if(string[i] = '0'){
                countZero++;
                countString++;
            } else break;
        }
        TLinkedList_Insert(lista,countZero,'0');
        if(aux != NULL){
            aux->byte = '0';
        }
        countZero = 0;
    }while(countString <= strlen(string));

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
#include "Prototipos.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct _list {
  unsigned int qty;
  int data[MAX];
};


StaticList *StaticList_create() {
  StaticList *list = (StaticList *)malloc(sizeof(StaticList));
  if (list != NULL) {
    list->qty = 0;
  }else{
    exit;
  }
  printf("%d",list->qty);
  return list;
}

/**
 * Busca por um elemento;
 * @param StaicList ponteiro para a lista estática
 * @param value valor a ser buscado
 * @param int* ponteiro para que seja gravada a posição do elemento buscado,
 * caso seja encontrado.
 * @return true se a busca foi bem sucedida, false caso contrário
 */
bool StaticList_search(StaticList *list, int valor, int *index) {
  // Tentar encontrar o valor no vetor dados da lista
  for (int i = 0; i < list->qty; i++)
    if (list->data[i] == valor) // encontrei!
    {
      *index = i;
      return true;
    }
  return false;
}
/**
 * Inserção de um elemento na lista;
 * @param list ponteiro para a lista estática
 * @param value valor a ser inserido
 * @return true se a inserção foi bem sucedida, false caso contrário
 */
bool StaticList_insert(StaticList *list, int novoItem) {
  // 1 passo
  if (!StaticList_is_full(list)) {

    // list->data[list->qty++] = novoItem;
    // return true;
    // 2 Localizar o indice do novo dado?
    // Só teste
    unsigned int i;
    for (i = 0; i < list->qty; i++)
      if (list->data[i] > novoItem)
        break;
    // printf("indice=%u\n", i);
    // 3 Mover os dados
    for (unsigned int k = list->qty; k > i; k--)
      list->data[k] = list->data[k - 1];
    // 4 inserir o novo dado na posição correta
    list->data[i] = novoItem;
    list->qty++;
    return true;
  }
  return false;
}

/**
 * Tenta remover um elemento da lista;
 * @param StaticList* ponteiro para a lista estática
 * @param value valor a ser removido
 * @return true se a remoção foi bem sucedida, false caso contrário
 */
bool StaticList_remove(StaticList *list, int valor) {
  int index;
  if (StaticList_search(list, valor, &index)) {
    for (int i = index; i < list->qty - 1; i++)
      list->data[i] = list->data[i + 1];
    list->qty--;
    return true;
  }
  return false;
}

bool StaticList_is_full(StaticList *list) { return list->qty == MAX; }

void StaticList_print(StaticList *list) {
  for (int i = 0; i < list->qty ; i++)
    printf("%d, ", list->data[i]);
  putchar('\n');
}

unsigned int StaticList_size(StaticList *list) { return list->qty; }


void StaticList_MergeLists(StaticList *lista1 , StaticList *lista2, StaticList *lista3){
    int qtyGeral = lista1->qty + lista2->qty;
    lista3->qty = qtyGeral;
    lista3->data[qtyGeral];
    int index = 0;

    for (int i = 0; i < lista1->qty; i++){
        lista3->data[i] = lista1->data[i];
        index++;
    }
    
    for (int i = 0; i < lista2->qty ; i++){
        lista3->data[index++] = lista2->data[i];
       
    }
}

void  StaticList_Cleaner(StaticList *list, int valor) {
 
  for (unsigned int i = 0; i < list -> qty - valor; i++){
      StaticList_print(list);
      list->data[i] = list->data[i+ valor];
      printf("[%d]\n",list->data[i]);
  }
  list->qty -=  valor;
}
// como posso saber quando o numero é maior que todos os outros numeros da lista?
void bigValue(StaticList *list){
  int bigValue;
  int index;
  int count;
  for (int i = 0; i < 5; i++)
  {
    bigValue = list->data[i];
 
    for(int k = 0; k < 5; k++)  // Correção: use 'k' na condição
    {
      
      if(bigValue > list->data[k])   // Correção: use 'data[k]' para comparação
      {
        count++;
      }
      if(count == 4)
      {
       printf("[%d] e o maior valor da lista\n", bigValue);
       break;
      }
    }
    count = 0;
  }
}

StaticList* NewparList(StaticList* list) {
    StaticList* newList = StaticList_create();
    if (!newList) {
        fprintf(stderr, "Failed to allocate memory for new list.\n");
        return NULL;
    }
    int count = 0;
    for (int i = 0; i < list->qty; i++) {
        if (list->data[i] % 2 == 0) {
            newList->data[count] = list->data[i];
            printf("newList->data[%d] = %d\n", count, newList->data[count]);
            count++;
        }else{
          newList->data[count] = 10;
        }
    }
    newList->qty = count;
    return newList;
}

void Staticlist_removeEquals(StaticList* list){
  //StaticList* removeEqualList = StaticList_create();
  
  int countEquals = 0;
  int verifyEquals;
  int index = 0;
  for(unsigned int i = 0 ; i < list->qty ; i++){
    verifyEquals = list->data[i];
    for(unsigned int k = 0 ; k < list->qty; k++){
      if(verifyEquals == list->data[k] ){
        countEquals++;
      }
    }
    if(countEquals == 1){
        list->data[index] = list->data[i];
        index++;
      }
      countEquals = 0;
  }
  
  list->qty = index;
}

StaticList *listInvert(StaticList *list){
  StaticList *newList = StaticList_create();
  int count = 0;
 
  for(int i = list->qty - 1 ; i >= 0  ; i--)
  {
    newList->data[count] = list->data[i];
    count++;
  }
  newList->qty = list->qty;
  return newList;
}

StaticList* StaticList_mergeClean(StaticList * lista1 , StaticList *lista2){
  StaticList* lista3 = StaticList_create();
  Staticlist_removeEquals(lista1);
  Staticlist_removeEquals(lista2);
  StaticList_MergeLists(lista1,lista2,lista3);
  return lista3;
}

void StaticList_delete(StaticList*list){
  free(list);
}


  
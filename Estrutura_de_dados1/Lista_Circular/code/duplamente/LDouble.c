#include "LDouble.h"
#include <stdio.h>
#include <stdlib.h>
struct no{
  int info;
  struct no* prox;
  struct no* ant;
};

struct no* TNo_createNfill(int info){
  TNo* novo = (TNo*)malloc(sizeof(TNo));
  if(novo){
    novo->info = info;
    novo->ant = NULL;
    novo->prox = NULL;
  }return novo;
}
struct double_linked{
  struct no* inicio, *fim;
};


TDList* TDList_create(){
  TDList* nova = (TDList*)malloc(sizeof(TDList));
  if(nova){
    nova->inicio = NULL;
    nova->fim = NULL;
  }
  return nova;
}

int TDList_insert_s(TDList* L, int info){
  TNo* novo = TNo_createNfill(info);
  if(novo==NULL)
    return 0;
  //Case I: A lista está vazia?
  if(L->inicio == NULL){
    L->inicio = novo;
    L->fim = novo;
  }else{//Case II: 
    if(info<L->inicio->info){//Case II.a
      L->inicio->ant = novo;
      novo->prox = L->inicio;
      L->inicio = novo;
    }else{//Case II.b
      TNo* aux = L->inicio;
      while(aux->info < info && aux!=L->fim)
        aux = aux->prox;
      if(aux==L->fim)
        L->fim = novo;
      else
        aux = aux->ant;
      novo->prox = aux->prox;
      novo->ant = aux;
      if(aux->prox != NULL)
        aux->prox->ant = novo;
      aux->prox = novo;
    }
  }
  return 1;
}

void TDList_print(TDList* L){
  if(L){
    TNo* aux = L->inicio;
    while(aux){
      printf("<-[%d]-> ", aux->info);
      aux = aux->prox;
    }
    puts("");
  }
}

void TDList_print_reverse(TDList* L){
    if(L){
    TNo* aux = L->fim;
    while(aux){
      printf("<-[%d]-> ", aux->info);
      aux = aux->ant;
    }
    puts("");
  }
}
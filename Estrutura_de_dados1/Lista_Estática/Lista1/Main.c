#include "Prototipos.h"
#include <stdio.h>
#include <stdlib.h>

void insertUI(StaticList *list) {
  int value;
  printf("Digite o valor a ser inserido: ");
  if (scanf("%d", &value) == 1) {
    if (StaticList_insert(list, value))
      puts("Inserido com sucesso!");
    else
      puts("Não foi possível inserir!");
  }
}

void removeUI(StaticList *list) {
  int value;
  printf("Digite o valor a ser removido: ");
  if (scanf("%d", &value) == 1) {
    if (StaticList_remove(list, value))
      puts("Removido com sucesso!");
    else
      puts("Não foi possível remover!");
  }
}

void searchUI(StaticList *list) {
  int value, index;
  printf("Digite o valor a ser buscado: ");
  if (scanf("%d", &value) == 1) {
    if (StaticList_search(list, value, &index))
      printf("Encontrado na posição %d\n", index);
    else
      puts("404 Not found!");
  }
}

void CleanerUI(StaticList* list) {
  int value;
  printf("\nQuantos elementos da lista deseja retirar\n");
  if (scanf("%d", &value) == 1) {
    if (StaticList_Cleaner(list, value))
      printf("Valores retirados com sucesso!\n");
    else
      puts("Erro ao retirar valores!");
  }
}

StaticList* parUI(StaticList* list) {
  StaticList* parList = NewparList(list);
  return parList;
}

StaticList* inverterUI(StaticList* list) {
  StaticList* invertList = listInvert(list);
  return invertList;
}

StaticList* newListwithoutequalsUI(StaticList* list1, StaticList* list2) {
  StaticList* withoutEquals = StaticList_mergeClean(list1, list2);
  return withoutEquals;
}

int menuUI() {
  printf("Mundo da lista!\n1-> Inserir\n2-> Buscar\n3-> Remover\n4-> Imprimir\n5-> Concatenar 2 listas\n6-> Limpar n itens\n7-> Maior item da lista\n8-> Nova lista Par\n9-> Remover num iguais\n10-> Nova lista Invertida\n11-> Criar nova lista concatenada sem n iguais\n0-> Sair\n");
  int op;
  return (scanf("%d", &op) == 1) ? op : 0;
}

void functionsUI(StaticList * list) {
  int op;
  do {
    op = menuUI();

    switch (op) {
    case 1:
      insertUI(list);
      break;
    case 2:
      searchUI(list);
      break;
    case 3:
      removeUI(list);
      break;
    case 4:
      puts("Imprimindo:\n ");
      StaticList_print(list);
      break;
    case 6:
      CleanerUI(list);
      break;
    case 0:
      puts("Até outra vez!\n");
      break;
    default:
      puts("Opção inválida!\n");
      break;
    }
  } while (op != 0);
}

int main(void) {
  StaticList *lista1 = StaticList_create();
  StaticList *lista2 = StaticList_create();

  functionsUI(lista1);

  StaticList_delete(lista1);
  StaticList_delete(lista2);

  return 0;
}

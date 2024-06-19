#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H
#include <stdbool.h>

typedef struct _list StaticList;


/**
 * Cria instâncias da StaticList;
 * @return ponteiro para a instância criada
 */
StaticList *StaticList_create();
/**
 * Libera os recursos de memória de uma lista estática;
 * @param list ponteiro para a lista estática
 */
void StaticList_delete(StaticList *);

/**
 * Inserção de um elemento na lista de maneira ordenada crescente;
 * @param list ponteiro para a lista estática
 * @param value valor a ser inserido
 * @return true se a inserção foi bem sucedida, false caso contrário
 */
bool StaticList_insert(StaticList *, int);
/**
 * Busca por um elemento;
 * @param StaicList ponteiro para a lista estática
 * @param value valor a ser buscado
 * @param int* ponteiro para que seja gravada a posição do elemento buscado,
 * caso seja encontrado.
 * @return true se a busca foi bem sucedida, false caso contrário
 */
bool StaticList_search(StaticList *, int, int *);
/**
 * Tenta remover um elemento da lista;
 * @param StaticList* ponteiro para a lista estática
 * @param value valor a ser removido
 * @return true se a remoção foi bem sucedida, false caso contrário
 */
bool StaticList_remove(StaticList *, int);

// Funções auxiliares :
/**
 * Retorna o Tamanho atual da lista;
 * @param StaticList* ponteiro para a lista estática
 * @return tamanho atual da lista
 */
unsigned int StaticList_size(StaticList *);
/**
 * Retorna se a lista está vazia
 * @param StaticList* ponteiro para a lista estática
 * @return true se a lista está vazia, false caso contrário
 */
bool StaticList_is_empty(StaticList *);
/**
 * Retorna se a lista está cheia
 * @param StaticList* ponteiro para a lista estática
 * @return true se a lista está cheia, false caso contrário
 */
bool StaticList_is_full(StaticList *);
/**
 * Imprime a lista formatada;
 * @param StaticList* ponteiro para a lista estática
 */
void StaticList_print(StaticList *);
/**
 * Retorna se a lista está vazia
 * @param void apenas para mergir listas
 * @Concatena 2 listas
 */
void StaticList_MergeLists(StaticList * , StaticList *, StaticList *);
/**
 * Retorna se a lista está vazia
 * @param void apenas para limpar n elementos de uma lista
 * @recebe como parametro n posições que serão eliminaas da lista
 */
void StaticList_Cleaner(StaticList *, int );
/**
 * Retorna se a lista está vazia
 * @param void apenas para mostrar o maior intem da lista
 * @recebe como parametro uma lista pata imprimir seu maior valor
 */
void bigValue(StaticList * );
/**
 * Retorna se a lista está vazia
 * @param StaticList apenas para imprimir uma nova lista com valores pares
 * @recebe como parametro uma lista para retirar seus valores impares
 */
StaticList* NewparList(StaticList * );
/**
 * Retorna se a lista está vazia
 * @param void apenas para remover os valores repetidos de uma lista
 * @modifica uma lista ,eliminando seus valores repetidos
 */
void  Staticlist_removeEquals(StaticList *);
/**
 * Retorna se a lista está vazia
 * @param StaticList para retornar uma nova lista com valores invertidos de outra lista
 * @recebe como parametro uma lista, para inverte-la e armazenar o valor invertido em uma nova lista
 */
StaticList *listInvert(StaticList *);
/**
 * Retorna se a lista está vazia
 * @param StaticList retorna uma nova lista
 * @recebe como parametro 2 lista onde serão retirados seus valores invertidos 
 * @retira os valores repetidos das duas listas
 * @return a lista que ira ser o resultado da concatenação da lista1 e lista2
 */
StaticList* StaticList_mergeClean(StaticList* , StaticList *);

#endif
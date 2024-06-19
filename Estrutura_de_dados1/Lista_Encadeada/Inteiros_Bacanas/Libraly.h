#ifndef LIBRALY_H
#define LIBRALY_H
#include <stdbool.h>
/**
 * @param Struct lista Dinamica
 */
typedef struct no TNo;
typedef struct list TLinkedList;
/**
 * Adiciona um elemento ao novo nó
 * 
 * @param Int element, recebe um elemento e adiciona ao TNo
 * @author Samuel
 */
TNo *createNfill(int element,char byte);
/**
 * Função para a criar a lista com malloc
 * 
 * @param WIHOUT parametros
 * @author Samuel
 */
TLinkedList* TLinkedList_creat();
/**
 * Função para Inserir um novo valor
 * Utiliza a função creatnFIll para criar um novo nó
 * faz inserção inicio e no final
 * @param TLinkedList 
 * @param Int
 * @return True caso adcione um primeiro elemento
 * @return True caso dicione um elemento no final da lista
 * @return false caso não adicione nada
 * @author Samuel
 */
bool TLinkedList_Insert(TLinkedList* lista, int valor, char byte);
/**
 * Função para imprimir a lista
 * 
 * @param TLinkedList ponteiro para lista 
 *
 * @author Samuel
 */
void TLinkedList_Print(TLinkedList *);
/**
 * Função para Deletar valor da lista
 * 
 * @param TLinkedList ponteiro para lista 
 * @param Int valor a ser deletado
 *
 * @author Samuel
 */
bool TLinkedList_Delete(TLinkedList*, int);
/**
 * Função De decomposição de um numero de 4 digitos
 * 
 * @param TLinkedList um ponterio para lista 
 * 
 *
 * @author Samuel
 */
void TLinkedList_Experimento(TLinkedList*);
/**
 * Função para liberar memoria
 * 
 * @param TLinkedList um ponterio para lista 
 * 
 *
 * @author Samuel
 */
void TLinkedList_Allocate(TLinkedList*);
/**
 * Função para fazer experimentos
 * 
 * @param TLinkedList um ponterio para lista 
 * 
 *
 * @author Samuel
 */
void teste1(TLinkedList* );
int teste2(TLinkedList* );
void separate_values(TLinkedList* );
void TLinkedList_Binarios(TLinkedList* , char* );
#endif
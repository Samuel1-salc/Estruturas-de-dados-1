
#ifndef PILHA_H
#define PILHA_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TDqueue Pilha;

/**
 * @brief Creates a new Pilha object.
 * 
 * @return A pointer to the newly created Pilha object.
 */
Pilha *TDqueue_Create();

/**
 * @brief Removes the top element from the Pilha.
 * 
 * @param pilha The Pilha object.
 * @return True if the operation was successful, false otherwise.
 */
bool TDqueue_Pop(Pilha *pilha);

/**
 * @brief Adds a new element to the top of the Pilha.
 * 
 * @param pilha The Pilha object.
 * @param valor The value to be added.
 * @return True if the operation was successful, false otherwise.
 */
bool TDqueue_Push(Pilha *pilha, int valor);

/**
 * @brief Retrieves the value of the top element from the Pilha.
 * 
 * @param pilha The Pilha object.
 * @param valor A pointer to store the value of the top element.
 * @return True if the operation was successful, false otherwise.
 */
bool TDqueue_Top(Pilha *pilha, char *valor);

/**
 * @brief Checks if the Pilha is empty.
 * 
 * @param pilha The Pilha object.
 * @return True if the Pilha is empty, false otherwise.
 */
bool TDqueue_Empty(Pilha *pilha);

/**
 * @brief Retrieves the size of the Pilha.
 * 
 * @param pilha The Pilha object.
 * @param tamanho A pointer to store the size of the Pilha.
 * @return True if the operation was successful, false otherwise.
 */
bool TDqueue_Size(Pilha *pilha, int *tamanho);

/**
 * @brief Clears all elements from the Pilha.
 * 
 * @param pilha The Pilha object.
 * @return True if the operation was successful, false otherwise.
 */
bool TDqueue_Clear(Pilha *pilha);

/**
 * @brief Destroys the Pilha object and frees the memory.
 * 
 * @param pilha The Pilha object.
 * @return True if the operation was successful, false otherwise.
 */
bool TDqueue_Destroy(Pilha *pilha);

#endif // PILHA_H
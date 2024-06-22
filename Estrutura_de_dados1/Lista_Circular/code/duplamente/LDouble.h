#ifndef DUPLAMENTE_LISTA
#define DUPLAMENTE_LISTA

typedef struct double_linked TDList;
typedef struct no TNo;

TDList* TDList_create();
void TDList_destroy(TDList*);
/**
 * Insere a informação de maneira ordenada (crescente) na lista.
 * @return int =0 houve erro ou =1 sucesso ao inserir.
 * @param TDList* ponteiro para uma lista válida
 * @param int informação para ser armazenada na lista.
 */
int TDList_insert_s(TDList*, int);

/**
 * Imprime a lista duplamente encadeada como sendo um numero inteiro gigante.
 * Os numeros deverao ser impressos um ao lado do outro sem espaco e com um \n no final da lista.
 * @param: ponteiro para lista duplamente encadeada que representa um numero inteiro positivo.
 */
void TDList_print(TDList*);
void TDList_print_reverse(TDList*);

#endif

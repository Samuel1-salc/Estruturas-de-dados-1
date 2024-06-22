#ifndef DUPLAMENTE_LISTA
#define DUPLAMENTE_LISTA

typedef struct double_linked TDList;
typedef struct no TNo;

TDList* TDList_create();
void TDList_destroy(TDList*);

int TDList_insert(TDList*, int);
TNo* TDList_search(TDList*, int);
int TDList_remove(TDList*, int);
void TDList_print(TDList*);
void TDList_reverse_print(TDList*);


#endif

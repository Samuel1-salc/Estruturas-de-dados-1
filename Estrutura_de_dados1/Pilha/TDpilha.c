#include "Pilha.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct TDqueue {
    int data[29];
    int tamanho;
    int capacidade;
};

Pilha *TDqueue_Create() {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    if (pilha != NULL) {
        pilha->tamanho = 0;
        pilha->capacidade = 29;
    }
    return pilha;
}

bool TDqueue_Pop(Pilha *pilha) {
    if (pilha == NULL || pilha->tamanho == 0) {
        return false;
    }
    pilha->tamanho--;
    return true;
}

bool TDqueue_Push(Pilha *pilha, int valor) {
    if (pilha == NULL || pilha->tamanho == pilha->capacidade) {
        return false;
    }
    if(pilha->tamanho == 0){
        pilha->data[0] = valor;
        pilha->tamanho++;
        return true;
    }
    pilha->data[pilha->tamanho] = valor;
    pilha->tamanho++;
    return true;
}

bool TDqueue_Top(Pilha *pilha, char *valor) {
    if (pilha == NULL || pilha->tamanho == 0) {
        return false;
    }
    *valor = pilha->data[pilha->tamanho-1];
    return true;
}

bool TDqueue_Empty(Pilha *pilha) {
    return pilha == NULL || pilha->tamanho == 0;
}

bool TDqueue_Size(Pilha *pilha, int *tamanho) {
    if (pilha == NULL) {
        return false;
    }
    *tamanho = pilha->tamanho;
    return true;
}

bool TDqueue_Clear(Pilha *pilha) {
    if (pilha == NULL) {
        return false;
    }
    pilha->tamanho = 0;
    return true;
}

bool TDqueue_Destroy(Pilha *pilha) {
    if (pilha == NULL) {
        return false;
    }
    free(pilha);
    return true;
}

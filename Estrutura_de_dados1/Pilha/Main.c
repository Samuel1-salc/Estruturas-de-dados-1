#include "Pilha.h"
#include <stdio.h>
#include <string.h>
void adcVAlores(Pilha *pilha, char *frase){
    for(int i = 0; i < strlen(frase); i++){
        TDqueue_Push(pilha, frase[i]);
    }
}
bool Limpando_imprimindo(Pilha *pilha){
    int tamanho;
  
    TDqueue_Size(pilha, &tamanho);
    for(int i = 0; i < tamanho; i++){
        char teste;
        TDqueue_Top(pilha, &teste);  
        printf("%c ", teste);
        TDqueue_Pop(pilha);
    }
   
    return true;
}

int main(){
    Pilha *pilha = TDqueue_Create();
    char frase[] = "(())";
    adcVAlores(pilha, frase);
    for(int i= 0; i < strlen(frase); i++){
        if(frase[i] == ' ' || '.'){
            Limpando_imprimindo(pilha);
            printf(" ");
        }else{
            TDqueue_Push(pilha, frase[i]);
        
        }
    }
    TDqueue_Clear(pilha);
    TDqueue_Destroy(pilha);
    return 0;
    
}
#include "Pilha.h"
#include <stdio.h>
#include <string.h>
bool chekIFEquals(Pilha*pilha1 , Pilha*pilha2){
    int tamanho1, tamanho2;
    TDqueue_Size(pilha1, &tamanho1);
    TDqueue_Size(pilha2, &tamanho2);
    if(tamanho1 != tamanho2){
        return false;
    }
    for(int i = 0; i < tamanho1; i++){
        char teste1, teste2;
        TDqueue_Top(pilha1, &teste1);
        TDqueue_Top(pilha2, &teste2);
        if(teste1 != teste2){
            return false;
        }
        TDqueue_Pop(pilha1);
        TDqueue_Pop(pilha2);
    }

    return true;
}
void adcVAlores(Pilha *pilha, char *frase){
    for(int i = 0; i < strlen(frase); i++){
        TDqueue_Push(pilha, frase[i]);
    }
}
bool Limpando_imprimindo(Pilha *pilha){
    int tamanho;
    printf("dadsd");
    TDqueue_Size(pilha, &tamanho);
    for(int i = 0; i < tamanho; i++){
        char teste;
        TDqueue_Top(pilha, &teste);  
        printf("%c ", teste);
        TDqueue_Pop(pilha);
    }
   
    return true;
}

bool copiaPilha(Pilha*pilha1, Pilha*pilha2){
    int tamanho;
    TDqueue_Size(pilha1, &tamanho);
    for(int i = 0; i < tamanho; i++){
        char teste;
        TDqueue_Top(pilha1, &teste);
        TDqueue_Push(pilha2, teste);
        TDqueue_Pop(pilha1);
    }
    return true;
}

int main(){
    Pilha *pilha1 = TDqueue_Create();
    Pilha *pilha2 = TDqueue_Create();
    char frase1[] = "osso";
   
    
    
    
    
    
    
    //Chek if equals
    /*
    
      if(chekIFEquals(pilha1, pilha2)){
        printf("Iguais\n");
    }else{
        printf("Diferentes\n");
    }
    
    */
    //Palindromo
    /*
       for(int i= 0; i < strlen(frase); i++){
        TDqueue_Top(pilha, &Palindromo);
        TDqueue_Pop(pilha);
        if(Palindromo != frase[i]){
            printf("Nao e palindromo\n");
            chek = true;
            break;
        }
    }
    if(chek == false){
        printf(" e palindromo\n");
    }

    
    */
 


    TDqueue_Clear(pilha1);
    TDqueue_Clear(pilha2);
    TDqueue_Destroy(pilha1);
    TDqueue_Destroy(pilha2);
    return 0;
    
}
#include "LDouble.h"
#include <string.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
  if(argc>1){
    int j = 0;
    TDList* L1 = TDList_create();
    for(j=1; j<argc; j++)
      TDList_insert_s(L1, atoi(argv[j]));
    TDList_print(L1);
    TDList_print_reverse(L1);
  }
  return 0;
}
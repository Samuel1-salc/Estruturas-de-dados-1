#include "TCircList.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/// @brief 
/// @return 
int main()
{
    CircularList* list = CircularList_creat();
  
    CircularPredefine(list,4);
    CircularEDMundo(list,8);
    
    
    CircularList_Print(list);
    
    return 0;
}
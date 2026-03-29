#include "../../include/dynamic_memory/header.h"
/******************
* Discription : Pritns all elements of given pointer to given length
* Function name : printEle
* Parameters : pointer to first element,number of elements (N)
* Return : void
*******************/
void printEle(int32_t *ptr, int32_t totalElements){
        if(!ptr)
                return;
        int32_t count = 0;
        while(totalElements > 0){
                printf("%d ", *(ptr+count));
                count++;
                totalElements--;
        }
        putchar('\n');
}

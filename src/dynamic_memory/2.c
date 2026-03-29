#include "../../include/dynamic_memory/header.h"
/***************************
* Discription : Write a program that: allocates an array for 4 integers, stores 4 values, uses realloc to grow it to 8 integers, stores 4 more
		values and prints all 8.
* Function nane :
* Paremeters :
* Returntype :
****************************/
int main(void){
	int32_t *ptr = NULL;
	ptr = (int32_t*)calloc(4,sizeof(int32_t));
	printEle(ptr,4);
	ptr = realloc(ptr,8*sizeof(int32_t));
	printEle(ptr,8);
	free(ptr);
	return 0;
}

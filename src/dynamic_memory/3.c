#include "../../include/dynamic_memory/header.h"
/***************************
* Discription : Allocate a block of N integers using malloc and implement functions to set/get a value at index i using only pointer arithmetic,not [].
* Function nane : getIdxvalue
* Paremeters : int32_t *ptr, index
* Returntype : int32_t
****************************/
int32_t getIdxvalue(int32_t *intarr, int32_t index){
	if(!intarr)
		return;
	return *(intarr + index);
}
/***************************
* Discription : set the value at desire index in allocate memory block.
* Function nane : setIdxvalue
* Paremeters : int32_t *ptr, int32_t index, int32_t value
* Returntype : void
****************************/
void setIdxvalue(int32_t *intarr, int32_t index, int32_t value){
         if(!intarr)
		return;
	*(intarr + index) = value;
}
int main(void){
	int32_t length;
	int32_t *ptr = NULL;
	printf("Enter length : ");
	scanf("%d",&length);
	ptr = (int32_t*)malloc(length*sizeof(int32_t));
	setIdxvalue(ptr, 2, 40);
	printf("%d",getIdxvalue(ptr,2));
}

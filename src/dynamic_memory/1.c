#include "../../include/dynamic_memory/header.h"
/******************
* Discription : Allocate memory for an array of N integers (N from user), initialize all elements to their index value, print them, and free the
		memory.
* Function name : initEleWithInx
* Parameters : number of elements (N)
* Return : Pointer to first element of integers
*******************/
int32_t *initEleWithInx(int32_t totalElements){
	int32_t count=0;
	int32_t *ptrToInt = NULL;
	ptrToInt = (int32_t*)malloc(totalElements*sizeof(int32_t));
	if (!ptrToInt){
		printf("Allocation Failier.\n");
		return 0;
	}
	while(totalElements > 0){
		*(ptrToInt+count) = count;
		++count;
		totalElements--;
	}
	return ptrToInt;
}
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
int main(void){
	int32_t totalElements = 0;
	int32_t *returnPtr  = NULL;
	printf("enter number if total number elements : ");
	scanf("%d", &totalElements);

	returnPtr = initEleWithInx(totalElements);
	printEle(returnPtr,totalElements);
	free(returnPtr);
	return 0;
}

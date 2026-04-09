#include "include/header.h"
int main(void){
	int16_t size = 0;
	int32_t *arr = NULL;
	arr = createArray(&size);
	printArray(arr, size);
	//maxMinEle(arr, size);
	secMinMax(arr, size);
	//countEvenOdd(arr, size);
	//insertEle(&arr,&size,3,0);
	//printArray(arr, size);
	//uniqueEle(arr,size);
	//sprintf("frequency of 4 is : %hd \n",frqCount(arr, size, 4));
	//checkPali(arr, size) ? printf("Array is palindrome.\n") : printf("Array is not palindrome.\n");
	//revPorofArr(arr,size,2,4);
	//printArray(arr, size);
	//checkSort(arr, size) ? printf("Array is sorted\n") : printf("Array is not sorted\n");
	//sortArray(arr,size,insertionSort);
	//printArray(arr, size);
	//printf("Found at : %hd\n",searchArray(arr, size, binarySearch, 5));
	//rotateleft(arr, size, 4);
	//rotateright(arr, size, 2);
	//printArray(arr, size);
	//removeDupli(&arr, &size);
	//printArray(arr, size);
	free(arr);
	return 1;
}

#include "../include/header.h"
/*****************************************
* Description : this is the function defination file for arrays
*****************************************/

int32_t* createArray(int16_t *size) {
    	printf("Enter array size: ");
    	scanf("%hd", size);
    	int32_t* arr = (int32_t*)malloc((*size) * sizeof(int32_t));
    	if (arr == NULL)
    	{
        	fprintf(stderr, "Memory allocation failed\n");
        	return NULL;
    	}
	printf("Enter %d elements:\n", *size);
    	for (int i = 0; i < *size; i++) {
        	scanf("%d", &arr[i]);
    	}
	return arr;
}
/******************************************
* Function Name : printArray()
* Description : print whole arrray
* Parameters : array, length
* Return Value : void
******************************************/
void printArray(int32_t* arr, int16_t size) {
	if(!arr){
		fprintf(stderr, "Null encountered\n");
		return;
	}
	printf("Array elements:\n");
	for (int i = 0; i < size; i++) {
        	printf("%d ", arr[i]);
    	}
    	printf("\n");
}

/******************************************
* Function Name : maxMinEle()
* Description : prints max and min value of an array
* Parameters : int32_t arr, arrLen
* Return Value : void
******************************************/
void maxMinEle(int32_t arr[], int16_t arrLen){
	int32_t min=0,max=0;
        int16_t idxright=0,idxleft=0;
        int iteration = 0;
        for(idxleft=0, idxright = arrLen - 1; idxleft != idxright;){
                //printf("%d\n",iteration);
                //printf("%d  %d\n",idxleft,idxright);
		if(arr[idxleft] > arr[idxright]){
                        idxright--;
                        max = arr[idxleft];
                }
                else if(arr[idxleft] < arr[idxright]){
                	idxleft++;
                        max = arr[idxright];
                }
                else{
                         idxleft++;
                         max = arr[idxright];
                }
                iteration++;
        }
    	printf("max : %d\n",max);
	for(idxleft=0, idxright = arrLen - 1; idxleft != idxright;){
		//printf("%d  %d\n",idxleft,idxright);
                if(arr[idxleft] > arr[idxright]){
                        idxleft++;
                        min = arr[idxright];
                }
                else if(arr[idxleft] < arr[idxright]){
                        idxright--;
                        min = arr[idxleft];
                }
                else{
                        idxleft++;
                        min = arr[idxright];
                }
                iteration++;
        }
	printf("min : %d\n",min);
	printf("iterations : %d\n", iteration);
}
/******************************************
* Function Name : secMinMax()
* Description : This function finds seccond max and min element from the array
* Parameters : int32_t arr[], int32_t arrLen
* Return Value : void
******************************************/
void secMinMax(int32_t arr[], int16_t arrLen){
    	if (arrLen < 2) {
        	printf("Array is too small to find second min/max.\n");
        	return;
    	}

    	int32_t min = INT32_MAX, secMin = INT32_MAX;
    	int32_t max = INT32_MIN, secMax = INT32_MIN;

    	for (int16_t i = 0; i < arrLen; i++) {
        	if (arr[i] > max) {
            		secMax = max;
            		max = arr[i];
        	}
        	else if (arr[i] > secMax && arr[i] < max)
            	{
            		secMax = arr[i];
        	}

        if (arr[i] < min) {
            secMin = min;
            min = arr[i];
        }
        else if (arr[i] < secMin && arr[i] > min) {
            secMin = arr[i];
        }
    }
    if (secMax == INT32_MIN || secMin == INT32_MAX) {
        fprintf(stderr, "No distinct second minimum or maximum found.\n");
    } else {
        printf("Second Min: %d\n", secMin);
        printf("Second Max: %d\n", secMax);
    }
}
/******************************************
* Function Name : countEvenOdd()
* Description : count total numbers of even and odd numbers
* Parameters : int32_t arr[], int32_t arrLen
* Return Value : void
******************************************/
void countEvenOdd(int32_t arr[], int16_t arrLen){
	if(!arrLen)
		return;
	int16_t evenNo=0, oddNo=0;
	for(int idx = 0; idx < arrLen; ++idx){
		if(arr[idx] % 2 == 0)
			evenNo++;
		else
			oddNo++;
	}
	printf("Total even numbers are : %hd \nToatal off numbers are : %hd\n", evenNo, oddNo);
}
/******************************************
* Function Name : uniqueEle()
* Description :	prints unique elements from the array
* Parameters : int32_t arr[], int16_t arrLen
* Return Value : total numbers of unique elements
******************************************/
int32_t uniqueEle(int32_t arr[], int16_t arrLen){
	for (int16_t i = 0; i < arrLen; i++) {
        int count = 0;

        for (int16_t j = 0; j < arrLen; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count == 1) {
            printf("%d ", arr[i]);
        }
    }
    putchar('\n');
}
/******************************************
* Function Name : insertEle()
* Description : insert element at given index
* Parameters : int32_t *arr,int16_t arrLen,int16_t position
* Return Value : void
******************************************/
void insertEle(int32_t **arr,int16_t *arrLen,int16_t position, int32_t value){
	if (arr == NULL || *arr == NULL) return;
        if (position < 0 || position >= *arrLen) return;
	int32_t *tmp = realloc(*arr, ((*arrLen + 1)) * sizeof(int32_t));
	if (tmp != NULL || arrLen - 1 == 0) {
		*arr = tmp; // update pointer if realloc succeeded
         }
	*arrLen += 1;
        for ( int16_t count = *arrLen - 1; count > position; --count){
		(*arr)[count] = (*arr)[count - 1];
        }
        (*arr)[position] = value;
}
/******************************************
* Function Name : delEle()
* Description : deletes element at given index
* Parameters : int32_t *arr,int16_t arrLen,int16_t position
* Return Value : void
******************************************/
void delEle(int32_t **arr,int16_t arrLen,int16_t position){
	if (arr == NULL || *arr == NULL) return;
    	if (position < 0 || position >= arrLen) return;
    	for (int16_t i = position; i < arrLen - 1; i++) {
        	(*arr)[i] = (*arr)[i + 1];
    	}
    	int32_t *temp = realloc(*arr, (arrLen - 1) * sizeof(int32_t));
    	if (temp != NULL || arrLen - 1 == 0) {
        	*arr = temp; // update pointer if realloc succeeded
    	}
}
/******************************************
* Function Name : freCount()
* Description : funtion to count how many times a particular element appears in a given array.
* Parameters : int32_t *arr,int16_t arrLen,int32_t value
* Return Value : int16_t totalOccur
******************************************/
int16_t frqCount(int32_t arr[],int16_t arrLen,int32_t value){
	int16_t count = 0;
	for (int i = 0; i < arrLen; ++i){
		if(arr[i] == value){
			count++;
		}
	}
	return count;
}
/******************************************
* Function Name : checkPali()
* Description : checks if the array is paindrome or not.
* Parameters : array, array length
* Return Value : 0 - isnotpalindrome 1 - ispalindrome
******************************************/
bool checkPali(int32_t arr[],int16_t arrLen){
	bool ispalindrome = 0;
	for(int i=0, j=arrLen-1; i <= (arrLen/2); ++i,--j){
		if(arr[i] == arr[j]){
			ispalindrome = 1;
			continue;
		}
		else
			ispalindrome = 0;
	}
	return ispalindrome;
}
/******************************************
* Function Name : revPorofArr()
* Description : reverse a portion of an array
* Parameters : arr - array, arrLen - array length, from - start position, to - end position
* Return Value : void
******************************************/
void revPorofArr(int32_t arr[],int16_t arrLen, int16_t startIdx, int16_t endIdx){
	if (startIdx < 0 || endIdx >= arrLen) {
        	fprintf(stderr, "Indices out of bounds.\n");
        	return;
    	}
	if(startIdx > endIdx){
		fprintf(stderr, "Starting index is greater than or equal to ending index.\n");
		return;
	}
	int32_t tmp = 0;
	int32_t *arrptr1 = arr + startIdx - 1;
	int32_t *arrptr2 = arr + endIdx - 1;
	while(arrptr1 < arrptr2){
		tmp = *arrptr1;
		*arrptr1 = *arrptr2;
		*arrptr2 = tmp;
		arrptr1++;
		arrptr2--;
	}
}
/******************************************
* Function Name : checkSort()
* Description : checks if the array is sorted or not
* Parameters : arrary, array length
* Return Value : bool, 1 - sorted, 0 - unsorted
******************************************/
bool isSort(int32_t arr[],int16_t arrLen){
	if (!arr)
		return 0;
	bool status;
	for(int i = 0; i < arrLen - 1; ++i){
		if(arr[i] < arr[i + 1])
			status = true;
		else
			status = false;
	}
	return status;
}
/******************************************
* Function Name : sortArray()
* Description : sort an array in accending order using bubble sort or insertion sort
* Parameters : array, array length, poiter to function
* Return Value : void
******************************************/
void sortArray(int32_t arr[],int16_t arrLen, void (*sortAlgo)(int32_t *, int16_t)){
	if(!isSort){
		fprintf(stderr, "Array is already sorted in decending order.\n");
		return;
	}
	sortAlgo(arr, arrLen);
}
/******************************************
* Function Name : bubbleSort
* Description : sort an array using function pointer
* Parameters : array, array length
* Return Value : void
******************************************/
void bubbleSort(int32_t arr[],int16_t arrLen){
	for(int i = 0; i < arrLen - 1; ++i){
		for(int j = i+1; j < arrLen; ++j){
			if(arr[j] < arr[i]){
				int32_t tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
/******************************************
* Function Name : insertionSort()
* Description : sort an array with insertion sort
* Parameters : array, array size
* Return Value : void
******************************************/
void insertionSort(int32_t arr[],int16_t arrLen){
	int16_t j;
	int16_t key = 1;
	for(int i = key; key < arrLen; ++key){
		i = key;
		for(j=key - 1; j>=0; --j){
			if(arr[i] < arr[j]){
				int tmp = arr[i];
                        	arr[i] = arr[j];
                        	arr[j] = tmp;
                        	i = j;
                        }
                        //printArray(arr,arrLen);
		}
	}
}
/******************************************
* Function Name : searchArray()
* Description : search for an element and return its index
* Parameters : array, size, algo functio
* Return Value : int16_t --> index
******************************************/
int16_t searchArray(int32_t arr[],uint16_t arrLen, int16_t (*searchAlgo)(int32_t *, int16_t, int32_t), int32_t value){
	return searchAlgo(arr, arrLen,value);
}
/******************************************
* Function Name : linearSearch()
* Description : search an element with linear search
* Parameters : array, length, value to be search for
* Return Value : index
******************************************/
int16_t linearSearch(int32_t *arr, int16_t arrLen, int32_t value) {
    for (int16_t i = 0; i < arrLen; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}
/******************************************
* Function Name : binarySearch()
* Description : search an element with linear search
* Parameters : array, length, value to be search for
* Return Value : index
******************************************/
int16_t binarySearch(int32_t *arr, int16_t arrLen, int32_t value) {
	if(!isSort(arr,arrLen))
    		sortArray(arr,arrLen,insertionSort);
	//printArray(arr, arrLen);
    	int16_t low = 0, high = arrLen - 1;
    	while (low <= high) {
        	int16_t mid = low + (high - low) / 2;

        	if (arr[mid] == value) {
            		return mid;
        	} else if (arr[mid] < value) {
            		low = mid + 1;
        	} else {
            		high = mid - 1;
        	}
    	}
    	return -1;
}
/******************************************
* Function Name : rotateleft()
* Description : shift array to left by given value
* Parameters : array, length, rotation value
* Return Value : void
******************************************/
void rotateleft(int32_t *arr, int16_t arrLen, int32_t rotateValue){
	while(rotateValue){
		for(int i = arrLen - 1; i>0; --i){
			int tmp = arr[i];
                        arr[i] = arr[0];
                        arr[0] = tmp;
		}
		rotateValue--;
	}
}
/******************************************
* Function Name : rotateright()
* Description : shift array to right by given value
* Parameters : array, size, ratation value
* Return Value : void
******************************************/
void rotateright(int32_t *arr, int16_t arrLen, int32_t rotateValue){
        while(rotateValue){
                for(int i = 0; i < arrLen - 1; ++i){
                        int tmp = arr[i];
                        arr[i] = arr[arrLen - 1];
                        arr[arrLen - 1] = tmp;
                }
                rotateValue--;
        }
}
/******************************************
* Function Name : removeDupli()
* Description : removes all duplicate elements
* Parameters : array address, length address
* Return Value : void
******************************************/
void removeDupli(int32_t **arr, int16_t *arrLen){
	for (int16_t i = 0; i < *arrLen; i++)
    	{
        	for (int16_t j = i + 1; j < *arrLen; )
        	{
            		if ( (*arr)[i] == (*arr)[j] )
            		{
                		for (int16_t k = j; k < *arrLen - 1; k++)
                		{
                    			(*arr)[k] = (*arr)[k + 1];
                		}

                		(*arrLen)--;
            		}
           		else
            		{
                		j++;
            		}
        	}
    	}
    	int32_t *tmp = realloc(*arr, (*arrLen) * sizeof(int32_t));
    	if (tmp != NULL)
    	{
        	*arr = tmp;
    	}
}

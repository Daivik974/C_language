#ifndef HEADER_D
#define HEADER_D
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<math.h>
#include<string.h>
int32_t* createArray(int16_t *size);
void printArray(int32_t* arr, int16_t size);
void maxMinEle(int32_t arr[], int16_t arrLen);
void countEvenOdd(int32_t arr[], int16_t arrLen);
int32_t uniqueEle(int32_t arr[], int16_t arrLen);
void insertEle(int32_t **arr,int16_t *arrLen,int16_t position, int32_t value);
int16_t frqCount(int32_t arr[],int16_t arrLen,int32_t value);
bool checkPali(int32_t arr[],int16_t arrLen);
void revPorofArr(int32_t *arr,int16_t arrLen, int16_t startIdx, int16_t endIdx);
bool isSort(int32_t arr[],int16_t arrLen);
void sortArray(int32_t arr[],int16_t arrLen, void (*sortAlgo)(int32_t *, int16_t));
void bubbleSort(int32_t arr[],int16_t arrLen);
void insertionSort(int32_t arr[],int16_t arrLen);
int16_t searchArray(int32_t arr[],uint16_t arrLen, int16_t (*searchAlgo)(int32_t *, int16_t, int32_t), int32_t value);
int16_t linearSearch(int32_t *arr, int16_t arrLen, int32_t value);
int16_t binarySearch(int32_t *arr, int16_t arrLen, int32_t value);
void rotateleft(int32_t *arr, int16_t arrLen, int32_t rotateValue);
void rotateright(int32_t *arr, int16_t arrLen, int32_t rotateValue);
void removeDupli(int32_t **arr, int16_t *arrLen);

#endif

/**************************************************************
* Discription : main file for bitmanipulation
**************************************************************/
#include "include/bit_manipulation/header.h"
int main(void){
	uint32_t number = 0;
	uint8_t bitPosition = 0;
	printf("Enter number : ");
	scanf("%x", &number);
	printf("Enter bit position :");
        scanf("%hhd", &bitPosition);
	setBit(&number, &bitPosition);
	printf("%x\n",number);
	return 0;
}

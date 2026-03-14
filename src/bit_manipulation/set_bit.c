#include "/home/daivik_pandya/clonedir/C_language/include/bit_manipulation/header.h"
/**********************************************************************
* Function : setBit
* Discription : set particular bit in any number
* parameters : number, bitPosition
* returnVale : void
*********************************************************************/
void setBit(uint32_t *number, uint8_t *bitPosition){
	*number |= 1u << ( *bitPosition - 1 );
}

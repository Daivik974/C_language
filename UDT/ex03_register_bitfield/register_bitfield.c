/******************************************
* Description : Design a structure using bit-fields to represent an 8-bit control register. Include flags like power enable, interrupt enable, mode
		select, and error flag.
		Write functions to set, clear, and display register values.
******************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct{
	uint32_t power : 1;
	uint32_t interrupt : 1;
	uint32_t mode : 2;
	uint32_t error : 1;
	uint8_t reserved : 3;
}ControlRegister;

void displayRegister(ControlRegister reg) {
    printf("Power: %u\n", reg.power);
    printf("Interrupt: %u\n", reg.interrupt);
    printf("Mode: %u\n", reg.mode);
    printf("Error: %u\n", reg.error);

    printf("Register: ");
    for (int i = 7; i >= 0; i--) {
        printf("%u", (*((uint8_t *)&reg) >> i) & 1);
    }
    printf("\n");
}

void setPower(ControlRegister *reg) {
    	reg->power = 1;
}

void setInterrupt(ControlRegister *reg) {
    	reg->interrupt = 1;
}

void setMode(ControlRegister *reg, uint8_t mode) {
    	reg->mode = mode & 0x03;
}

void setError(ControlRegister *reg) {
    	reg->error = 1;
}

void clearPower(ControlRegister *reg) {
    reg->power = 0;
}

void clearInterrupt(ControlRegister *reg) {
    reg->interrupt = 0;
}

void clearMode(ControlRegister *reg) {
    reg->mode = 0;
}

void clearError(ControlRegister *reg) {
    reg->error = 0;
}
void menu(){
	printf("\n----- control register menu -----\n");
        printf("1. Set power\n");
        printf("2. Clear power\n");
        printf("3. Set interrupt\n");
        printf("4. Clear interrupt\n");
        printf("5. Set mode\n");
        printf("6. Clear mode\n");
        printf("7. Set error\n");
        printf("8. Clear error\n");
        printf("9. Display register\n");
        printf("0. exit\n");
}
int main() {
    	ControlRegister reg = {0};
    	int choice;
    	uint8_t mode;
	menu();
    	while (1) {
        	printf("Enter choice: ");
        	scanf("%d", &choice);

        	switch (choice) {
            		case 1:
                	setPower(&reg);
                	break;
            	case 2:
                	clearPower(&reg);
                	break;
            	case 3:
                	setInterrupt(&reg);
                	break;
            	case 4:
                	clearInterrupt(&reg);
                	break;
            	case 5:
                	printf("Enter mode (0–3): ");
                	scanf("%hhu", &mode);
                	setMode(&reg, mode);
                	break;
            	case 6:
                	clearMode(&reg);
                	break;
            	case 7:
                	setError(&reg);
                	break;
            	case 8:
                	clearError(&reg);
                	break;
            	case 9:
                	displayRegister(reg);
                	break;
            	case 0:
                	return 0;
            	default:
                	printf("Invalid choice!\n");
        	}
    	}

    	return 0;
}

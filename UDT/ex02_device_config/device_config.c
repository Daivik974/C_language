/******************************************
* Description : Define a `struct DeviceConfig` containing device name, mode, baud rate, sampling interval, and enable flags.
		Use `typedef` to simplify the type name.
		Allow the user to update one field at a time and print the full configuration after each update.
******************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

enum Mode{normal, sleep, debug};
typedef struct{
	char deviceName[10];
	enum Mode mode;
	uint32_t baudrate;
	float sampling_interval;
	bool flag;
}DeviceConfig;

void menu(){
	printf("-----------------Menu--------------------\n");
         printf("0 : Device name\n");
         printf("1 : Mode (normal=0, sleep=1, debug=2)\n");
         printf("2 : baudrate\n");
         printf("3 : sampling_interval\n");
         printf("4 : flag\n");
         printf("-----------------------------------------\n");
}
void modify_field(DeviceConfig config){
	uint16_t choice;
	printf("Which field do you want to modify?\n");
	scanf("%hd", &choice);
	switch (choice){
		case 0:
			printf("Enter new device name: ");
			scanf("%s", config.deviceName);
			break;
		case 1:
			printf("Enter mode: ");
			scanf("%u", &config.mode);
			break;
		case 2:
			printf("Enter new baudrate: ");
			scanf("%d", &config.baudrate);
			break;
		case 3:
			printf("Enter new sampling interval: ");
			scanf("%f", &config.sampling_interval);
			break;
		case 4:
			config.flag ^= 1;
			break;
		default :
			printf("Invalid choice");
	}
}

void printConfig(DeviceConfig config){
	printf("-----------------Current Configurations-------------------- \n");
	printf("Device name: %s \n",config.deviceName);
	printf("Mode: %d\n", config.mode);
	printf("Baudrate: %d\n", config.baudrate);
	printf("Sampling Rate: %f\n", config.sampling_interval);
	printf("Flag: %d\n", config.flag);
}
int main(){
	int repeat = true;
	DeviceConfig config;
	config.flag=0;
	menu();
	while(repeat){
		modify_field(config);
		printConfig(config);
		printf("Want to continue?(1/0): ");
		scanf("%d",&repeat);
	}
	return 0;
}

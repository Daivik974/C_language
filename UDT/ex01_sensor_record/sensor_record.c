/******************************************
* Description : Create a `struct Sensor` to store sensor ID, sensor name, reading value, and status.Use an `enum` for status values such as `OK`, 
		`WARN`, and `FAIL`.
		Write a program to input readings for 5 sensors and display only the valid readings.
******************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

enum status {OK, WARN, FAIL};
typedef struct{
	uint16_t ID;
	char name[10];
	float readingValue;
	char whatstatus[5];
}Sensor;

void takeInput(Sensor *sensor, int8_t number){
	for(int i = 0; i < 5; i++){
		printf("Enter ID of sensor %d : ",i);
		scanf("%hd", &sensor[i].ID);
		printf("Enter name of sensor %d : ",i);
		scanf("%s", sensor[i].name);
		printf("Enter reading values of sensor %d : ",i);
		scanf("%f", &sensor[i].readingValue);
		printf("Enter status of sensor %d : ", i);
		scanf("%s", sensor[i].whatstatus);
	}
}

int main(){
	Sensor sensor[5];
	takeInput(sensor, 5);
	return 0;
}

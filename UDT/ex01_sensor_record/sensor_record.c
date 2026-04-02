/******************************************
* Description : Create a `struct Sensor` to store sensor ID, sensor name, reading value, and status.Use an `enum` for status values such as `OK`, 
		`WARN`, and `FAIL`.
		Write a program to input readings for 5 sensors and display only the valid readings.
******************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define TOATAL_SENSORS 2

enum Status {OK, WARN, FAIL};
typedef struct{
	uint16_t id;
	char name[10];
	float readingValue;
	enum Status status;
}Sensor;

void takeInput(Sensor *sensor){
	printf("For status --> OK=0, WARN=1, FAIL=2\n");
	for(int i = 1; i <= TOATAL_SENSORS; i++){
		printf("Enter ID of sensor %d : ",i);
		scanf("%hd", &sensor[i-1].id);
		printf("Enter name of sensor %d : ",i);
		scanf("%s", sensor[i-1].name);
		printf("Enter reading values of sensor %d : ",i);
		scanf("%f", &sensor[i-1].readingValue);
		printf("Enter status of sensor %d : ", i);
		scanf("%u", &sensor[i-1].status);
	}
}

void printData(Sensor *sensor){
	for(int i=1; i <= TOATAL_SENSORS; i++){
		if(sensor[i-1].status != FAIL){
			printf("Readings of %s sensor with ID : %hd is %f.\n",sensor[i-1].name, sensor[i-1].id, sensor[i-1].readingValue);
		}
		else{
			printf("%s sensor with ID : %hd is failed.\n",sensor[i-1].name, sensor[i-1].id);
		}
	}
}

int main(){
	Sensor sensor[TOATAL_SENSORS];
	takeInput(sensor);
	printData(sensor);
	return 0;
}

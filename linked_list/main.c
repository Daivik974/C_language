/**************************************************
Description: main file for linked list
**************************************************/
#include"include/header.h"
int main(){
	int32_t choice=0;
	int8_t repeat = 1;
	int32_t data=0;
	int32_t totalNodes=0;
	Node *head = NULL;
	while(repeat){
		menu();
		printf("Enter your choice :");
		scanf("%d",&choice);
		printf("Enter data : ");
		scanf("%d", &data);
		switch(choice){
			case 1:
				head = initList(head,data);
				break;
			case 2:
				head = insertAtBegin(head, data);
				break;
			case 3:
				head = insertAtEnd(head, data);
				break;
			case 4:
				int32_t position=0;
				printf("After witch position you want to add a node: ");
				scanf("%d", &position);
				insertAfterPos(head, data, position);
				break;
			case 5:
                                printf("Enter before witch posion you want to add a node: ");
                                scanf("%d", &position);
                                head = insertBeforePos(head, data, position);
				break;
			case 6:
				int32_t dataAfter = 0;
				printf("Enter afetr witch data you want to add a node: ");
				scanf("%d", &dataAfter);
				head = insertAfterVal(head, dataAfter, data);
				break;
			case 7:
				int32_t databefore = 0;
				printf("Enter before witch data you want to add a node: ");
                                scanf("%d", &databefore);
				head = insertBeforeVal(head, databefore, data);
				break;
			case 8:
				totalNodes = countNodes(head);
				printf("Total numbers of nodes are %d\n", totalNodes);
				break;
			case 9:
				displaylist(head);
				break;
			case 10:
				printf("Enter At witch posion you want to add a node: ");
                                scanf("%d", &position);
				head=insertAtpos(head, data, position);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Invalid Choice.");
		}
		printf("Do you what to enter again?(n=0/y=1): ");
		scanf("%hhd",&repeat);
	}
	return 0;
}

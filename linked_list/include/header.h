#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;

void menu();
Node *initList(Node *head,int32_t data);
Node *insertAtBegin(Node *head, int32_t data);
void displaylist(Node *head);
int32_t countNodes(Node *head);
Node *insertAtEnd(Node *head, int32_t data);
Node *insertAfterPos(Node *head, int32_t data, int32_t position);
Node *insertBeforePos(Node *head, int32_t data, int32_t position);
Node *insertBeforeVal(Node *head, int data, int dataToAdd);
Node *insertAfterVal(Node *head, int data, int dataToadd);
Node *insertAtpos(Node *head,int32_t data, int32_t position);

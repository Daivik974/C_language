#include"../include/header.h"
/******************************************
* Function Name :
* Description :
* Parameters :
* Return Value :
******************************************/
void menu()
{
    printf("\n----- LINKED LIST MENU -----\n");
    printf("1. Initialize List\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at End\n");
    printf("4. Insert After Position\n");
    printf("5. Insert Before Position\n");
    printf("6. Insert After Value\n");
    printf("7. Insert Before Value\n");
    printf("8. Count Nodes\n");
    printf("9. Display List\n");
    printf("10. Reverse List\n");
    printf("0. Exit\n");
    printf("----------------------------\n");
}
Node *initList(Node *head,int32_t data){
	if(head == NULL){
		head = malloc(sizeof(Node));
	}
	else
	{
		printf("List Aready Initialized\n");
		return head;
	}
	if(!head)
		printf("Memory Allocation Faliure\n");
	head->data = data;
	head -> next = NULL;
	return head;
}

Node *insertAtBegin(Node *head, int32_t data){
	Node *tmp = NULL;
	tmp = (Node*)malloc(sizeof(Node));
	if(!tmp){
		printf("allocation failed.\n");
		return head;
	}
	if (head == NULL){
		head = tmp;
		head -> next = NULL;
	}
	else{
		tmp -> next = head;
		head = tmp;
	}
	head -> data = data;
	return head;
}

Node *insertAtEnd(Node *head, int32_t data){
	Node *newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	if(!newNode){
                 printf("allocation failed.");
                 return head;
         }
	if (head == NULL){
                 head = newNode;
                 head -> next = NULL;
                 return head;
         }
	Node *tmp = NULL;
	tmp = head;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	newNode->next = NULL;
	newNode->data = data;
	tmp->next = newNode;
	return head;
}
Node *insertAfterPos(Node *head, int32_t data, int32_t position){
	 if (head == NULL) {
                 printf("List is empty\n");
                 return head;
         }
         Node *temp = head;
         Node *newNode = (Node *)malloc(sizeof(Node));
         if (newNode == NULL) {
                 printf("Allocation failure\n");
                 return head;
         }
         newNode->data = data;
         int32_t count=1,totalCount=0;
         totalCount = countNodes(head);
         while(count != position && count <= totalCount){
		temp = temp->next;
		count++;
         }
         if (temp == NULL){
                 printf("total count is less than position\n");
                 free(newNode);
                 return head;
         }
         newNode->next = temp->next;
         temp->next = newNode;
         return head;
}

Node *insertBeforePos(Node *head, int32_t data, int32_t position){
	if (head == NULL) {
                  printf("List is empty\n");
                  return head;
         }
         Node *temp = head;
         Node *prev = NULL;
         Node *newNode = (Node *)malloc(sizeof(Node));
         if (newNode == NULL) {
                 printf("Allocation failure");
                 return head;
         }
         newNode->data = data;
         int32_t count=1,totalCount=0;
         totalCount = countNodes(head);
         while (count != position && count <= totalCount) {
                 prev = temp;
                 temp = temp->next;
                 count++;
         }
         if (temp == NULL) {
                 printf("data not found");
                 free(newNode);
                 return head;
         }
         newNode->next = temp;
         prev->next = newNode;
         return head;
}
Node *insertAfterVal(Node *head, int data, int dataToadd){
	if (head == NULL) {
        	printf("List is empty");
        	return head;
    	}
   	Node *temp = head;
    	Node *newNode = (Node *)malloc(sizeof(Node));
   	if (newNode == NULL) {
        	printf("Allocation failure");
    	}
    	newNode->data = dataToadd;
    	while (temp != NULL && temp->data != data) {
        	temp = temp->next;
    	}
    	if (temp == NULL) {
        	printf("data not found");
        	free(newNode);
    	}
    	newNode->next = temp->next;
    	temp->next = newNode;
    	return head;
}

Node *insertBeforeVal(Node *head, int data, int dataToAdd){
	if (head == NULL) {
		printf("List is empty");
    	}
	Node *temp = head;
	Node *prev = NULL;
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL) {
        	printf("Allocation failure");
    	}
	newNode->data = dataToAdd;
	while (temp != NULL && temp->data != data) {
		prev = temp;
        	temp = temp->next;
    	}
	if (temp == NULL) {
        	printf("data not found");
        	free(newNode);
    	}
    	newNode->next = temp;
	prev->next = newNode;
	return head;
}

int32_t countNodes(Node *head){
	if(!head){
                 printf("List is empty\n");
                 return 0;
         }
         int32_t count = 0;
         while(head){
                 head = head->next;
                 count++;
         }
         return count;
}

void displaylist(Node *head){
	if(!head){
		printf("List is empty\n");
	}
	int32_t count=1;
	Node *tmp = head;
	while(tmp){
		printf("Node: %d data: %d\n",count,tmp->data);
		tmp = tmp->next;
		count++;
	}
}

Node *insertAtpos(Node *head,int32_t data, int32_t position){
	Node *temp = head;
	Node *newNode = NULL;
	Node *prev = NULL;
	newNode = malloc(sizeof(Node));
	int32_t totalCount=0,count=1;
	totalCount = countNodes(head);
	if(position == 1){
		printf("in 1\n");
		newNode-> next = head;
		head = newNode;
		head->data = data;
		return head;
	}
	else if(position <= totalCount){
		while (count != position && count <= totalCount) {
                  	prev = temp;
                  	temp = temp->next;
                  	count++;
          	}
          	newNode->next = temp;
          	prev->next = newNode;
	}
	else{
		if(position == (totalCount + 1)){
			while (temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = NULL;
		}
		else{
			printf("Can not add node/n");
			free(newNode);
			return head;
		}
	}
	newNode->data = data;
	return head;
}

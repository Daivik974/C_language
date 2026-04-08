/******************************************
* Function Name :
* Description :
* Parameters :
* Return Value :
******************************************/
Node *initList(Node *head,int32_t data){
	if(head == NULL){
		head = malloc(sizeof(Node));
	}
	head->data = data;
	head -> next = NULL;
}

Node *insertAtBegin(){
}

Node *insertAtEnd(){
}

Node *insertAfterPos(){
}

Node *insertBeforePos{
}

Node *insertAfterVal(){
}

Node *insertBeforeVal(){
}

int32_t countNodes(Node *head){
}

Node *displaylist(Node *head){
}

Node *reverseList(Node *head){
}

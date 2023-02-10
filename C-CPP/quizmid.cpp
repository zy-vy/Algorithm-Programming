#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
	char name[101];
	int prior=11;
	data *next,*prev;

}*head=NULL,*tail=NULL,*curr=NULL,*temp=NULL;


void pushHead(char name[],int num){
	data *curr = (data *)malloc(sizeof(data));
	strcpy(curr->name,name);
	curr->prior = num;
	curr->next = NULL;

	if(!head){
		head = tail = curr;
	}
	else if (curr->prior<head->prior){
		head->prev=curr;
		curr->next=head;
		head=curr;
	}
	else {
		temp=head;
		while (temp->next!=NULL&&temp->next->prior<num){
			temp=temp->next;
		}
		curr->next=temp->next;
		curr->prev=temp;
		temp->next=curr;
		curr=temp->next;
	}
}

void pushTail(char name[],int num){
	data *curr = (data *)malloc(sizeof(data));
	strcpy(curr->name,name);
	curr->prior = num;
	curr->next = NULL;
	if(!head){
		head = tail = curr;
	}
	else{
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
	}
}
void popTail(){
	if(!head){
		printf ("Wish not found \n");
		return;
	}
	else if(head == tail){
		free(head);
		head = tail = NULL;
	}
	else{
		tail = tail->prev;
		free(tail->next);
		tail->next->prev = NULL;
		tail->next = NULL;
	}
}

void popHead(){
	if(!head){
		return;
		}
	else if(head == tail){
		free(head);
		head = tail =NULL;
	}
	else{
		head = head->next;
		free(head->prev);
		head->prev->next = NULL;
		head->prev = NULL;
	}
}
void add (){
	char name[101];int num=0;
//	getchar();
	do {

		printf ("Input wishlist name [1...100] : ");

		scanf ("%[^\n]",&name);getchar();
		printf ("\n");
	}while (strlen(name)<1||strlen(name)>100);
	do {

		printf ("Input wishlist priority [1...10] : ");
		scanf ("%d",&num);
		printf ("\n");
	}while (num<1||num>10);

		pushHead(name,num);
}

void zdelete(char name[]){
	int temp = 0;
	curr = head;
	while(curr){
		if(strcmp(curr->name,name)==0){
			if (curr==head){
				popHead();
				temp=1;
			}
			else if (curr==tail){
				popTail();
				temp=1;
			}
			else {
				curr->prev->next=curr->next;
				curr->next->prev=curr->prev;
				free(curr);
				curr=curr->prev;

	//			curr=NULL;
				temp = 1;
				break;
			}

		}
		curr = curr->next;
	}
	if(temp == 0){
		printf("Wish not found \n");
	}
}

void view(){
	curr = head;
	int count=1;
	while(curr){
		printf("%d. %s #%d\n",count,curr->name,curr->prior);
		curr = curr->next;
		count++;
	}
	printf ("\n");
}
void popAll2(){
	while(head){
		popHead();
	}
}


int main (){
	int input=0;
	while (input !=4){
		printf ("1. add wishlist\n2. view wishlist\n3. remove wishlist\n4. exit\nplease choose :");
		scanf ("%d",&input);getchar();
		printf ("\n");
		switch (input){
			case 1:
				add();
				break;
			case 2:
				view();
				break;
			case 3:
				char name[101];
				if (head==NULL){
					printf ("wish not found\n\n");
				}
				else {
					do {
						printf ("Wish name [1...100] : ");
				//		getchar();
						scanf ("%[^\n]",&name);getchar();

					}while (strlen(name)<1||strlen(name)>100);
			//		getchar();
					zdelete(name);
				}

				break;
			case 4:
				popAll2();

				break;
		}

	}
	return 0;
}

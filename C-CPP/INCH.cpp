#include<stdio.h>
#include<stdlib.h>

struct data{
	int num=0;
	data*next,*prev;
}*head,*tail,*curr,*temp;

void pushTail(int angka){
	data *curr = (data *)malloc(sizeof(data));
	curr->num = angka;
	curr->next = NULL;
	curr->prev=NULL;
	if(!tail){
		head = tail =curr;
	}
	else{
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
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
		temp=head->next;
		temp->prev=NULL;
		temp->next=head->next->next;
		head->next=NULL;
		head->next->prev=NULL;
		free(head);
		
		head = temp;
	}
}


void popTail(){
	if(!tail){
		return;
	}
	else if(tail == head){
		free(tail);
		head = tail =NULL;
	}
	else{
		temp = tail->prev;
		temp->next=NULL;
		temp->prev=tail->prev->prev;
		tail->prev=NULL;
		tail->next=NULL;
		free(tail);
		tail=temp;
	}
}


void search(int angka){
	curr = head;
	while(curr){

		if(curr->num == angka){
			if (curr==head)popHead;
			else if (curr==tail)popTail;
			temp=curr->next;
			temp->next=curr->next->next;
			curr->prev->next=temp;
			free(curr);
			curr = temp;
			return;
		}
		curr = curr->next;
	}
	return;
}
void view(){
	curr = head;
	while(curr){
		printf("angka %d\n",curr->num);
		curr = curr->next;
	}
}
int main (){
	int n,m;
	scanf("%d",&n);
	int item[100001]={0},bid[100001]={0};
	
	for (int i=0;i<n;i++){
		scanf ("%d",&item[i]);
	
	}
	scanf ("%d",&m);
	for (int i=0;i<m;i++){
		scanf ("%d",&bid[i]);
		pushTail(bid[i]);
	}
//	view();
	int count[n]={0};
	for (int i=0;i<n;i++){
		curr=head;
//		printf ("IIII %d\n",i);
		while(curr){
			if (curr->num>=item[i]){
				item[i]=curr->num;
				count[i]=1;
				
				curr = curr->next;
//				printf ("%d\n",item[i]);
//				deleteangka(item[i]);
//				popHead();
//				popTail();
				
				search (item[i]);
				
			}
			else 
			curr = curr->next;
		}
	}
//	int count[n]={0};
//	for (int i =0;i<n;i++){
//		for (int j=0;j<m;j++){
//			if (bid[j]>=item[i]){
//				item[i]=bid[j];
//				count[i]=1;
//				bid[j]=0;
//			}
//			
//			
//		}
//	}
	int total=0;
	for (int i=0;i<n;i++){
		if (count[i]==1)total++;
	}
	
	printf ("%d\n",total);
	return 0;
}

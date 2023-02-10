#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct pro{
	char process[8];
};

struct data {
	char nama[100];
	struct pro proses[8];
	data *next=NULL;
	data *prev=NULL;
}*head=NULL,*tail=NULL,*curr=NULL;

void pushTail(char nama[]){
	data *curr = (data *)malloc(sizeof(data));
	strcpy(curr->nama,nama);
	curr->next = NULL;
	if(!head){
		head = tail = curr;
	}
	else{
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
	}
	for (int a=0;a<7;a++){
		int n=rand()%5+1;
		if (n==1){
			strcpy(curr->proses[a].process,"copy");
		}
		else if (n==2){
			strcpy(curr->proses[a].process,"paste");
		}
		else if (n==3){
			strcpy(curr->proses[a].process,"delete");
		}
		else if (n==4){
			strcpy(curr->proses[a].process,"crop");
		}
		else if (n==5){
			strcpy(curr->proses[a].process,"layer");
		}
		printf ("proses %s\n",curr->proses[a].process);
	}
}

void view (){
	curr=head;
	while (curr){
		printf ("%s\n",curr->nama);
		for (int i=0;i<7;i++){
			printf ("%s ",curr->proses[i].process);
		}
		printf ("\n");
		curr=curr->next;
	}
}

open (){
	char nama[100],format[4];
	getchar();
	scanf ("%[^.]",&nama);
	printf ("nama %s\n",nama);  
	do {
		scanf ("%s",&format);
		printf ("format %s\n",format);
	}while (strcmp(format,".jpg")!=0&&strcmp(format,".png")!=0&&strcmp(format,".gif")!=0);
	strcat(nama,format);
	printf ("nama %s\n",nama);
	pushTail(nama);
}

check (){
	curr=head;
	while (curr){
		if (curr==NULL){
			printf ("no data \n");
		}
		else {
			printf ("%s >> ",curr->nama);
			int countLayer=0;
			int countCrop=0;
			for (int i=0;i<7;i++){
				if (strcmp(curr->proses[i].process,"crop")==0){
					countCrop++;
				}
				else if (strcmp(curr->proses[i].process,"layer")==0){
					countLayer++;
				}
			}
			if (countLayer>=2&&countCrop>=2){
				printf ("Hoax \n");
			}
			else {
				printf ("Valid \n");
			}
		}
		curr=curr->next;
	}
}
int main (){
	srand(time(NULL));
	int input=0;
	while (input!=4){
		view();
		printf ("menu\n");
		scanf ("%d",&input);
		switch (input) {
		case 1:
			open();
			break;
		
		case 2:
			check();
			break;
			
		}
	}
	
	
	
}

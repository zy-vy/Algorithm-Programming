#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct data{
	char name[25];
	char type[15];
	int quant;
	int price;
	data *next;
}*coffee=NULL,*cart=NULL,*curr=NULL;

data *createNode (char name[],char type[],int quant,int price){
	data *node=(data*)malloc(sizeof (data));
	strcpy(node->name,name);
	strcpy(node->type,type);
	node->quant=quant;
	node->price=price;
	node->next=NULL;
	return node;
}

data* push(data *list,char name[],char type[],int quant,int price,int s){
	if (list==NULL){
		list=createNode(name,type,quant,price);
		if (coffee==NULL&&s==0){
			coffee=list;
		}
		else if (cart==NULL&&s==1){
			cart=list;
		}
		return list;
	}

		if (s==0){
			if (strcmp(list->name,name)==0){
				list->quant+=quant;
			}
			else
			list->next=push(list->next,name,type,quant,price,0);
		}	
		else {
			if (strcmp(list->name,name)==0){
				list->quant+=quant;
				list->price+=price;
			}
			else
			list->next=push(list->next,name,type,quant,price,1);
		}	
}
void pop(data**list,int a){
	curr=*list;
	int count=1;
	while (curr){
		if (a==1){
			*list=curr->next;
			free(curr);curr=NULL;
			break;
		}
		else if (count==(a-1)){
			data *temp=curr->next;
			curr->next=temp->next;
			
			free(temp);
			break;
		}
		
		curr=curr->next;
		count+=1;
	}
}

void popAll(data **list){
	data *temp;

	temp=*list;
	
	while (*list!=NULL){
		temp=(*list)->next;
		free(*list);
		*list=temp;
	}
	curr=temp=*list=NULL;
};

data *search (int num){
	curr=coffee;
	int count=1;
	while (curr){
		if (count==num){
			return curr;
		}
		curr=curr->next;
		count+=1;
	}
}
void viewMenu(data *list){
	curr=list;
	int i=1;
	printf ("No.| Menu                                              | Type       | Quantity | Price             |\n");

	printf ("----------------------------------------------------------------------------------------------------\n");
	while (curr){
		printf ("%-3d| %-50s|%11s |%9d | %10d        |\n",i,curr->name,curr->type,curr->quant,curr->price);
		curr=curr->next;
		i++;
	}
	printf ("----------------------------------------------------------------------------------------------------\n");
}
void viewAdmin(){
	printf ("====================================================================================================\n                                         +++++  Brew Coffee Shop  +++++\n\nWelcome, Mr./Mrs. Admin\n\n====================================================================================================\n");
	viewMenu(coffee);
	printf ("1. Add item\n2. Remove item\n3. Exit\n____________________________________________________________________________________________________\nEnter your action : ");
	
};
void addItem(int no){
	int flag=0,quant,price;
	char str[20],type[4];
	do{
		printf ("Insert item name: ");
		scanf ("%[^\n]",&str);getchar();
		if (strlen(str)>=5&&strlen(str)<=19)flag=1;
		else printf ("Input lenght of name between 5 and 19\n");
	}while (flag==0);
	
	do {
		printf ("Type of Coffee [yes/no] : ");
		scanf ("%s",&type);getchar();
		if (stricmp(type,"yes")==0){
			flag=0;
			strcpy(type,"Coffee");
		}
		else if (stricmp(type,"no")==0){
			flag=0;
			strcpy(type,"Non-Coffee");
		}
	}while (flag==1);
	
	do {
		printf ("Insert the quantity of the item : ");
		scanf ("%d",&quant);//getchar();
		if (quant>0&&quant<101){
			flag=1;
		}
		else {
			printf ("Please insert quantity between 1-100\n");
		}
	}while (flag==0);
	
	do {
		printf ("Insert the price of the item : ");
		scanf ("%d",&price);//getchar();
		if (price>=10000&&price<=100000)flag=0;
		else printf ("Please insert price between 10.000-100.000\n");
	}while (flag==1);
	
	push (coffee,str,type,quant,price,0);
	
};
void removeItem(int no){
	int input,flag=0;
	if (!coffee){
		printf ("no data\n");
		return;
	}
	do {
		printf ("Which item do you want to remove [1-%d] : ",no);
		scanf ("%d",&input);
		if (input>0&&input<=no){
			flag=1;
		}
		else printf ("Select data between [1-%d]\n",no);
	}while (flag==0);
	pop (&coffee,input);
};
void viewCust(char str[]){
	printf ("====================================================================================================\n                                         +++++  Brew Coffee Shop  +++++\n\nWelcome, Mr./Mrs. %s\n\n====================================================================================================\n",str);
	viewMenu(coffee);
	if(!cart)printf ("data is empty\n");
	else {
		printf ("\n\n your order:\n");
		viewMenu(cart);
	}
	printf ("1. Buy item\n2. Cancel item\n3. Exit\n____________________________________________________________________________________________________\nEnter your action : ");
	
};
void buy(int *no){
	printf ("\n\n");
	viewMenu(coffee);
	int input,quant,flag=0;
	do{
		printf ("Choose your menu [1-%d] : ",*no);
		scanf ("%d",&input);
		if (input >=1&&input<=*no)flag=1;
		else printf ("Insert valid number\n");
	}while(flag==0);
	data *temp=search(input);
	do{
		printf("Enter the quantity [1-%d] : ",temp->quant);
		scanf ("%d",&quant);
		if (quant>=1&&quant<=temp->quant)flag=0;
		else printf ("Insert quantity number between 1-%d\n",temp->quant);
	}while(flag==1);
	push(cart,temp->name,temp->type,quant,temp->price*quant,1);
	temp->quant-=quant;
	printf (" Success\n");
	if (temp->quant==0){
		pop(&coffee,input);
		*no-=1;
	}
};
void init(){
	push(coffee,"Americano","Coffee",24,19000,0);
	push(coffee,"Chocolato baked","Non-coffee",15,24000,0);
	push(coffee,"Alberto","Coffee",7,44000,0);
}
void cancel(int *no){
	data *temp=cart;
	if (!coffee){
		init();
		*no=3;
		printf ("init\n");
	}
	else
	while (temp){
		int flag=0;
		curr=coffee;
		printf("while temp %s\n",temp->name);
		for (int i=1;i<=*no;i++){
			printf ("for %s\n",curr->name);
			if (strcmp(temp->name,curr->name)==0){
				push(coffee,temp->name,temp->type,temp->quant,0,0);
				printf ("add\n");
				flag=1;
				break;
			}
			curr=curr->next;
		}
		if (flag==0){
			if (strcmp(temp->name,"Americano")==0){
					data *node = createNode ("Americano","Coffee",24,19000);
					node->next=coffee;
					coffee=node;
					*no+=1;
			}
			else if (strcmp(temp->name,"Chocolate Baked")==0){
					data *node = createNode ("Chocolato baked","Non-coffee",15,24000);
					node->next=coffee->next->next;
					coffee->next=node;
					*no+=1;
			}
			else if (strcmp(temp->name,"Alberto")==0){
					data *node = createNode ("Alberto","Coffee",7,44000);
					node->next=NULL;
					coffee->next->next=node;
					*no+=1;
			}
//			push(coffee,temp->name,temp->type,temp->quant,temp->price/temp->quant,0);
//			*no+=1;
		}
		temp=temp->next;
	}
	popAll(&cart);
	
}


int main (){
	char username[20];
	do{
		printf ("enter your name : ");
		scanf ("%[^\n]",&username);getchar();
	}while(strlen(username)<4);
	init();
	int count=3;
	if (stricmp(username,"admin")==0){
		int input;
		while (input!=3){
			viewAdmin();
			scanf ("%d",&input);getchar();
			switch (input){
				case 1:
					addItem(count);
					count++;
					break;			
				case 2:
					removeItem(count);
					count--;
					break;
			}
		}
		popAll(&coffee);
	}else{
		strcpy(username,strupr(username));
		for (int i =0;i<strlen(username);i++)
			if (username[i]>=65&&username[i]<=91)username[i]+=32;
			username[0]-=32;
		int input;
		while (input !=3){
			viewCust(username);
			scanf ("%d",&input);
			switch (input){
				case 1:
					buy(&count);
					break;
				case 2:
					cancel(&count);
					break;
			}
		}
		popAll(&cart);
		popAll(&coffee);
	}
		
	return 0;
}

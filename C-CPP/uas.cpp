#include "stdio.h"
#include "stdlib.h"
#include "string.h";

struct node {
	long long int num;
	int height;
	char name[31];
	node* left;
	node* right;
}*root=NULL,*temp=NULL;

node* createNode (char str[],long long int num){
	temp=(node*)malloc(sizeof(node));
	strcpy(temp->name,str);
	temp->num=num;
	temp->height=1;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int getHeight(node *temp){
	if (temp)return temp->height;
	return 0;
}

int max (int a,int b){
	if (a>b)return a;
	return b;
}

int setHeight(node *temp){
	return 1 + max(getHeight(temp->left),getHeight(temp->right));
}

int getBalance (node *temp){
	if (temp)
	return getHeight(temp->left)-getHeight(temp->right);
}

node *rotateRR(node *temp){
	node *rightChild = temp->right;
	node *leftGrandChild = rightChild->left;
	
	rightChild->left=temp;
	temp->right=leftGrandChild;
	
	temp->height = setHeight (temp);
	rightChild->height=setHeight(rightChild);
	
	return rightChild;
}

node *rotateLL (node *temp){
	node *leftChild = temp->left;
	node *rightGrandChild = leftChild->right;
	
	leftChild->right=temp;
	temp->left=rightGrandChild;
	
	temp->height=setHeight(temp);
	leftChild->height=setHeight(leftChild);
	
	return leftChild;
}

node *rotateRL(node *temp){
	temp->right=rotateLL(temp->right);
	return rotateRR (temp);
}

node *rotateLR(node *temp){
	temp->left=rotateRR(temp->left);
	return rotateLL(temp);
}

node *avl(node *temp){
	temp->height=setHeight(temp);
	int balance = getBalance(temp);
	if (balance <-1){
		int childBalance = getBalance (temp->right);
		if (childBalance <=0){
			return rotateRR(temp);
		}
		else {
			return rotateRL(temp);
		}
	}
	else if(balance >1){
		int childBalance =getBalance(temp->left);
		if (childBalance >=0){
			return rotateLL(temp);
		}
		else {
			return rotateLR(temp);
		}
	}
	return temp;
}

node *push (node *temp,char name[],long long int num){
	if (!temp){
		temp=createNode(name,num);
		if (!root){
			root=temp;
		}
		return temp;
	}

	if (temp->num>num){
		temp->left=push(temp->left,name,num);
	}
	else if (temp->num<num){
		temp->right=push(temp->right,name,num);
	}
	avl(temp);
}

node *pop(node *temp,int num){
	if (!root){
		return NULL;
	}
	else {
		if (!temp){
			return temp;
		}
		else if (temp->num>num){
			temp->left=pop(temp->left,num);
		}
		else if (temp->num<num){
			temp->right=pop(temp->right,num);
		}
		else {
			if (!temp->right){
				node *curr=temp->left;
				free(temp);
				return curr;
			}
			else if (!temp->left){
				node *curr=temp->right;
				free(temp);
				return curr;
			}
			else {
				node *predecessor = temp->left;
				while(predecessor->right!=NULL){
					predecessor=predecessor->right;
				}
				temp->num=predecessor->num;
				temp->left=pop(temp->left,predecessor->num);
			}
		}
		avl(temp);
	}
}

int count=0;
void printOrder(node *temp,long long int num){
	if (!temp)return;
	
	if (temp->num>num)
		count++;
	printOrder(temp->left,num);
	printOrder(temp->right,num);
	return;
}
int total=0;
void totalPlanet(node *temp){
	if(!temp)return;
	total++;
	totalPlanet(temp->left);
	totalPlanet(temp->right);
	return;
}

//node* countNum(node *temp){
//	if(!temp)return;
//	totalPlanet(temp->left);
//	totalPlanet(temp->right);
//}
node *find(node *temp,long long int num){
	if (!temp)return NULL;
//	
	if (temp->num>=num){
		
	}
	return temp;
}

node *show (node *temp,int from,int to){
	if(!temp)return NULL;
	count++;
	totalPlanet(temp->left);
	if (count>=from&&count<=to){
		printf ("%d: %lld %s\n",count,temp->num,temp->name);
	}
	totalPlanet(temp->right);
	return NULL;
}

int main (){
	int t=0;
	scanf ("%d",&t);
	int input;
	for (int i=1;i<=t;i++){
		scanf ("%d",&input);
				char str[31];
				long long int temp;
				int from,to;
				node *cur=(node*)malloc(sizeof(node));
		switch (input){
			case 1:
				scanf ("%lld\n ",&temp);
				scanf("%[^\n]",&str);getchar();
				push (root,str,temp);
				printOrder(root,temp);
				printf ("%d\n",count);
				count=0;
				
				break;
			case 2:
				scanf ("%[^\n]",&str);getchar();
				totalPlanet(root);
				printf ("%d\n",total);
				total=0;
				break;
			case 3:
				scanf ("%lld",&temp);
				cur =find(root,temp);
				printf("%lld %s\n",cur->num,cur->name);
				break;	
			case 4:
				scanf ("%d %d",&from,&to);
				show(root,from,to);
				break;
		}
	}
//	do {
//		printf ("BeeCountry universe\n====================\n1. INSERT NEW PLANET\n2. DELETE PLANET/ASTEROID\n3. FIND SIMILAR PLANET/ASTEROID\n4. SHOW PLANET/ASTEROIDS\n");
//		printf(">>\n");
//		
//		
//	}while (input<1&&input>4 )
	
}

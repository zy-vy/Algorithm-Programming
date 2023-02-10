#include <stdio.h>
#include <stdlib.h>
struct node {
	int num;
	int height;
	node* left;
	node* right;
}*root=NULL,*temp=NULL;

node* createNode (int num){
	temp=(node*)malloc(sizeof(node));
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

node *push (node *temp,int num){
	if (!temp){
		temp=createNode(num);
		if (!root){
			root=temp;
		}
		return temp;
	}
	if (temp->num==num){
		return temp;
	}
	if (temp->num>num){
		temp->left=push(temp->left,num);
	}
	else if (temp->num<num){
		temp->right=push(temp->right,num);
	}
	avl(temp);
}

node *pop(node *temp,int num){
	if (!root){
		printf ("Number is not found\n");
		return NULL;
	}
	else {
		if (!temp){
			printf ("Number is not found\n");
			return NULL;
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


node* find (node *temp,int num,int step){
	if (!temp){
		printf ("Number is not found...\n");
		return NULL;
	}
	if (temp->num==num){
		printf ("Need %d step(s) to find the number\n",step);
		return NULL;
	}
	else if (temp->num>num){
		temp->left=find(temp->left,num,step+1);
	}
	else if (temp->num<num){
		temp->right=find(temp->right,num,step+1);
	}
}

void popAll(node *temp){
	if (temp!=NULL){
		popAll(temp->left);
		popAll(temp->right);
		free(temp);
	}
	return;
};


int main (){
	int input;
	do {
		
		printf ("Menu\n=================\n1. Add NUmber\n2. Delete Number\n3. Find Number\n4. Exit\n\nMenu number [1..4]: ");
		scanf ("%d",&input);
		int num;
		switch (input){
			case 1 :
				do {
					printf ("Input number [1-100.000]: ");
					scanf ("%d",&num);
				}while (num<1||num>100000);
				root = push (root,num);
				printf ("Done to insert number %d...\n",num);
				break;
			case 2:
				do {
					printf ("Input number [1-100.000]: ");
					scanf ("%d",&num);
				}while (num<1||num>100000);
				node *temp;
				temp=pop(root,num);
//				pop(root,num);
				if (!temp){
					printf ("Done to delete number %d...\n",num);		
				}
			
				break;
			case 3:
				do {
					printf ("Input number [1-100.000]: ");
					scanf ("%d",&num);
				}while (num<1||num>100000);
				find(root,num,1);
				
				break;
		}
		printf ("\n\n");
	}while (input!=4);
	popAll (root);
	return 0;
}

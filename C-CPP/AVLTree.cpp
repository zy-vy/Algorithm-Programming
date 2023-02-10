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
		printf ("No Tree\n");
		return NULL;
	}
	else {
		if (!temp){
			printf ("Vale not found %d \n",num);
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

void print(node *temp,int height){
	if (!temp){
		return;
	}
	print(temp->right,height+1);
	for (int i =0; i<height;i++){
		printf ("	");
	}
	printf ("%d (%d)\n",temp->num,temp->height);
	
	print(temp->left,height+1);
}

int main (){
	root = push (root,59);
	root =push (root,80);
	root = push (root,47);
	root = push (root,70);
	root = push (root,22);
	root = push (root,90);
	root = push (root,16);
	root = push (root,46);
	root = push (root,55);
	root = push (root,36);
	print(root,0);
	return 0;
}

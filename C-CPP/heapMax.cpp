#include <stdio.h>

int heap[100];
int count = 0;

void swap (int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void upheapmax (int index){
	if (index <=1)return;
	int parentIdx = index/2;
	if (heap[index]>heap[parentIdx]){
		swap (&heap[index],&heap[parentIdx]);
		upheapmax(parentIdx);
	}
}

void push (int value){
	count ++;
	heap[count]=value;
	upheapmax(count);
}

void view(){
	for (int i=1;i<=count;i++){
		printf ("%2d ",heap[i]);
	}
	printf ("\n");	
}

void downheapmax(int index){
	if (index *2 > count )return;
	int left = index/2;
	int right = index*2+1;
	
	int max = index;
	if (left<=count && heap[left]>heap[max]){
		max=left;
	}
	if (right <=count && heap[right] > heap[max]){
		max= right;
	}
	swap (&heap[max],&heap[index]);
	
	downheapmax(max);
}

void pop(){
	if (count ==0)return ;
	heap[1]=heap[count];
	count--;
	downheapmax(1);
}

int main (){
	int input,key;
	do {
		printf ("Max Heap\n");
		printf ("========\n");
		printf ("1. Insert\n2. Delete\n3. Exit>> ");
		scanf ("%d",&input);
		switch (input){
			case 1:
				printf ("Enter value : ");
				scanf ("%d",&key);
				push (key);
				printf ("\nInsert success\n");
				break;
			case 2: 
				pop();
				printf ("\nDelete success\n");
				break;
		}
		printf ("\n");
		view();
		printf ("\n");
	}while (input!= 3);
	return 0;
}

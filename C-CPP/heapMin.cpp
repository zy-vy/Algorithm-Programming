#include <stdio.h>

int heap[100];
int count=0;

int getParentIdx(int index){
	return index/2;
}

int getLeftChildIdx(int index){
	return index*2;
}

int getRightChildIdx(int index){
	return index*2+1;
}

void upheapmin(int index){
	if (index<=1) return;
	int parentIdx = getParentIdx(index);
	if (heap[index]<heap[parentIdx]){
		int temp=heap[parentIdx];
		heap[parentIdx]=heap[index];
		heap[index]=temp;
		upheapmin(parentIdx);
	}
}

void push (int value){
	count++;
	heap[count]=value;
	upheapmin(count);
}

void view(){
	int i;
	for (i=1;i<=count;i++){
		printf ("%2d ",heap[i]);
	}
	printf ("\n");
}

void downheapmin(int index){
	if (index *2>count)return;
	int left = getLeftChildIdx(index);
	int right = getRightChildIdx(index);
	
	int smallest = index;
	if (left <= count && heap[left] < heap[smallest]){
		smallest=left;
	}
	if (right <= count && heap [right]< heap [smallest]){
		smallest=right;
	}
	if (smallest == index) return;
	
	int temp = heap[index];
	heap[index]=heap[smallest];
	heap[smallest]=temp;
	
	downheapmin(smallest);
}

void pop(){
	if (count==0)return;
	printf ("count %d\n",count);
	heap[1]=heap[count];
	printf ("heap 1 %d\n",heap[1]);
	count--;
	downheapmin(1);	
}

int main (){
	push (10);
	push(20);
	push(8);
	push(1);
	view();
	pop();
	view();
	return 0;
}

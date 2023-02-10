#include <stdio.h>

void swap (int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}

int partition (int arr[], int low, int high){
	int pivot, index;
	pivot = high;
	index=low;
	for (int i=low;i<high;i++){
		if (arr[i]<arr[pivot]){
			swap (&arr[i],&arr[index]);
			index++;
		}
	}
	swap (&arr[index],&arr[pivot]);
	return index;
}

void quicksort(int arr[],int low,int high){
	int pindex;
	pindex= partition(arr,low,high);
	
	if (high<low)return;
	quicksort(arr,low,pindex-1);
	quicksort(arr,pindex+1,high);
	
}


int main (){
	int arr[6]={4,2,3,5,1};
	
	quicksort(arr,0,5);
	for(int i=0;i<5;i++){
		printf ("%d ",arr[i]);
	}
	
	
	return 0;
}

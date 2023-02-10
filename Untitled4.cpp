#include <stdio.h>
#include <string.h>


int calculate (int arr[]){
	int max=arr[0],count=0;
	
//	for (int i=0;i<len(arr);i++){
//		if (arr[i]>max)max= arr[i];
//	}
	
	for (int i=0;i<len(arr);i++){
		if (arr[i]>max){
			max=arr[i];
			count=1;
		}
		else if (arr[i]==max)++count;
	}
	return count;
}

int main(){
	int arr[5]={4,4,1,3};
	
	printf ("%d\n",calculate(arr));
	return 0;
}

#include <stdio.h>

void swap(int *a,int *b){
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
	return;
	
}


int main(){
	
	int a=5,b=10;
	
	swap(&a,&b);
	
	printf("%d %d",a,b);
	return 0;
}

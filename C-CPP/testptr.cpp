#include <stdio.h>
#include <stdlib.h>


int main (){
	int num=9;
	int *ptr=&num;
	
	ptr+=1;
	*ptr = 10;
	printf ("arr  = %d\n",num);
	printf ("&arr = %d\n",&num);
	printf ("*ptr = %d\n",*ptr);
	printf ("ptr  = %d\n",ptr);
	printf ("&ptr = %d\n\n",&ptr);
	
	int arr[5]={1,2,3,4,5};
	int* p=(int*)malloc (sizeof(int));
	*p=1;
	*(p+1)=2;
	printf ("*p = %d\n",*p);
	printf ("p  = %d\n",p);
	printf ("*p+1 = %d\n",*(p+1));
	printf ("p+1 = %d\n",p+1);
	
	
	return 0;
}

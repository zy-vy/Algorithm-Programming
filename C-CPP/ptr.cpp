#include <stdio.h>

struct data{
	int num;
}*node;

void count0 (int *a){
	*a=*a+3;
}

void count (int *a){
	*a=*a+1;
	count0(a);
}

void count1 (int *a){
	count (a);
	printf ("%d  %d\n",a,&a);
}

void sum1(int *a){
	*a+=1;
}

void str(data *list){
	list->num=5;
}
int main (){
	int a=2;
	int *ptr=&a;
	printf ("%d-%d\n",ptr,*ptr);
	sum1(ptr);
	printf ("ptr %d\n",*ptr);
	count1(&a);
	printf ("%d\n",a);
	str(node);
	printf ("node %d\n",node->num);
	
	return 0;
}

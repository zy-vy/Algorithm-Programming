#include <stdio.h>

int main (){
	int n=23;
	char arr1[50][50];
	char arr2[50][50];
	for (int i=0;i<n;i++){
		scanf(" %[^\n]",&arr1[i]);
	};
	for (int i=0;i<n;i++){
		scanf(" %[^\n]",&arr2[i]);
	};
	for (int i =0;i<n;i++){
		printf ("\"%s\":\"%s\"\n",arr1[i],arr2[i]);
	};
	
	
	return 0;
}


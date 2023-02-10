#include <stdio.h>

int main(){
	int n,m;
	int arr[1001];
	long int john=0;
	long int pres=0;
	
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	int i=(n-1);
	for(int j=m;i>=0&&j>0;i--,j--){
	//	printf ("%d %d %d %ld\n",arr[i],i,j,john);
		john+=arr[i];
		arr[i]=0;
	}
	arr[i+1]=john;
	n=n+1-m;
	
//	for(int i =0;i<n;i++){
//		printf ("%d ",arr[i]);
//	}

	for(int i=0;i<n;i++){
		pres^=arr[i];
//		printf ("pres %d\n",pres);
	}
	if(pres %2==0)printf("Preston\n");
	else printf("John\n");
	
	
	return 0;
}

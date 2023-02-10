#include <stdio.h>

int main (){
	int n;
	int arr[100][100];
	scanf ("%d",&n);
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			scanf ("%d",&arr[i][j]);
		}
	}
	int row[100],col[100],tempR=0,tempC=0,countR=0,countC=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
		//	printf (" %d %d %d\n",i,j,row[i]);
			if (arr[i][j]>tempR){
				tempR=arr[i][j];
				row[i]++;
	//			printf ("row %d %d\n",arr[i][j],row[i]);
			}
			if(arr[j][i]>tempC){
				tempC=arr[j][i];
				col[i]++;
			}
		}
		tempR=0;tempC=0;
//		printf("i++\n");
	}

		
	for (int i=0;i<n;i++){
		printf ("%d",col[i]);
		if(i!=n-1)printf(" ");
	}
	printf("\n");
	for(int i=0;i<n;i++){
		printf("%d\n",row[i]);
	}
	
	return 0;
}

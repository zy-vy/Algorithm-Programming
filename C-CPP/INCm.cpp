#include <stdio.h>

int main (){
	int n;
	scanf("%d",&n);
	
	int arr[100001],mark[100001]={0},cp;
	for(int i=0;i<n;i++){
		scanf("%d",&cp);
		if(i==0){
			if(cp==1){
				mark[i]=1;
			}
			else if (cp==2){
				mark[i]=1;
				mark[i+1]=1;
			}
			else if (cp>2){
				mark[i]=1;
				mark[i+1]=1;
			}
			
		}
		else if (i==(n-1)){
			if(cp==1){
				if (mark[i-1]==0)mark [i-1]=1;
				else mark[i]=1;
			}
			else if (cp==2){
				if (mark[i-1]==0)mark [i-1]=1;
				mark[i]=1;
			}
			else if (cp>2){
				if (mark[i-1]==0)mark [i-1]=1;
				mark[i]=1;
			}
			
		}
		else{
			if(cp==1){
				if (mark[i-1]==0)mark[i-1]=1;
				else if (mark [i]==0) mark [i]=1;
				else mark[i+1]=1;
			}
			else if (cp==2){
				if (mark[i-1]==0)mark[i-1]=1;
				else if (mark [i]==0) mark [i]=1;
				else mark[i+1]=1;
				if (mark[i-1]==0)mark[i-1]=1;
				else if (mark [i]==0) mark [i]=1;
				else mark[i+1]=1;
			}
			else if (cp>2){
				if (mark[i-1]==0)mark[i-1]=1;
				else if (mark [i]==0) mark [i]=1;
				else mark[i+1]=1;
				if (mark[i-1]==0)mark[i-1]=1;
				else if (mark [i]==0) mark [i]=1;
				else mark[i+1]=1;
				if (mark[i-1]==0)mark[i-1]=1;
				else if (mark [i]==0) mark [i]=1;
				else mark[i+1]=1;
			}
		}
	}
	int count=0;
	for (int i =0;i<n;i++){
		if (mark[i]==1)count++;
	}
	printf ("%d\n",count);
	
	
	
	
	
	
	return 0;
}

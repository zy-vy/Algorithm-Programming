#include <stdio.h>
#include <string.h>
#include <math.h>

int FindValue(int crew_value,int b, int*job_id){
	
	for (int i=0;i<b;i++){
		if (crew_value==job_id[i]){
			return i;
		}
	}
	return -1;
}

int recursRight(int crew_value, int b,int* job_id,int max){
	if(crew_value>max){
		return -1;
	}
	
	int index=FindValue(crew_value,b,job_id);
	if(index!=-1){
		return index;
	};
	
	
	return recursRight(crew_value+1,b,job_id,max);
}

int recursLeft(int crew_value, int b,int* job_id){
	if(crew_value<0){
		return -1;
	}
	
	int index=FindValue(crew_value,b,job_id);
	if(index!=-1){
		return index;
	};
	
	
	return recursLeft(crew_value-1,b,job_id);
}

int NearestValue(int crew_value, int b, int *job_id,int max){
	int isCorrectValue=0;
	int index=FindValue(crew_value,b,job_id);
	if(index!=-1){
		job_id[index]=-1;
		printf ("same number return0\n");
		return 0;
	};
	
	int indexLeft=recursLeft(crew_value-1,b,job_id);
	printf ("resursRight\n");
	int indexRight=recursRight(crew_value+1,b,job_id,max);
	printf ("value left right = %d %d %d\n",crew_value,job_id[indexLeft],job_id[indexRight]);
	if (indexLeft<0){
		int temp=abs(job_id[indexRight]-crew_value);
		job_id[indexRight]=-1;
		printf("index left = -1 \n");
		return temp;
	}
	if (indexRight<0){
		int temp=abs(job_id[indexLeft]-crew_value);
		job_id[indexLeft]=-1;
		printf ("index right = -1\n");
		return temp ;
	}
	
	if (abs(job_id[indexLeft]-crew_value)<abs(job_id[indexRight]-crew_value)){
		int temp =abs(job_id[indexLeft]-crew_value);
		job_id[indexLeft]=-1;
		printf ("left is smaller \n");
		return temp ;
	}
	else {
		int temp =abs(job_id[indexRight]-crew_value);
		job_id[indexRight]=-1;
		printf ("right is smaller \n");
		return temp ;
	}
	
	return -1;
}

int GetMinStep(int a,int* crew_id,int b ,int* job_id){
	int num=0;
	int max=0;
	for (int i=0;i<b;i++){
		if (job_id[i]>max)max=job_id[i];
	}
	for (int i =0;i<a;i++){
		int min=0;
		min=NearestValue(crew_id[i],b, job_id,max);
		
		num+=min;
		printf ("num %d\n",min);
	}
	
	return num;
}

int main (){
	int a=5,b=5;
	int crew_id[6]={2,3,5,4,1};
	int job_id[6]={1,1,6,3,2};
//	int crew_id[6]={2};
//	int job_id[6]={1};
	int min=0;
	min = GetMinStep(a,crew_id,b,job_id);
	printf("final min: %d\n",min);
	
	
	return 0;
}

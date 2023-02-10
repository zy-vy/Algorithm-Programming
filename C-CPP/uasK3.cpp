#include <stdio.h>
#include <math.h>

void swap(int *a,int *b){
int temp=*b;
*b=*a;
*a=temp;
return;
}

void quicksort(int arr[],int min,int max){
if (min<max){
    int pvt=max,idx=min;
    for (int i=min;i<max;i++){
        if (arr[i]<arr[pvt]){
            swap(&arr[i],&arr[idx]);
            idx++;
        }
    }
    swap(&arr[pvt],&arr[idx]);
    quicksort(arr,min,idx-1);
    quicksort(arr,idx+1,max);
}
return;
}


int main (){
FILE *fp=fopen("testdata.in","r");

int w;
    fscanf (fp,"%d",&w);
    for (int t=1;t<=w;t++){
        int arr[10001]={0},n,m;
        fscanf (fp,"%d %d",&n,&m);
  //      memset (arr,0,sizeof (arr));
        for (int i=0;i<n*m;i++){
 //           for (int j=0;j<m;j++){
                fscanf (fp,"%d",&arr[i]);
  //          }
        }
        quicksort(arr,0,n*m-1);
        double median;
        double mid;
        if ((n*m)%2==1){
            mid=(n*m)/2+1;
            median=arr[(n*m)/2];
        }
        else {
            median=(arr[n*m/2]+arr[(n*m/2)-1]);
            median/=2;
        }
        printf ("Case #%d: %.0lf\n",t,median);
    }
return 0;
}

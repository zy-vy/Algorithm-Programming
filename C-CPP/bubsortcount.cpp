#include <stdio.h>

int sort (int arr[],int n){
             int time=0;
    int i,j,temp;
    for (i=0;i<n-1;i++){
        for (j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                time++;
            }
        }
    }

    return time;
}

int main (){
    int w;
    scanf ("%d",&w);
    for (int t=1;t<=w;t++){
        int arr[1000],n,k;
        scanf ("%d%d",&n,&k);
        for (int i=0;i<n;i++)
            scanf ("%d",&arr[i]);

        int count=sort (arr,n);
        int total=count*k;
        printf ("Case #%d: %d\n",t,total);

    }
}

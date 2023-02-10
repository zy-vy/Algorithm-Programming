#include <stdio.h>

void prin (int arr[],int n){
    for (int i=0;i<n;i++){printf ("%d ",arr[i]);}printf ("\n");
}
void sort (int arr[],int n){
    int i,j,temp;
    for (i=1;i<n;i++){
        temp=arr[i];
        for (j=i-1;j>=0&&arr[j]>temp;j--){
            arr[j+1]=arr[j];
            prin (arr,n);
        }
        printf("%d\n",j+1);
        arr[j+1]=temp;
        prin (arr,n);
    }
return ;
}

int main (){
    int arr[100];
    int n;
    printf ("enter number of element\n");
    scanf ("%d",&n);
    printf ("enter element\n");
    for (int i=0;i<n;i++){
        scanf ("%d",&arr[i]);
    }
    sort (arr,n);
    for (int i=0;i<n;i++){
        printf ("%d ",arr[i]);
    }
return 0;
}

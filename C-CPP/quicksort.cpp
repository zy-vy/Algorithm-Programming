#include <stdio.h>
#include <cstdlib>

void print (int arr[],int n){
    for (int i=0;i<n;i++){
        printf ("%d ",arr[i]);
    }printf ("\n");
    return ;
}

void swap (int *a,int *b){
    int temp;
    temp =*a;
    *a=*b;
    *b=temp;
return ;
}

int partition(int arr[],int low,int high){
    int pivot,index;
    index =low;
    pivot =high;
    for (int i=low;i<high;i++){
        if (arr[i]<arr[pivot]){
            swap (&arr[i],&arr[index]);
            index++;
        }
    }
    swap (&arr[pivot],&arr[index]);
return index;
}

int randpivotpart(int arr[],int low,int high){
    int pivot,n,temp;
    n=rand();
    pivot = low + n%(high-low+1);
    swap (&arr[high],&arr[pivot]);
return partition(arr,low,high);
}

void quicksort (int arr[],int low,int high){
    int pindex;
    if (low<high){
        pindex = randpivotpart (arr,low,high);
        quicksort (arr,low,pindex-1);
        quicksort (arr,pindex+1,high);
    }
return;
}

int main (){
    int arr[1000],temp=0;
    int n=0;
    printf("Enter number to sort, end with -1\n");
    while (temp != -1){
        scanf ("%d",&temp);
        if (temp!=-1){
            arr[n]=temp;
            n++;
        }
    }
    quicksort (arr,0,n-1);

    for (int i=0;i<n;i++){
        printf ("%d ",arr[i]);
    }

    return 0;
}

#include <stdio.h>
void swap (int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
return;
}

int part(int arr[],int low,int high){
    int index=low,pivot=high;
    for (int i=low;i<high;i++){
        if (arr[i]>arr[pivot]){
            swap (&arr[index],&arr[i]);
            index++;
        }
    }
    swap (&arr[index],&arr[pivot]);
    return index;
}

void quicksort (int arr[],int low,int high){
    int index=low,pivot=high;
    for (int i=low;i<high;i++){
        if (arr[i]>arr[pivot]){
            swap (&arr[i],&arr[index]);
            index++;
        }
    }
    swap (&arr[index],&arr[pivot]);

    int pindex;
    if (low<high){
        pindex=index;
        //pindex=part(arr,low,high);
        quicksort (arr,low,pindex-1);
        quicksort (arr,pindex+1,high);
    }
return;
}

int main (){
    int arr[5]={5,4,3,3,1};
    quicksort(arr,0,5);
    for (int i=0;i<5;i++)
        printf ("%d ",arr[i]);

return 0;
}

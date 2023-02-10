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
    pivot =low + n%(high-low+1);

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
    int w;
    scanf ("%d",&w);
    for (int t=1;t<=w;t++){
        int n,arr[1000],arr1[1000],arr2[1000];
        scanf ("%d",&n);
        int mid =n/2;
        for (int i=0;i<n;i++)
            scanf ("%d",&arr[i]);

        quicksort(arr,0,n-1);
        //print(arr,n);

        int i=0;
        for (int j=0;i<mid;i++,j++){
            arr1[j]=arr[i];
           // printf ("i%d",i);
        }
     //   printf ("i%d\n",i);
        for (int j=0;i<n;i++,j++){
         //   printf ("i i%d\n",i);
            arr2[j]=arr[i];
        }
    //    printf ("i%d\n",i);
        for (int i=0;i<mid;i++){
     //       printf ("%d ",arr1[i]);
        }
        for (int i=0;i<mid;i++){
            printf ("%d ",arr2[i]);
        }
        int count =0;
        for (int i=0;i<mid-1;i++){
            if (arr1[i+1]-arr1[i]>count){
                count=arr1[i+1]-arr1[i];
                printf ("1 %d\n",count);
            }
        }
        for (int i=0;i<mid-1;i++){
            if (arr2[i+1]-arr2[i]>count){
                count=arr2[i+1]-arr2[i];
                printf ("2 %d\n",count);
            }
        }
        printf ("Case #%d :%d\n",t,count);
    }



}

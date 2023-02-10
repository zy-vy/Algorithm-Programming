\#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int bsearch (int arr[],int min,int max,int target){
    if (min<=max){
        int mid = (min+max)/2;
        if (arr[mid]==target){
            return mid;
        }
        if (arr[mid]>target){
            return bsearch (arr,min,mid-1,target);
        }
        else {
            return bsearch (arr,mid+1,max,target);
        }
    }
    return -1;
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
int remov(int arr[],int n){
    if (n==0||n==1){
        return n;
    }
    int j=0;
    for (int i=0;i<n-1;i++)
    if (arr[i]!=arr[i+1])
        arr[j++]=arr[i];
    arr[j++]=arr[n-1];
    return j;
}

int main (){
    int w;
    scanf ("%d",&w);
    for (int t=1;t<=w;t++){
        int arr[10001]={0},n,m;
        scanf ("%d %d",&n,&m);
  //      memset (arr,0,sizeof (arr));
        for (int i=0;i<n*m;i++){
 //           for (int j=0;j<m;j++){
                scanf ("%d",&arr[i]);
  //          }
        }

        quicksort(arr,0,(n*m)-1);
        for (int i=0;i<n*m;i++){
   //         for (int j=0;j<m;j++){
                printf ("%d ",arr[i]);
   //         }
        }
        printf ("\n");
        int arr2[256]={0};

        for (int i=0;i<n*m;i++){
            arr2[arr[i]]++;
            printf ("%d %d | ",arr[i],arr2[arr[i]]);
        }
        printf ("\n");
        int a=0,arr3[256]={0};
        for (int i=0;i<256;i++){
            if (arr2[i]!=0){
                arr3[a]=arr2[i];
                a++;
            }
        }

        int b=remov(arr,n*m);
        for (int i=0;i<a;i++){
            printf ("%d ",arr3[i]);
        }
        printf ("\n");
        for (int i=0;i<b;i++){
            printf ("%d ",arr[i]);
        }printf ("\n");
        int T,Tmax=0;
        double meanA=0,meanB=0,weightA=0,weightB=0,bcv=0,bcvMax=0;;int arrA[256]={0},arrA2[256]={0},arrB[256]={0},arrB2[256]={0};
        printf ("%lf %lf %lf %lf\n",weightA,weightB,meanA,meanB);
        for (T=0;T<b;T++){
            for (int i=0;i<T;i++){
                weightA+=arr3[i];
                printf ("arr3 %d ",arr3[i]);
                meanA+=(arr[i]*arr3[i]);
                printf ("arr  %d ",arr[i]);

            }
            for (int i=T;i<a;i++){
                weightB+=arr3[i];
                printf ("arr3 inv %d arr  inv %d ",arr3[i],arr[i]);
                meanB+=(arr[i]*arr3[i]);
                printf ("%lf %lf %lf %lf\n",weightA,weightB,meanA,meanB);
            }
            if (weightA!=0)meanA/=weightA;
            if (weightB!=0)meanB/=weightB;
            weightA/=n*m;
            weightB/=n*m;
            printf (">>>%lf %lf %lf %lf\n",weightA,weightB,meanA,meanB);
            bcv=weightA*weightB*pow(meanA-meanB,2);
            printf ("bcv %lf T %d\n",bcv,T);
            if (bcv>bcvMax){
                bcvMax=bcv;
                Tmax=T;
            }
            meanA=0;meanB=0;weightA=0;weightB=0;
        }
        printf ("T %d\n",Tmax);

        /*for (int i=0;i<a;i++){
            T=i;
            for (int j=0;j<;j++){
                arrA[j]=arr[j];
                arrA2[arrA[j]]=arr2[arrA[j]];
                printf ("%d %d ",arrA[j],arr[arrA[j]]);
            }
        }*/

    }


return 0;}

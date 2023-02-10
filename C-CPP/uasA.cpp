#include <stdio.h>

void swap (int *a,int *b){
    int temp =*a;
    *a=*b;
    *b=temp;
return ;}

void quicksort (int arr[],int min, int max){
    if (min<max){
        int pvt=max,index=min;
        for (int i=min;i<max;i++){
            if (arr[i]<arr[pvt]){
                swap (&arr[i],&arr[index]);
                index++;
            }
        }
        swap (&arr[index],&arr[pvt]);
        quicksort (arr,index+1,max);
        quicksort (arr,min,index-1);
    }
    return;
}

void move (int arr[],int min,int max,int k,int m,int *count){

    if (k>0){
        for (int i=max;i>min;i--){
            if (arr[i]>arr[min]){
                *count+=1;
                printf ("k%d %d\n",k,*count);
                k--;
                min++;
                move(arr,min,max,k,m,count);
                break;
            }
            else {
                *count =0;
                return ;
            }
        }
    }
    else if (m>0){
        for (int i=min;i<max;i++){
            if (arr[i]<arr[max]){
                *count+=1;
                printf("m%d %d\n",m,*count);
                max--;
                m--;
                move (arr,min,max,k,m,count);
                break;
            }
            else {
                *count=0;
                return ;
            }
        }
    }

    return;

}

int main (){
    int w;
    scanf ("%d",&w);
    for (int t=1;t<=w;t++){
        int n,k,m,arr[10001];
        scanf ("%d%d%d",&n,&k,&m);
        for (int i=0;i<n;i++){
            scanf ("%d",&arr[i]);
        }
        quicksort (arr,0,n-1);
        for (int i =0;i<n;i++){
            printf ("%d ",arr[i]);
        }
        printf ("\n");
        int total=0;

        move(arr,0,n-1,k,m,&total);
        if (total ==0)total = -2;

        printf ("Case #%d: %d\n",t,total+1);

}

return 0;}

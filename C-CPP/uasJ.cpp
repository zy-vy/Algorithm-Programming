#include <stdio.h>

int countquery=0;
int arrquery[10001]={0};
void swap (int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
return;
}

void quicksort(int arr[],int min,int max){
    if(min<max){
        int pvt=max,index=min;
        for (int i=min;i<max;i++){
            if (arr[i]<arr[pvt]){
                swap(&arr[index],&arr[i]);
                index++;
            }
        }
        swap (&arr[index],&arr[pvt]);
        quicksort(arr,min,index-1);
        quicksort(arr,index+1,max);
    }
    return;
}
int bsearch(int arr[],int min,int max,int target){
    if (min<max){
        int mid=(min+max)/2;
        if (arr[mid]==target){
            return mid;
        }
        else if (arr[mid]>target){
            return bsearch(arr,min,mid-1,target);
        }
        else return bsearch(arr,mid+1,max,target);
    }
    return -1;
}
void print(int arr[],int n){
for (int i=0;i<n;i++)
    printf ("%d ",arr[i]);
    printf ("\n");
    return;
}

void insert (int arr[],int *n,int num){
 //   printf ("%d\n",*n);
    arr[*n]=num;
    *n+=1;
    return;
}

void alter(int arr[],int n,int num){
    int changed;
    scanf ("%d",&changed);
  //  printf ("%d %d %d\n",n,num,changed);
    quicksort(arr,0,n-1);
    for (int i=0;i<n;i++){
        if (arr[i]==num){
            arr[i]=changed;
        }
    }
    quicksort(arr,0,n-1);
  //  print (arr,n);
    return;
}
void del(int arr[],int *n,int num){
    for (int i=*n-1;i>=0;i--){
        if (arr[i]==num){
 //           printf("%d %d\n",i,arr[i]);
            for (int j=i;j<*n;j++){
                arr[j]=arr[j+1];
  //              printf ("%d\n",arr[j]);
            }
            arr[*n]=0;
            *n-=1;
        }
    }
 //   print(arr,*n);
    return;
}
void query(int arr[],int n,int num){
    quicksort (arr,0,n-1);
//    print (arr,n);
    int i=0,count=0;
    while (arr[i]<=num){

        count ++;
        i++;
 //       printf ("%d %d\n",i,num);
    }
    arrquery[countquery]=count;

//    printf ("%d\n",arrquery[countquery]);
    countquery+=1;
    return;
}
int main (){
    int n,k;
    scanf ("%d %d",&n,&k);
//    printf ("%d",k);
    int arr[10001]={0};
    for (int i=0;i<n;i++){
        scanf ("%d",&arr[i]);
    }
//    quicksort(arr,0,n-1);
//    print(arr,n);
//    k*=3;

    while (k>0){
        char c;
        int num;
        scanf ("%c %d",&c,&num);
        if (c=='I'){
            insert(arr,&n,num);
            k--;
        }
        else if (c=='A'){
      //      scanf ("%d",&changed);
            alter(arr,n,num);
            k--;
        }
        else if (c=='D'){
            del(arr,&n,num);
            k--;
        }
        else if (c=='Q'){
  //          printf ("Q %d\n",num);
            query(arr,n,num);
            k--;
        }

  //      printf ("k %d\n",k);

    }
    for (int i=0;i<countquery;i++){
        printf ("%d\n",arrquery[i]);
    }

return 0;
}

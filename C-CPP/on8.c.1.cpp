#include <stdio.h>

void prin (unsigned long long int arr[]){
    for (int i =0;i<25;i++){
        printf ("%llu ",arr[i]);
    }printf ("\n");
    return;
}

void sort (unsigned long long int arr[],int n){
    int i,j;
    unsigned long long int temp;
    for (i=1;i<n;i++){
        temp=arr[i];
  //      printf ("temp %llu\n",temp);
        for (j=i-1;j>=0&&arr[j]>temp;j--){
 //           printf ("j %d arrj+1 %llu arrj %llu\n",j,arr[j+1],arr[j]);

            arr[j+1]=arr[j];
          //  printf ("temp %llu | ",temp);prin(arr);
 //           printf ("%llu\n",arr[j+1]);
        }
   //     printf ("j=%d\n",j);
        arr[j+1]=temp;
  //      printf ("temp %llu | ",temp);prin(arr);
  //      printf ("T %llu\n\n",arr[j]);

    }
    return;
}

int main (){
    int t;
    scanf ("%d",&t);
    for (int w=1;w<=t;w++){
        unsigned long long int arr[26],num[6];

        for (int i=0;i<25;i++){
            scanf ("%llu",&arr[i]);
        }

        sort (arr,25);
  //      prin (arr);
        printf ("Case #%d: ",w);
        for (int i=0;i<5;i++){
            if (i==0){
                printf ("%llu ",arr[0]/2);
            }
            else if (i==1){
                printf ("%llu ",arr[1]-(arr[0]/2));
            }
            else if (i==2){
                printf ("%llu ",arr[12]/2);//arr[4]-(arr[0]/2));
            }
            else if (i==3){
                printf ("%llu ",arr[23]-(arr[24]/2));
            }
            else if (i==4){
                printf ("%llu",arr[24]/2);
            }

        }
        printf ("\n");


    }

return 0;
}

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
        unsigned long long int arr[26],num[6]={0},total=0,temp=0;

        for (int i=0;i<25;i++){
            scanf ("%llu",&arr[i]);
            total +=arr[i];
        }
        printf ("%llu\n",total);
        sort (arr,25);
  //      prin (arr);
        num[0]=arr[0]/2;
        num[1]=arr[1]-(arr[0]/2);
        num[3]=arr[23]-(arr[24]/2);
        num[4]=arr[24]/2;
        for (int i=0;i<5;i++){
            for (int j=0;j<5;j++){
                temp+=(num[i]+num[j]);
  //              printf ("%llu ",temp);
            }
        }
   //     printf ("\n");
        printf ("%llu\n",temp);
   //     num[2]=(total-(temp+num[0]+num[1]+num[3]+num[4]))/6;
        num[2]=(total-(temp))/10;
        printf ("Case #%d: ",w);
        printf ("%llu %llu %llu %llu %llu\n",num[0],num[1],num[2],num[3],num[4]);
    /*    for (int i=0;i<5;i++){
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
        */


    }

return 0;
}

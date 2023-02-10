
#include <stdio.h>

int main (){
    int n,d,arr[1001]={0};
    scanf ("%d%d",&n,&d);
    for (int i=0;i<n;i++)
        scanf ("%d",&arr[i]);
    int count=0,temp=0;
   /* for (int i=0;i<n;i++){
        int temp[3]={0};
        temp[0]=arr[i];
        printf("temp i %d\n",temp[0]);
        for (int j=1;j<3;j++){

            for (int k=i+1;k<n;k++){
                if ((arr[k]-temp[j-1])==d){
                    temp[j]=arr[k];
                    printf ("%d %d\n",j,temp[j]);
                    //break;
                }
            }
        }
        if (temp[2]!=0){
            count ++;
            printf("count %d\n",count);
        }
    }*/

  //  for (int i=0;i<n;i++){
        temp=1;
        for (int j=1;j<n;j++){
            if (arr[j]-arr[j-1]==d){
                temp ++;

      //          printf("temp %d\n",temp);
            }
            else {
                if(temp != 1){
                    count +=temp;
    //                printf ("count %d\n",count);
                }

                temp=1;
       //         printf ("T\n");
            }
            if(j==n-1&&temp != 1){
                    count +=temp;
     //               printf ("count %d\n",count);
                }
        }


    printf ("%d",count);


return 0;}

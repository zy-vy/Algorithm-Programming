#include<stdio.h>
#include <string.h>

int main (){
    int n;
    scanf ("%d",&n);

   char c[n][10000];

    char arr[1000]={0};
    for (int i=0;i<n;i++){
        scanf ("%s",&c[i]);
        char arr[1000]={0};
        for (int j=0;j<strlen(c[i]);j++){
            arr[c[i][j]]+=1;
        }
        int count =0;
        for (int k=97;k<=122;k++)
        {

            if(arr[k]!=0)count++;
        }
         for (int l=97;l<=122;l++)
        {
            arr[l]=0;
        }
        if (count%2==0)printf ("Yay\n");
        else printf ("Ewwww\n");
    }


return 0;}

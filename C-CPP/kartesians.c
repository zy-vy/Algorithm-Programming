#include <stdio.h>

int main (){
   // int x,y=10
    int x,y;
    printf ("enter x,y\n");
    scanf ("%d%d",&x,&y);
    int arr[y][x];
    int count =1;

    for (int i =0;i<y;i++){

        for (int j=0;j<x;j++){
            arr[i][j]=count;
            ++count;
        }
    }
    char temp[10][10];
    printf ("in array\n");

    for (int i=0;i<y;i++){
        for (int j=0;j<x;j++){
            printf ("%d ",arr[i][j]);

        }printf ("\n");
    }printf ("\n");
    count =1;
    printf ("in castersian\n");
    for (int i =0;i<x;i++){
        for (int j=0;j<y;j++){
            printf ("%d ",arr[j][x-i-1]);
        }printf ("\n");
    }printf ("\n");
    //printf ("%d %d",x,y);
return 0;
}

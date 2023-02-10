#include <stdio.h>

int main (){
    int x,y;
    scanf ("%d %d",&x,&y);
    int c[x][y];
    for (int i=0;i<x;i++)
    {
        for (int j=0;j<y;j++)
        {
            scanf ("%d",&c[i][j]);

        }
    }

    int n,d;
     scanf ("%d",&n);
    int a,b;
    for (int i=0;i<n;i++){
        scanf ("%d %d %d",&a,&b,&d);
        c[a-1][b-1]=d;
    }
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            if(j!=0)printf (" ");
            printf ("%d",c[i][j]);
        }
        printf("\n");
    }

return 0;}

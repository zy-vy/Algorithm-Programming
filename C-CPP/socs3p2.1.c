#include<stdio.h>
#include<string.h>

int main (){
    int n;
    scanf ("%d",&n);

    char c[n][n];
    n=n+1;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf ("%c",&c[i][j]);
            if(i==(n-1))break;
        }
    }
    printf ("%d\n",n);

    n=n-2;
    printf ("%d\n",n);
    int x=n;
    for (int k=n;k>=0;k--)
       for (int l=(x+1);l>=1;l--)
       printf("%c",c[k][l]);


return 0;}

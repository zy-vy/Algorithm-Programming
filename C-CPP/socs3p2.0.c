#include<stdio.h>
#include<string.h>

int main (){


 int n;
    scanf ("%d",&n);
    char c[n][n];
    fflush(stdin);


    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
             scanf ("%c",&c[i][j]);

        }fflush (stdin);
        }


n=n-1;
    for (int i=n;i>=0;i--){
        for (int j=n;j>=0;j--){
                if(c[i][j]=='*'||c[i][j]=='#'||c[i][j]=='%')
                printf("%c",c[i][j]);

        }
        printf("\n");
;    }



return 0;}

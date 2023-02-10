#include <stdio.h>
#include <string.h>

int main (){
    int n;
    scanf ("%d",&n);
    char c[n][n];
    getchar();

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){

            scanf ("%c",&c[i][j]);
            printf ("%c",c[i][j]);
        }

    }

    for (int k=0;k<n;k++){
        for (int l=0;l<n;l++){
        printf ("%c",c[k][l]);
        }


}
return 0;}

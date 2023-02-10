#include <stdio.h>

int main (){
    int n;
    scanf ("%d",&n);
    char arr[n][n],kart[n][n];
    for (int i=0;i<n;i++){
        scanf ("%s",&arr[i]);
    }

    printf ("\n");

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            kart[i][j]=arr[j][n-i-1];
            printf ("%c",kart[i][j]);
        }printf ("\n");
    }

    for (int i=n;i>=0;i--){
        for (int j=0;j<n;j++){
            if (arr[i][j]=='.'){
                printf ("%d %d",j+1,i+1);
            }
        }
    }

    return 0;
}

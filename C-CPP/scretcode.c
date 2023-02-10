#include<stdio.h>
#include<string.h>
int main (){
    int n;
    scanf ("%d",&n);
    getchar();

    char arr[n][10000];
    char c[n][10000];
    for (int i=0;i<n;i++){
        scanf("%s",&arr[i]);
        for(int j=0;j<strlen(arr[i]);j++){
            c[i][j]=(arr[i][j]%2);
            printf("%d",c[i][j]);
        }
        printf("\n");
    }

    for (int i=0;i<n;i++){
        for (int j =0;j<strlen(arr[i]);j++){
            printf ("%d",c[i][strlen(arr[i])-j-1]);
        }
        printf("\n");
    }


return 0;}

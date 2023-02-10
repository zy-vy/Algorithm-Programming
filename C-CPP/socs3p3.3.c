#include<stdio.h>

int main (){
    int n;
    scanf("%d",&n);

    int c[n][n];

    for (int i=0;i<n;i++){

                scanf ("%s",&c[i]);
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=j+1;k<n;k++){
                if (c[i][j]==c[i][k]||c[k][i]==c[j][i]){
                    printf ("Nay\n");return 0 ;}

            }
        }

    }
printf ("Yay\n");
return 0;
}

#include <stdio.h>

void print (int n){
    int c,row,t = 1;
    for (row = 1; row <= n; row++) {
        for (c = 1; c <= n - row; c++)
        printf("  ");

        t = 1;

        for (c = 1; c <= row; c++) {
            printf("%d ", t);
            t++;
        }

        t = t - 2;

        for (c = 1 ; c < row; c++) {
            printf("%d ", t);
            t--;
        }

        printf("\n");
  }
  for (row = n-1 ; row >= 1 ; row--){
        for (c = 1 ; c <= n-row ; c++){
            printf ("  ");
        }

        t = 1;

        for (c = 1 ; c <= row ; c++){
            printf ("%d ",t);
            t++;
        }

        t = t - 2;

        for (c = 1 ; c < row ; c++){
            printf ("%d ",t);
            t--;
        }
        printf ("\n");

    }
    return ;
}

int main (){
    int row,c,n;
    scanf ("%d",&n);
    print (n);
    return 0;
}

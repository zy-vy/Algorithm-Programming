#include <stdio.h>

int main (){
    int t;
    scanf ("%d",&t);
    getchar();
    for (int i=1;i<t;t++){
        int n;
        scanf ("%d",&n);
        getchar();

        int jojo[n][n];
        for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    scanf("%d",&jojo[i][j]);
                }
            }
        int lily[n][n];
        for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    scanf ("%d",&lily[i][j]);
                }
            }
        int bibi[n][n];
        for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    scanf("%d",&bibi[i][j]);
                }
            }
        int libi[51][51]={0};
        for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    for (int k=0;k<n;++k){
                        libi[i][j]+=(lily[i][k]*bibi[k][j]);
                    }
                 //   printf ("%d",libi[i][j]);
                }
            }
        int jolibi[51][51]={0};
        for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    for (int k=0;k<n;++k){
                        jolibi[i][j]+=(libi[i][k]*jojo[k][j]);
                    }
                 //   printf ("%d",jolibi[i][j]);
                }
            }
        printf ("Case #%d:\n",t);
        for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){

                    printf ("%d ",jolibi[i][j]);
                }
                printf ("\n");
            }

    }
    return 0;
}

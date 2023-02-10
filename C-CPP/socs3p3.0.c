#include <stdio.h>
#include <string.h>
int main (){
    int n;
    scanf ("%d",&n);
    getchar();

    char c[101][101];

    for (int i=0;i<n;i++){

            scanf ("%s", &c[i]);

    }
    int count=0;
    for (int k=0;k<n;k++){
        for (int l=0;l<n;l++){
            for (int m=l+1;m<n;m++){
                if(c[k][l]==c[k][m])
                    count ++;
                    printf ("%d",count);
            }

        }
        printf ("\n");
    }
    printf ("\n c ij\n");

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf ("%c",c[i][j]);
        }printf ("\n");
    }


char temp[n][n];
    for (int a=0;a<n;a++){
        for (int b=0;b<n;b++){
            temp[a][b]=c[a][b];


        }

    }
printf ("temp\n");
    for (int a=0;a<n;a++){
        for (int b=0;b<n;b++){
            printf ("%c",temp[a][b]);
        }printf ("\n");
    }
    printf ("\n");

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            c[i][j]=temp[j][i];
        }
    }
    printf ("c ji\n");
 for (int a=0;a<n;a++){
        for (int b=0;b<n;b++){
                printf("%c",c[a][b]);
        }printf ("\n");}

printf("\ncount \n");
    for (int a=0;a<n;a++){
        for (int b=0;b<n;b++){
            for (int d=b+1;d<n;d++){
                if (c[a][b]==c[a][d]){
                    count ++;}
                printf ("%d",count);
            }
        }
        printf ("\n");
    }

    if (count==0)printf("Yay\n");
    else printf ("Nay\n");





return 0;}

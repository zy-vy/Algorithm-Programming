#include <stdio.h>
#include <string.h>

int main (){
    int n;
    scanf ("%d",&n);
    getchar();

    int flip=0;
    int fs=0,ls=0;
    char c[n][1000];
    for (int i=0;i<n;i++){
        scanf ("%[^\n]",&c[i]);
        printf ("Case %d: ",i+1);
        for (int j=0;j<strlen(c[i]);j++){


            if (c[i][j]==' '&&flip==0){
                ls=j-1;
                 for (fs;fs<=ls;fs++){
                    printf ("%c",c[i][fs]);
                }
                fs=j-1;
                flip=1;

                }




            else if (c[i][j]==' '&&flip==1){
                ls=j-1;
                flip=0;
                for (ls;fs<=ls;ls--){
                    printf ("%c",c[i][ls]);
                }
            }
            if (c[i][j]==' '&&j!=strlen(c[i])-1){
                printf(" ");
            }
        }
        printf(" ");


    }


return 0;}

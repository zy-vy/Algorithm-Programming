#include<stdio.h>
#include <string.h>
int main (){
    int n;

    scanf("%d",&n);
    getchar();
    int leng;

    char s[n][10000];
    for (int i=0;i<n;i++){
         scanf ("%d",&leng);
        getchar();
        for (int po=0;po<leng;po++){
            scanf ("%c",&s[i][po]);


        }

        printf ("Case #%d: ",i+1);

        int space=0;
        for (int j=0;j<leng;j++){
             if (space%2==0&&s[i][j]!=' '){
                printf("%c",s[i][j]);
             }
            else if (space %2==0){
                printf (" ");
            }
             if (j==leng-1){
                    printf ("\n");
             break;}
             else if (s[i][j]==' '){
               // printf ("");
                space++;
             }

        }
    }



return 0;}

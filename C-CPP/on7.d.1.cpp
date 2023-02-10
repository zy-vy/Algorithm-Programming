#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char arr[101][101];
int ccc;
void prin (){
    for (int i =0 ;i<3;i++){
        for (int j=0;j<3;j++){
            printf ("%c",arr[i][j]);
        }printf ("\n");
    }printf ("\n");
}

int expand1 (int x,int y,int count){
    static int n=ccc;
    if (x<0||y<0||arr[x][y]!='#'||n>count){
        n=0;
        return 0;}

    printf ("count %d\n",count);
    printf ("n %d\n",n);
    arr[x][y]='F';
    for (int i=1;i<=count;i++){
        arr[x][y-i]='F';
        arr[x][y+i]='F';
        printf ("i %d\n",i);
        prin();
    }
    n++;
    printf ("n %d\n",n);


    return expand1 (x-n,y,count);
}
int expand2 (int x,int y, int count){
    static int n=0;
    if (x<0||y<0||arr[x][y]!='#'||n>count)return 0;
    arr[x][y]='F';
    for (int i=1;i<=count;i++){
        arr[x][y-i]='F';
        arr[x][y+i]='F';
        printf ("%d\n",i);
        prin();
    }
    printf ("n %d\n",n);
    n++;
    return expand2 (x+1,y,count);
}


int main (){

    int x,y;
    scanf ("%d%d",&x,&y);getchar();

    for (int i=0;i<x;i++){
        printf ("%s\n",arr[i]);
    };
    printf("\n");


    for (int i=0;i<x;i++){

        scanf ("%s",&arr[i]);getchar();
    }
    for (int i=0;i<x;i++){
        printf ("%s\n",arr[i]);
    };
    printf("\n");

    int n=2;
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            if (arr[i][j]=='F'){
                for (int k=1;k<=n;k++){
                    arr[i][j]='#';
                    ccc=0;
                    expand1(i,j,k);

                   // prin();
                  //  arr[i][j]='#';
                   // prin();
                   // expand2 (i,j,k);
                }
            }
            break;
        }
    }
  /*  for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            printf ("%c",arr[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
    memset(arr,0,sizeof(arr[101][101])*100*100);

    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            printf ("%c",arr[i][j]);
        }
        printf ("\n");
    }*/

    return 0;
}

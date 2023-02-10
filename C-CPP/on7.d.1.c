#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void print(char* arr,int x,int y){
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            printf ("%c",arr(i*y+j));
        }printf ("\n");
    }printf ("\n");
    return;
}
void expand_1 (int x,int y,char arr[]){}


int main (){
    char *v;
    int x,y;
    scanf ("%d%d",&x,&y);getchar();

    char arr[x+1][y+1];
    v=(char*)malloc(x*y*sizeof *v);

    for (int i=0;i<x;i++){

        scanf ("%s",&arr[i]);getchar();
    }
    for (int i=0;i<x;i++){
      //  printf ("%s",arr[i]);
    }
    print(v,x,y);
    free(v);
    return 0;
}

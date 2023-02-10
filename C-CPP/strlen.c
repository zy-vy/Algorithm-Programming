#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main (){
    int n;
    scanf ("%d",&n);

    char c[n][14];
    int z[13]={0};
    //printf ("%d\n",z[1]);
    for (int i=0;i<n;i++){
        scanf ("%s",&c[i]);
       z[i]=strlen(c[i]);
    }

    for (int i=0;i<n;i++){
        printf ("Case %d: %d\n",i+1,z[i]);
    }


return 0;}

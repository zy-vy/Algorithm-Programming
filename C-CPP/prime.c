#include <stdio.h>

int main (){
    int n,i=3,count,c;
    scanf ("%d,&n");

    if (n>=1)printf ("2 ");

    for (count =2;count <=n;){
        for (c=2;c<=i-1;c++)
        {
            if (i%c==0)
                break;
        }
        if (c==i){
            printf ("%d ",i);
            count ++;
        }
        i++;
    }


return 0;}

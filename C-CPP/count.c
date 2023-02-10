#include <stdio.h>

int main (){
    int n;
    scanf ("%d",&n);

    int x[n],y[n],z;
    for (int i=0;i<n;i++){
        scanf ("%d",&x[i]);
       // printf ("Case #%d:\n",i+1);
      /*  for (int j=1;j<=x[i];j++){
            if ((j%3==0&&j%15!=0)||(j%5==0&&j%15!=0))
                printf ("%d Jojo\n",j);
            else printf ("%d Lili\n",j);
        }*/
    }

    for (int i=0;i<n;i++){
        printf ("Case #%d:\n",i+1);
        for (int j=1;j<=x[i];j++){
            if ((j%3==0&&j%15!=0)||(j%5==0&&j%15!=0))
                printf ("%d Jojo\n",j);
            else printf ("%d Lili\n",j);
        }
    }

return 0;}

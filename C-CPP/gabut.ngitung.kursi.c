#include <stdio.h>

int main (){
    int t;
    scanf ("%d",&t);
    getchar();
    int n;
    long long int a,b,c,x[t],y;

    for (int i=0;i<t;i++){
        scanf ("%d %lld %lld %lld",&n,&a,&b,&c);

        y=n-(c-a);

      //  printf ("%d\n",y);
        if (y%(a+b+c)==0){
        x[i]=y/(a+b+c);
         printf ("Case #%d: %lld\n",i+1,x[i]-1);
        }
        else printf ("Case #%d: -1\n",i+1);


    }
    for (int i=0;i<t;i++){

    }


return 0;}

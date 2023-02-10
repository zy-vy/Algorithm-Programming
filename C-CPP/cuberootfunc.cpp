#include "stdio.h"

double cuberoot(double n){
    double precision = 0.000001;
    double i;
    for (i=1;(i*i*i)<=n;++i){
        printf ("%lf\n",i);
    }
    printf ("T %lf\n",i);
    for (--i;(i*i*i)<=n;i+=precision){
        printf ("%lf\n",i);
    }
    return i;

}

int main (){
    int n;
    scanf ("%d",&n);
    printf ("%.0lf\n",cuberoot(n));


return 0;
}

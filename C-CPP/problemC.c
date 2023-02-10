#include <stdio.h>

int main(){

    double   T,Ut,Ua,output;

    scanf("%lf %lf %lf",&T,&Ut,&Ua);
    output=(20/100*T)+(30/100*Ut)+(50/100*Ua);


    printf("%.2lf\n",output);


return 0;
}

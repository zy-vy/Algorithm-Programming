#include<stdio.h>
#include <math.h>
int main (){
    unsigned long long int a,b,c,k=1000000007;
    int n;
    scanf ("%d",&n);

    for (int i=0;i<n;i++){
        scanf ("%llu %llu",&a,&b);
        a=pow(2,a);
        b=pow(3,b);
        c=(a*b)%k;
        printf ("%llu\n",c);
    }


return 0;}

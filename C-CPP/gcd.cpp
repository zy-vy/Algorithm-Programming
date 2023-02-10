#include "stdio.h"

unsigned long long int gcd(unsigned long long int a,unsigned long long int b){
    if (b>a)
        return gcd(b,a);
    if (a%b==0)
        return b;
    return gcd(b,a%b);
}

int main (){
    unsigned long long int n,m;
    printf ("enter 2 int\n");
    scanf ("%llu%llu",&n,&m);
    printf ("%llu\n",gcd(n,m));
return 0;
}

#include <stdio.h>

unsigned long long int factorial(unsigned long long int fac);

int main (){
    int x;
    unsigned long long int z;
    scanf ("%d",&x);
    z=factorial (x);
    printf ("%llu\n",z);

return 0;
}

unsigned long long int factorial(unsigned long long int fac){
    unsigned long long int total;
    if (fac ==1)return 1;
    else {
    total = fac *factorial (fac-1);

return total;}
}


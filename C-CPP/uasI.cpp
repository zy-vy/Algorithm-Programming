#include "stdio.h"

int gcd(int a,int b){
    if (b>a)
        return gcd (b,a);
    if (a%b==0)
        return b;
    return gcd(b,a%b);
}

int recurv1(int n,int i){
    if (n==1)
        return i;
    else if (n==0)
        return 1;
    return recurv1(n-1,i)*recurv1(1,i)+recurv1(n-2,i);
}

int main (){

int w;
scanf ("%d",&w);
for (int t=1;t<=w;t++){
    int n,x;
    scanf ("%d %d",&n,&x);

    int result = recurv1(n,x);
//    printf ("%d\n",result);
    int result2 = recurv1 (n-1,x);
//    printf ("%d\n",result2);
    result /= gcd (result,result2);
    result2/= gcd (result,result2);
    printf ("Case #%d: %d/%d\n",t,result,result2);

}

return 0;
}

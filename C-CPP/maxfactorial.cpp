#include <stdio.h>
int main() {
   long int n;
   long int div=2, ans = 0, maxFact;
   scanf("%d",&n);
   while(n!=0) {
      if(n % div !=0)
         div = div + 1;
      else {
         maxFact = n;
         printf("%d\n",n);
         n = n / div;
         if(n == 1) {
            printf("%d is the largest prime factor !",maxFact);
            ans = 1;
            break;
         }
      }
   }
   return 0;
}


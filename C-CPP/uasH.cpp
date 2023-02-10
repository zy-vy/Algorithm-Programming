#include <stdio.h>
#include <math.h>
double cuberoot(double n){
    double precision = 0.000001;
    double i;
    for (i=1;(i*i*i)<=n;++i){
 //       printf ("%lf\n",i);
    }
 //   printf ("T %lf\n",i);
    for (--i;(i*i*i)<=n;i+=precision){
 //       printf ("%lf\n",i);
    }
    return i;

}

int main (){
FILE *fp=fopen("testdata.in","r");
int n;
long long int num;

    fscanf (fp,"%d\n",&n);
    for (int i=0;i<n;i++){
        fscanf (fp,"%lld\n",&num);
        printf ("Case #%d: %.0lf\n",i+1,cbrt(num));
    }

fclose(fp);
return 0;}

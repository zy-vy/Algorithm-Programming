#include<stdio.h>
#include <math.h>
#define e 2.7182818284590452353602874713527

int main (){
    int t;
    scanf ("%d",&t);
    getchar();
    for (int i=1;i<=t;i++){
        double a,b,c,ab,ec;
        scanf ("%lf %lf %lf",&a,&b,&c);

        ab=b*log10(a);
        ec=c*log10(e);

        if (ab<ec)
        printf ("Case #%d: <\n",i);
        else printf ("Case #%d: >\n",i);
    }
}

#include <stdio.h>

int main (){

    int t;
    int n;
    scanf ("%d",&t);
    getchar();
    for (int i=1;i<=t;i++){
        scanf ("%d",&n);
        getchar();
        char c[100],s[100];
        scanf ("%s%s",&c,&s);
        printf ("Case #%d: YES\n",t);

    }
    return 0;
}

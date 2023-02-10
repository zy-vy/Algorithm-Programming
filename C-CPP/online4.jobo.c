#include <stdio.h>

int jobo(int x);

int main (){
    int n;
    scanf ("%d",&n);

    printf ("%d\n",jobo(n));
    return 0;
}

int jobo (int x){
    if (x==0)return 0;
    else if (x==1)return 1;
    else if (x==2) return 1;
    else return jobo(x-1)+jobo(x-3);
}

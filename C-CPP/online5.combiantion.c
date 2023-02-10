#include <stdio.h>

int combi (int x);


int main (){
    int n;
    scanf ("%d",&n);

    printf ("%d\n",combi(n));

return 0;
}

int combi (int x){
    if (x==0)
        return 0;
    else if (x==1)
        return 3;
    else return combi(x-1)+x+1;
}

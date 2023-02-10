#include <stdio.h>
int main(){
    int tc;
    scanf ("%d",&tc);
    int input;
    int total =0;
    for (int i=0;i<tc;i++){
        scanf ("%d",&input);
        total += input;
        if (total ==12) total =28;
        else if (total ==35)total =7;
        else if (total >=40)total = total-40;
        else if (total ==30) total =10;
    }

printf ("%d",total);


return 0;}


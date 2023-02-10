#include<stdio.h>
int main(){
    long long int d,s,t;

    scanf ("%lld %lld %lld",&d,&s,&t);



    if (t>d&&t>s){
        if (s>d)
            printf ("Telur\nSayur\nDaging\n");
        else
            printf ("Telur\nDaging\nSayur\n");
    }
    else if (s>t&&s>d){
        if(t>d){
            printf("Sayur\nTelur\nDaging\n");
        }
        else
            printf("Sayur\nDaging\nTelur\n");
    }
    else if (d>s&&d>t){
        if (s>t){
            printf("Daging\nSayur\nTelur\n");
        }
        else
            printf ("Daging\nTelur\nSayur\n");
    }


return 0;}

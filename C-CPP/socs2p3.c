#include<stdio.h>
int main(){
    long long int uang[4],temp;

    for (int i=0;i<3;i++){
        scanf ("%lld",&uang[i]);

    }

    if (uang[2]>uang[1]&&uang[2]>uang[0]){
        if (uang[1]>uang[0])
            printf ("Telur\nSayur\nDaging\n");
        else
            printf ("Telur\nDaging\nSayur\n");
    }
    else if (uang[1]>uang[0]&&uang[1]>uang[2]){
        if(uang[2]>uang[0]){
            printf("Sayur\nTelur\nDaging\n");
        }
        else
            printf("Sayur\nDaging\nTelur\n");
    }
    else if (uang[0]>uang[1]&&uang[0]>uang[2]){
        if (uang[1]>uang[2]){
            printf("Daging\nSayur\nTelur\n");
        }
        else
            printf ("Daging\nTelur\nSayur\n");
    }


return 0;}

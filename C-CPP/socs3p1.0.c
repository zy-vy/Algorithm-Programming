#include <stdio.h>
#include <string.h>
int main (){
    char a[10000];

    scanf ("%[^\n]",&a);
    long long int s = strlen(a);
    for (long long int i=0;i<s;i++){
        if (a[i]>=97){
            a[i]-=32;}

        else continue;


    }

    for (long long int i=0;i<s;i++){
        if (a[i]=='I')a[i]='1';
        else if (a[i]=='R')a[i]='2';
        else if (a[i]=='E')a[i]='3';
        else if (a[i]=='A')a[i]='4';
        else if (a[i]=='S')a[i]='5';
        else if (a[i]=='G')a[i]='6';
        else if (a[i]=='T')a[i]='7';
        else if (a[i]=='B')a[i]='8';
        else if (a[i]=='P')a[i]='9';
        else if (a[i]=='O')a[i]='0';

    }
    printf ("%s\n",a);

return 0;
}

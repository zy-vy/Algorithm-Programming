#include<stdio.h>

int main (){
int a,t;
char c[1001];

scanf("%[^\n]",&c);

for (int i=0; i<c; i++){
    scanf(" %d",&a);
    t+=a;
}
printf("%d",t);

return 0;}

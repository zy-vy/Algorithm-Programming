#include<stdio.h>
int main(){
    int damage=100;
    int total=0 ,N;

    scanf("%d",&N);
    total = damage;
    while(N>1){

        damage+=50;
        total+=damage;
        N--;
    }

    printf("%d\n",total);
return 0;
}

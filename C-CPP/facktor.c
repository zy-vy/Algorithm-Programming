#include <stdio.h>

int main (){
    int n;
    scanf ("%d",&n);
    getchar();
    int x;
    long long int total;
    for (int i=0;i<n;i++){
       scanf ("%d",&x);
       getchar();
       int prime [x];
       int q=0;
       for (int a=x;a>1;a--){
            int fact =0;
        for (int b=1;b<=x;b++){
            if (a%b==0)
            fact ++;
            }
            if (fact ==2){
                prime[q]=a;
                q++;
                }
            }
        int count[1000]={0};
        int g=x;
        for (int a=0;a<q;a++){

            if (g%prime[a]==0){
                g/=prime[a];
                count [a]++;
            }
            else if (g%prime[a]!=0&&a==q-1){
                x--;
                }
            }
        printf ("%d %d\n",prime[i],count[i]);


       }







return 0;}

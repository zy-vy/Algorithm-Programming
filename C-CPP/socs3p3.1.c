#include <stdio.h>
int main (){
long long int n;
scanf("%lld",&n);
getchar();

char c[101][101];

for (int i=0;i<n;i++){
    scanf ("%s",&c[i]);
}
int count =0;

for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
            for (int k=j+1;k<n;k++){
                if (c[i][j]==c[i][k])
                    count ++;

            }
    }
}



for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
            for (int k=j+1;k<n;k++){
                if (c[j][i]==c[k][i])
                    count ++;

            }
    }
}


if (count == 0)printf ("Yay\n");
else printf ("Nay\n");
return 0;}

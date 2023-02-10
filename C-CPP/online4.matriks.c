#include <stdio.h>

void kali(int row1,int col1,int m1[51][51],int row2,int col2, int m2[51][51],int m3[51][51]);
void getm(int m[51][51],int a);
void prin(int m[51][51],int a);


int main (){
    int t;
    scanf ("%d",&t);
    getchar();
    for (int i=1;i<=t;i++){
        int n;
        scanf ("%d",&n);
        getchar();

        int jojo[51][51];
        getm(jojo,n);

        int lily[51][51];
        getm(lily,n);

        int bibi[51][51];
        getm(bibi,n);

        int libi[51][51]={0};
        kali(n,n,lily,n,n,bibi,libi);

        int jolibi[51][51]={0};
        kali(n,n,libi,n,n,jojo,jolibi);

        printf ("Case #%d:\n",i);
        prin(jolibi,n);


    }
    return 0;
}

void kali(int row1,int col1,int m1[51][51],int row2,int col2,int m2[51][51],int m3[51][51]){
    for (int i=0;i<row1;i++){
        for (int j=0;j<col2;j++){
            for (int k=0;k<col1;k++){
                m3[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
}
void getm(int m[51][51],int a){
    for (int i=0;i<a;i++){
        for (int j =0;j<a;j++){
            scanf ("%d",&m[i][j]);
        }
    }
}
void prin(int m[51][51],int a){
    for (int i=0;i<a;i++){
        for (int j=0;j<a;j++){
            printf("%d",m[i][j]);
            if (j!=(a-1))
                printf (" ");
        }
        printf ("\n");
    }
}

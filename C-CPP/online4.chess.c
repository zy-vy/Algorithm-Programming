#include <stdio.h>
#include<string.h>
void move1(int x1,int y1,int n,int x2,int y2,char chess[9][9]);
void move2(int x1,int y1,int n,int x2,int y2,char chess[9][9]);
int res=0;
void prin(int c[9][9]){
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            printf("%d",c[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
}
int main (){
    int t;
    scanf ("%d",&t);
    for (int z=1;z<=t;z++){
        int n;
        scanf ("%d",&n);
        getchar();
        int chess[9][9];
        memset(chess,0,sizeof(chess[9][9])*9*9);
        char c1,c2;
        int y1,y2;
        scanf ("%c %d %c %d",&c1,&y1,&c2,&y2);
        int x1=(c1-64);
        int x2=(c2-64);
        //printf ("%d,%d %d%,%d",x1,y1,x2,y2);

        chess[y1-1][x1-1]=1;
        chess[y2-1][x2-1]=2;
        prin(chess);

        move1(y1-1,x1-1,n,y2-2,x2-1,chess);
        for (int i =0;i<8;i++)
        for (int j=0;j<8;j++){
                if (chess[i][j]==1)
        move2(y2-1,x2-1,n,j,i,chess);
        }
        prin(chess);
        printf ("Case #%d: ",t);
        if (res==1)printf ("YES\n");
        else printf ("NO\n");
        res=0;
    }
    return 0;
}

void move1(int x1,int y1,int n,int x2,int y2,char chess[9][9]){
    if (x1>7||y1>7||n<=0||x1<0||y1<0)
        return;
    if (x1==x2){
        if (x1==0){
            if (y1>y2){
                    chess[x1][y1]=0;
                chess[x1+1][y1-2]=1;
                move1(x1+1,y1-2,n-1,x2,y2,chess);
            }
            else {
                    chess[x1][y1]=0;
                chess[x1+1][y1+2]=1;
                move1(x1+1,y1+2,n-1,x2,y2,chess);
            }
        }
        else if (x1==7){
            if (y1>y2){
                    chess[x1][y1]=0;
                chess[x1-1][y1-2]=1;
                move1(x1-1,y1-2,n-1,x2,y2,chess);
            }
            else {
                    chess[x1][y1]=0;
                chess[x1-1][y1+2]=1;
                move1(x1-1,y1+2,n-1,x2,y2,chess);
            }
        }
    }
    else if (y1==y2){
        if (y1==0){
            if (x1>x2){
                    chess[x1][y1]=0;
                chess[x1-2][y1+1]=1;
                move1(x1-2,y1+1,n-1,x2,y2,chess);
            }
            else {
                    chess[x1][y1]=0;
                chess[x1+2][y1+1]=1;
                move1(x1+2,y1+1,n-1,x2,y2,chess);
            }
        }
        else if (y1==7){
            if (x1>x2){
                    chess[x1][y1]=0;
                chess[x1-2][y1-1]=1;
                move1(x1-2,y1-1,n-1,x2,y2,chess);
            }
            else {
                    chess[x1][y1]=0;
                chess[x1+2][y1-1]=1;
                move1(x1+2,y1-1,n-1,x2,y2,chess);
            }
        }
    }
    else if (x1<x2&&y1>y2){
            chess[x1][y1]=0;
        chess[x1+2][y1-1]=1;
        move1(x1+2,y1-1,n-1,x2,y2,chess);
    }
    else if (x1<x2&&y1<y2){
            chess[x1][y1]=0;
        chess[x1+1][y1+2]=1;
        move1(x1+1,y1+2,n-1,x2,y2,chess);
    }
    else if (x1>x2&&y1>y2){
        chess[x1][y1]=0;
        chess[x1-1][y1-2]=1;
        move1(x1-1,y1-2,n-1,x2,y2,chess);
    }
    else if (x1>x2&&y1<y2){
        chess[x1][y1]=0;
        chess[x1-2][y1+1]=1;
        move1(x1-2,y1+1,n-1,x2,y2,chess);
    }
    return;
}





void move2(int x1,int y1,int n,int x2,int y2,char chess[9][9]){
    if (x1>7||y1>7||n<=0||x1<0||y1<0)
        return;

    if (x1==x2){
        if (x1==0){
            if (y1>y2){
                    chess[x1][y1]=0;
                if (chess[x1+1][y1-2]==1)res=1;
                move2(x1+1,y1-2,n-1,x2,y2,chess);
                chess[x1+1][y1-2]=2;
            }
            else {
                    chess[x1][y1]=0;
                if (chess[x1+1][y1+2]==1)res=1;
                move2(x1+1,y1+2,n-1,x2,y2,chess);
                chess[x1+1][y1+2]=2;
            }
        }
        else if (x1==7){
            if (y1>y2){
                    chess[x1][y1]=0;
                if (chess[x1-1][y1-2]==1)res=1;
                move2(x1-1,y1-2,n-1,x2,y2,chess);
                chess[x1-1][y1-2]=2;
            }
            else {
                    chess[x1][y1]=0;
                    if (chess[x1-1][y1+2]==1)res=1;
                move2(x1-1,y1+2,n-1,x2,y2,chess);
                chess[x1-1][y1+2]=2;
            }
        }
    }
    else if (y1==y2){
        if (y1==0){
            if (x1>x2){
                    chess[x1][y1]=0;
                if (chess[x1-2][y1+1]==1)res=1;
                move2(x1-2,y1+1,n-1,x2,y2,chess);
                chess[x1-2][y1+1]=2;
            }
            else {
                    chess[x1][y1]=0;
               if (chess[x1+2][y1+1]==1)res=1;
                move2(x1+2,y1+1,n-1,x2,y2,chess);
                 chess[x1+2][y1+1]=2;
            }
        }
        else if (y1==7){
            if (x1>x2){
                    chess[x1][y1]=0;
              if (chess[x1-2][y1-1]==1)res=1;
                move2(x1-2,y1-1,n-1,x2,y2,chess);
                  chess[x1-2][y1-1]=2;
            }
            else {
                    chess[x1][y1]=0;
                if (chess[x1+2][y1-1]==1)res=1;
                move2(x1+2,y1-1,n-1,x2,y2,chess);
                chess[x1+2][y1-1]=2;
            }
        }
    }
    else if (x1<x2&&y1>y2){
            chess[x1][y1]=0;
        if (chess[x1+2][y1-1]==1)res=1;
        move2(x1+2,y1-1,n-1,x2,y2,chess);
        chess[x1+2][y1-1]=2;
    }
    else if (x1<x2&&y1<y2){
            chess[x1][y1]=0;
        if (chess[x1+1][y1+2]==1)res=1;
        move2(x1+1,y1+2,n-1,x2,y2,chess);
        chess[x1+1][y1+2]=2;
    }
    else if (x1>x2&&y1>y2){
        chess[x1][y1]=0;
        if (chess[x1-1][y1-2]==1)res=1;
        move2(x1-1,y1-2,n-1,x2,y2,chess);
        chess[x1-1][y1-2]=2;
    }
    else if (x1>x2&&y1<y2){
        chess[x1][y1]=0;
        if (chess[x1-2][y1+1]==1)res=1;
        move2(x1-2,y1+1,n-1,x2,y2,chess);
        chess[x1-2][y1+1]=2;
    }
    return;
}

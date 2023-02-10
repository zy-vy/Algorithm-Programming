#include <stdio.h>
#include <string.h>

void move(int x,int y);
int food=0;
int x,y;
int count=0;
char c[101][101];
void prin(){
    for (int i=0;i<=x+1;i++){
        for (int j=0;j<=y+1;j++){
            printf("%c",c[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
}

int main (){
    int t;
    scanf ("%d",&t);
    for(int z=1;z<=t;z++){
        scanf ("%d%d",&x,&y);
        getchar();
        memset(c,'#',sizeof(c[101][101])*100*100);
      //  prin();
        for (int i =1;i<=x;i++){
            scanf ("%s",&c[i]);
        }
        for (int i=1;i<=x;i++){
            for (int j=0;j<y;j++){
                c[i][y-j]=c[i][y-j-1];
                if (j==y-1)c[i][y-j-1]='#';
            }
        }
      //  prin ();
        for (int i=0;i<=x;i++){
            for (int j=0;j<=y;j++){
                if (c[i][j]=='P'){
                    c[i][j]='.';
                 //   printf ("%c",c[i][j]);
                    move (i,j);
                }
            }
        }
        printf ("Case #%d: %d\n",z,food);
        food =0;
       /* for (int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                //c[i][j]='#';
            }
        }*/
        memset(c,'#',sizeof(c[101][101])*100*100);
      //  prin();
    }
    return 0;
}

void move (int x,int y){
  //  printf ("%c",c[x][y]);
    if (c[x][y]=='#'||c[x][y]=='P'||c[x][y]=='\0')
        return;
    if(c[x][y]=='*'){
        food++;
    }
    c[x][y]='P';
    count ++;
    printf ("%d\n",count);
    prin();

    move (x+1,y);
    move (x,y+1);

    move (x-1,y);
  //  printf ("x=%d\n",x);

    move (x,y-1);
//    printf("y=%d\n",y);
   // prin();

    return;
}

#include <stdio.h>
#include <string.h>
int n,m,count=0;
char arr[101][101];
void print(){
for (int i=0;i<n;i++){
    for (int j=0;j<m;j++)
        printf ("%c",arr[i][j]);
        printf ("\n");
}printf ("\n");
return;
}
void move (int x,int y){
    if (arr[x][y]=='\0'||arr[x][y]=='S'||arr[x][y]=='F'||x<0||y<0||x>n||y>m){
        return;
    }
    if (arr[x][y]=='K'){
        count++;
    }
    arr[x][y]='S';
 //   print();
    move(x+1,y);
    move(x-1,y);
    move(x,y+1);
    move(x,y-1);
return;}

int main (){
//    int n,m;
    int w;
    scanf ("%d",&w);
    for (int t=1;t<=w;t++){
        scanf ("%d%d",&n,&m);
        getchar();
    //    memset(arr,'S',sizeof(arr));
    //    print();
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
   //             printf ("%d %d\n",i,j);
                scanf ("%c",&arr[i][j]);
            }//scanf("\n");
            getchar();
        }
  //      print();
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (arr[i][j]=='H'){
         //           printf("move\n");
                    move (i,j);
                }
            }
        }
        printf ("Case #%d: %d\n",t,count);
        count=0;
        memset(arr,'\0',sizeof(arr));
}

return 0;
}

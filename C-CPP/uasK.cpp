#include <stdio.h>
#include <string.h>
#include <math.h>

int main (){
    int w;
    scanf ("%d",&w);
    for (int t=1;t<=w;t++){
        int n,m;
        scanf ("%d%d",&n,&m);
        double arr[101][101];
        memset(arr,0,sizeof(arr));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                scanf ("%lf",&arr[i][j]);
            //    printf ("%lf ",arr[i][j]);
            }
        }
        int i=0,j=0;
        for (;i<n;i++){
            for (j=1;j<m;j++){
                arr[i][0]+=arr[i][j];
            }
            arr[i][0]/=m;
        }
        for (int i=1;i<n;i++){
            arr[0][0]+=arr[i][0];
        }
        arr[0][0]/=n;
  //      arr[0][0]= floor (arr[0][0]);
        printf ("%lf\n",arr[0][0]);
        }

return 0;}

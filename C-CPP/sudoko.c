#include<stdio.h>

int main (){
    int n;
    scanf ("%d",&n);
   getchar();

    int arr[100][100];
   /* for (int i=0;i<n;i++){
        for (int j=0;j<9;j++){
            for (int k=0;k<9;k++){
                scanf ("%d",&arr[j][k]);
                getchar ();
            }
        }
    }
    */

    int stt[1000]={0};
    for (int i=0;i<n;i++){
        for (int j=0;j<9;j++){
            for (int k=0;k<9;k++){
                scanf ("%d",&arr[j][k]);
                getchar ();
            }
        }
        for (int j=0;j<9;j++){
            for (int k=0;k<9;k++){
                //printf ("%d",arr[j][k]);
                for (int l=k+1;l<9;l++){
                    if (arr[j][k]==arr[j][l]||arr[k][j]==arr[l][j])
                        stt[i]=1;
                      //  printf("ke %d%d%d: %d\n",j,k,l,stt[i]);
                }
            }
          //  printf ("\n");
        }
      /* if (stt[i]==0)
            printf ("Case %d: True\n",i+1);
        else if (stt[i]==1)
            printf("Case %d: False\n",i+1);
        */

        for (int aa=0;aa<9;aa+=3){
            int limit=3;
            for (int a=aa, b=aa;a<limit,b<limit;a++,b++){

                for (int c=a+1, d=b+1;c<limit,d<limit;c++,d++){
                   // printf ("%d.%d %d.%d | ",a,b,c,d);
                    if (arr[a][b]==arr[c][d]){
                        stt[i]=1;
                    }

                }

            }
            limit +=3;
        }
    }

    int total=0;
    float score=0;
    for (int i=0;i<n;i++){
        total+=stt[i];
        if(stt[i]==0)
            printf("Case #%d: TRUE\n",i+1);
        else if (stt[i]==1)
            printf("Case #%d: FALSE\n",i+1);
    }

    score= 100-((float)total/n*100);
    printf ("%.2f%%\n",score);


return 0;}

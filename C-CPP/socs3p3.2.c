#include <stdio.h>

int main (){
    int n;
    scanf ("%d",&n);
    getchar();

    char c[n][n];

    for (int i=0;i<n;i++){
        scanf ("%s",&c[i]);
    }

    int count =0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){

                    for (int k=j+1;k<n;k++){
                            if (c[i][j]==c[i][k]){
                                count =1;
                            }

            }
        }

    }


        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                  for (int k=j+1;k<n;k++){
                    if(c[j][i]==c[k][i])
                        count =1;
                    ;

            }
        }

        }




if (count ==0){
    printf ("Yay\n");
}
else printf ("Nay\n");

return 0;}

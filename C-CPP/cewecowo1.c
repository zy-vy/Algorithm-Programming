#include <stdio.h>
#include <string.h>

int main (){
    int n;
    scanf ("%d",&n);
    getchar();

    char c[n][10001];

    char arr[123]={0};
    for (int i=0;i<n;i++){
        scanf ("%s",&c[i]);
    }
    printf ("%c\n",arr[123]);
    for (int i=0;i<n;i++){
        for (int j=0;j<strlen(c[i]);j++){
            arr[c[i][j]];
            printf ("%c\n",arr[c[i][j]]);

        }
    }
    int count =0;
    for (int i=0;i<n;i++){
        for (int j=97;j<=122;j++){
            if (arr[c[i][j]]!=0)
                count ++;
        }
    }

    for (int i=0;i<n;i++){
        if (count %2==0) printf ("case %d: Yay\n",i);
        else printf ("case %d: Nay\n",i);
    }


return 0;}

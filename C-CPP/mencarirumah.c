#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n,i,j;
    scanf("%d",&n);
    char arr[101];
    scanf("%s",&arr);
    for (i=0,j=n-1;i<n&&j>=0;i++,j--){
        printf ("%d %d",i,j);
        if(arr[i]=='F'&&arr[j]=='F'){
            printf("SAMA SAJA");
            break;
        }
        else if(arr[i]=='F'){
            printf("KIRI");
            break;
        }
        else if (arr[j]=='F'){
            printf("KANAN");
        break;}
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

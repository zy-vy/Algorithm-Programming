#include <iostream>
#include <stdio.h>

// using namespace std;
int count (long long int *arr,long long int m,long long int *total){
    if (*total>m){

        return -1;
    }
    if (*arr=='\0'){

        return 0;
    }
    if (*total<=m){

        *total+=*arr;
        return 1 + count (arr+1,m,total);
    }

}

int main() {
    int n;
    scanf ("%d",&n);
    long long int arr[100001];
    for (int i=0;i<n;i++){
        scanf ("%d",&arr[i]);
    }

    int q,chain=0;
    scanf ("%d",&q);
    long long int m,total=0;
    for (int i=1;i<=q;i++){
        scanf ("%lld",&m);
        chain = count (&arr[0],m,&total);
        if (chain==0){
            printf ("Case #%d: -1\n",i);
        }
        else
        printf ("Case #%d: %d\n",i,chain);
        chain =0;
        total =0;

    }
   return 0;
}

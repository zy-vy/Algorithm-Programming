#include <stdio.h>

int count (unsigned long long int *arr,unsigned long long int m,unsigned long long int *total){
    if (*total >m){
  //      printf ("-1\n");
        return -1;
    }
    if (*arr=='\0'){
  //      printf ("0\n");
        return 0;
    }
    if (*total<=m){
        *total +=*arr;
  //      printf ("total %llu\n",*total);
        return 1+count (arr+1,m,total);
    }

}
int main (){
    long long int n;
    scanf ("%lld",&n);
    unsigned long long int arr[10001],m,total=0;
    for (int i=0;i<n;i++){
        scanf ("%llu",&arr[i]);
    }

    long long int q,chain=0,temp=0;
    scanf ("%lld",&q);
    for (int i=1;i<=q;i++){
        scanf ("%llu",&m);
        for (int j=0;j<n;j++){
            temp = count (&arr[j],m,&total);
  //          printf ("%d temp %lld\n",j,temp);
            if (temp >=chain){
                chain = temp;
            }
            if (chain >=(n-j-1)){
                temp=0;
                total=0;
                break;
            }
            temp = 0;
            total = 0;
        }
        if (chain ==0){
            printf ("Case #%d: -1\n",i);
        }
        else
            printf ("Case #%d: %lld\n",i,chain);
        chain =0;
    //    printf ("%temp %lld chain %lld total %llu\n",temp,chain,total);

    }


return 0;
}

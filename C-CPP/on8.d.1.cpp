
#include <stdio.h>

int count (unsigned long long int *total,unsigned long long int max,unsigned long long int *arr){
  //  static int chain=0,temp=0;

    if (*total > max){
   //     printf ("-1\n");
        return -1;
   //    chain =temp;
    }
    if (*arr=='\0'){
   //     printf ("0\n");
        return 0;
    }
    if (*total <=max){
        *total+=*arr;
   //     printf ("total %llu\n",*total);
        return 1 + count (total,max,arr+1);

    }

}

int main (){
    int w;
    scanf ("%d",&w);getchar();

    for (int t=1;t<=w;t++){
        int n;unsigned long long int m;
        scanf ("%d%llu",&n,&m);
   //     printf ("%d\n",n);
        unsigned long long int arr[10001];
        for (int i=0;i<n;i++){
            scanf ("%llu",&arr[i]);
   //         printf ("%d",arr[i]);
        }
   //     printf ("\n");


        unsigned long long int total=0,temp=0,chain=0;
        for (int i=0;i<n;i++){
            temp = count (&total,m,&arr[i]);
   //         printf ("%d temp %llu\n",i,temp);
            if (temp >= chain){
                chain = temp;
            }
            printf ("n %d i %d %d %d\n",n,i,chain,n-i-1);
            if (chain>=(n-i-1)){
                break;
            }
            total = 0 ;
            temp = 0 ;
        }
        if (chain==0){
            printf ("Case #%d: -1\n",t);
        }
        else printf ("Case #%d: %llu\n",t,chain);
    }
return 0;
}

#include <iostream>
#include <stdio.h>


//using namespace std;


int main() {
    int t;
    scanf ("%d",&t);
    for (int w=1;w<=t;w++){

        int n;
        scanf("%d",&n);
        double arr[5001],mean=0,median=0,temp;
        for (int i=0;i<n;i++){
            scanf ("%lf",&arr[i]);
            mean+=arr[i];
        }
        mean/=n;
        int j;
        for (int i=1;i<n;i++){
            temp=arr[i];
            for (j=i-1;j>=0&&arr[j]>temp;j--){
                arr[j+1]=arr[j];
            }
            arr[j+1]=temp;
        }
        if(n%2==0){
            median = ((arr[(n/2)]+arr[(n/2)-1])/2);
        }
        else {median = (arr[n/2]);
        }

        printf ("Case #%d:\n",w);
        printf ("Mean : %.2lf\n",mean);
        printf ("Median : %.2lf\n",median);


    }




    return 0;
}

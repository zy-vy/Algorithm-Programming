#include<stdio.h>

int main(){

	int n;
	scanf("%d", &n);
	
	for(int t = 1; t <= n; t++){
		int a, b;
		scanf("%d %d", &a, &b);
		
		int x, y;
		if(a > b){
			x = a;
			y = b;
		}else{
			x = b;
			y = a;
		}
		
//		int flag, min = a, max = 0;
//		for(int i = 2; i <= y + 1 ; i++){
//			flag = 1;
//			for(int j = 2; j <= i / 2; j++){
//				if(i % j == 0){
//					flag = 0;
//					break;
//				}
//			}
//			
//			if(flag == 1){
//				if(a % i == 0 && b % i == 0){
//					if(min > i){
//						min = i;
//					}
//					if(max < i){
//						max = i;
//					}
//				}
//				printf("%d ", i);
//			}
//		}
	long int n,m;
	n=y;m=x;
   long int div=2, ans = 0, maxFact=0,minFact=0;
   int flag=0;
		while(n!=0) {
     		 if(n % div !=0)
        	 div = div + 1;
    		  else {
    		  	if (y%div==0&&m%div==0&&flag==0){
    		  		minFact=div;
    		  		flag=1;
				  }
			if(m%div==0&&y%div==0){
				maxFact = n;
        	 n = n / div;
        	 if(n == 1) {
         	   ans = 1;
        	    break;
       		  }
			}
        	 
   		   }
   		}
		puts("");
		printf("min: %d max: %d\n", minFact, maxFact);
		int total = minFact * maxFact;
		printf("Case #%d: ", t);
		printf("%d\n", total);
	}
	
	
	
	return 0;
}

#include<stdio.h>
#include<string.h>

int main(){
	
	int n;
	scanf("%d", &n);getchar();
	
	for(int tc = 1; tc <= n; tc++){
		char sheep[100001];
		scanf("%[^\n]", &sheep);getchar();
		int x = strlen(sheep);
		int ctrW = 0;
		int ctrB = 0;
		
		for(int i = 0; i < x; i++){
			if(sheep[i] == 'W'){
				ctrW++;
			}else if(sheep[i] == 'B'){
				ctrB++;
				if(ctrB == 2 && ctrW > 0){
					ctrW-=1;
					ctrB = 0;
				}
				else if(ctrB==2 && ctrW<0){
					ctrB=0;
				}
			}
		}
		
		printf("Case #%d: ", tc);
		if(ctrW == 10){
			printf("Jojo fall asleep\n");
		}else if(ctrW != 10){
			printf("Jojo stayed awake\n");
		}
	}
	
	
	return 0;
}

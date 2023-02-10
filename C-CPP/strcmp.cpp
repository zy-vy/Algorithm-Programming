#include <stdio.h>
#include <string.h>

int main (){
	char a[20]="makan";
	char b[20]="basi";
	if (b[1]==a[1]){
		printf("work\n");
	}
	else{
		printf("No\n");
	}
	char temp[20];
	memset(temp, '\0', sizeof(temp));
	strncpy(temp,&b[1],3);
	strcat(a,temp);
	printf("%s=%s\n",temp,a);
	strncpy(temp,&b[0],1);
	printf("%s\n",temp);
	return 0;
}

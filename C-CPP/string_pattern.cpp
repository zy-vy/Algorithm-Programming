#include <string.h>
#include <stdio.h>
notfinished
case = ababacababac
should be 1

int main (){
	
	char str[50];
	scanf ("%[^\n]", &str);
	int count=0;
	char pat[50]={'\0'};
	int len=strlen(str);
	int flag=0;
	int patFound=0;
	char temp[50]={'\0'};
	
	for(int i =0;i<len;i++){
		if (i==0){
			memset(temp,'\0',sizeof(temp));
			strncpy(temp,&str[flag],1);
			strcat(pat,temp);
			printf ("i=0 %s\n",pat);
		}
		else if (str[i]!=pat[flag]&&patFound==0){
			memset(temp,'\0',sizeof(temp));
			strncpy(temp,&str[i],1);
			strcat(pat,temp);
			printf ("cat2\n");
		}
		
		else if (str[i]==pat[flag]&&patFound==0&&i!=0){
			printf ("====%c %c %d\n",pat[flag],str[i],patFound);
			patFound=1;
			if(strlen(pat)==1){
				printf("len pat 1\n");
				count++;
			}
			flag++;
		}
		else if (patFound==1){
			printf ("flag %d %d\n",flag,strlen(pat));
			if(strlen(pat)==1&&pat[0]==str[i]){
				printf("1pat\n");
				count++;
			}
			else {
				if (flag==strlen(pat)-1&&pat[flag]==str[i]){
					count++;
					flag=0;
					printf ("count++\n");
				}
				
				
				
				else if(pat[flag]==str[i]&&i!=len-1){
					printf ("++flag\n");
					++flag;
				}
				else{
					printf ("		else\n");
					count=0;
					memset(pat,'\0',sizeof(pat));
					break;
				}
			}
			
		}
	}
	printf ("pat = %s\n",pat);
	printf("count %d\n",count);
	
	return 0;
}

#include<stdio.h>
#include<string.h>

int main (){
    int s[123];
    memset (s,'\0',sizeof(s));
    for (int i =65;i<123;i++){
        printf ("%c\n",s[i]);
    }

    int a;
    scanf ("%d",&a);
    printf ("%d\n",a);
return 0;
}

#include <stdio.h>
#include <string.h>
int main (){
    for (int i=0;i<9998;i++){
      //  printf ("1");
    }
    char s[10001],c;
    FILE *fp=fopen("D://test10k.txt","r");
    c=fgetc(fp);
    int i=1;
    while (c!=EOF){
        printf ("%d %c / ",i,c);
        i++;
        c=fgetc(fp);}

    while (s[i]!='\0'){
    //printf ("%d",i);
    i++;}

return 0;}

#include <stdio.h>
#include <string.h>
int main (){
    for (int i=0;i<9998;i++){
      //  printf ("1");
    }
    char s[10001];
    FILE *fp=fopen("D://test10k.txt","r");
    while (fp!=EOF){
    fscanf (fp,"%c",&s);}
    int i=0;
    while (s[i]!='\0'){
    printf ("%d",i);
    i++;}

return 0;}

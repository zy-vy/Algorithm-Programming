#include <stdio.h>

int count(char *s,int min,int max,int *buff);
int main (){
    FILE *fp=fopen("D://testdata1.txt","r");
    int t;
    fscanf (fp,"%d",&t);fgetc(fp);
    for (int w=1;w<=t;w++){
        int time,min,max;
        fscanf (fp,"%d %d %d",&time,&min,&max);fgetc(fp);
        char s[10001];
        fscanf (fp,"%[^\n]*c",&s);fgetc(fp);//getchar();

        int total=0,buff=0;
        total=count(&s[0],min,max,&buff);
        printf ("Case #%d: %d\n",w,total);
    }
    return 0;

}

int count (char *s,int min,int max,int *buff){
    //if (min>max)return 0;
    if (*s=='\0'){
        if (*buff>min&&*buff<max)
        return 1;
        else
        return 0;
    }
   // printf ("%d 1\n",*buff);
    if (*s=='0'){
        if (*buff>min&&*buff<max){
            *buff=0;
           // printf ("T\n\n");
            return 1 + count (s+1,min,max,buff);
        }
        else {
            *buff=0;
        return count (s+1,min,max,buff);
        }
    }
    else if (*s=='1'){
        *buff+=1;
        ;
        //printf ("%d 3\n",*buff);
        return count(s+1,min,max,buff);
    }
}

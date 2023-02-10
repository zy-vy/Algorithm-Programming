#include<string.h>
#include <stdio.h>

int change (char *s,char before,char after){
    if (*s=='\0')return 0;
    if (*s==before){
        *s=(after+32);
    }
    //printf ("%c",*s);
    return change (s+1,before,after);
}

int count (char *s,int abjad[],char after[]){
    if (*s=='\0')return 0;
    for (int i=0;i<strlen(after);i++){
        if (*s==after[i]){
            //printf ("%c %d|",*s,abjad[*s]);
        abjad[*s]=abjad[*s]+1;
        return count (s+1,abjad,after);
        }
    }
   // printf ("\n");
    //printf ("%c %d/",*s,abjad[*s]);
    return count(s+1,abjad,after);
}
int main (){
    FILE *fp=fopen("testdata.in","r");
    int t;
    fscanf (fp,"%d",&t);fgetc(fp);
    //getchar();
    //printf ("%d\n",t);

    for (int w=1;w<=t;w++){
        char s[101];
        fscanf (fp,"%[^\n]*c",&s);fgetc(fp);//getchar();
        //printf ("%s\n",s);
        int n;
        fscanf (fp,"%d",&n);fgetc(fp);//getchar();
        //printf ("%d\n",n);
        char before,after[101];
        for (int i=0;i<n;i++){
            fscanf (fp,"%c %c",&before,&after[i]);fgetc(fp);//getchar();
            //printf ("%c %c\n",before,after[i]);
            change(&s[0],before,after[i]);
        }
        int abjad[123];
        memset(abjad,0,sizeof(abjad));

        for (int i=0;i<strlen(s);i++){
            if (s[i]>=97)s[i]-=32;
        }
        //printf ("%s\n",s);
        for (int i=65;i<97;i++){
           // printf ("%c %d | ",i,abjad[i]);
        }
        //printf ("\n");
        count(&s[0],abjad,after);
        //printf ("\n");
        for (int i=65;i<97;i++){
         //   printf ("%c %d | ",i,abjad[i]);
        }
      //  printf ("\n");

        for (int i=65;i<91;i++){
            if (abjad[i]!=0)
                printf ("%c %d\n",i,abjad[i]);
        }//printf ("\n");
        memset (abjad,0,sizeof(abjad));
        memset (s,0,sizeof(s));

    }
    return 0;
}

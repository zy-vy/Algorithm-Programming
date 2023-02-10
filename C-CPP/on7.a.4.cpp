#include <stdio.h>
#include <string.h>

int change (char *s,char before,char after){
    if (*s=='\0')return 0;
    if (*s==before){
        *s=after;
       }
 //   printf ("%c|%c ",before,after);
    return change (s+1,before,after);
}

int count (char *s,int abjad[],char after[]){
    if (*s=='\0')return 0;
    for (int i=0;i<strlen(after);i++){
       // if (*s==after[i]){    << GAK DI PAKE
            abjad[*s]+=1;
   //         printf ("%c|%d ",*s,abjad[*s]);
            return count (s+1,abjad,after);
       // }   << GAK DI PAKE
    }
    return count(s+1,abjad,after);
}

int main (){
    FILE *fp=fopen("testdata.in","r");
    int t;
    fscanf(fp,"%d",&t);fgetc(fp);
//    printf ("%d\n",t);
    for (int w=0;w<t;w++){

        char s[101];
        fscanf (fp,"%[^\n]*c",&s);fgetc(fp);
 //       printf ("%s\n",s);
        int n;
        fscanf (fp,"%d",&n);fgetc(fp);
 //       printf ("%d\n",n);
        char before[101],after[101];
        int abjad[123],mark[123];
        memset(abjad,0,sizeof(abjad));
        memset(mark,0,sizeof(mark));
        for (int i=0;i<n;i++){
            fscanf (fp,"%c %c",&before[i],&after[i]);fgetc(fp);
   //         printf ("%c %c\n",before[i],after[i]);
            if (mark[before[i]]==0){
                change (&s[0],before[i],after[i]);
                mark[before[i]]=1;
            }
        }
 //       printf ("\n");
        count (&s[0],abjad,after);
 //       printf ("\n");
        for (int i=65;i<91;i++){
            if (abjad[i]!=0){
                printf ("%c %d\n",i,abjad[i]);
            }
        }




    }
return 0;
}

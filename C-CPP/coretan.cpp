#include<string.h>
#include <stdio.h>

int change (char *s,char before,char after){
    if (*s=='\0')return 0;
    if (*s==before){
        *s=after;
    }
    return change (s+1,before,after);
}

int count (char *s,int abjad[],char after){
    if (*s=='\0')return 0;
    if (*s==after)
    abjad[*s]++;
    return count(s+1,abjad,after);
}
int main (){
    FILE *fp=fopen("testdata.in","r");
    int t;
    fscanf (fp,"%d",&t);
    //getchar();
    //printf ("%d\n",t);

    for (int w=1;w<=t;w++){
        char s[101];
        fscanf (fp,"%s",&s);//getchar();
        //printf ("%s\n",s);
        int n;
        fscanf (fp,"%d",&n);fgetc(fp);//getchar();
       // printf ("%d\n",n);
        char before,after;
        int abjad[123];
        memset(abjad,0,sizeof(abjad));
        for (int i=0;i<n;i++){
            fscanf (fp,"%c %c",&before,&after);fgetc(fp);//getchar();
           // printf ("%c %c\n",before,after);
            change(&s[0],before,after);
            count (&s[0],abjad,after);
        }


        //count(&s[0],abjad);

        for (int i=65;i<97;i++){
            if (abjad[i]!=0)
                printf ("%c %d\n",i,abjad[i]);
        }


    }
    return 0;
}

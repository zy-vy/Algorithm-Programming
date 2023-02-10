#include <stdio.h>


int main (){
    FILE *fp=fopen("D://testdata2.txt","r");
    int t;
    fscanf (fp,"%d",&t);fgetc(fp);
    for (int w=1;w<=t;w++){
        int size,time;
        char s[101][101];
        fscanf (fp,"%d%d",&size,&time);fgetc(fp);
        for (int i=0;i<size;i++){
            fscanf (fp,"%s",&s[i]);fgetc(fp);
        }
        int x,y;

            for (int j=0;j<size;j++){
                for (int k=0;k<size;k++){
                    if (s[j][k]=='F'){
                       x=j;
                       y=k;
                    }
                }
            }


        printf ("Case #%d:\n",w);
        for (int i=0;i<size;i++){
            for (int j=0;j<size;j++){
                if (i>x-time&&j>y-time&&i<x+time&&j<y+time)
                printf ("F");
                else printf ("#");
            }printf ("\n");
        }
        printf ("\n");

    }




return 0;
}

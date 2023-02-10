#include <stdio.h>
#include <string.h>

int move (int x,int y);
int baris,kolom;

char c[baris][kolom];
int main (){


    scanf ("%d %d",&baris,&kolom);
    getchar();

    for (int i=0;i<baris;i++){
        scanf ("%s",&c[i]);
    }

    int food=0;
    for (int i=0;i<baris;i++)
    {

        for (int j=0;j<kolom;j++)
        {
            if (c[i][j]=='P')
            {
           //     printf ("okay ");
                food = move (i,j);
                printf ("%d %d\n",i,j);
            }
           // printf ("test ");
        }
    }
    printf ("%d\n",food);

    return 0;
}

int move (int x,int y)
{

    printf ("%d %d\n",x,y);
    if (c[x][y+1]=='.')
    {
        c[x][y+1]='P';
        c[x][y]='#';
        y+=1;
        return +0;
    }
    else if (c[x][y-1]=='.')
    {
        c[x][y-1]='P';
        c[x][y]='#';
        y-=1;
        return +0;
    }
    else if (c[x+1][y]=='.')
    {
        c[x+1][y]='P';
        c[x][y]='#';
        x+=1;
        return +0;
    }
    else if (c[x-1][y]=='.')
    {
        c[x-1][y]='P';
        c[x][y]='#';
        x-=1;
        return +0;
    }


    else if (c[x][y+1]=='*')
    {
        c[x][y+1]='P';
        c[x][y]='#';
        y+=1;
        return +1;
    }
    else if (c[x][y-1]=='*')
    {
        c[x][y-1]='P';
        c[x][y]='#';
        y-=1;
        return +1;
    }
    else if (c[x+1][y]=='*')
    {
        c[x+1][y]='P';
        c[x][y]='#';
        x+=1;
        return +1;
    }
    else if (c[x-1][y]=='*')
    {
        c[x-1][y]='P';
        c[x][y]='#';
        x-=1;
        return +1;
    }

}

#include<stdio.h>
#include<string.h>
struct karyawan {
   char nama[101],gender[101],div[101];
   int st = 0;
};
struct karyawan  kar[101];

void tambah(int n);
void swap();
void out();
void pensi();
int main (){
    int n;
    scanf ("%d",&n);

    for (int i=0;i<n;i++){
        int cs;
        scanf ("%d",&cs);
        switch (cs){
    case 1:
        tambah(n);break;
    case 2:
        swap();break;
    case 3:
        out();break;
    case 4:
        pensi();break;
        }
    }
    for (int i=0;i<n;i++){
        if (kar[i].st==1)
        printf ("%s\n",kar[i].nama);
    }


return 0;}

void swap (){
    struct karyawan temp;
    int a,b;
    scanf ("%d%d",&a,&b);
    a--;b--;
    if (kar[a].st==1&&kar[b].st==1){

            temp=kar[a];
            kar[a]=kar[b];
            kar[b]=temp;
    }
    return;
}

void out (){
    int a;
    scanf ("%d",&a);
    a--;
    kar[a].st=NULL;
    return;
}

void resign(){
    int m;
    scanf ("%d",&m);
    m--;
    kar[m].st=4;
return;
}

void tambah(int n){
    for (int i =0;i<n;i++){
            if(kar[i].st==0){
                 scanf("%[^\n]", &kar[i].nama); getchar();
                 scanf("%[^\n]", &kar[i].gender); getchar();
                 scanf("%[^\n]", &kar[i].div); getchar();
                 kar[i].st= 1;

                    break;
            }
    }

return;
}

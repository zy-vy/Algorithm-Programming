#include<stdio.h>
#include<string.h>

struct karyawan {
     char nama[101],gender[101],div[101];
     int stats = 0;
};

struct employeeData employee[101];

int main(){
    int n, i, j;

    int out;
    int pensi;
    int tes;
    scanf("%d", &n); getchar();
    for(int l = 0; l < n; l++){
    scanf("%d", &tes); getchar();
    if(tes == 1){
        for(int i = 1; i <= n; i++){
            if(kar[i].stats==0){
                 scanf("%[^\n]", &kar[i].nama); getchar();
                 scanf("%[^\n]", &kar[i].gender); getchar();
                 scanf("%[^\n]", &kar[i].div); getchar();
                    kar[i].stats = 1;

                    break;
            }
        }
    }
    int a,b;
      if(test == 2){
           scanf("%d %d", &a, &b); getchar();
           if(kar[a].stats == 1 && kar[b].stats == 1){
                struct karyawan temp;
                temp=kar[a];
                kar[a]=kar[b];
                kar[b]=temp;
           }
      }

    if(test == 3){
        scanf("%d", &out); getchar();
        kar[out].stats = NULL;
    }

    if(tes == 4){
        scanf("%d", &pensi); getchar();
       kar[pensi].stats = 4;
        }
    }

     for(int j = 1; j <= n; j++){
            if(kar[j].stats == 1){
            printf("%s\n", kar[j].nama);
            }
     }
    return 0;
}

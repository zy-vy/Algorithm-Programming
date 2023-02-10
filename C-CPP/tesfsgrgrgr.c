#include<stdio.h>
#include<string.h>

struct Karyawan{
  char Nama[100];
  char JenisKelamin[100];
  char Divisi[100];
  int aktif = 0;
};

struct Karyawan kr[200];

int main(){

  int n;
  char arr[200];
  int pensiun, keluar, proses[100];

  scanf("%d", &n); getchar();

  for(int t = 0; t < n; t++){
    scanf("%d", &proses[t]); getchar();
    if(proses[t] == 1){
      for(int i = 1; i <= n; i++){
       if(kr[i].aktif==0){
        scanf("%[^\n]", &kr[i].Nama); getchar();
        scanf("%[^\n]", &kr[i].JenisKelamin); getchar();
        scanf("%[^\n]", &kr[i].Divisi); getchar();
        kr[i].aktif = 1;
         break;
       }
      }
    }
    int replace1, replace2;
    if(proses[t] == 2){
      scanf("%d %d", &replace1, &replace2); getchar();
      if(kr[replace1].aktif == 1 && kr[replace2].aktif == 1)
      {
       strcpy(arr, kr[replace1].Nama);
       strcpy(kr[replace1].Nama, kr[replace2].Nama);
       strcpy(kr[replace2].Nama, arr);
      }
    }
    if(proses[t] == 3){
     scanf("%d", &keluar); getchar();
     kr[keluar].aktif = NULL;
    }
    if(proses[t] == 4){
     scanf("%d", &pensiun); getchar();
     kr[pensiun].aktif = 4;
   }
 }

  for(int i = 1; i <= n; i++){
    if(kr[i].aktif == 1){
      printf("%s\n", kr[i].Nama);
    }
  }

 return 0;
}

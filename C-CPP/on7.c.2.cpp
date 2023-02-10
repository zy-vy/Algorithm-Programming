#include<stdio.h>
#include <string.h>

int main(){
     int n,a,b;
     int lightning = 0, count = 0;
     int t, w;
     char arr[10001];

     FILE *fp = fopen("testdata.in", "r");
     fscanf(fp, "%d", &t);

     for (int w = 1; w<=t; w++){
          fscanf(fp, "%d %d %d", &n, &a, &b);
          fscanf(fp, "%s", arr);

          int x = strlen(arr);
          lightning = 0;
          count = 0;


          for(int i = 0; i <= strlen(arr); i++){
               if(arr[i] == '1'){
                    count++;
               }

               if(arr[i] == '0' || arr[i] == '\0'){
                    if(count >= a && count <= b){
                    lightning++;
                    }
                    count = 0;
               }
          }

          printf("Case #%d: %d\n", w, lightning);
     }






     return 0;
}

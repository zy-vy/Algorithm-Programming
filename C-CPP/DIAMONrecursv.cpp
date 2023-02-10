#include <stdio.h>
void print (int);

int main () {
   int rows;
    printf ("enter rows\n");
   scanf("%d", &rows);

   print(rows);

   return 0;
}

void print (int r) {
   int c, space;
   static int stars = -1,count =r;

   if (r <= 0)
     return;

   space = r - 1;
   stars += 2;

   for (c = 0; c < space; c++)
      printf(" ");

   for (c = 0; c < stars; c++)
      printf("*");

   printf("\n");

   print(--r);

   space = r + 1;
   stars -= 2;
    count --;
    if (r<=count+2)
   for (c = 0; c < space; c++)
      printf(" ");

   for (c = 0; c < stars; c++)
      printf("*");


   if (r<=count+2){
      printf("\n");
   }
   //printf ("%d\n",r);
}

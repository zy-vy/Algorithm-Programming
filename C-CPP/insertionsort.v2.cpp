#include <stdio.h>
void prin (int arr[],int n){
    for (int i=0;i<n;i++){printf ("%d ",arr[i]);}printf ("\n");
}
int main()
{
  int n, array[1000], c, d, t, flag = 0;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  for (c = 1 ; c <= n - 1; c++) {
    t = array[c];

    for (d = c - 1 ; d >= 0; d--) {
      if (array[d] > t) {
        array[d+1] = array[d];
        flag = 1;
        prin(array,n);
      }
      else{
        printf("T\n");
        break;
      }
    }
    if (flag)
      array[d+1] = t;
      prin(array,n);
  }

  printf("Sorted list in ascending order:\n");

  for (c = 0; c <= n - 1; c++) {
    printf("%d\n", array[c]);
  }

  return 0;
}

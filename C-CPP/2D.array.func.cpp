#include <stdio.h>
#include <stdlib.h>


void func(int* array, int rows, int cols)
{
  int i, j;

  for (i=0; i<rows; i++)
  {
    for (j=0; j<cols; j++)
    {
      array[i*cols+j]=i*j;
    }
  }
}

int main()
{
  int rows, cols;
  int *x;

  /* obtain values for rows & cols */

  /* allocate the array */
  x = malloc(rows * cols * sizeof *x);

  /* use the array */
  func(x, rows, cols);

  /* deallocate the array */
  free(x);
}

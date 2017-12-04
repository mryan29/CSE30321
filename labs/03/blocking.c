#include <stdio.h>
#include <math.h>

#define MATRIX_SIZE 5 
#define XSIZE 5 
#define YSIZE 5

int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  int i, j, k;
  int B = 1;
  
  int r;

	printf("\nx matrix: \n");
  /* Initialize x matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      x[i][j] = 0;
      printf("%d\t", x[i][j]);
    }
    printf("\n");
  }

	printf("\ny matrix: \n");
  /* Initialize y matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      y[i][j] = i + j;
      printf("%d\t", y[i][j]);
    }
    printf("\n");
  }

	printf("\nz matrix: \n");
  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
	z[i][j] = i + j;
	printf("%d\t", z[i][j]);
    }
    printf("\n");
  }

  /* Do matrix multiply */

/*
  for(i=0; i<XSIZE; i=i+1) {
    for(j=0; j<YSIZE; j=j+1) {
      r = 0;
      for(k=0; k<XSIZE; k=k+1) {
        r = r + y[i][k] * z[k][j];
      }
      x[i][j] = r;
      printf("%i ", r);
    }
    printf("\n");
  }
*/

// i originally had i++, j++, etc instead of i+b
// but i think you have to expand the code more than this (which is essentially
// what was given)
// I was using this link for reference before running out of time
// http://csapp.cs.cmu.edu/2e/waside/waside-blocking.pdf

printf("matrix multiply w blocking(y*z): \n");
  for (i=0; i < MATRIX_SIZE; i=i+B) {
    for (j=0; j < MATRIX_SIZE; j=j+B) {
      for (k=0; k < MATRIX_SIZE; k=k+B) {
        x[i][j] = x[i][j] + y[i][k] * z[k][j];
      }
      printf("%i ", x[i][j]);
    }
    printf("\n");
  }
}

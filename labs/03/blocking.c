#include <stdio.h>
#include <math.h>

#define MATRIX_SIZE 200 
#define XSIZE 200
#define YSIZE 200
#define min( a, b ) ( ( a < b ) ? a : b ) 

int main(void) {

  int blockfactor=10;
  int blocksize=XSIZE/blockfactor;

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  int i, j, k, ii, jj;
  
  int r;


  /* Initialize x matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      x[i][j] = 0;
    }
  }

  /* Initialize y matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      y[i][j] = i + j;
    }
  }

  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
	z[i][j] = i + j;
    }
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

  for (i=0; i<XSIZE; i=i+blocksize) {
    for (j=0; j<YSIZE; j=j+blocksize) {
      for (k=0; k<XSIZE; k++) {
        for (jj=j; jj < min(j + blocksize, XSIZE); jj++) {
          for (ii=i; ii < min(i+blocksize, XSIZE); ii++) {
            x[k][jj] += y[k][ii] * z[ii][jj];
          }
        }
      }
    }
  }

}

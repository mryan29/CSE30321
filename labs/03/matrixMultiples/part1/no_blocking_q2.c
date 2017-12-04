#include <stdio.h>
#include <math.h>

#define XSIZE 10
#define YSIZE 10

int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  int i, j, k;

  int r;

	printf("\nx array:\n");
//  /* Initialize x matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      x[i][j] = 0;
	printf("%pn\t", &x[i][j]);
    }
	printf("\n");
  }


	printf("\ny matrix:\n");
  /* Initialize y matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      y[i][j] = i + j;
      printf("%pn\t", &y[i][j]);
    }
    printf("\n");
  }

	printf("\nz matrix:\n");
  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
	z[i][j] = i + j;
	printf("%pn\t", &z[i][j]);
    }
    printf("\n");
  }

  /* Do matrix multiply */
  for(i=0; i<XSIZE; i=i+1) {
    for(j=0; j<YSIZE; j=j+1) {
      r = 0;
      for(k=0; k<XSIZE; k=k+1) {
        r = r + y[i][k] * z[k][j];
      }
      x[i][j] = r;
    }
  }

}

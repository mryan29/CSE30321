#include <stdio.h>
#include <math.h>

#define XSIZE 100
#define YSIZE 100
#define MATRIX_SIZE 100
int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  int i, j, k;

  int r;

	printf("Initializing y matrix...\n");
  /* Initialize y matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      y[i][j] = i + j;
  //    printf("%d ", y[i][j]);

    }
    //printf("\n");
  }

	printf("Initializing z matrix...\n");
  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
	z[i][j] = i + j;
//	printf("%d ", z[i][j]);
    }
  //  printf("\n");
  }

	printf("Building x matrix...\n");
	// MATRIX_SIZE captures both the row and column dimensions of all matrices
	for (i=0; i < MATRIX_SIZE; i++) {
		for (j=0; j < MATRIX_SIZE; j++) {
			x[i][j] = 0;
			for(k=0; k < MATRIX_SIZE; k++) {
				x[i][j] = x[i][j] + y[i][k] * z[k][j];
			}
	//		printf("%d ", x[i][j]);
		}
	//	printf("\n");
	}

}

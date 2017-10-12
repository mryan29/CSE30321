/* Version 4 of Problem A corresponding to Step 6:
	Modify your code from Step 5 such that 16 matrix elements (a 4x4 grid) are calculated during each
	iteration of the loop.
*/

#include <stdio.h>
#include <math.h>

#define XSIZE 100
#define YSIZE 100
#define MATRIX_SIZE 100
int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  int i, j, k, m;

  int r;

	printf("Initializing y matrix...\n");
  /* Initialize y matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      y[i][j] = i + j;
    //  printf("%d ", y[i][j]);

    }
    //printf("\n");
  }

	printf("Initializing z matrix...\n");
  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
	z[i][j] = i + j;
	//printf("%d ", z[i][j]);
    }
    //printf("\n");
  }

	/* unrolled loop body such that 4 matrix elements calculated each iteration:
		x[i][j], x[i+1][j], x[i][j+1], and x[i+1][j+1].
		x[i][j] replaced with variable m
	*/
	printf("Building x matrix...\n");
	for (i=0; i < MATRIX_SIZE-1; i++) {
		for (j=0; j < MATRIX_SIZE-1; j++) {
			m = 0;
//			x[i][j] = 0;
			x[i+1][j] = 0;
			x[i][j+1] = 0;
			x[i+1][j+1]=0;
			for(k=0; k < MATRIX_SIZE; k++) {
	//			printf("i: %d, j: %d, k: %d\n", i, j, k);
				m = m + y[i][k] * z[k][j];
	//			printf("x[i][j]: %d\t", x[i][j]);
				x[i+1][j] 	= x[i+1][j] + y[i+1][k] * z[k][j];
	//			printf("x[i+1][j]: %d\t", x[i+1][j]);
				x[i][j+1]	= x[i][j+1] + y[i][k] * z[k][j+1];
	//			printf("x[i][j+1]: %d\t", x[i][j+1]);
				x[i+1][j+1]	= x[i+1][j+1] + y[i+1][k] * z[k][j+1];
	//			printf("x[i+1][j+1]: %d\n", x[i+1][j+1]);
				x[i+2][j] 	= x[i+2][j] + y[i+2][k] * z[k][j];
				x[i+3][j] 	= x[i+3][j] + y[i+3][k] * z[k][j];
				x[i][j+2]	= x[i][j+2] + y[i][k] * z[k][j+2];
				x[i][j+3]	= x[i][j+3] + y[i][k] * z[k][j+3];
				x[i+2][j+2]	= x[i+2][j+2] + y[i+2][k] * z[k][j+2];
				x[i+3][j+3]	= x[i+3][j+3] + y[i+3][k] * z[k][j+3];
			}
			x[i][j] = m;
			j+=3;
		}
		i+=3;
	}

	// for testing purposes
	for (i = 0; i < MATRIX_SIZE; i++) {
		for (j = 0; j < MATRIX_SIZE; j++) {
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}

}

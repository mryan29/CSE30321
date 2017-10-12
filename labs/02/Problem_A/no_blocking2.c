
/* Version of no_blocking.c corresponding to step 4 of the lab prompt
Step 4: unroll loop body such that 4 matrix elements calculated each iteration:
		x[i][j], x[i+1][j], x[i][j+1], and x[i+1][j+1].
*/

#include <stdio.h>
#include <math.h>

#define XSIZE 3
#define YSIZE 3
#define MATRIX_SIZE 3
int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  int i, j, k;

  int r;

	printf("Initializing y matrix...\n");	// for testing purposes

  /* Initialize y matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      y[i][j] = i + j;
      printf("%d ", y[i][j]); // for testing purposes

    }
    printf("\n");				// for testing purposes
  }

	printf("Initializing z matrix...\n");	// for testing purposes
  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
	z[i][j] = i + j;
	printf("%d ", z[i][j]);		// for testing purposes
    }
    printf("\n");				// for testing purposes
  }

	/* unrolled loop body such that 4 matrix elements calculated each iteration:
		x[i][j], x[i+1][j], x[i][j+1], and x[i+1][j+1].
	 */
	printf("Building x matrix...\n");	// for testing purposes
	// MATRIX_SIZE captures both the row and column dimensions of all matrices
	for (i=0; i < MATRIX_SIZE - 1; i++) {
		for (j=0; j < MATRIX_SIZE - 1; j++) {
			x[i][j] = 0;
			x[i+1][j] = 0;
			x[i][j+1] = 0;
			x[i+1][j+1]=0;
			for(k=0; k < MATRIX_SIZE; k++) {
				x[i][j] 	= x[i][j] + y[i][k] * z[k][j];
				x[i+1][j] 	= x[i+1][j] + y[i+1][k] * z[k][j];
				x[i][j+1]	= x[i][j+1] + y[i][k] * z[k][j+1];
				x[i+1][j+1]	= x[i+1][j+1] + y[i+1][k] * z[k][j+1];
			}
			j++;
			//printf("%d ", x[i][j]);	// for testing purposes
		}
		i++;
//	printf("\n");				// for testing purposes
	}

	// for testing purposes
	for (i = 0; i < MATRIX_SIZE; i++) {
		for (j = 0; j < MATRIX_SIZE; j++) {
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}

}

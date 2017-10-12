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
	*/
	printf("Building x matrix...\n");
	for (i=0; i < MATRIX_SIZE-1; i++) {
		for (j=0; j < MATRIX_SIZE-1; j++) {
			x[i][j] = 0;
			x[i+1][j] = 0;
			x[i][j+1] = 0;
			x[i+1][j+1]=0;
			for(k=0; k < MATRIX_SIZE; k++) {
	//			printf("i: %d, j: %d, k: %d\n", i, j, k);
				x[i][j] = x[i][j] + y[i][k] * z[k][j];
	//			printf("x[i][j]: %d\t", x[i][j]);
				x[i+1][j] 	= x[i+1][j] + y[i+1][k] * z[k][j];
	//			printf("x[i+1][j]: %d\t", x[i+1][j]);
				x[i][j+1]	= x[i][j+1] + y[i][k] * z[k][j+1];
	//			printf("x[i][j+1]: %d\t", x[i][j+1]);
				x[i+1][j+1]	= x[i+1][j+1] + y[i+1][k] * z[k][j+1];
	//			printf("x[i+1][j+1]: %d\n", x[i+1][j+1]);
			}
			j++;
		}
		i++;
	}

	// for testing purposes
/*	for (i = 0; i < MATRIX_SIZE; i++) {
		for (j = 0; j < MATRIX_SIZE; j++) {
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}
*/
}

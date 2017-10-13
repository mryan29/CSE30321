/* Version 3 of Problem A corresponding to Step 5:
	modify the code such that x[i][j] = x[i][j] + y[i][k] * z[k][j] is replaced by a variable
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

  int i, j, k;

  int r0, r1, r2, r3;

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
			r0 = 0;
			r1 = 0;
			r2 = 0;
			r3 = 0;
/*			x[i][j] = 0;
			x[i+1][j] = 0;
			x[i][j+1] = 0;
			x[i+1][j+1]=0;
*/			for(k=0; k < MATRIX_SIZE; k++) {
				r0	= r0 + y[i][k] * z[k][j];
				r1	= r1 + y[i+1][k] * z[k][j];
				r2	= r2 + y[i][k] * z[k][j+1];
				r3	= r3 + y[i+1][k] * z[k][j+1];
			}
			x[i][j] 	= r0;
			x[i+1][j]	= r1;
			x[i][j+1]	= r2;
			x[i+1][j+1]	= r3;

			j++;
		}
		i++;
	}

	// for testing purposes
	for (i = 0; i < MATRIX_SIZE; i++) {
		for (j = 0; j < MATRIX_SIZE; j++) {
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}

}
